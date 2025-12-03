/*
** Autor: Jack "Scarso" Farhall
** Opis:
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_disguiseIdentity";

_this params [
	["_item", "", [""]],
	["_identity", name player, [""]]
];

// Brak aktywnej tożsamości i ta karta tożsamości odpowiada naszemu imieniu
if (isNil { player getVariable "name" } && { (name player) isEqualTo _identity }) exitWith {};

// Zatrzymaj spam...
if (time < (player getVariable ["last_disguised", 0])) exitWith {
	["Ostatnio zmieniłeś swoją tożsamość, poczekaj chwilę..."] call fini_fnc_noty;
	false
};
player setVariable ["last_disguised", time + 3];

// Jeśli tożsamość odpowiada naszej obecnej tożsamości publicznej
if (_identity isEqualTo (name player) || { ((player getVariable ["name", name player]) isEqualTo _identity) }) then {
	player setVariable ["name", nil, true];
	["Przywróciłeś swoją publiczną tożsamość do normalnej."] call fini_fnc_noty;
} else {
	player setVariable ["name", _identity, true];
	[format ["Zmieniono twoją publiczną tożsamość na <t color='#B92DE0'>%1</t>.", _identity]] call fini_fnc_noty;
	["DisguiseID"] call ULP_fnc_achieve;
};

true
