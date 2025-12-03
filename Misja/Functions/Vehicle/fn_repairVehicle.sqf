/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_repairVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

private _hasToolkit = "ToolKit" in (items player);
private _isPatching = !_hasToolkit && { [_vehicle] call ULP_fnc_hasTyreDamage };

if !(isClass _missionCfg) exitWith {};
if (!_hasToolkit && { !_isPatching }) exitWith {
	["Nie masz naprawki!"] call fini_fnc_noty;
};

private _time = 40;
if (isNumber (_missionCfg >> "repairTime")) then {
	_time = _time + getNumber (_missionCfg >> "repairTime");
};

private _profession = ["Naprawianie"] call ULP_fnc_getProfessionCalculation;
if (_profession > 0) then {
	_time = _time - (_time * (_profession / 100));
};

if !([format["%1 %2", ["Naprawianie", "Wymienianie koła w"] select (_isPatching), _name], _time, [_vehicle, _name, _isPatching], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { "ToolKit" in (items player) || { (_this select 2) } } && { (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_vehicle", "_name", "_isPatching" ];

	if (isNull _vehicle || { !(alive _vehicle) } || { !("ToolKit" in (items player)) && { !_isPatching } }) exitWith {
		[format["Nie udało ci się naprawić <t color='#B92DE0'>%1</t> ponieważ jest zbyt uszkodzony, lub nie masz odpowiednich narzędzi"]] call fini_fnc_noty;
	};
	
	if (!([player, ["Hato"]] call ULP_fnc_isFaction) && { !_isPatching }) then {

		// No Perk - 0, L1 Perk - 0.25, L2 - .5, L3 - .75, L4 - 1
		private _perkValue = ["GeneralMechanic", 0] call ULP_fnc_activatePerk;

		// For everyone but HATO apply "General Mechanic" Perk
		if ((1 - _perkValue) <= (random 1)) exitWith {
			["Udało ci się nie zniszczyć narzędzi."] call fini_fnc_noty;
		};

		player removeItem "Toolkit";
	};

	if (_isPatching) then {
		{
			if (((toLower (configName _x)) find "wheel") > -1) then {
				_vehicle setHitPointDamage [configName _x, 0];
			};
		} forEach ("isClass _x" configClasses (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "HitPoints"));

		[format["Załatałeś opony w <t color='#B92DE0'>%1</t>, lecz bez naprawki nie naprawisz nic innego.", _name]] call fini_fnc_noty;
	} else {
		_vehicle setDamage 0;
		[format["Naprawiłeś <t color='#B92DE0'>%1</t> przy użyciu naprawki.", _name]] call fini_fnc_noty;
		["RepairVeh"] call ULP_fnc_achieve;
	};

	if (time >= (_vehicle getVariable ["ProfessionCooldown", time - 120])) then {
		["Repairing", 1, 40] call ULP_fnc_increaseProfession;
		_vehicle setVariable ["ProfessionCooldown", time + 120];
	};
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	["Nie można naprawić pojazdu podczas wykonywania innej akcji!"] call fini_fnc_noty;
};

closeDialog 0;