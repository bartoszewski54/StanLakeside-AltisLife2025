/*
	author: bartoszewski
	description: none
	returns: nothing
*/

params ["_veh"];
_veh = vehicle _veh;

[_veh, "klakson", 100, 1] remoteExecCall ["ULP_fnc_say3D"];