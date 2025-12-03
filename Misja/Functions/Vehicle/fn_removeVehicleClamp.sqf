/*
** Author: Jack "Scarso" Farhall
** Description: Allows the removal of a clamp from a vehicle if the player is Police or HATO
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeVehicleClamp";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

private _clamp = _vehicle getVariable ["clamp_fine", []];

if (_clamp isEqualTo []) exitWith {
	["Ten pojazd nie ma blokady..."] call fini_fnc_noty;
	false
};

if !([player, ["Police", "Hato"]] call ULP_fnc_isFaction) exitWith {
	["Tylko policja lub HATO może usunąć blokady..."] call fini_fnc_noty;
	false
};

private _profileName = _clamp param [0, "Unknown"];

closeDialog 0;

[format["Usuwanie blokady %1 na %2", _profileName, (_cfg param [3, "Vehicle"])], 30, [_vehicle, _cfg], { (player distance (_this select 0)) <= 5 }, {
	_this params [
		["_vehicle", objNull, [objNull]],
		["_cfg", configNull, [configNull]]
	];
	
	if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
		["Ten pojazd jest zbyt uszkodzony lub nie istnieje..."] call fini_fnc_noty;
	};

	_vehicle setVariable ["clamp_fine", nil, true];
	[format ["Pomyślnie usunięto blokadę z <t color='#B92DE0'>%1</t>...", _cfg param [5, "Vehicle"]]] call fini_fnc_noty;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;

true