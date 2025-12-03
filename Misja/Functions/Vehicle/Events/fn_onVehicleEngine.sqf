/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onVehicleEngine";

_this params [
	["_vehicle", objNull, [objNull]],
	["_engineOn", false, [true]]
];

if (local _vehicle && { _engineOn }) then {
	if ([player] call ULP_fnc_isRestrained) exitWIth {
		_vehicle engineOn false;
	};

	private _clamp = _vehicle getVariable ["clamp_fine", []];

	if !(_clamp isEqualTo []) then {
		_vehicle engineOn false;

		_clamp params [ "_finer", "_steamid", "_fine" ];

		if (CASH < _fine) exitWith {
			if (time >= _vehicle getVariable ["clamp_notify", 0]) then {
				[format ["Twój pojazd ma założoną blokadę na koła przez <t color='#B92DE0'>%1</t> i nie masz <t color='#B92DE0'>%2%3</t> by opłacić mandat...", _finer, "$", [_fine] call ULP_fnc_numberText]] call fini_fnc_noty;
			};
			_vehicle setVariable ["clamp_notify", time + 3];
		};

		[
			(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Mandat - Parking", ["Zapłać", "Anuluj"],
			format ["%1 założył Ci blokade na koła i wystawił mandat na kwotę %2%3", _finer, "$", [_fine] call ULP_fnc_numberText], [_vehicle, _fine, _steamid],
			{	
				_this params [ "_vehicle", "_fine", "_steamid" ];

				if ([_fine, false, "Mandat - Parking"] call ULP_fnc_removeMoney) then {
					_vehicle engineOn true;
					_vehicle setVariable ["clamp_fine", nil, true];

					[format ["Zapłaciłeś mandat w wysokości <t color='#B92DE0'>%1%2</t>, blokada została zdjęta...", "$", [_fine] call ULP_fnc_numberText]] call fini_fnc_noty;

					private _unit = [_steamid] call ULP_fnc_playerByUID;
					if (!(isNull _unit) && { [player, ["Police", "Hato"]] call ULP_fnc_isFaction }) then {
						["ClampFinePaid", [profileName, _vehicle, _fine]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
					};
				} else {
					["Nie masz przy sobie wystarczająco dużo pieniędzy, aby zapłacić grzywnę..."] call fini_fnc_noty;
				};
			}, {}, false
		] call ULP_fnc_confirm;
	};
};