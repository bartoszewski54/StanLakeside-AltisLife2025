/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_claimMail";

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

if (player getVariable ["claiming_mail", false]) exitWith { closeDialog 0; };

private _list = _display displayCtrl 5302;

private _selected = _list lbData (lbCurSel _list);
if (_selected isEqualTo "") exitWith {
	["Musisz wybrać przedmiot do odebrania ze swojej skrzynki pocztowej."] call fini_fnc_noty;
};

_button ctrlEnable false;

player setVariable ["claiming_mail", true];

private _lbData = parseSimpleArray _selected;

_lbData params [
	"_id", 
	"_type", 
	"_className", 
	"_data"
];

private _claimedAmount = 0;
private _totalAmount = 0;

if (_data isEqualType 0) then {
	_totalAmount = _data;
};

switch (_type) do {
	case "Vehicle";
	case "Texture": {
		_totalAmount = _data param [0, 0];
		private _texture = _data param [1, ""];

		if (_totalAmount isEqualTo 0 && { [_className, _texture] call ULP_fnc_isTextureUnlocked }) exitWith {
			["Masz już odblokowaną tę teksturę"] call fini_fnc_noty;
			player setVariable ["claiming_mail", nil];
			_button ctrlEnable true;
			breakOut "fn_claimMail";
		};

		[_className, _texture] call ULP_fnc_unlockTexture;

		// It's more than a texture unlock
		if (_totalAmount > 0) then {
			private _faction = [player] call ULP_fnc_getFaction;

			[
				0, 
				getPlayerUID player, 
				profileName, _faction, 
				_className, 
				[], 
				_texture, 
				false,
				true,
				0
			] remoteExecCall ["ULP_SRV_fnc_createVehicle", RSERV];
		};

		// These ensure we tell the user they've claimed all and update database
		_claimedAmount = 1;
		_totalAmount = 1;
	};
	case "VirtualItem": {
		private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _className;

		if !(isClass _itemCfg) exitWith { ["Wystąpił błąd podczas odbierania przedmiotów"] call fini_fnc_noty; };

		private _weight = getNumber (_itemCfg >> "weight");

		private _maxQuantity = _totalAmount;

		if (_weight > 0) then {
			_maxQuantity = [_weight] call ULP_fnc_getMaxQuantity;
		};

		_claimedAmount = _maxQuantity min _totalAmount;

		if (_claimedAmount <= 0 || { !([_className, _claimedAmount, false] call ULP_fnc_handleItem) } ) exitWith {
			["Nie masz wystarczająco dużo miejsca, aby zabrać którykolwiek z tych przedmiotów"] call fini_fnc_noty;
			player setVariable ["claiming_mail", nil];
			_button ctrlEnable true;
			breakOut "fn_claimMail";
		};

		_data = (_totalAmount - _claimedAmount) max 0;
	};
	case "Money": {
		if ([_totalAmount, false, _className] call ULP_fnc_addMoney) then {
			_claimedAmount = _totalAmount;
		};
	};
	default {
		for "_i" from 1 to _totalAmount do {
			if ([_className, false] call ULP_fnc_handleGear) then {
				_claimedAmount = _claimedAmount + 1;
			};
		};

		_data = (_totalAmount - _claimedAmount) max 0;
	};
};

if (_claimedAmount <= 0) exitWith {
	["Nie masz wystarczająco dużo miejsca, aby zabrać którykolwiek z tych przedmiotów"] call fini_fnc_noty;
	player setVariable ["claiming_mail", nil];
	_button ctrlEnable true;
};

[getPlayerUID player, "Mail", [_id, _type, _className, _data, _totalAmount, _claimedAmount]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];

[format ["Odebrałeś %1", [
	format ["%1 tych przedmiotów, ale nie mogłeś ich wszystkich zmieścic.", _claimedAmount],
	"całość"
] select (_claimedAmount isEqualTo _totalAmount)]] call fini_fnc_noty;

_display setVariable ["mail_claimed", (["MailClaimed", {
		[getPlayerUID player] remoteExecCall ["ULP_SRV_fnc_getMail", RSERV];
		player setVariable ["claiming_mail", nil];
	}, true] call ULP_fnc_addEventHandler)];

[_id, _data, _totalAmount, _claimedAmount] remoteExecCall ["ULP_SRV_fnc_updateMail", RSERV];