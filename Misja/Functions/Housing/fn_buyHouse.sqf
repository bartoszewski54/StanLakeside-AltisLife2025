/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyHouse";

if (canSuspend) exitWith {
    [ULP_fnc_buyHouse, _this] call ULP_fnc_directCall;
};

_this params [
	["_house", objNull, [objNull]]
];

if ([player] call ULP_fnc_onDuty) exitWith {
	["Nie możesz kupować domu na duty..."] call fini_fnc_noty;
};

private _objectCfg = [typeOf _house] call ULP_fnc_vehicleCfg;

if !([_house] call ULP_fnc_isHouse || 
	{ isClass (missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction >> "Housing") } || 
	{ !([_house] call ULP_fnc_isHouseOwned) } ||
	{ (count _objectCfg) > 0 }
) exitWith {
	["Tego domu nie mozna kupić!"] call fini_fnc_noty;
};

if !(["Home"] call ULP_fnc_hasLicense) exitWith {
	["Nie masz licencji na dom."] call fini_fnc_noty;
};

if (_house getVariable ["blacklisted", false]) exitWith {
	["This house is <t color='#B92DE0'>blacklisted</t>."] call fini_fnc_noty;
};

if !(call compile getText (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house) >> "condition")) exitWith {
	["Nie możesz obecnie kupić tego domu..."] call fini_fnc_noty;
};

private _limit = getNumber (missionConfigFile >> "CfgHousing" >> "houseLimit");
if (["LandLord"] call ULP_fnc_hasPerk) then { _limit = _limit + 1 };
if ((count ([_house] call ULP_fnc_ownedHouses)) >= _limit) exitWith {
	[format ["Osiągnąłeś limit domów wynoszący <t color='#B92DE0'>%1</t>.", _limit]] call fini_fnc_noty;
};

private _money = getNumber (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house) >> "price");

_objectCfg params [ "", "", "", "_name" ];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Potwierdzenie", ["Tak", "Nie"],
	format ["Napewno chcesz wydać <t color='#B92DE0'>%1%2</t> na <t color='#B92DE0'>%3</t>...", "$", [_money] call ULP_fnc_numberText, _name], [_house, _money],
	{	
		_this params [
			["_house", objNull, [objNull]],
			["_money", 0, [0]]
		];

		if (isNull _house) exitWith {};

		if (_house getVariable ["buying", false]) exitWith {
			["Ten dom już jest zajęty!"] call fini_fnc_noty;
		};

		_house setVariable ["buying", true];
		closeDialog 0;

		["HouseBought", {
			_this params [
				["_house", objNull, [objNull]],
				["_success", false, [true]],
				["_message", "", [""]],
				["_money", 0, [0]]
			];

			if (_success) then {
				[[_house]] call ULP_fnc_setupHouses;
				["BuyHouse"] call ULP_fnc_achieve;
				
				private _cfg = missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house);
				if (isText (_cfg >> "onBought")) then {
					call compile getText (_cfg >> "onBought");
				};
			} else {
				[_money, true, "Kupno domu - Zwrot"] call ULP_fnc_addMoney;
			};

			[_message] call fini_fnc_noty;

			_house setVariable ["buying", nil];
		}, true] call ULP_fnc_addEventHandler;

		if ([_money, true, "Kupno domu"] call ULP_fnc_removeMoney) then {
			["Kupowanie..."] call fini_fnc_noty;
			[player, _house, _money] remoteExecCall ["ULP_SRV_fnc_buyHouse", RSERV];
		} else {
			[format ["Nie masz <t color='#B92DE0'>%1%2</t> aby kupić ten dom!", "$", [_money] call ULP_fnc_numberText]] call fini_fnc_noty;
			_house setVariable ["buying", nil];
		};
	}, {}, false
] call ULP_fnc_confirm;