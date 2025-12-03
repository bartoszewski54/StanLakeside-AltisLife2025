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

if !([4] call ULP_fnc_canGroupRank) exitWith {
	["Nie masz uprawnień do wykonania tej akcji!"] call fini_fnc_noty;
};

private _memberList = _display displayCtrl 23062;

private _selected = lnbCurSelRow _memberList;
private _selectedMember = _memberList lnbData [_selected, 1];

if !([_selectedMember, group player] call ULP_fnc_isGroupMember) exitWith {
	["Musisz wybrać członka swojej grupy do wyrzucenia!"] call fini_fnc_noty;
};

// Rank Checks...
if ((_memberList lnbValue [_selected, 1]) >= ([] call ULP_fnc_getGroupRank)) exitWith { ["Nie możesz wyrzucić kogoś równego lub wyższego rangą.!"] call fini_fnc_noty; };

private _name = _memberList lnbData [_selected, 0];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Potwierdzenie", ["Akceptuj", "Anuluj"],
	format ["Czy na pewno chcesz wyrzucić %1?", _name], [_display, _selectedMember, _name],
	{
		_this params [ "_display", "_member", "_name" ];

		private _unit = [_member] call ULP_fnc_playerByUID;

		if !(isNull _unit) then { _member = _unit; };

		if ([group player, _member] call ULP_fnc_removeMember) then {
			if !(_member isEqualType "") then {
				["GroupKicked", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			};

			_display call ULP_fnc_overview;
			[format ["Wyrzuciłeś <t color='#B92DE0'>%1</t> z grupy", _name]] call fini_fnc_noty;
		} else {
			[format ["Błąd podczas wyrzucania <t color='#B92DE0'>%1</t>, spróbuj jeszcze raz...", _name]] call fini_fnc_noty;
		};
	}, {}, true
] call ULP_fnc_confirm;