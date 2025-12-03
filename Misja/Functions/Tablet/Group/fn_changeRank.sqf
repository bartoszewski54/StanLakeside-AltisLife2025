/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_changeRank";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if !([2] call ULP_fnc_canGroupRank) exitWith {
	["Nie masz uprawnień do wykonania tej akcji!"] call fini_fnc_noty;
};

private _memberList = _display displayCtrl 23062;
private _rankList = _display displayCtrl 23068;

private _selected = lnbCurSelRow _memberList;
private _selectedMember = _memberList lnbData [_selected, 1];
private _selectedRank = lbCurSel _rankList;

if !([_selectedMember, group player] call ULP_fnc_isGroupMember) exitWith {
	["Musisz wybrać członka swojej grupy, aby zmienić rangę!"] call fini_fnc_noty;
};

private _currentRank = _memberList lnbValue [_selected, 1];
private _myRank = [] call ULP_fnc_getGroupRank;

// Rank Checks...
if (_selectedRank isEqualTo _currentRank) exitWith { ["Ten członek ma już tę rangę!"] call fini_fnc_noty; };
if (_currentRank >= _myRank) exitWith { ["Nie możesz zmienić rangi osoby równej lub wyższej twojej randze!"] call fini_fnc_noty; };
if (_selectedRank >= _myRank) exitWith { ["Nie możesz nadać komuś rangi wyższej lub równej sobie!"] call fini_fnc_noty; };

private _name = _memberList lnbData [_selected, 0];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Potwierdzenie", ["Potwierdź", "Anuluj"],
	format ["Czy na pewno chcesz zmienić range <t color='#B92DE0'>%1</t>?", _name], [_display, _selectedMember, _selectedRank, _name],
	{
		_this params [ "_display", "_member", "_rank", "_name" ];

		private _unit = [_member] call ULP_fnc_playerByUID;

		if !(isNull _unit) then { _member = _unit; };

		if ([group player, _member, _rank] call ULP_fnc_setGroupRank) then {
			if !(_member isEqualType "") then {
				["GroupRankChanged", [_rank, player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			};

			_display call ULP_fnc_overview;
			[format ["Zmieniłe<t color='#B92DE0'>%1</t> range na <t color='#B92DE0'>%2</t>", _name, [_rank] call ULP_fnc_rankName]] call fini_fnc_noty;
		} else {
			[format ["Nie udało ci się zmienić rangi <t color='#B92DE0'>%1's</t>...", _name]] call fini_fnc_noty;
		};
	}, {}, true
] call ULP_fnc_confirm;