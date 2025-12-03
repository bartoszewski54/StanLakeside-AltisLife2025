/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_pickupMoney";

if (canSuspend) exitWith {
    [ULP_fnc_pickupMoney, _this] call ULP_fnc_directCall;
};

_this params [
	["_pile", objNull, [objNull]]
];

if (dialog) then { closeDialog 0; };
if (isNull _pile || { (_pile getVariable ["ULP_MoneyStack", 0]) < 1 }) exitWith { false };

private _amount = _pile getVariable ["ULP_MoneyStack", 0];

if ([_amount, false, "Podniosłeś"] call ULP_fnc_addMoney) exitWith {
	player playMove "AinvPknlMstpSlayWrflDnon";
	
	deleteVehicle _pile;
	[format ["Podniosłeś <t color='#B92DE0'>%1%2</t> z ziemi...", "$", [_amount] call ULP_fnc_numberText]] call fini_fnc_noty;
	true
};

false