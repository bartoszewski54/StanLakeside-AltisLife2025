/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_crushVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

if !(isClass _missionCfg) exitWith {};
if !([player, ["Police"]] call ULP_fnc_isFaction) exitWith {
	["Tylko policja może złomować pojazdy!"] call fini_fnc_noty;
};

if !((crew _vehicle) isEqualTo []) exitWith {
	["Nikt nie może znajdować się w pojeździe podczas jego złomowania!"] call fini_fnc_noty;
};

if ((_vehicle getVariable ["vehicle_id", -1]) < 0) exitWith {
	["Wypożyczonych aut nie można złomować!"] call fini_fnc_noty;
};

private _time = ["StreetCleaner", getNumber (missionConfigFile >> "CfgSettings" >> "Police" >> "crushTime")] call ULP_fnc_activatePerk;
if (isNumber (_missionCfg >> "crushTime")) then {
	_time = _time + getNumber (_missionCfg >> "crushTime");
};

if ([] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty }) then { _time = 5; };

if !([format["Zgniatanie %1", _name], _time, [_vehicle, _name, _fee], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_vehicle", "_name", "_fee" ];

	if (isNull _vehicle || { !((crew _vehicle) isEqualTo []) }) exitWith {
		[format["Nie udało ci się zezłomować tego pojazdu, ponieważ albo ktoś w nim był, albo został już usunięty!"]] call fini_fnc_noty;
	};

	private _id = _vehicle getVariable ["vehicle_id", -1];
	if (_id >= 0) then {
		[_id] remoteExecCall ["ULP_SRV_fnc_destroyVehicle", RSERV];
	};

	private _owner = (_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, []];

	deleteVehicle _vehicle;

	[player, "CrushVehicle"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];

	["FirstCrush"] call ULP_fnc_achieve;

	["Pojazd został zezłomowany!"] call fini_fnc_noty;
	["Crushed", [_owner param [0, "Someone"], _name, [player, true] call ULP_fnc_getName]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
}, {}] call ULP_UI_fnc_startProgress) exitWith {
	["Nie można złomować pojazdu podczas wykonywania innej akcji.!"] call fini_fnc_noty;
};

closeDialog 0;