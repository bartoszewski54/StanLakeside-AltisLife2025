/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_recieveMoney";

if (canSuspend) exitWith {
    [ULP_fnc_recieveMoney, _this] call ULP_fnc_directCall;
};

_this params [
	["_unit", objNull, [objNull]],
	["_amount", 0, [0]],
	["_bank", false, [true]]
];

if (isNull _unit || { _unit isEqualTo player } || { _amount < 1 }) exitWith {};

if ([_amount, _bank, format ["Otrzymano %1%2 w %3", "$", [_amount] call ULP_fnc_numberText, ["gotówce", "przelewie"] select (_bank)]] call ULP_fnc_addMoney) then {
	[format ["%1 %2 Ci <t color='#B92DE0'>%3%4</t>", name _unit, ["dał", "przelał"] select (_bank), "$", [_amount] call ULP_fnc_numberText]] call fini_fnc_noty;
};