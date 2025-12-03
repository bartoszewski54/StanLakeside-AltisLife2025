/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_saveCart";

private _display = _this param [0, displayNull, [displayNull]];
private _name = _this param [1, _display getVariable ["saved_cart", ""], [""]];

if (isNull _display || { _name isEqualTo "" }  || { isNil "_name" }) exitWith { systemChat "Wystąpił błąd podczas zapisywania koszyka"; };

private _storeCfgName = format["%1%2", configName (_display getVariable "storeCfg"), configName (_display getVariable "curStore")];
private _allSavedCarts = + (missionProfileNamespace getVariable ["ULP_SavedCarts", createHashMap]);
private _savedCarts = _allSavedCarts getOrDefault [_storeCfgName, createHashMap];

private _maxCarts = getNumber (missionConfigFile >> "CfgStores" >> "maxCarts");
if ([] call ULP_fnc_donatorLevel > 0) then {
	_maxCarts = _maxCarts + getNumber (missionConfigFile >> "CfgStores" >> "extraDonatorCarts");
};

if ((count _savedCarts) >= _maxCarts) exitWith {
	[format["Maksymalna wartość %1 została już zapisana!", _maxCarts]] call fini_fnc_noty;
};

private _cartList = _display displayCtrl 3107;
private _cartSize = lbSize _cartList;
if (_cartSize isEqualTo 0) exitWith {
	["Musisz dodać coś do koszyka, zanim będziesz mógł to zapisać!"] call fini_fnc_noty;
};

private _savedCart = [];

for "_i" from 0 to (_cartSize - 1) do {
	_savedCart pushBack (parseSimpleArray (_cartList lbData _i));
};

if (_savedCart isEqualTo []) exitWith {}; // Failsafe

_savedCarts set [_name, _savedCart];
_allSavedCarts set [_storeCfgName, _savedCarts];

missionProfileNamespace setVariable ["ULP_SavedCarts", _allSavedCarts];
saveMissionProfileNamespace;

_display setVariable ["saved_cart", _name];
(_display displayCtrl 3117) ctrlEnable true;
(_display displayCtrl 3118) ctrlEnable true;

[format ["Koszyk '%1' został zapisany", _name]] call fini_fnc_noty;