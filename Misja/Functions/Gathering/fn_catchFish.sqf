/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_catchFish";

_this params [
	["_fish", objNull, [objNull]]
];

if (isNull _fish || { alive _fish }) exitWith { false };

private _typeOf = typeOf _fish;

if !(_typeOf in getArray (missionConfigFile >> "CfgGathering" >> "Fishing" >> "fish")) exitWith { false };

// Check turtle zoning...
if (_typeOf isEqualTo "Turtle_F") then {
	private _zones = getArray (missionConfigFile >> "CfgGathering" >> "Fishing" >> "turtleZones");

	if ((_zones findIf { (player distance (getMarkerPos _x)) <= 250 }) < 0) then {
		["Aby złapać żółwia, musisz znajdować się w strefie kłusownictwa.!"] call fini_fnc_noty;
		false breakOut "fn_catchFish";
	};
};

private _name = (_typeOf splitString "_") param [0, "Fish"];

if ([format["%1_Raw", _typeOf], 1] call ULP_fnc_handleItem) exitWith {
    deleteVehicle _fish;
	[format ["Zdobyłeś <t color='#B92DE0'>%1</t>.", _name]] call fini_fnc_noty;

	["Fishing", 1, 40] call ULP_fnc_increaseProfession;

	true
};

[format ["Nie masz wystarczająco dużo miejsca w ekwipunku, aby pomieścić <t color='#B92DE0'>%1</t>.", _name]] call fini_fnc_noty;