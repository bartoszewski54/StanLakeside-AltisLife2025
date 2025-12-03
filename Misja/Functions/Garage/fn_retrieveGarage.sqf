/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_retrieveGarage";

if (canSuspend) exitWith {
    [ULP_fnc_retrieveGarage, _this] call ULP_fnc_directCall;
};

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _impound = _display getVariable ["impound", false];

private _vehInfo = _display getVariable ["selected", []];
if (_vehInfo isEqualTo []) exitWith {};

_vehInfo params [
	"_id", "_classname", "_texture", "_price"
];

private _cfg = missionConfigFile >> "CfgVehicles" >> _classname;

if !(call compile getText(_cfg >> "conditions")) exitWith {
	["Ten pojazd ma specjalne wymagania, których już nie spełniasz."] call fini_fnc_noty;
};

private _spawns = _display getVariable ["spawns", []];

_spawns = _spawns apply {
	if (_x isEqualType []) exitWith { [_x] };
	[markerPos _x, markerDir _x]
};

private _spawn = {
	if (((_x select 0) nearEntities [["Car", "Ship", "Air"], 8]) isEqualTo []) exitWith { _x };
} forEach _spawns;

if (isNil "_spawn") exitWith {
	["Miejsce spawnu jest zajęte!"] call fini_fnc_noty;
};

if ([_price, true, (["Cena wyciągnięcia pojazdu", "Cena schowania pojazdu"] select (_impound))] call ULP_fnc_removeMoney) exitWith {
	closeDialog 0;

	[_classname, _spawn, _texture, _id] call ULP_fnc_createVehicle;
	[_id] remoteExecCall ["ULP_SRV_fnc_retrieveVehicle", RSERV];
};

[format["Nie stać cię na wyciągnięcie tego pojazdu. Potrzebujesz $%1.", [_price] call ULP_fnc_numberText]] call fini_fnc_noty;