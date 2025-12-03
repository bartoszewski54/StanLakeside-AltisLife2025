/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#define FREIGHT_ITEM_CFG missionConfigFile >> "CfgVirtualItems" >> "FreightCargo"
#include "..\..\script_macros.hpp"
scopeName "fn_claimFreight";

if (canSuspend) exitWith {
    [ULP_fnc_claimFreight, _this] call ULP_fnc_directCall;
};

_this params [
	["_trader", objNull, [objNull]],
	["_mission", "Kavala_Freight", [""]]
];

if (isNull _trader) exitWith {};

if !(["Freight"] call ULP_fnc_hasGroupPerk) exitWith {
	["Twoja grupa nie ma dostępu do tego."] call fini_fnc_noty;
};

private _near = ((_trader nearEntities [["Car"], 10]) select {
[player, _x] call ULP_fnc_isVehicleOwner
});

if (_near isEqualTo []) exitWith {
	["Brak Twojej ciężarówki w pobliżu"] call fini_fnc_noty;
};

if ("CorporateFreight" in ULP_Missions) exitWith {
	["Możesz robić tylko jedną misję."] call fini_fnc_noty;
};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (_near apply { 
	([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "", "_picture", "_name" ]; 
	[_picture, _name, _x call BIS_fnc_netId, 0];
}), ["Fill", "Cancel"], [_trader, _mission], {
	_this params [
		["_trader", objNull, [objNull]],
		["_mission", "Kavala_Freight", [""]],
		["_display", displayNull, [displayNull]]
	];

	if ((player distance _trader) > 5) exitWith {
		["Odszedłeś za daleko"] call fini_fnc_noty;
	};

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _vehicle) exitWith { ["Nie wybrałeś pojazdu do wypełnienia ładunkiem!"] call fini_fnc_noty; };

	if !([_vehicle, getPos _trader] call ULP_fnc_isVehicleStationary) exitWith { ["Silnik pojazdu musi być wyłączony i znajdować się blisko tabliczki!"] call fini_fnc_noty; };

	private _currentVehicleLoad = [_vehicle] call ULP_fnc_currentLoad;
	private _maxVehicleLoad = [_vehicle] call ULP_fnc_maxLoad;

	private _freightItemWeight = getNumber (FREIGHT_ITEM_CFG >> "weight");

	private _maxQuantity = ( floor ((_maxVehicleLoad - _currentVehicleLoad) / _freightItemWeight) max 0 );

	if (_maxQuantity <= 0) exitWith { ["Ten pojazd nie ma miejsca i nie może pomieścić nawet jednego ładunku!"] call fini_fnc_noty; };

	private _time = (_freightItemWeight * _maxQuantity) / getNumber (missionConfigFile >> "CfgMissions" >> "CorporateFreight" >> "timeDivisionAmount");

	private _vehicleCfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;

	private _item = configName (FREIGHT_ITEM_CFG);

	if (_item in getArray ((_vehicleCfg select 1) >> "blacklistedItems")) exitWith {
		["Tylko pojazdy ciężarowe mogą być używana do misji transportowych."] call fini_fnc_noty;
	};

	[format["Ładowanie ładunku do %1", _vehicleCfg param [3, "a vehicle"]], _time, [_trader, _vehicle, _maxQuantity, _item, _mission],
		{ (player distance (_this select 0)) <= 5 && { [(_this select 1), getPos (_this select 0)] call ULP_fnc_isVehicleStationary } }, 
		{
			_this params [ "_trader", "_vehicle", "_maxQuantity", "_item", "_mission" ];
			if (isNull _vehicle) exitWith {};

			if ("CorporateFreight" in ULP_Missions) exitWith {
				[getText (missionConfigFile >> "CfgMissions" >> "CorporateFreight" >> "Messages" >> "onAlreadyHas")] call fini_fnc_noty;
			};

			private _cargoParams = [_vehicle, _item, _maxQuantity];

			if !(_cargoParams call ULP_fnc_addToCargo) exitWith {
				["Pojazd ten nie jest w stanie przechować danej ilości ładunków, pamiętaj aby nic nie wkładać do niego podczas trwania ładunku!"] call fini_fnc_noty;
			};

			missionNamespace setVariable ["ULP_FreightVehicle", [_vehicle, _maxQuantity]];

			if !(["CorporateFreight", _mission] call ULP_fnc_claimMission) exitWith {
				_cargoParams call ULP_fnc_removeFromCargo;
			};
		}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
	}, false] call ULP_fnc_selectObject;