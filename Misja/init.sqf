/*
** Author: Jack "Scarso" Farhall
** Description: Shared initialization of the player and server.
*/
#include "script_macros.hpp"

[] execVM "IgiLoad\IgiLoadInit.sqf";
[] execVM "Functions\dlc_unlocker.sqf";
[] execVM "Functions\gazowaniezydow.sqf";
[] execVM "Functions\gazowaniezydowwersjastrong.sqf";
//[] execVM "AWGJ74gwa5.sqf";

if (IS_DEBUG_MODE) then { ULP_DebugMode = true; };