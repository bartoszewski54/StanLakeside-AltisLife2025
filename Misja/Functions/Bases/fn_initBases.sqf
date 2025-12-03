/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initBases";

if ([player, ["Civilian"]] call ULP_fnc_isFaction && { missionNamespace getVariable ["ULP_SRV_Setting_BaseBidsActive", false] }) then {
	["Inicjalizowanie Aukcji Baz..."] call ULP_fnc_logIt;

	{
		private _flag = missionNamespace getVariable [format ["ULP_SRV_Base_%1", configName _x], objNull];

		if !(isNull _flag) then {
private _bidAction = _flag addAction [format["Postaw na %1", getText (_x >> "displayName")], { [(_this select 3)] call ULP_fnc_placeBid }, configName _x, 1.25, true, true, "", "true", 3];
			_flag setVariable ["bidAction", _bidAction];
	};
	} forEach ("[getNumber (_x >> ""includeBidding"")] call ULP_fnc_bool" configClasses (missionConfigFile >> "CfgBases"));

	["BaseAwarded", {
		_this params [
			["_baseCfgName", "", [""]],
			["_groupTag", "", [""]]
		];
		if (_baseCfgName isEqualTo "" || { _groupTag isEqualTo "" }) exitWith {};
		private _flag = missionNamespace getVariable [format ["ULP_SRV_Base_%1", _baseCfgName], objNull];
		if (isNull _flag) exitWith {};
		_flag removeAction (_flag getVariable ["bidAction", -1]);
		[format [
			"<t color='#ff0000' size='1.5px'>Wojny Gangów<br/></t><t color='#ffffff' size='1px'><t color='#B92DE0'>%1</t> wygrał <t color='#B92DE0'>%2</t> Baze gangu",
			_groupTag, _baseCfgName
		]] call fini_fnc_noty;
	}] call ULP_fnc_addEventHandler;

	["KilledSomeone", {
		_this params [
			["_unit", objNull, [objNull]]
		];

		if (isNull _unit
			|| { !(isPlayer _unit) }
			|| { !(["redzone_"] call ULP_fnc_isUnitsInZone) }
			|| { (currentWeapon _unit) isEqualTo "" }
			|| { [group player, _unit] call ULP_fnc_inGroup }) exitWith {};

		private _reward = getNumber (missionConfigFile >> "CfgBases" >> "RedzoneKillReward");

		[5, "Redzone Kill"] call ULP_fnc_addXP;

		if ([_reward, true, "Wojny gangów"] call ULP_fnc_addMoney) then {
			[format ["Otrzymujesz <t color='#B92DE0'>%1%2</t> za zabicie kogoś w redzonie podczas wojny gangów...", "$", [_reward] call ULP_fnc_numberText]] call fini_fnc_noty;
		};
	}] call ULP_fnc_addEventHandler;
};