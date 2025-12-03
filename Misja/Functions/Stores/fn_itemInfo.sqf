/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_itemInfo";

private _item = _display getVariable ["itemData", []];
if (_item isEqualTo []) exitWith { "" };

_item params [
	"_name", "_price"
];

format[
	"<t size='0.8'><br/>Informacje o przedmiocie<br/>Nazwa: %1<br/>Cena: <t color='#8cff9b'>$%2</t><br/></t>",
	_name, [_price] call ULP_fnc_numberText
]