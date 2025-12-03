/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyVItems";

private _ctrl = 

_this params [
	"_controls",
	["_remove", false, [true]]
];

_controls params [
	"_ctrl"
];

disableSerialization;

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if ([player] call ULP_fnc_onDuty) exitWith {
	["Podczas służby nie możesz sprzedawać ani kupować przedmiotów..."] call fini_fnc_noty;
};

private _list = _display displayCtrl 3303;

private _curSel = missionConfigFile >> "CfgVirtualItems" >> (_list lnbData [(lnbCurSelRow _list), 0]);
if !(isClass _curSel) exitWith { ["Najpierw należy wybrać element!"] call fini_fnc_noty; };

private _buyPrice = _list lnbValue [(lnbCurSelRow _list), 1];
private _sellPrice = _list lnbValue [(lnbCurSelRow _list), 2];
(parseSimpleArray (_list lnbData [(lnbCurSelRow _list), 2])) params [ "_gangTax", "_cartels" ];
private _amount = 1;

if (_remove) then {
	_amount = [configName _curSel] call ULP_fnc_hasItem;
	if (_amount isEqualTo -1) exitWith {
		["Nie masz żadnego z wybranych przedmiotów do sprzedania!"] call fini_fnc_noty;
		false breakOut "fn_buyVItems";
	};
} else {
	_amount = [getNumber(_curSel >> "weight")] call ULP_fnc_getMaxQuantity;
	if (_amount isEqualTo 0) exitWith {
		["Brakuje ci miejsca w plecaku!"] call fini_fnc_noty;
		false breakOut "fn_buyVItems";
	};
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_curSel, _remove, _buyPrice, _sellPrice, _gangTax, _cartels],
	{
		_this params [
			["_cfg", configNull, [configNull]],
			["_remove", false, [true]],
			["_buyPrice", 0, [0]],
			["_sellPrice", 0, [0]],
			["_gangTax", 0, [0]],
			["_cartels", [], [[]]],
			["_display", displayNull, [displayNull]],
			["_value", 1, [0]]
		];

		_display = findDisplay 3300; // We don't need select so we switch this to virtual store...
		if (isNull _display || { isNull _cfg }) exitWith {};

		_buyPrice = _buyPrice * _value;
		_sellPrice = _sellPrice * _value;
		_gangTax = _gangTax * _value;

		private _name = getText(_cfg >> "displayName");

		if (_remove) then {
			if ([configName _cfg, _value, true] call ULP_fnc_handleItem) then {
				["SoldVirtualItem", [configName _cfg, _value, _sellPrice, [getNumber (_cfg >> "Settings" >> "isIllegal")] call ULP_fnc_bool]] call ULP_fnc_invokeEvent;
				[_sellPrice, false, format["Sprzedaż %1 %2", _value, _name]] call ULP_fnc_addMoney;

				{
					_x params [ "_group", "_price" ];
					if ([_group] call ULP_fnc_isGroup) then {
						[_group, round (_price * _value), true] remoteExecCall ["ULP_SRV_fnc_handleGroupFunds", RSERV];
					};
				} forEach _cartels;

				if ([] call ULP_fnc_isGroup && { _gangTax > 0 }) then {
					[group player, _gangTax, true] remoteExecCall ["ULP_SRV_fnc_handleGroupFunds", RSERV];
					[format["Sprzedałeś %1 %2 za <t color='#B92DE0'>$%3</t>, a $%4 z tego poszło na konto grupy.!", _value, _name, [_sellPrice] call ULP_fnc_numberText, [_gangTax] call ULP_fnc_numberText]] call fini_fnc_noty;
				} else {
					[format["Sprzedałeś %1 %2 za <t color='#B92DE0'>$%3</t>!", _value, _name, [_sellPrice] call ULP_fnc_numberText]] call fini_fnc_noty;
				};

				[true] call ULP_fnc_saveGear;
			} else {
				[format["Nie masz %1 %2 do sprzedania!", _value, _name]] call fini_fnc_noty;
			};
		} else {
			if ([_buyPrice, false, format["Kupno %1 %2", _value, _name]] call ULP_fnc_removeMoney) then {
				if ([configName _cfg, _value, false] call ULP_fnc_handleItem) then {
					[format["Kupiłeś %1 %2 za $%3!", _value, _name, [_buyPrice] call ULP_fnc_numberText]] call fini_fnc_noty;
					[true] call ULP_fnc_saveGear;
				} else {
					[_buyPrice, false] call ULP_fnc_addMoney; // Give them the money back, they didn't get what they paid for...
					["Nie masz miejsca w plecaku!"] call fini_fnc_noty;
				};
			} else {
				[format["Nie masz <t color='#B92DE0'>$%1</t> na %2 %3!", [_buyPrice] call ULP_fnc_numberText, _value, _name]] call fini_fnc_noty;
			};
		};

		[_display] call ULP_fnc_updateVStore;
	}, false
] call ULP_fnc_selectNumber;