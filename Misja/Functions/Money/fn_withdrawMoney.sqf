/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_withdrawMoney";

if (canSuspend) exitWith {
    [ULP_fnc_withdrawMoney, _this] call ULP_fnc_directCall;
};

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _group = _display getVariable ["group", false];

if (_group && { !([1] call ULP_fnc_canGroupRank) }) exitWith {
	["Nie masz pozwolenia na wypłatę z funduszy grupowych!"] call fini_fnc_noty;
};

private _amount = ([BANK, [] call ULP_fnc_groupFunds] select (_group));
if (_amount <= 0) exitWith {
	["Nie masz nic do wypłaty!"] call fini_fnc_noty;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_group],
	{
		_this params [
			["_group", false, [true]],
			["_display", displayNull, [displayNull]],
			["_value", 1, [0]]
		];

		if (_group) then {
			[format ["Attempting to withdraw %1%2...", "$", [_value] call ULP_fnc_numberText]] call fini_fnc_noty;
			[player, _value] remoteExecCall ["ULP_SRV_fnc_handleGroupFunds", RSERV];
		} else {
			if (_value > BANK) exitWith {
				[format["Nie masz <t color='#B92DE0'>%1%2</t> aby je wypłacić!", "$", [_value] call ULP_fnc_numberText]] call fini_fnc_noty;
			};

			if ([_value, true, "Wypłata z banku"] call ULP_fnc_removeMoney) then {
				[_value, false, "Wypłata z banku"] call ULP_fnc_addMoney;
				[format["Wypłaciłeś <t color='#B92DE0'>%1%2</t>.", "$", [_value] call ULP_fnc_numberText]] call fini_fnc_noty;
			};
		};
	}, false
] call ULP_fnc_selectNumber;