/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_rewardPersonalGoal";

if (canSuspend) exitWith {
    [ULP_fnc_rewardPersonalGoal, _this] call ULP_fnc_directCall;
};

_this params [
	["_cfg", configNull, [configNull]],
	["_tier", 0, [0]]
];

private _title = getText (_cfg >> "title");

["GoalReward", [format ["Osiągnąłeś tier %1 w, '%2'", _tier, getText (_cfg >> "title")]]] call BIS_fnc_showNotification;
playSound "FD_Finish_F";

[(_tier - 1), format["osiągniesz tier %1 za %2...", _tier, _title]] call ULP_fnc_grantReward;

[getPlayerUID player, "Goal", [_title, _tier]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];