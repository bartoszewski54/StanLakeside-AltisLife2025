/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_depositMoney";

if (canSuspend) exitWith {
    [ULP_fnc_depositMoney, _this] call ULP_fnc_directCall;
};

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _group = _display getVariable ["group", false];

if (_group && { !([0] call ULP_fnc_canGroupRank) }) exitWith {
	["Nie masz uprawnień do wpłacania środków grupowych!"] call fini_fnc_noty;
};

private _amount = CASH;
if (_amount <= 0) exitWith {
	["Nie masz nic do zdeponowania!"] call fini_fnc_noty;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_group],
	{
		_this params [
			["_group", false, [true]],
			["_display", displayNull, [displayNull]],
			["_value", 1, [0]]
		];

		if (_value > CASH) exitWith {
			[format["Nie masz <t color='#B92DE0'>%1%2</t> do wpłacenia!", "$", [_value] call ULP_fnc_numberText]] call fini_fnc_noty;
		};

		if ([_value, false, "Bankomat"] call ULP_fnc_removeMoney) then {
			if (_group) then {
				[player, _value, true] remoteExecCall ["ULP_SRV_fnc_handleGroupFunds", RSERV];
			} else {
				[_value, true, "Bankomat"] call ULP_fnc_addMoney;
			};

			[format["Wpłacono <t color='#B92DE0'>%1%2</t>.", "$", [_value] call ULP_fnc_numberText]] call fini_fnc_noty;
		};
	}, false
] call ULP_fnc_selectNumber;