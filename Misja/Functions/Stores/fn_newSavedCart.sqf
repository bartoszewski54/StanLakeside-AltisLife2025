/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_newSavedCart";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Wprowadź nazwę koszyka", ["Zapisz", "Anuluj"], "...", [_display],
	{	
		_this params [
			["_display", displayNull, [displayNull]],
			["_name", "", [""]]
		];

		_name = [_name] call ULP_fnc_stripString;

		private _maxLengthCart = getNumber (missionConfigFile >> "CfgStores" >> "maxCartNameLength");

		if ((count _name) > _maxLengthCart) exitWith {
			[format["Maksymalna długość nazwy koszyka wynosi %1!", _maxLengthCart]] call fini_fnc_noty;
		};

		[_display, _name] call ULP_fnc_saveCart;
	}, false
] call ULP_fnc_enterString;