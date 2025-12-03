/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vehicleRegistration";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _owner = (_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, []];

if (_owner isEqualTo []) exitWith {
	deleteVehicle _vehicle;
	["Pojazd został usunięty, ponieważ nie ma właściciela.."] call fini_fnc_noty;
};

[format ["<t color='#FF0000'><t size='1.7'>Rejestracja pojazdu</t></t><br/><t color='#FFD700'><t size='1.5'>Właściciel:</t></t><br/> %1", _owner param [0, "Nieznany"]]] call fini_fnc_noty;