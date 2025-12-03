/*
** Autor: Jack "Scarso" Farhall
** Opis:
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_drill";

private _object = cursorObject;

// Sprawdzenie, czy obiekt istnieje, czy gracz jest wystarczająco blisko i czy obiekt nie został już otwarty
if (isNull _object || { (player distance _object) > 5 } || { _object getVariable ["locked", false] }) exitWith {
	["Jesteś albo za daleko od czegoś, co możesz przewiercić, albo zostało to już otwarte..."] call fini_fnc_noty;
};

// Rozpoczęcie procesu wiercenia
["Wiercenie kontenera", 240, [_object], { (player distance (_this select 0)) <= 5 }, {
	private _object = _this select 0;

	["Udało ci się otworzyć zamek!"] call fini_fnc_noty;
	_object setVariable ["locked", nil, true];
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
