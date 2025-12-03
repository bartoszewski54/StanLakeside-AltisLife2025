/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getBuildingDoors";

_this params [
	["_building", objNull, [objNull]]
];

// Sprawdzenie liczby drzwi
private _doorCount = getNumber (configFile >> "CfgVehicles" >> (typeOf _building) >> "numberOfDoors");
if (_doorCount isEqualTo 0) exitWith { [] };

// Inicjalizacja pustej tablicy dla drzwi
private _doors = [];

// Pętla przez wszystkie drzwi
for "_i" from 1 to _doorCount do {
	_doors pushBack (_building modelToWorld (_building selectionPosition format ["Door_%1_trigger", _i]));
};

// Zwrócenie tablicy drzwi
_doors
