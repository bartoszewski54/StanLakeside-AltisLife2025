/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_deconstruct";

_this params [
	["_item", "", [""]]
];

if !(isNull (objectParent player)) exitWith {
	["Nie możesz dekonstruować przedmiotów w pojeździe..."] call fini_fnc_noty;
	false;
};

private _cfg =  missionConfigFile >> "CfgVirtualItems" >> _item;
if !(isClass (_cfg >> "Deconstruction")) exitWith {
	["Ten przedmiot nie może zostać zdekonstruowany"] call fini_fnc_noty;
	false
};

if (["Toolbox"] call ULP_fnc_hasItem < 1) exitWith {
	["Potrzebujesz Tool Box do dekonstruowania przedmiotów..."] call fini_fnc_noty;
	false
};

if ([getNumber (_cfg >> "Deconstruction" >> "workbench")] call ULP_fnc_bool && { !([] call ULP_fnc_nearWorkbench) }) exitWith {
	["Aby dekonstruować przedmiot musisz być w zasięgu <t color='#B92DE0'>stołu warsztatowego</t>"] call fini_fnc_noty;
	false
};

private _name = getText (_cfg >> "displayName");

private _total = [_item] call ULP_fnc_hasItem;
if (_total < 1) exitWith {
	[format ["Nie masz żadnego <t color='#B92DE0'>%1</t> do dekonstrukcji.", _name]] call fini_fnc_noty;
	false
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _total], [_cfg, _name],
	{
		_this params [
			["_cfg", configNull, [configNull]],
			["_name", "", [""]],
			["_display", displayNull, [displayNull]],
			["_amount", 1, [0]]
		];

		if (_amount < 0 || { _amount > ([configName _cfg] call ULP_fnc_hasItem) }) exitWith {};
		closeDialog 0;

		[format["Dekonstruowanie %1(s)", _name], getNumber (_cfg >> "Deconstruction" >> "time") * _amount, [_cfg, _name, _amount], { true }, {
			_this params [ "_cfg", "_name", "_amount" ];

			if ([configName _cfg, _amount, true] call ULP_fnc_handleItem) then {
				{ [_x select 0, (_x select 1) * _amount, false, true] call ULP_fnc_handleItem; } forEach getArray (_cfg >> "Deconstruction" >> "materials");
				{ _x call ULP_fnc_unlockBlueprint; } forEach getArray (_cfg >> "Deconstruction" >> "blueprints");

				[format ["Rozłożono <t color='#B92DE0'>%2 %1(s)</t>...", _name, [_amount] call ULP_fnc_numberText]] call fini_fnc_noty;
                ["Deconstructing"] call ULP_fnc_achieve;
				[true] call ULP_fnc_saveGear;
			} else {
				[format ["Nie masz żadnych <t color='#B92DE0'>%2</t> x <t color='#B92DE0'>%1</t> do dekonstrukcji...", _name, [_amount] call ULP_fnc_numberText]] call fini_fnc_noty;
			};
		}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
	}, true
] call ULP_fnc_selectNumber;
true