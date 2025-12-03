/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_removeItem";

_this params [
	"_ctrl"
];

disableSerialization;

private _display = ctrlParent _ctrl;
private _list = _display displayCtrl 23016;
if (isNull _display || { isNull _list }) exitWith {};

private _list = _display displayCtrl 23016;
private _curSel = missionConfigFile >> "CfgVirtualItems" >> (_list lbData (lbCurSel _list));
if !(isClass _curSel) exitWith { ["Najpierw musisz wybrać przedmiot!"] call fini_fnc_noty; };

private _amount = [configName _curSel] call ULP_fnc_hasItem;
if (_amount isEqualTo -1) exitWith {
	["Nie musisz usuwać żadnego z tych elementów!"] call fini_fnc_noty;
};

if ([getNumber (_curSel >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
	private _itemData = (([configName _curSel] call ULP_fnc_hasItem) select (_list lbValue (lbCurSel _list)));
	private _name = format [getText(_curSel >> "displayName"), _itemData];

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
		format ["Czy na pewno chcesz usunąć %1...", _name], [_curSel, _itemData, _name],
		{	
			_this params [ "_cfg", "_data", "_name" ];

			_display = findDisplay 23000; // We don't need select so we switch this to tablet...
			if (isNull _display || { isNull _cfg }) exitWith {};

			if ([configName _cfg, _data, true] call ULP_fnc_handleItem) then {
				[format["Usunięto %1 z ekwipunku!", _name]] call fini_fnc_noty;
				_display call ULP_fnc_inventory;
			} else {
				["Nie masz tego elementu do usunięcia!"] call fini_fnc_noty;
			};
		}, {}, false
	] call ULP_fnc_confirm;
} else {
	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_curSel],
		{
			_this params [
				["_cfg", configNull, [configNull]],
				["_display", displayNull, [displayNull]],
				["_value", 1, [0]]
			];

			_display = findDisplay 23000; // We don't need select so we switch this to tablet...
			if (isNull _display || { isNull _cfg }) exitWith {};

			if ([configName _cfg, _value, true] call ULP_fnc_handleItem) then {
				[format["Usunięto <t color='#B92DE0'>%1 %2(s)</t> z ekwipunku.", _value, getText(_cfg >> "displayName")]] call fini_fnc_noty;
				_display call ULP_fnc_inventory;
			} else {
				["Nie ma aż tylu sztuk tego przedmiotu!"] call fini_fnc_noty;
			};
		}
	] call ULP_fnc_selectNumber;
};