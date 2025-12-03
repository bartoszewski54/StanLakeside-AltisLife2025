/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_robObject";

_this params [
	["_object", objNull, [objNull]],
	["_store", "FuelStation", [""]],
	["_customName", "", [""]]
];

private _cfg = missionConfigFile >> "CfgRobberies" >> _store;
if (isNull _object || { !(isClass _cfg) } || { !([player, getArray (_cfg >> "factions")] call ULP_fnc_isFaction) }) exitWith {};

private _desk = nearestObject [_object, "Land_CashDesk_F"];
private _intersetObject2 = [_desk, _object] select (isNull _desk);

if (lineIntersects [eyePos player, eyePos _object, player, _intersetObject2]) exitWith { ["Musisz utrzymywać linię wzroku ze sklepem"] call fini_fnc_noty; };

private _personalTimeout = getNumber (missionConfigFile >> "CfgRobberies" >> "personalTimeout");
private _timeout = getNumber (_cfg >> "timeout");
private _objectTimeout = _object getVariable "timeout";

if (!isNil "ULP_Robbery_Timeout" && { time < ULP_Robbery_Timeout }) exitWith {
	[format["W ciągu ostatnich <t color='#B92DE0'>%1 minut</t> próbowałeś już obrabować sklep!", round (_personalTimeout / 60)]] call fini_fnc_noty;
};
if (!isNil "_objectTimeout" && { time < _objectTimeout }) exitWith { [format["Ten sklep został okradziony w ciągu ostatnich %1 minut!", round (_timeout / 60)]] call fini_fnc_noty; };

private _condition = getText (_cfg >> "condition");
private _onFail = getText (_cfg >> "onFail");
if !(call compile _condition) exitWith { call compile _onFail; };

if !(isNull (_object getVariable ["robber", objNull])) exitWith { ["Ten sklep jest obecnie okradany, więc nie może zostać okradziony przez Ciebie!"] call fini_fnc_noty; };
if ((currentWeapon player) in getArray(missionConfigFile >> "CfgSettings" >> "doesntThreaten")) exitWith { ["Do obrabowania tego sklepu potrzebna jest broń!"] call fini_fnc_noty; };

ULP_Robbery_Timeout = time + _personalTimeout;
_object setVariable ["robber", player, true];

private _marker = createMarker [format["store_robbery_%1", getPlayerUID player], position _object];
_marker setMarkerType "mil_warning";
_marker setMarkerColor "ColorRed";
_marker setMarkerSize [0.8, 0.8];

private _msg = missionConfigFile >> "CfgMessages" >> "Robbery";
private _targets = getText (_msg >> "targets");
[_msg, format ["Napad został zgłoszony i jest teraz widoczny na Twojej mapie!"], _targets] call ULP_fnc_sendMessage;

private _suspectedWeapon = ([currentWeapon player] call ULP_fnc_itemCfg) param [5, "Unknown"];

[format["Napadanie %1%2", _customName, getText (_cfg >> "name")], getNumber (_cfg >> "time"), [_object, _marker, _cfg, _customName, _suspectedWeapon, _intersetObject2], {
	_this params [ "_object", "", "", "", "", "_intersetObject2" ];

	private _robber = _object getVariable ["robber", objNull];

	!(isNull _robber) &&
	{ alive _robber } && 
	{ player isEqualTo _robber } && 
	{ (_robber distance _object) <= 8 } && 
	{ !(lineIntersects [eyePos _robber, eyePos _object, _robber, _intersetObject2]) }
}, {
	_this params [ "_object", "_marker", "_cfg", "_customName", "_suspectedWeapon" ];

	private _reward = getArray(_cfg >> "reward");
	private _money = (_reward # 0) + round (random (_reward # 1));
	[_money, false, format ["Napad: %1 ", getPos player]] call ULP_fnc_addMoney;

	getArray (_cfg >> "leveling") call ULP_fnc_addXP;

	if ([] call ULP_fnc_isGroup) then {
		[(group player), "Robbery"] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];
	};

	[getPlayerUID player, "TheftAct", "S8",
		format [
			"%2%3 | Prawdopodobnie użyta broń: %1",
			_suspectedWeapon,
			_customName, getText (_cfg >> "name")
		]
	] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];
	[player, "RobStore"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];

	[format["Okradłeś ten sklep na kwotę %1 $.", [_money] call ULP_fnc_numberText]] call ULP_fnc_achieve;
	[getPlayerUID player, "Robbery", [_customName, _money]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];

	_object setVariable["timeout", time + (getNumber (_cfg >> "timeout")), true];
	_object setVariable["robber", nil, true];
	deleteMarker _marker;
}, {
	_this params [ "_object", "_marker", "_cfg", "_customName", "_suspectedWeapon" ];
	_object setVariable["robber", nil, true];
	deleteMarker _marker;

	[getPlayerUID player, "CriminalAttempts", "Section1",
		format [
			"Próba rabunku %2%3 | Prawdopodobnie użyta broń: %1",
			_suspectedWeapon,
			_customName, getText (_cfg >> "name")
		]
	] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];
}] call ULP_UI_fnc_startProgress;