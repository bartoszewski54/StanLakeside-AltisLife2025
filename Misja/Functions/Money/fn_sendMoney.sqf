/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_sendMoney";

if (canSuspend) exitWith {
    [ULP_fnc_sendMoney, _this] call ULP_fnc_directCall;
};

_this params [
	["_unit", objNull, [objNull]],
	["_amount", 0, [0]],
	["_bank", false, [true]]
];

if (isNull _unit || { _unit isEqualTo player } || { [] call ULP_fnc_isRestrained } || { [] call ULP_fnc_isSurrendered } || { isDowned(player) } || { isDowned(_unit) } || { !_bank && ((player distance _unit) > 3) }) exitWith {
	["Musisz być blisko, niezakuty i nie podanny, aby dać gotówkę..."] call fini_fnc_noty;
};

if (_amount < 1) exitWith {
	["W tej chwili nie masz pieniędzy do przekazania..."] call fini_fnc_noty;
};

if !([_amount, _bank, format ["%1 %2", ["Dałeś", "Przelałeś"] select (_bank), name _unit]] call ULP_fnc_removeMoney) exitWith {
	[format ["Nie masz <t color='#B92DE0'>%1%2</t> aby dać %3...", "$", [_amount] call ULP_fnc_numberText, ["give", "transfer"] select (_bank)]] call fini_fnc_noty;
};

[player, _amount, _bank] remoteExecCall ["ULP_fnc_recieveMoney", _unit];
[format ["%1 <t color='#B92DE0'>%2%3</t> do %4", ["Dałeś", "Przelałeś"] select (_bank), "$", [_amount] call ULP_fnc_numberText, name _unit]] call fini_fnc_noty;