/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_serviceVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_serviceVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	["_location", objNull, [objNull]]
];

if (isNull _location) exitWith {};

private _near = _location nearEntities [["Air"], 15];
private _vehicle = _near param [(_near findIf { [player, _x] call ULP_fnc_isVehicleOwner }), objNull];

if (isNil "_vehicle" || { isNull _vehicle } || { !(alive _vehicle) }) exitWith {
	["Brak helki/samolotu w pobliżu stanowiska do obsługi!"] call fini_fnc_noty;
};

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (_cfg isEqualTo []) exitWith {};

_cfg params [
	"", "_missionCfg", "", "_name", "", "", "", "", "_fuel"
];

private _time = 15;
if (isNumber (_missionCfg >> "serviceTime")) then {
	_time = _time + getNumber (_missionCfg >> "serviceTime");
};

private _cost = ["PartsCarrier", round ((["Service", 1000] call ULP_fnc_getLegislation) * (_fuel / 10))] call ULP_fnc_activatePerk;
if (isNumber (_missionCfg >> "serviceCost")) then {
	_cost = _cost + getNumber (_missionCfg >> "serviceCost");
};

if (CASH < _cost) exitWith {
	[format ["Nie masz<t color='#B92DE0'>%1%2</t> na serwis tego pojazdu!", "$", [_cost] call ULP_fnc_numberText]] call fini_fnc_noty;
};

if !([format["Serwisowanie %1", _name], _time, [_location, _vehicle, _name, _cost], {
	!(isNull (_this select 0)) && { alive (_this select 1) } && { ((_this select 0) distance (_this select 1)) <= 15 }
}, {
	_this params [ "_location", "_vehicle", "_name", "_cost" ];

	if (isNull _vehicle || { !(alive _vehicle) } || { (_location distance _vehicle) > 15 }) exitWith {
		[format ["Nie udało ci się serwisować %1, ponieważ jest on albo nienaprawialny, albo nie znajduje się w pobliżu stanowiska!", _name]] call fini_fnc_noty;
	};

	if ([_cost, false, format ["Serwis %1", _name]] call ULP_fnc_removeMoney) exitWith {
		[format ["Nie masz %1%2 by zapłacić serwisowanie tego pojazdu!", "$", [_cost] call ULP_fnc_numberText]] call fini_fnc_noty;
	};

	[_vehicle, 1] remoteExecCall ["ULP_fnc_setFuel", _vehicle];
	_vehicle setDamage 0;

	[format ["Pomyślnie przeprowadziłeś serwis na <t color='#B92DE0'>%1</t>.", _name]] call fini_fnc_noty;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	["Nie można serwisować pojazdu podczas wykonywania innej czynności!"] call fini_fnc_noty;
};