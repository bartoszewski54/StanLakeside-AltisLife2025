/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_togglePerk";

_this params [
	["_perk", "", [""]]
];

private _cfg = missionConfigFile >> "CfgPerks" >> _perk;

if ([_perk] call ULP_fnc_hasPerk) then {
	private _name = getText (_cfg >> "displayName");
	private _cost = getNumber (missionConfigFile >> "CfgPerks" >> "removalCost");
	_cost = _cost * getNumber (_cfg >> "removalMultiplier");
	
	if (BANK < _cost) exitWith {
		[format ["Potrzebujesz %1%2 do dezaktywacji perku!", "$", [_cost] call ULP_fnc_numberText]] call fini_fnc_noty;
		false breakOut "fn_togglePerk";
	};

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
		format ["Jesteś pewien, że chcesz wydać %1%2 na usunięcie %3...", "$", [_cost] call ULP_fnc_numberText, _name], [_perk, _name, _cost, _cfg],
		{	
			_this params [ "_perk", "_name", "_cost", "_cfg" ];

			if ([_cost, true, format ["Wyłączenie %1", _name]] call ULP_fnc_removeMoney) then {
				ULP_Perks deleteAt _perk;
				[format ["<t color='#B92DE0'>%1</t> został wyłączony za <t color='#B92DE0'>%2%3</t>.", _name, "$", [_cost] call ULP_fnc_numberText]] call fini_fnc_noty;
				
				false call compile getText (_cfg >> "onChanged");
				["PerksChanged", [_perk, ULP_Perks]] call ULP_fnc_invokeEvent;
			};
		}, {}, true
	] call ULP_fnc_confirm;
} else {
	if !(isClass _cfg) exitWith {
		["Ten perk już nie istnieje i został automatycznie usunięty."] call fini_fnc_noty;
		false breakOut "fn_togglePerk";
	};

//	private _limit = [] call ULP_fnc_getPerkLimit;
//	if ((count ULP_Perks) >= _limit) exitWith {
//		[format ["Nie można aktywować więcej niż <t color='#B92DE0'>%1</t> perk jednocześnie!", _limit]] call fini_fnc_noty;
//		false breakOut "fn_togglePerk";
//	};

	ULP_Perks set [_perk, [1, 0]];
	[format ["<t color='#B92DE0'>%1</t> został pomyślnie aktywowany!", getText (_cfg >> "displayName")]] call fini_fnc_noty;

	true call compile getText (_cfg >> "onChanged");
	["PerksChanged", [_perk, ULP_Perks]] call ULP_fnc_invokeEvent;
};

true