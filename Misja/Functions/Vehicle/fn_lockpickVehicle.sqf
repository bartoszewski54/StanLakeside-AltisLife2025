/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_lockpickVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] } || { ((["Lockpick"] call ULP_fnc_hasItem) < 1) }) exitWith { if (dialog) then { closeDialog 0; }; };

closeDialog 0;

if (_vehicle in ULP_Keys) exitWith {
	["Masz już kluczyki do tego pojazdu"] call fini_fnc_noty;
};

private _time = ["SpeedyLocksmith", round (40 + (random 25))] call ULP_fnc_activatePerk;

if ([] call ULP_fnc_isGroup) then {
	private _buff = [group player, "Lockpicking"] call ULP_fnc_groupBuff;
	if (_buff > 0) then { _time = _time - (_time * _buff); };
};

[format["Wytrychowanie %1", (_cfg param [3, "Vehicle"])], _time, [_vehicle, _cfg], { (player distance (_this select 0)) <= 5 }, {
	_this params [
		["_vehicle", objNull, [objNull]],
		["_cfg", [], [[]]]
	];
	
	if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
		["Ten pojazd jest zbyt uszkodzony, lub już nie istnieje..."] call fini_fnc_noty;
	};

	if (_vehicle in ULP_Keys) exitWith {
		["Masz już kluczyki do tego pojazdu"] call fini_fnc_noty;
	};

	if (["Lockpick", 1, true] call ULP_fnc_handleItem) then {
		if ((random 1) <= 0.12) then {
			[getPlayerUID player, "TheftAct", "S25",
				format [
					"Włamanie do pojazdu: %1 (%2)",
					([typeOf _vehicle] call ULP_fnc_vehicleCfg) param [3, "Unknown"], 
					getText (missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle) >> "Textures" >> (_vehicle getVariable ["texture", ""]) >> "displayName")
				]
			] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];

			[format ["Zwytrychowałeś <t color='#B92DE0'>%1</t>, dorabiając przy tym kluczyki...", _cfg param [3, "vehicle"]]] call fini_fnc_noty;
			ULP_Keys pushBackUnique _vehicle;
		} else {
			[getPlayerUID player, "RoadsAct", "Section1",
				format [
					"Próba włamania do pojazdu: %1 (%2)",
					([typeOf _vehicle] call ULP_fnc_vehicleCfg) param [3, "Unknown"], 
					getText (missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle) >> "Textures" >> (_vehicle getVariable ["texture", ""]) >> "displayName")
				]
			] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];

			["Złamałeś wytrych..."] call fini_fnc_noty;
		};
	} else {
		["Jakimś sposobem nie masz już wytrychu..."] call fini_fnc_noty;
	};
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;