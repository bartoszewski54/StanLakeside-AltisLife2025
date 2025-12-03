/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_chopVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_chopVehicle, _this] call ULP_fnc_directCall;
};

_this params [
    ["_trader", player, [objNull]],
    ["_payMore", false, [true]],
    ["_allowKeep", false, [true]]
];

if !([player, ["Civilian"]] call ULP_fnc_isFaction) exitWith {
    ["Tylko cywile mają tu dostęp!"] call fini_fnc_noty;
};

private _near = ((_trader nearEntities [["Car", "Air", "Ship"], 15]) select {
    !([_x] call ULP_fnc_getVehicleOwner isEqualTo "") &&
    { !([player, _x] call ULP_fnc_isVehicleOwner) }
});

if (_near isEqualTo []) exitWith {
    ["W pobliżu nie ma żadnych pojazdów, które można by pociąć!"] call fini_fnc_noty;
};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (_near apply {
    ([typeOf _x] call ULP_fnc_vehicleCfg) params [ "", "", "_picture", "_name" ];
    [_picture, _name, _x call BIS_fnc_netId, 0];
}), ["Chop", "Cancel"], [_trader, _payMore, _allowKeep], {
    _this params [
        ["_trader", player, [objNull]],
        ["_payMore", false, [true]],
        ["_allowKeep", false, [true]],
        ["_display", displayNull, [displayNull]]
    ];

    if (isNull _display) exitWith {};
    private _list = _display displayCtrl 4509;

    private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
    if (isNull _vehicle) exitWith { ["Nie wybrałeś pojazdu do pocięcia!"] call fini_fnc_noty; };

    if (_vehicle getVariable ["beingChopped", false]) exitWith {
        ["Ten pojazd jest już w trakcie cięcia!"] call fini_fnc_noty;
    };

    _vehicle setVariable ["beingChopped", true, true]; // Ustawiamy flagę globalnie

    _vehicle setVariable ["chopperUID", getPlayerUID player, true];

    private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
    if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith {};

    _cfg params [ "", "_missionCfg", "_picture", "_name" ];

    if !(isClass _missionCfg) exitWith {};

    private _time = getNumber (missionConfigFile >> "CfgVehicles" >> "chopTime");
    if (isNumber (_missionCfg >> "chopTime")) then {
        _time = _time + getNumber (_missionCfg >> "chopTime");
    };

    if !([format["Cięcie %1", _name], _time, [_vehicle, _missionCfg, _name, _payMore, _allowKeep], {
        !(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 15 }
    }, {
        scopeName "_fnc_onChopped";
        _this params [ "_vehicle", "_cfg", "_name", "_payMore", "_allowKeep" ];

        if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
            _vehicle setVariable ["beingChopped", false, true];
            [format["Nie udało ci się pociąć <t color='#B92DE0'>%1</t> ponieważ pojazd ten został zniszczony."]] call fini_fnc_noty;
        };

        private _chopValue = getNumber (_cfg >> "buyPrice") * ([
            getNumber (missionConfigFile >> "CfgVehicles" >> "chopPerc"),
            getNumber (_cfg >> "chopPerc")
        ] select (isNumber (_cfg >> "chopPerc")));

        if (_payMore) then {
            _chopValue = _chopValue * 1.1;
        };

        _chopValue = ["ScrapDealer", _chopValue] call ULP_fnc_activatePerk;

        private _id = _vehicle getVariable ["vehicle_id", -1];
        private _owner = [_vehicle] call ULP_fnc_getVehicleOwner;
        deleteVehicle _vehicle;

        if (_id >= 0) then {
            [_id] remoteExecCall ["ULP_SRV_fnc_destroyVehicle", RSERV];
        };

        [_chopValue, false, format["Pocięto %1", _name]] call ULP_fnc_addMoney;
        [format["Pociąłeś <t color='#B92DE0'>%1</t> za <t color='#B92DE0'>%2%3</t>.", _name, "$", [_chopValue] call ULP_fnc_numberText]] call fini_fnc_noty;

        [player, "ChopVehicle"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];

        ["ChopVeh"] call ULP_fnc_achieve;
    }, {
        _this params [ "_vehicle" ];
        if (!isNull _vehicle) then {
            _vehicle setVariable ["beingChopped", false, true];
        };
        ["Musisz stać obok pojazdu który chcesz pociąć..."] call fini_fnc_noty;
    }, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
        _vehicle setVariable ["beingChopped", false, true];
        ["Nie można ciąć pojazdu podczas wykonywania czegoś innego!"] call fini_fnc_noty;
    };
}, false] call ULP_fnc_selectObject;
