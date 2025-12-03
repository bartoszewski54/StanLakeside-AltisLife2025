/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_garageVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

if !(isClass _missionCfg) exitWith {};

private _time = ["rapidStorer", getNumber (missionConfigFile >> "CfgSettings" >> "garageDelay")] call ULP_fnc_activatePerk;
if (isNumber (_missionCfg >> "garageDelay")) then {
	_time = _time + getNumber (_missionCfg >> "garageDelay");
};
if ([] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty }) then { _time = 5; };

if !((crew _vehicle) isEqualTo []) exitWith {
	["Nikt nie może przebywać w pojeździe podczas jego przechowywania!"] call fini_fnc_noty;
};

if !([format["Garażowanie (%1)", _name], _time, [_vehicle, _name], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_vehicle", "_name" ];

	if (isNull _vehicle || { !((crew _vehicle) isEqualTo []) }) exitWith {
		[format["Nie udało ci się przechować tego pojazdu, ponieważ albo ktoś w nim był, albo został już usunięty!"]] call fini_fnc_noty;
	};

	private _owner = (_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, []];

	private _id = _vehicle getVariable ["vehicle_id", -1];
	if (_id >= 0) then {
		["VehicleStored", { ["Pojazd został schowany do garażu."] call fini_fnc_noty; }, true] call ULP_fnc_addEventHandler;
		[_vehicle] remoteExecCall ["ULP_SRV_fnc_storeVehicle", RSERV];
	} else {
		deleteVehicle _vehicle;
		["Pojazd schowany."] call fini_fnc_noty;
	};

	["Garaged", [_owner param [0, "Someone"], _name, [player, true] call ULP_fnc_getName]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
}, {}] call ULP_UI_fnc_startProgress) exitWith {
	["Nie możnesz schować pojazdu podczas wykonywania innej akcji!"] call fini_fnc_noty;
};

closeDialog 0;