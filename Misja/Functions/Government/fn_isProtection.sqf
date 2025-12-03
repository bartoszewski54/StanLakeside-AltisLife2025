/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isProtection";

([] call ULP_fnc_isGroup && 
	{ ["Protection"] call ULP_fnc_hasLicense })