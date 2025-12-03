/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_leaveGroup";

if !([] call ULP_fnc_isGroup) exitWith { false };

private _group = group player;

if ([] call ULP_fnc_isGroupOwner) exitWith {
	["Musisz przenieść grupę na kogoś innego, zanim będziesz mógł opuścić grupę!"] call fini_fnc_noty;
	false
};

private _name = [_group] call ULP_fnc_getGroupName;

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Potwierdzenie", ["Opuść", "Anuluj"],
	format ["Czy na pewno chcesz odejść z %1?", _name], [_group, _name],
	{	
		_this params [ "_group", "_name" ];

		if ([group player, player] call ULP_fnc_removeMember) then {
			[format ["<t color='#B92DE0'>Opuściłeś %1</t>", _name]] call fini_fnc_noty;

			["Home"] call ULP_fnc_setScreen;
			[ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
		} else {
			[format ["Nie możesz opuścić <t color='#B92DE0'>%1</t>, spróbuj później...", _name]] call fini_fnc_noty;
		};
	}, {}, true
] call ULP_fnc_confirm;

true