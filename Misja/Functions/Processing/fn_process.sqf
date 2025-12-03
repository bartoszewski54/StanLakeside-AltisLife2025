/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_process";

_this params [
	["_process", "", [""]]
];

private _cfg = missionConfigFile >> "CfgProcessing" >> _process;
if !(isClass _cfg || { !([player] call ULP_fnc_getFaction in getArray (_cfg >> "factions")) }) exitWith { false };

private _reqItems = getArray (_cfg >> "reqItems") select { ([_x] call ULP_fnc_hasItem isEqualTo -1) };

if ((count _reqItems) > 0) exitWith {
	[format["Te przedmioty są potrzebne do przetwarzania tutaj: <t color='#B92DE0'>%1</t>!", _reqItems]] call fini_fnc_noty;
	false
};

private _reqLicenses = getArray (_cfg >> "reqLicenses") select { !([_x] call ULP_fnc_hasLicense) };

if ((count _reqLicenses) > 0) exitWith {
	[format["Te licencje są potrzebne do przetwarzania tutaj: <t color='#B92DE0'>%1</t>!", _reqLicenses]] call fini_fnc_noty;
	false
};

private _items = getArray (_cfg >> "items");
private _materials = getArray (_cfg >> "materials");
if (_items isEqualTo [] || { _materials isEqualTo [] }) exitWith { false };

{
    if ([_x select 0] call ULP_fnc_hasItem < _x select 1) exitWith {
		[format["Nie masz wymaganych materiałów do przetworzenia: <t color='#B92DE0'>%1</t>!", _materials]] call fini_fnc_noty;
		false breakOut "fn_process";
    };
} forEach _materials;

private _profession = getArray (_cfg >> "profession");
private _leveling = getArray (_cfg >> "leveling");

private _time = getNumber(_cfg >> "processTime");

if !(_profession isEqualTo []) then {
	private _profCal = [(_profession select 0)] call ULP_fnc_getProfessionCalculation;
	if (_profCal > 0) then { _time = _time - (_time * (_profCal / 100)); };
};

[format["%1 Item(s)", getText(_cfg >> "processTitle")], _time, [getPos player, _items, _materials, _cfg, _profession, _leveling], { (player distance (_this select 0)) <= 5 }, {
	_this params [ "", "_items", "_materials", "_cfg", "_profession", "_leveling" ];

	private _possibleConversions = [];

	{
        _possibleConversions pushBack (floor (([_x select 0] call ULP_fnc_hasItem) / (_x select 1)));
    } forEach _materials;

    private _conversion = selectMin _possibleConversions;
	if (_conversion <= 0) exitWith {};

	{
		_x params ["_item", "_amount"];
		private _total = _amount * _conversion;

		[_item, _total, true] call ULP_fnc_handleItem;
		["ProcessedVirtualItem", [_item, _total]] call ULP_fnc_invokeEvent;
	} forEach _materials;

	{
		[(_x select 0), (_x select 1) * _conversion] call ULP_fnc_handleItem;
	} forEach _items;

	["Itemy zostały pomyślnie przetworzone!"] call fini_fnc_noty;

	if (time >= (player getVariable ["ProcessCooldown", time - 30])) then {
		if !(_profession isEqualTo []) then { _profession call ULP_fnc_increaseProfession; };
		if !(_leveling isEqualTo []) then { _leveling call ULP_fnc_addXP; };
		player setVariable ["ProcessCooldown", time + 30];
	};
}] call ULP_UI_fnc_startProgress;

true