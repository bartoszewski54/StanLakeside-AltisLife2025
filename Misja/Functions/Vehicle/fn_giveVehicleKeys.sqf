/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_giveVehicleKeys";

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit || { !(isPlayer _unit) } || { (player distance _unit) > 5 }) exitWith {};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (ULP_Keys apply { 
	([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "_missionCfg", "", "_name" ]; 
	[_picture, _name, _x call BIS_fnc_netId, 0];
}), ["Daj", "Anuluj"], [_unit], {
	_this params [
		["_unit", objNull, [objNull]],
		["_display", displayNull, [displayNull]]
	];

	if ((player distance _unit) > 5) exitWith {
		["Nie jesteś wystarczająco blisko, by dać tej osobie klucze!"] call fini_fnc_noty;
	};

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _vehicle) exitWith { ["Nie wybrałeś pojazdu do dania kluczy do niego!"] call fini_fnc_noty; };

	private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
	if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith {};

	_cfg params [
		"", "_missionCfg", "", "_name"
	];

	if !(isClass _missionCfg) exitWith {};

	["KeysGiven", [_vehicle, player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	[format ["Dałeś <t color='#B92DE0'>%2</t> kluczę do <t color='#B92DE0'>%1</t>.", name _unit, _name]] call fini_fnc_noty;
}, false] call ULP_fnc_selectObject;