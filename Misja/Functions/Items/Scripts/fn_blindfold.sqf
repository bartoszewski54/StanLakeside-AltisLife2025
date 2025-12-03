/*
** Autor: Jack "Scarso" Farhall
** Opis:
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_blindfold";

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit) exitWith {};

// Sprawdzenie, czy jednostka ma założoną opaskę na oczy
if (_unit getVariable ["blindfold", false]) then {
	// Zdjęcie opaski z oczu
	_unit setVariable ["blindfold", nil, true];
	["Blindfold", 1, false, true] call ULP_fnc_handleItem;
	[format ["Zdjąłeś opaskę na oczy z <t color='#B92DE0'>%1</t>...", [_unit, true] call ULP_fnc_getName]] call fini_fnc_noty;
} else {
	// Założenie opaski na oczy
	if (["Blindfold", 1, true] call ULP_fnc_handleItem) then {
		_unit setVariable ["blindfold", true, true];
		[format ["Założyłeś opaskę na oczy <t color='#B92DE0'>%1</t>...", [_unit, true] call ULP_fnc_getName]] call fini_fnc_noty;
	} else {
		breakOut "fn_blindfold";
	};
};

// Wywołanie zdarzenia "Blindfold" dla jednostki
["Blindfold", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
closeDialog 0;
