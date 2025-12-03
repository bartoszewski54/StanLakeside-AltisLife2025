/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#include "..\..\dikCodes.hpp"
#define ACT_KEY(name, default) [(actionKeys name) select 0, default] select (actionKeys name isEqualTo [])
scopeName "fn_keyUp";

_this params [
    "_ctrl", "_code", "_shift", "_ctrlKey", "_alt"
];

private _handled = false;

private _seatKey = ACT_KEY("User1", B);
private _interactionKey = ACT_KEY("User10", LWINDOWS);
private _anprKey = ACT_KEY("User11", NUMSLASH);
if (_code in (actionKeys "NightVision") && { [goggles player] call ULP_fnc_isNightVision }) exitWith {
    private _action = if ((currentVisionMode player) isEqualTo 1) then { "nvGogglesOff" } else { "nvGoggles" };
    player action [_action, player];
    _handled = true;
};

switch (_code) do {
    if (isDowned(player)) then {
        _handled = true;
        case F: {
            if (_shift && {missionNamespace getVariable ["ULP_CanRespawn", false] }) then {
                if (((["Medic"] call ULP_fnc_allMembers) findIf { !(player isEqualTo _x) && { (player distance _x) <= 300 } }) > -1) exitWith {
                    ["<t color='#B92DE0'>Medyk jest obok Ciebie</t>, nie możesz się odrodzić..."] call fini_fnc_noty;
                };

                player setDamage 1;
            };
        };
		case SPACE: {
            if ((count (["Medic"] call ULP_fnc_allMembers)) < 1) exitWith { ["Brak medyków..."] call fini_fnc_noty; };

            if (localNamespace getVariable ["ULP_MedicalRequest", 0] < time) then {
                private _cfg = missionConfigFile >> "CfgMessages" >> "MedicRequest";
                private _targets = getText (_cfg >> "targets");

                [_cfg, format ["%1 prosi o pomoc medyczną...", profileName], _targets] call ULP_fnc_sendMessage;
                ["Zażądałeś pomocy medycznej..."] call fini_fnc_noty;

                localNamespace setVariable ["ULP_MedicalRequest", time + 180];
            } else {
                ["Ostatnio już prosiłeś o pomoc medyczną, poczekaj zanim spróbujesz ponownie..."] call fini_fnc_noty;
            };
        };
    };

    case NINE: {
        [] call ULP_fnc_movesMenu;
    };

    case FOUR: {
        if (isNull (objectParent player) && { !([] call ULP_UI_fnc_isProgress) }) then {
            private _move = switch (true) do {
                case (_shift): { "gestureHiC" };
                case (_ctrlKey) : { "gestureHiB" };
                case (_alt): { "gesturenod" };
                default { "" };
            };
            
            if (_move isEqualTo "") exitWith {};
            player playActionNow _move;
        };
    };

    case _interactionKey: {
        if !([] call ULP_UI_fnc_isProgress) then {
            _this call ULP_fnc_actionKeyDown;
            _handled = true;
        };
    };

    case _seatKey: {
        if (!(isNull (objectParent player)) && { (vehicle player) isKindOf "LandVehicle" }) then {
            player setVariable["seatbelt", !(player getVariable["seatbelt", false])];
        };
    };

    case J: {
        if (_shift && { !([player] call ULP_fnc_isRestrained) } && { !([player] call ULP_fnc_isKnocked) } && { !([player] call ULP_fnc_isSurrendered) } && { (["PanicButton"] call ULP_fnc_hasItem) > 0 }) then {
            [] call ULP_fnc_panic;
        };
    };

    case T: {
        if !(_shift && { _ctrlKey } && { _alt } && { dialog }) then {
            if (isNull (objectParent player)) then {
                private _container = cursorObject;

                if ((player distance _container) < 5) then {
                    _handled = [_container] call ULP_fnc_openInventory;
                };
            } else {
                _handled = [vehicle player] call ULP_fnc_openInventory;
            };
        };
    };

    case O: {
        if (_shift && { !_ctrlKey } && { !_alt }) then {
            ULP_FadeSound = !ULP_FadeSound;
            0 fadeSound ([1, ["EffectsFade", "Audio"] call ULP_fnc_getOption] select (ULP_FadeSound));
            0 fadeMusic ([1, ["MusicFade", "Audio"] call ULP_fnc_getOption] select (ULP_FadeSound));

            [format["<t color='#B92DE0'>%1</t> zatyczki.", ["Wyciągnąłeś", "Włożyłeś"] select (ULP_FadeSound)]] call fini_fnc_noty;
        };
    };

    case F1: {
        if ([] call ULP_fnc_isStaff && { _shift } && { !_ctrlKey } && { !_alt }) then {
            [] call ULP_fnc_toggleAdminGear;
        };
    };

    case F2: {
        if ([] call ULP_fnc_isStaff && { ["Camera", false] call ULP_fnc_checkPower } && { _shift } && { !_ctrlKey } && { !_alt }) then {
            (findDisplay 46) createDisplay "DisplayAdmin";
            _handled = true;
        };
    };

    case F3: {
        if ([] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { ["Invis", false] call ULP_fnc_checkPower } && { _shift } && { !_ctrlKey } && { !_alt }) then {
            if (time < (player getVariable ["admin_invis_cooldown", 0])) exitWith {
                ["Niedawno włączyłeś niewidkę, poczekaj zanim spróbujesz ponownie..."] call fini_fnc_noty;
                false
            };
            player setVariable ["admin_invis_cooldown", time + 2];

            [player, !(isObjectHidden player)] remoteExecCall ["ULP_SRV_fnc_hidePlayer", RSERV];
            [getPlayerUID player, "Admin", ["AdminInvisibility", serverTime, []]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
        };
    };

    case F4: {
        if ([] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { ["Compensate", false] call ULP_fnc_checkPower } && { _shift } && { !_ctrlKey } && { !_alt }) then {
            if (time < (player getVariable ["admin_comp_cooldown", 0])) exitWith {
                ["Niedawno zrespiłeś pieniądze, poczekaj przed ponowną próbą..."] call fini_fnc_noty;
                false
            };

            [
                (findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, 3000000], [],
                {
                    _this params [
                        ["_display", displayNull, [displayNull]],
                        ["_value", 1, [0]]
                    ];

                    if ([_value, false, "Zwrot"] call ULP_fnc_addMoney) then {
                        [format ["Zrespiłeś <t color='#B92DE0'>%1%2</t>", "$", [_value] call ULP_fnc_numberText]] call fini_fnc_noty;

                        [getPlayerUID player, "Admin", ["AdminCompensate", serverTime, [_value]]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
                        player setVariable ["admin_comp_cooldown", time + 5];
                    };
                }, false
            ] call ULP_fnc_selectNumber;
        };
    };

    case F5: {
        if ([] call ULP_fnc_isStaff && { ["Medical", false] call ULP_fnc_checkPower } && { isDowned(player) } && { _shift } && { _ctrlKey } && { !_alt }) then {
            [player] remoteExecCall ["ULP_fnc_revived", player];
            player setDamage 0;

            ["Zrevivowaleś się..."] call fini_fnc_noty;

            [getPlayerUID player, "Admin", ["AdminSelfRevive", serverTime, []]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
        };
    };

    case F9: {
        if ([] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { ["Medical", false] call ULP_fnc_checkPower } && { _shift } && { _ctrlKey } && { !_alt }) then {
            if (time < (player getVariable ["admin_mass_cooldown", 0])) exitWith {
                ["Niedawno użyłeś mass revive & heal, poczekaj zanim spróbujesz ponownie..."] call fini_fnc_noty;
                false
            };

            [
                (findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Napewno?", ["Tak", "Nie"],
                format ["Napewno chcesz wszystkich podnieść i uleczyć?"], [],
                {	
                    {
                        if (isDowned(_x)) then {
                            [player] remoteExecCall ["ULP_fnc_revived", _x];
                        };

                        if ((damage _x) >= 0.01) then {
                            _x setDamage 0;
                        };
                    } forEach playableUnits;

                    ["Podniosłeś i uzdrowiłeś wszystkich..."] call fini_fnc_noty;

                    [getPlayerUID player, "Admin", ["AdminMassRevive", serverTime, []]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
                    player setVariable ["admin_mass_cooldown", time + 15];
                }, {}, false
            ] call ULP_fnc_confirm;
        };
    };

    case U : {
        if (_shift && { _ctrlKey } && { !_alt } && { [] call ULP_fnc_isUndercover }) then {
            if (time < (player getVariable ["uc_cooldown", 0])) exitWith {
                ["Niedawno zmieniłeś tożsamość, poczekaj przed ponowną próbą..."] call fini_fnc_noty;
            };
            player setVariable ["uc_cooldown", time + 3];

            if ([player, ["Civilian"]] call ULP_fnc_isFaction) then {
                [player, "Police"] call ULP_fnc_setFaction;
            } else {
                [player, "Civilian"] call ULP_fnc_setFaction;
            };

            [] call ULP_fnc_setTags;
            _handled = true;
        };

        if ([] call ULP_fnc_isStaff && { ([player] call ULP_fnc_isRestrained) } && { [player] call ULP_fnc_onDuty } && { ["Restrain", false] call ULP_fnc_checkPower } && { _ctrlKey } && { !_shift } && { !_alt }) then {
            [player, objNull, false] call ULP_fnc_restrain;
        };
    };

    case P : {
        private _veh = vehicle player;

        if ([_veh] call ULP_fnc_vehRemoteGate) then {
            if !(_shift && { _ctrlKey } && { _alt } && { _veh isEqualTo player }) then {
                {
                    private _anim = getText(missionConfigFile >> "CfgSettings" >> "Gates" >> (typeOf _x) >> "anim");

                    if ([player, (_x getVariable ["gate_factions", []])] call ULP_fnc_isFaction) then {
                        _x animate [_anim, ([1, 0] select ((_x animationPhase _anim) isEqualTo 1))];
                    };
                } forEach (nearestObjects [player, (("isClass _x" configClasses (missionConfigFile >> "CfgSettings" >> "Gates")) apply { configName _x }), 15]);
            };
        };
    };

    case _anprKey : {
        private _veh = vehicle player;
        
        if ([_veh] call ULP_fnc_canANPR) then {
            if (_veh isKindOf "LandVehicle") then {
                if (time < (_veh getVariable ["anpr_delay", 0])) exitWith {};
                _veh setVariable ["anpr_delay", time + 3];

                private _cars = (nearestObjects [_veh, ["Car"], 100]) select {
                    !(_veh isEqualTo _x) && { alive _x }
                };

                private _vehicle = _cars param [0, objNull];
                if (isNull _vehicle) exitWith {};

                [format ["<t color='#316dff' size='1.5' align='center'>ANPR</t><br/><t color='#f9f2f2' size='1' align='center'>Żądanie informacji z DVLA....</t>"]] call fini_fnc_noty;
                [1, [_vehicle], {
                    _this params [ "_vehicle" ];

                    [format [
                        "<t color='#316dff' size='1.5' align='center'>ANPR</t><br/><t color='#119b0c' size='1px' align='center'>Typ:</t><t size='1' align='center'> %1</t><br/><t color='#119b0c' size='1px' align='center'>Właściciel:</t><t size='1' align='center'> %2</t><br/><t color='#119b0c' size='1px' align='center'>Prędkość:</t><t size='1' align='center'> %3 km/h</t>",
                        ([typeOf _vehicle] call ULP_fnc_itemCfg) param [5, "Vehicle"], (((_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, []]) param [0, "Unknown"]), round (speed _vehicle)
                    ]] call fini_fnc_noty;
                }] call ULP_fnc_waitExecute;
            };
        };
    };

    case DELETE : {
        private _veh = cursorObject;

        if (time < (player getVariable ["delete_delay", 0])) exitWith {};

        if (!(isNull _veh) && { !_shift } && { !_ctrlKey } && { !_alt } && { [] call ULP_fnc_isStaff } && { [player] call ULP_fnc_onDuty } && { ["Vehicle", false] call ULP_fnc_checkPower } && { [_veh, ["LandVehicle", "Air", "Ship"]] call ULP_fnc_isKindOf }) then {
            player setVariable ["delete_delay", time + 3];
            deleteVehicle _veh;

            [getPlayerUID player, "Admin", ["VehicleDelete", serverTime, [getPos _veh, _veh getVariable ["vehicle_id", -1]]]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
        };
    };
};

_handled