/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_putInCargo";

if (canSuspend) exitWith {
    [ULP_fnc_putInCargo, _this] call ULP_fnc_directCall;
};

_this params [
	["_ctrl", controlNull, [controlNull]]
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _container = _display getVariable ["container", objNull];
if (isNull _container || { !([_container] call ULP_fnc_isCargoUser) }) exitWith {
	_ctrl ctrlEnable false;
	["Musisz być w menu ładunku, aby zabierać lub umieszczać przedmioty w tym ekwipunku!"] call fini_fnc_noty;
};

private _containerList = _display displayCtrl 4204;

private _item = _containerList lnbData [(lnbCurSelRow _containerList), 0];
if (_item isEqualTo "") exitWith {
	["Musisz wybrać coś, co włożysz do tego ekwipunku!"] call fini_fnc_noty;
};

if (_item in getArray (missionConfigFile >> "CfgVehicles" >> (typeOf _container) >> "blacklistedItems")) exitWith {
	["Ten przedmiot nie może być przechowywany w bagażniku..."] call fini_fnc_noty;
};

private _vItem = missionConfigFile >> "CfgVirtualItems" >> _item;

// System items are added / removed via script from vehicles
if ([getNumber (_vItem >> "Settings" >> "isSystemItem")] call ULP_fnc_bool) exitWith {
	["Tego elementu nie można ręcznie przenieść do tego kontenera"] call fini_fnc_noty;
};

private _data = ULP_Inventory getOrDefault [_item, 0];

private _count = _data;

if (_count isEqualType []) then {
	_count = 1;

	private _index = _data find (_containerList lnbData [(lnbCurSelRow _containerList), 1]);

	if (_index < 0) then {
		_count = 0;
	} else {
		_data = _data select _index;
	};
} else {
	_data = -1;
};

if (_count <= 0) exitWith {
	["Nie masz żadnego przedmiotu, który mógłbyś umieścić w tym pojemniku!"] call fini_fnc_noty;
};

private _itemWeight = getNumber(_vItem >> "weight");
private _maxCarry = _count;

if (_itemWeight > 0) then {
	_maxCarry = floor ((([_container] call ULP_fnc_maxLoad) - ([_container] call ULP_fnc_currentLoad)) / _itemWeight);
};

if (_maxCarry <= 0) exitWith {
	["W tym pojeździe nie ma wystarczająco dużo miejsca, aby zmieścić nawet jeden z tych przedmiotów!"] call fini_fnc_noty;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, (_count min _maxCarry)], [_display, _container, _item, _data],
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

		if ([_container, _item, _value] call ULP_fnc_addToCargo) then {
			if ([_item, _value, true] call ULP_fnc_handleItem) then {
				[format["You have put <t color='#B92DE0'>%1 %2(s)</t> into this container.", _value, _name]] call fini_fnc_noty;
				[_display, 0] call ULP_fnc_updateInventory;
				[_display, 1] call ULP_fnc_updateInventory;
			} else {
				[_container, _item, _value] call ULP_fnc_removeFromCargo;
				[format["Nie masz %1 %2 do umieszczenia w tym pojemniku!", _value, _name]] call fini_fnc_noty;
			};
		} else {
			[format["Ten pojemnik nie ma wystarczająco dużo miejsca, aby pomieścić <t color='#B92DE0'>%1 %2</t>!", _value, _name]] call fini_fnc_noty;
		};
	}, false
] call ULP_fnc_selectNumber;