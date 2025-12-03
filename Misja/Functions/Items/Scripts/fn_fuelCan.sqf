/*
** Autor: Jack "Scarso" Farhall
** Opis:
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_fuelCan";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;

// Sprawdzenie, czy pojazd jest poprawny i czy jego konfiguracja jest dostępna
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "", "", "", "", "_fuel"
];

// Sprawdzenie, czy konfiguracja misji jest klasą
if !(isClass _missionCfg) exitWith {};

private _time = 40;
// Dostosowanie czasu tankowania na podstawie konfiguracji misji
if (isNumber (_missionCfg >> "refuelTime")) then {
	_time = _time + getNumber (_missionCfg >> "refuelTime");
};

// Sprawdzenie, czy można rozpocząć proces tankowania
if !([format["Tankowanie %1", _name], _time, [_vehicle, _name, _fuel], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { ["FuelCan"] call ULP_fnc_hasItem > 0 } && { (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_vehicle", "_name", "_fuel" ];

	// Sprawdzenie, czy pojazd istnieje, jest sprawny i czy gracz ma kanister paliwa
	if (isNull _vehicle || { !(alive _vehicle) } || { !(["FuelCan", 1, true] call ULP_fnc_handleItem) }) exitWith {
		[format["Nie udało się zatankować pojazdu <t color='#B92DE0'>%1</t>, ponieważ jest on poważnie uszkodzony lub straciłeś kanister paliwa..."]] call fini_fnc_noty;
	};

	// Obsługa tankowania, zmniejszenie liczby kanistrów i ustawienie poziomu paliwa
	_fuel = ((fuel _vehicle) + (_fuel / 100));

	if (local _vehicle) then {
		_vehicle setFuel _fuel;
	} else {
		[_vehicle, _fuel] remoteExecCall ["ULP_fnc_setFuel", _vehicle];

		[format["Zatankowałeś pojazd <t color='#B92DE0'>%1</t> za pomocą kanistra paliwa..."]] call fini_fnc_noty;
	};
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	["Nie możesz tankować pojazdu, wykonując jednocześnie inną akcję!"] call fini_fnc_noty;
};

// Zamknięcie dialogu po zakończeniu procesu
closeDialog 0;
