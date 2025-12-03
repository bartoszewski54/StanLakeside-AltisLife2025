/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyItems";

_this params [
	"_ctrl"
];

if !(canSuspend) exitWith { _this spawn ULP_fnc_buyItems; };

if ([player] call ULP_fnc_onDuty) exitWith {
	["Podczas służby nie możesz sprzedawać ani kupować przedmiotów..."] call fini_fnc_noty;
};

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _onItemBuy = getText((_display getVariable "storeCfg") >> "onItemBuy");
if (_onItemBuy isEqualTo "") exitWith {};

private _cartList = _display displayCtrl 3107;
if ((lbSize _cartList) isEqualTo 0) exitWith {
	["Musisz dodać coś do koszyka przed dokonaniem płatności!"] call fini_fnc_noty;
};

_ctrl ctrlEnable false;

private _override = cbChecked (_display displayCtrl 3114);
private _cartValue = _display getVariable "cartValue";

if (!([[player] call ULP_fnc_getFaction, "physical"] call ULP_fnc_factionFree) && { CASH < _cartValue }) then {
	["Nie stać cię na te przedmioty!"] call fini_fnc_noty;
} else {
	private _itemsBought = 0;
	private _itemsNotBought = createHashMap;

	for "_i" from 0 to ((lbSize _cartList) - 1) do {
		private _data = _cartList lbData _i;
		_data = parseSimpleArray _data;

		_data params [
			"_className", "_texClass"
		];

		([_className] call ULP_fnc_itemCfg) params [
			"_cfgName",
			"_itemCfg", "", "", "", "_name"
		];
		
		if ([_cartValue, _cartList, _className, _texClass, _cfgName, _itemCfg, _i, _override] call compile _onItemBuy) then {
			_itemsBought = _itemsBought + 1;
		} else {
			_itemsNotBought set [_name, (_itemsNotBought getOrDefault [_name, 0]) + 1];
			_cartValue = _cartValue - (_cartList lbValue _i);
		};
	};

	if !(_itemsBought isEqualTo 0) then {
		// Wipe Cart...
		lbClear _cartList;
		_cartList lbSetCurSel -1;

		(_display displayCtrl 3115) ctrlEnable false;
		(_display displayCtrl 3117) ctrlEnable false;
		(_display displayCtrl 3118) ctrlEnable false;

		// Pay for it and wipe total value...
		if !([[player] call ULP_fnc_getFaction, "physical"] call ULP_fnc_factionFree) then {
			[_cartValue, false, format ["Kupno przedmiotów"]] call ULP_fnc_removeMoney;
		};
		_display setVariable ["cartValue", 0];

		if ((count _itemsNotBought) isEqualTo 0) then {
			[format["Kupiłeś te przedmioty za <t color='#B92DE0'>$%1</t>.", [_cartValue] call ULP_fnc_numberText]] call fini_fnc_noty;
		} else {
			private _message = [format["Kupiłeś te przedmioty za%1 zł.<br/><br/> Nie miałeś miejsca na następujące przedmioty, dlatego nie zapłaciłeś za nie:<br/>", [_cartValue] call ULP_fnc_numberText]];
			
			{
				_message pushBack format [" - %1 (%2)", _x, [_y] call ULP_fnc_numberText];
			} forEach _itemsNotBought;

			[_message joinString "<br/>"] call fini_fnc_noty;
		};
	} else {
		["Nie masz wystarczająco dużo miejsca na te przedmioty!"] call fini_fnc_noty;
	};
};

[] call ULP_fnc_syncPlayerInfo;
_ctrl ctrlEnable true;