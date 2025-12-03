/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_forgeIdentity";

if !([player, ["Civilian"]] call ULP_fnc_isFaction || { ["IDForger"] call ULP_fnc_hasPerk }) exitWith {
	["Tylko cywile mogą podrabiać dowody tożsamości!"] call fini_fnc_noty;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Zmiana tożsamości", ["Gotowe", "Anuluj"], "Wpisz nazwę tutaj...", [],
	{	
		_this params [
			["_name", "", [""]]
		];
		
		_name = [_name] call ULP_fnc_stripString;

		if ((count _name) > getNumber (missionConfigFile >> "CfgSettings" >> "Identity" >> "nameLength")) exitWith {
			["Nazwa jest za długa."] call fini_fnc_noty;
		};

		private _cost = getNumber (missionConfigFile >> "CfgVirtualItems" >> "Identification" >> "buyPrice");
		if ([] call ULP_fnc_isUndercover) then { _cost = 0 };

		if (CASH < _cost) exitWith {
			[format ["Potrzebujesz <t color='#B92DE0'>%1%2</t> aby podrobić dowód tożsamości!", "$", [_cost] call ULP_fnc_numberText]] call fini_fnc_noty;
		};

		if ([_cost, true, "Podrobienie dowodu"] call ULP_fnc_removeMoney) then {
			if (["Identification", _name] call ULP_fnc_handleItem) then {
				[format ["Otrzymałeś dowód o nazwie <t color='#B92DE0'>%1</t>.", _name]] call fini_fnc_noty;
				["Forger"] call ULP_fnc_achieve;
			} else {
				[format ["Nie udało się otrzymać dowodu z nazwą <t color='#B92DE0'>%1</t>.", _name]] call fini_fnc_noty;
			};
		} else {
			[format ["Nie masz <t color='#B92DE0'>%1%2</t> do podrobienia dowodu.", "$", [_cost] call ULP_fnc_numberText]] call fini_fnc_noty;
		};
	}, false
] call ULP_fnc_enterString;