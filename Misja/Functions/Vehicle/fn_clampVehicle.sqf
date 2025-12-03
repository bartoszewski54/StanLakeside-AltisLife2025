/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_clampVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] } || { ((["VehicleClamp"] call ULP_fnc_hasItem) < 1) }) exitWith { if (dialog) then { closeDialog 0; }; };

private _clamp = _vehicle getVariable ["clamp_fine", []];

if !(_clamp isEqualTo []) exitWith {
	["Pojazd ten ma już blokadę..."] call fini_fnc_noty;
	false
};

if !([player, ["Police", "Hato"]] call ULP_fnc_isFaction) exitWith {
	["Musisz być w drogówce lub policji aby nakładać blokady..."] call fini_fnc_noty;
	false
};

if ([player, ["Police"]] call ULP_fnc_isFaction && { [["Hato"]] call ULP_fnc_onlineFaction > 0 }) exitWith {
	["HATO jest aktywne, więc to oni zakładają blokady..."] call fini_fnc_noty;
	false
};

closeDialog 0;

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), getArray (missionConfigFile >> "CfgSettings" >> "Police" >> "clampFee"), [_vehicle, _cfg],
	{
		_this params [
			["_vehicle", objNull, [objNull]],
			["_cfg", [], [[]]],
			["_display", displayNull, [displayNull]],
			["_fine", 1, [0]]
		];

		[format["Clamping %1", (_cfg param [3, "Vehicle"])], 30, [_vehicle, _cfg, _fine], { (player distance (_this select 0)) <= 5 }, {
			_this params [
				["_vehicle", objNull, [objNull]],
				["_cfg", configNull, [configNull]],
				["_fine", 1, [0]]
			];
			
			if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
				["Jesteś za daleko od pojazdu..."] call fini_fnc_noty;
			};

			if (["VehicleClamp", 1, true] call ULP_fnc_handleItem) then {
				_vehicle setVariable ["clamp_fine", [profileName, getPlayerUID player, _fine], true];
				[format ["Założyłeś blokadę na <t color='#B92DE0'>%1</t> na kwotę <t color='#B92DE0'>%2%3</t>...", _cfg param [5, "Vehicle"], "$", [_fine] call ULP_fnc_numberText]] call fini_fnc_noty;
				["ClampVeh"] call ULP_fnc_achieve;
			} else {
				["Potrzebujesz blokady na koła..."] call ULP_fnc_numberText;
			};
		}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
	}, false, "format [""%1%2"", ""$"", [_this] call ULP_fnc_numberText]", false
] call ULP_fnc_selectNumber;

true