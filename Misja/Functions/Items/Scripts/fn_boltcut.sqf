/*
** Autor: Jack "Scarso" Farhall
** Opis:
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_boltcut";

private _object = cursorObject;

// Sprawdzenie, czy cięcie zamka jest zablokowane dla danego obiektu
if (_object getVariable ["block_boltcutter", false]) exitWith {
	["Nie możesz przeciąć zamka do tego budynku..."] call fini_fnc_noty;
	false
};

private _door = [_object] call ULP_fnc_getNearestDoor;
private _pos = _object;
private _isDoor = false;

// Sprawdzenie, czy obiekt to zablokowane drzwi
if (!(_object getVariable ["locked", false]) && { _door > -1 } && { (_object getVariable [format ["bis_disabled_Door_%1", _door], 0]) isEqualTo 1 }) then {
	_isDoor = true;
	_pos = (([_object] call ULP_fnc_getBuildingDoors) select (_door - 1));
};

// Sprawdzenie, czy gracz jest wystarczająco blisko, aby przeciąć zamek
if (isNull _object || { (player distance _pos) > 5 } || { !(_object getVariable ["locked", false]) && !_isDoor }) exitWith {
	["Jesteś albo za daleko od czegoś, co możesz przeciąć, albo zamek został już przecięty..."] call fini_fnc_noty;
	false
};

[] spawn ULP_UI_fnc_closeDialogs;

private _time = ["BoltCutter", 150] call ULP_fnc_activatePerk;
private _onBreakIn = "";

// Jeśli gracz jest w grupie, zastosuj bonusy grupowe
if ([] call ULP_fnc_isGroup) then {
	private _buff = [group player, "Boltcutting"] call ULP_fnc_groupBuff;
	if (_buff > 0) then { _time = _time - (_time * _buff); };
};

private _breakInCfg = _object getVariable ["breakInConfig", configNull];
if !(isNull _breakInCfg) then {
	_time = getNumber (_breakInCfg >> "breakIn");
	_onBreakIn = getText (_breakInCfg >> "onBreakIn");
	if !(call compile getText (_breakInCfg >> "condition")) exitWith {
		call compile getText (_breakInCfg >> "onFail");
		false breakOut "fn_boltcut";
	};
};

// Uruchom proces cięcia zamka
["Przecinanie", _time, [_object, _pos, _isDoor, _door, _onBreakIn], { (player distance (_this select 1)) <= 5 }, {
	_this params [ "_object", "_pos", "_isDoor", "_door", "_onBreakIn" ];

	["Udało ci się przeciąć zamek!"] call fini_fnc_noty;

	if (_isDoor) then {
		_object setVariable [format ["bis_disabled_Door_%1", _door], 0, true];
	} else {
		_object setVariable ["locked", nil, true];
	};

	if !(_onBreakIn isEqualTo "") then {
		_object call compile _onBreakIn;
	};
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
true
