/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_checkMoney";

if (canSuspend) exitWith {
    [ULP_fnc_checkMoney, _this] call ULP_fnc_directCall;
};

_this params [
	["_mode", 0, [0]],
	["_params", [], []]
];

switch (_mode) do {
	case 2: {
		_params params [
			["_unit", objNull, [objNull]],
			["_cash", 0, [0]]
		];

		if (isNull _unit || { _unit isEqualTo player }) exitWith {};
		
		if (_cash > 0) then {
			[format ["%1 ma przy sobie <t color='#B92DE0'>%2%3</t> w gotówce...", [_unit, true] call ULP_fnc_getName, "$", [_cash] call ULP_fnc_numberText]] call fini_fnc_noty;
			_unit setVariable ["checking_money", nil];
		} else {
			[format ["%1 nie ma przy sobie gotówki...", [_unit, true] call ULP_fnc_getName]] call fini_fnc_noty;
		};
	};

	case 1: {
		_params params [
			["_unit", objNull, [objNull]]
		];

		if (isNull _unit || { _unit isEqualTo player }) exitWith {};
		
		[2, [player, CASH]] remoteExecCall ["ULP_fnc_checkMoney", _unit];
	};

	default {
		_params params [
			["_unit", objNull, [objNull]]
		];

		if (isNull _unit || { _unit isEqualTo player }) exitWith {};
		
		if (_unit getVariable ["checking_money", false]) exitWith {
			["Już liczysz pieniądze tej osoby..."] call fini_fnc_noty;
		};
		_unit setVariable ["checking_money", true];
		
		[1, [player]] remoteExecCall ["ULP_fnc_checkMoney", _unit];
	};
};