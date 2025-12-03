/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_receivedBlood";

_this params [
	["_medic", objNull, [objNull]],
	["_increase", getNumber (missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "BloodBagIncrease"), [0]]
];

if !(alive player || { isDowned(player) }) exitWith {};

private _incapUi = ["RscIncapacitated"] call ULP_UI_fnc_getLayer;
if (isNull _incapUi) exitWith {};

[[format ["<t color='#B92DE0'>%1</t> podał ci krew, więc twoje krwawienie zostało przedłużone...", name _medic], "Otrzymałeś więcej krwi, więc czas krwawienia został wydłużony..."] select (isNull _medic)] call fini_fnc_noty;

_incapUi setVariable ["endTime", (_incapUi getVariable ["endTime", time + 10]) + _increase];