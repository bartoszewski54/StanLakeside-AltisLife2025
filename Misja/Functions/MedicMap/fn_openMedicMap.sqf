/*
	author: bartoszewski
	description: none
	returns: nothing
*/

#include "..\..\script_macros.hpp"
scopeName "fn_openMedicMap";
if (canSuspend) exitWith {
    [ULP_fnc_openMedicMap, _this] call ULP_fnc_directCall;
};
createDialog "DialogMedicMap";