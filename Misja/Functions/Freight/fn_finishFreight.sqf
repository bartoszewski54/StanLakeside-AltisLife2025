/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_finishFreight";

if (canSuspend) exitWith {
    [ULP_fnc_finishFreight, _this] call ULP_fnc_directCall;
};

if !("CorporateFreight" in ULP_Missions) exitWith {
	[getText (missionConfigFile >> "CfgMissions" >> "CorporateFreight" >> "Messages" >> "onFinishWithoutMission")] call fini_fnc_noty;
	false
};

(missionNamespace getVariable ["ULP_FreightVehicle", [objNull, 0]]) params [
	"_vehicle",
	"_expectedQuantity"
];

if (isNull _vehicle || { !(alive _vehicle) } || { (player distance _vehicle) > 15 }) exitWith {
	["Twój pojazd został zniszczony, lub jesteś za daleko od niego."] call fini_fnc_noty;
	false
};

private _countRemoved = [_vehicle, "FreightCargo"] call ULP_fnc_wipeItemFromCargo;

if !(_countRemoved isEqualTo _expectedQuantity) exitWith {
	["Twój pojazd nie miał oczekiwanej ilości ładunku, nagroda nie została przyznana."] call fini_fnc_noty;
	false
};

private _secondaryReward = getNumber (missionConfigFile >> "CfgVirtualItems" >> "FreightCargo" >> "sellPrice") * _countRemoved;

[_secondaryReward, false, "Działka z misji"] call ULP_fnc_addMoney;
[(group player), "Freight"] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];

[format ["Otrzymałeś swoją działkę w wysokości <t color='#B92DE0'>%1%2</t> za ładunek i zdobyłeś troche grupowego XP.", "$", [_secondaryReward] call ULP_fnc_numberText]] call fini_fnc_noty;

true