/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_administerBlood";

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit || { !(alive _unit) }) exitWith {};

if ((0 max (["BloodBag"] call ULP_fnc_hasItem)) < 1) exitWith { ["Do podania krwi potrzebny jest worek z krwią!"] call fini_fnc_noty; };
if !(isDowned(_unit)) exitWith { ["Krew można podawać tylko zranionym!"] call fini_fnc_noty; };

private _name = [_unit, true] call ULP_fnc_getName;

private _time = 30;

if !([format["Podawanie krwi do %1", _name], _time, [_unit, _name], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { isDowned((_this select 0)) } && { (0 max (["BloodBag"] call ULP_fnc_hasItem)) > 0 } && 
	{ (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_unit", "_name" ];

	if (isNull _unit || { !(alive _unit) } || { !(isDowned(_unit)) } || { (0 max (["BloodBag"] call ULP_fnc_hasItem)) < 1 }) exitWith {
		["Albo zgubiłeś worek z krwią, albo pacjent którego leczyłeś, nie żyje..."] call fini_fnc_noty;
	};

	if ([] call ULP_fnc_isGroup) then {
		if (_unit in (units (group player))) then {
			[(group player), "MedicalAid"] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];
		};
	};

	["BloodBag", 1, true] call ULP_fnc_handleItem;
	[format ["Podałeś krew do <t color='#B92DE0'>%1</t>.", _name]] call fini_fnc_noty;

	private _unitRep = _unit getVariable ["reputation", 0];
	if (_unitRep >= 500) then {
		[_medic, "BloodHigh"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];
	};

	["GivenBlood"] call ULP_fnc_achieve;


	[player, ["BloodCarrier", getNumber (missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "BloodBagIncrease")] call ULP_fnc_activatePerk] remoteExecCall ["ULP_fnc_receivedBlood", _unit];
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	["Nie można podawać krwi podczas wykonywania innej akcji..."] call fini_fnc_noty;
};

closeDialog 0;