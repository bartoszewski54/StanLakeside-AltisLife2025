/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_useItem";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
private _list = _display displayCtrl 23016;
if (isNull _display || { isNull _list }) exitWith {};

private _list = _display displayCtrl 23016;
private _curSel = missionConfigFile >> "CfgVirtualItems" >> (_list lbData (lbCurSel _list));
if !(isClass _curSel) exitWith { ["Najpierw musisz wybrać przedmiot!"] call fini_fnc_noty; };

private _amount = [configName _curSel] call ULP_fnc_hasItem;
if (_amount isEqualTo -1) exitWith {
	["Nie masz żadnego z tych przedmiotów do użycia!"] call fini_fnc_noty;
};

if !(isText (_curSel >> "Events" >> "onUse")) exitWith { ["Ten przedmiot nie może być używany do niczego!"] call fini_fnc_noty; };

private _item = 1;
if !(_amount isEqualType 0) then {
	_item = (_amount select (_list lbValue (lbCurSel _list)));
};

[configName _curSel, _item] call compile getText (_curSel >> "Events" >> "onUse");
_display call ULP_fnc_inventory;