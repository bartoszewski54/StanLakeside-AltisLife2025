/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_takeFromCargo";

if (canSuspend) exitWith {
    [ULP_fnc_takeFromCargo, _this] call ULP_fnc_directCall;
};

_this params [
	["_ctrl", controlNull, [controlNull]]
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _container = _display getVariable ["container", objNull];
if (isNull _container || { !([_container] call ULP_fnc_isCargoUser) }) exitWith {
	_ctrl ctrlEnable false;
	["Nie jesteś użytkownikiem tego inventory!"] call fini_fnc_noty;
};

private _containerList = _display displayCtrl 4208;

private _selected = lnbCurSelRow _containerList;
private _item = _containerList lnbData [_selected, 0];
if (_item isEqualTo "") exitWith {
	["Musisz coś wybrać!"] call fini_fnc_noty;
};

private _vItem = missionConfigFile >> "CfgVirtualItems" >> _item;

// System items are added / removed via script from vehicles
if ([getNumber (_vItem >> "Settings" >> "isSystemItem")] call ULP_fnc_bool) exitWith {
	["Ten przedmiot nie może być tutaj chowany"] call fini_fnc_noty;
};

private _cargo = _container getVariable ["ULP_VirtualCargo", createHashMap];

private _data = _cargo getOrDefault [_item, 0];

private _count = _data;

if (_count isEqualType []) then {
	_count = 1;

	private _index = _data find (_containerList lnbData [_selected, 1]);

	if (_index < 0) then {
		_count = 0;
	} else {
		_data = _data select _index;
	};
} else {
	_data = -1;
};

if (_count <= 0) exitWith {
	["Tego przedmiotu już tutaj nie ma!"] call fini_fnc_noty;
};

// Special handling
if (_item isEqualTo "DroppedMoney") exitWith {
	private _money = parseNumber _data;

	if ([_container, _item, _data] call ULP_fnc_removeFromCargo) then {
		[_money, false, "Pickup"] call ULP_fnc_addMoney;
		[format ["Zabrałeś <t color='#B92DE0'>%1%2</t> z tego inventory!", "$", [_money] call ULP_fnc_numberText]] call fini_fnc_noty;

		[_display, 1] call ULP_fnc_updateInventory;
	};
};

private _itemWeight = getNumber(_vItem >> "weight");
private _maxCarry = _count;

if (_itemWeight > 0) then {
	_maxCarry = [_itemWeight] call ULP_fnc_getMaxQuantity;
};

if (_maxCarry <= 0) exitWith {
	["Brakuje ci miejsca!"] call fini_fnc_noty;
};

private _maxValue = _count min _maxCarry;

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _maxValue], [_display, _container, _item, _data],
	{
		_this params [
			["_display", displayNull, [displayNull]],
			["_container", objNull, [objNull]],
			["_item", "", [""]],
			["_data", 1, [0, "", []]],
			"",
			["_value", 1, [0]]
		];

		if (isNull _display || { _item isEqualTo "" }) exitWith {};

		private _name = getText (missionConfigFile >> "CfgVirtualItems" >> _item >> "displayName");
		if ([getNumber (missionConfigFile >> "CfgVirtualItems" >> _item >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
			_value = _data;
			_name = format [_name, _value];
		};

		if ([_item, _value] call ULP_fnc_handleItem) then {
			if ([_container, _item, _value] call ULP_fnc_removeFromCargo) then {
				[format["Zabrałeś <t color='#B92DE0'>%1 %2</t> z tego inventory!", _value, _name]] call fini_fnc_noty;
				[_display, 0] call ULP_fnc_updateInventory;
				[_display, 1] call ULP_fnc_updateInventory;
			} else {
				[_item, _value, true] call ULP_fnc_handleItem;
				[format["To inventory nie ma <t color='#B92DE0'>%1 %2</t>!", _value, _name]] call fini_fnc_noty;
			};
		} else {
			[format["Nie masz tyle miejsca aby zabrać <t color='#B92DE0'>%1 %2</t>!", _value, _name]] call fini_fnc_noty;
		};
	}, false
] call ULP_fnc_selectNumber;