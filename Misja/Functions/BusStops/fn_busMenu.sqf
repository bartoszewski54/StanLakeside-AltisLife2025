#include "..\..\script_macros.hpp"
/*

	Author: ToxicRageTv
	File: fn_busMenu.sqf
	Description: Sets up the bus menu

*/
if (!alive player || dialog) exitWith {};
createDialog "Toxic_Bus_Menu";
disableSerialization;

private _display = uiNamespace getVariable "Toxic_Bus_Menu";

ctrlShow [1919,false];

private _busList = _display displayCtrl 1500;

private _side = switch (playerSide) do {
    case west: {"Cop"};
    case independent: {"Medic"};
    default {"Civilian"};
};

private _busStops = getArray(missionConfigFile >> "CfgSettings" >> "Toxic_Bus_Config" >> _side >> "stops");

{
	_busList = lbAdd [ 1500, ( _x select 0 ) ]; 
	lbSetData [ 1500, _busList, ( _x select 1 ) ];  
} forEach _busStops;