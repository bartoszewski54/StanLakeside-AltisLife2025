/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_toggleOnStretcher";
_this params [
	["_unit", player, [objNull]]
];
private _stretcher = [_unit] call ULP_fnc_nearestStretcher;
if (isNull _unit || { isNull _stretcher } || { !([_stretcher] call ULP_fnc_isPlaceable) } || { !(isDowned(_unit)) }) exitWith { false };
private _attachedUnit = _stretcher getVariable ["unitAttached", objNull];
private _isAttaching = !(_attachedUnit isEqualTo _unit);
if (_isAttaching) exitWith {
	if !(isNull _attachedUnit) exitWith { ["Brak noszy w pobliżu"] call fini_fnc_noty; false };
	_stretcher setVariable ["unitAttached", _unit, true];
	_unit attachTo [_stretcher, [0, 0.1, 0.2]];
	[format ["Położyłeś <t color='#B92DE0'>%1</t> na noszach", [_unit, true] call ULP_fnc_getName]] call fini_fnc_noty;
	true
};
_stretcher setVariable["unitAttached", nil, true];
detach _unit;
true