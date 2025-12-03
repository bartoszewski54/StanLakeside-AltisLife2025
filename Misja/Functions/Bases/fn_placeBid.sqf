/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_placeBid";

_this params [
	["_base", "", [""]]
];

if (!([player, ["Civilian"]] call ULP_fnc_isFaction) || { [] call ULP_fnc_isUndercover }) exitWith {
	["Tylko cywile mogą licytować..."] call fini_fnc_noty;
};

if !([] call ULP_fnc_isGroup) exitWith {
	["Musisz być w grupie, aby licytować baze..."] call fini_fnc_noty;
};

private _obj = missionNamespace getVariable [format ["ULP_SRV_Base_%1", _base], objNull];
if (isNull _obj) exitWith {
	["Błąd podczas obstawiania..."] call fini_fnc_noty;
};

if !(missionNamespace getVariable ["ULP_SRV_Setting_BaseBidsActive", false]) exitWith {
	["Obecnie licytacje są nieaktywne..."] call fini_fnc_noty;
};

private _bid = (_obj getVariable ["current_bid", getNumber (missionConfigFile >> "CfgBases" >> "StartingBid")]) + getNumber (missionConfigFile >> "CfgBases" >> "BidIncrement");

if (_bid > ([] call ULP_fnc_groupFunds)) exitWith {
	[format ["Następna licytacja to <t color='#B92DE0'>%1%2</t>, brakuje środków na grupie...", "$", [_bid] call ULP_fnc_numberText]] call fini_fnc_noty;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Potwierdzenie", ["Tak", "Nie"],
	format ["Napewno chcesz postawić <t color='#B92DE0'>%1%2</t>?", "$", [_bid] call ULP_fnc_numberText], [_bid, _base],
	{	
		_this params [ "_bid", "_base" ];
		
		if (player getVariable ["bidding", false]) exitWith {
			["Już obstawiłeś!"] call fini_fnc_noty;
		};

		player setVariable ["bidding", true];

		["BaseBid", {
			[_this param [0, "Pomyślnie złożono oferte..."]] call fini_fnc_noty;
			player setVariable ["bidding", nil];
		}, true] call ULP_fnc_addEventHandler;

		["Obstawianie..."] call fini_fnc_noty;
		[player, _bid, _base] remoteExecCall ["ULP_SRV_fnc_addBaseBid", RSERV];
	}, {}, false
] call ULP_fnc_confirm;