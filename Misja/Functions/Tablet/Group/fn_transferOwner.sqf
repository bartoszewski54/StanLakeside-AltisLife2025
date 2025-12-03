/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_transferOwner";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _group = group player;

if !([] call ULP_fnc_isGroupOwner) exitWith {
	["Tylko właściciel może przenieść własność grupy!"] call fini_fnc_noty;
	false
};

if !((ULP_Houses findIf { [_x, player, false] call ULP_fnc_isHouseOwner && { !(call compile getText (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _x) >> "condition")) } }) isEqualTo -1) exitWith {
	["Przed przeniesieniem własności musisz sprzedać wszystkie domy dodane do grupy!"] call fini_fnc_noty;
	false
};

private _memberList = _display displayCtrl 23062;

private _selected = lnbCurSelRow _memberList;
private _selectedMember = _memberList lnbData [_selected, 1];

if !([_selectedMember, group player] call ULP_fnc_isGroupMember) exitWith {
	["Musisz wybrać członka swojej grupy, na którego chcesz przenieść własność!"] call fini_fnc_noty;
};

if (_selectedMember isEqualTo (_group getVariable ["group_owner", ""])) exitWith {
	["Nie możesz przenieść prawa własności na siebie"] call fini_fnc_noty;
	false
};

private _name = _memberList lnbData [_selected, 0];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Potwierdzenie", ["Potwierdź", "Anuluj"],
	format ["Czy na pewno chcesz przenieść własność na %1?", _name], [_display, _selectedMember, _name],
	{
		_this params [ "_display", "_member", "_name" ];

		private _unit = [_member] call ULP_fnc_playerByUID;

		if !(isNull _unit) then { _member = _unit; };

		if ([group player, _member] call ULP_fnc_setGroupOwner) then {
			if !(_member isEqualType "") then {
				["GroupOwner", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			};

			_display call ULP_fnc_overview;
			[format ["Od teraz <t color='#B92DE0'>%1</t> jest właścicielem grupy...", _name]] call fini_fnc_noty;
		} else {
			[format ["Twoja próba przeniesienia grupy na <t color='#B92DE0'>%1</t>, nie powiodła się...", _name]] call fini_fnc_noty;
		};
	}, {}, true
] call ULP_fnc_confirm;