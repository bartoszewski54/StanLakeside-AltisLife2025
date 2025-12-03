/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setLegislation";

_this params [
	["_ctrl", controlNull, [controlNull]]
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if !([] call ULP_fnc_isGovernor) exitWith {
	["Tylko gubernator ma dostęp do tego systemu..."] call fini_fnc_noty;
};

// Stop spam...
if (time < (player getVariable ["governor_cooldown", 0])) exitWith {
	["Niedawno zmieniono niektóre przepisy, poczekaj przed ponowną próbą."] call fini_fnc_noty;
};
player setVariable ["governor_cooldown", time + 5];

private _list = _display displayCtrl 4801;
private _legislation = missionConfigFile >> "CfgGovernment" >> "Legislation" >> (_list lbData (lbCurSel _list));
if !(isClass _legislation) exitWith {
	["Te przepisy nie mogą obecnie zostać zmienione... spróbuj ponownie później..."] call fini_fnc_noty;
};

private _values = getArray (_legislation >> "values");

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), getArray (_legislation >> "values") param [0, [0, 1]], [_legislation],
	{
		_this params [
			["_legislation", configNull, [configNull]],
			["_display", displayNull, [displayNull]],
			["_value", 1, [0]]
		];

		[configName _legislation, _value] remoteExecCall ["ULP_SRV_fnc_saveLegislation", RSERV];

		[format ["Zmieniłeś <t color='#B92DE0'>%1</t> na <t color='#B92DE0'>%2</t>", getText (_legislation >> "displayName"), _value call compile getText (_legislation >> "format")]] call fini_fnc_noty;
	}, false, getText (_legislation >> "format"), false
] call ULP_fnc_selectNumber;