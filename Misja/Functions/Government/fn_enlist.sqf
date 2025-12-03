/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_enlist";

if (missionNamespace getVariable ["ULP_SRV_Setting_Election", false]) exitWith {
	["Nie możesz zapisać się na wybory, gdy one trwają..."] call fini_fnc_noty;
};

if (!([player, ["Civilian"]] call ULP_fnc_isFaction) || { [] call ULP_fnc_isUndercover }) exitWith {
	["Musisz być cywilem, aby zapisać się na następne wybory..."] call fini_fnc_noty;
};

if !([] call ULP_fnc_isGroup || { ["Governor"] call ULP_fnc_hasGroupPerk }) exitWith {
	["Twoja grupa nie ma możliwości kandydowania na gubernatora..."] call fini_fnc_noty;
};

if ([] call ULP_fnc_isGovernor) exitWith {
	["Jako gubernator nie możesz startować w następnych wyborach..."] call fini_fnc_noty;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Potwierdzenie", ["Akceptuj", "Anuluj"],
	format ["Czy na pewno chcesz działać jako %1 dla Governor...", profileName], [],
	{	
		if (player getVariable ["enlisting", false]) exitWith {
			["Twoja rekrutacja jest w trakcie przetwarzania!"] call fini_fnc_noty;
		};

		player setVariable ["enlisting", true];

		["Enlistment", {
			[_this param [0, "Udało ci się wziąć udział w następnych wyborach..."]] call fini_fnc_noty;
			player setVariable ["enlisting", nil];
		}, true] call ULP_fnc_addEventHandler;

		["Wysłano żądanie o zapis na liście..."] call fini_fnc_noty;
		[player] remoteExecCall ["ULP_SRV_fnc_enlistCandidate", RSERV];
	}, {}, false
] call ULP_fnc_confirm;