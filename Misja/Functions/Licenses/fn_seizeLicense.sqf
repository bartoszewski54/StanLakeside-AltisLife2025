/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_seizeLicense";

if (canSuspend) exitWith {
    [ULP_fnc_seizeLicense, _this] call ULP_fnc_directCall;
};

if !([player, ["Police"]] call ULP_fnc_isFaction) exitWith {
	["Tylko policja może zabierać licencje..."] call fini_fnc_noty;
};

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _unit = _display getVariable ["unit", objNull];
if (isNull _unit) exitWith { closeDialog 0; };

private _list = _display displayCtrl 5102;
private _curSel = lbCurSel _list;

private _license = _list lbData _curSel;

private _cfg = missionConfigFile >> "CfgLicenses" >> _license;

if ([getNumber (_cfg >> "Settings" >> "isRemovable")] call ULP_fnc_bool) then {
	["LicenseSeized", [player, _license]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	[format ["Zabrałeś %1 Licencje: %2", [_unit, true] call ULP_fnc_getName, getText (_cfg >> "displayName")]] call fini_fnc_noty;

	[player, "SeizeLicense"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];

	["TakeLicense"] call ULP_fnc_achieve;
	_list lbDelete _curSel;
} else {
	["Tej licencji nie da się zabrać..."] call fini_fnc_noty;
};