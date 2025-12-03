/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_cartInfo";

format[
	"<t size='0.8'><br/>Informacje o koszyku<br/>Total Cost: <t color='#8cff9b'>$%1</t><br/></t>",
	[(_display getVariable ["cartValue", 0])] call ULP_fnc_numberText
]