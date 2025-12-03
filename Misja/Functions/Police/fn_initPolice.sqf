/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initPolice";

["Initialising Police Related Events"] call ULP_fnc_logIt;

["TicketPaid", {
	_this params [
		["_name", "", [""]],
		["_amount", 0, [0]],
		["_paid", false, [true]]
	];

	if (_name isEqualTo "" || { _amount < 0 }) exitWith {};

	if (_paid) then {
		[format ["<t color='#B92DE0'>%1</t> zapłacił mandat w wysokości <t color='#B92DE0'>%2%3</t>", _name, "$", [_amount] call ULP_fnc_numberText]] call fini_fnc_noty;
		[round (_amount / 2), true, format ["Mandat -%1", _name]] call ULP_fnc_addMoney;
	} else {
		[format ["<t color='#B92DE0'>%1</t> odmówił lub nie był w stanie zapłacić mandatu..", _name]] call fini_fnc_noty;
	};
}] call ULP_fnc_addEventHandler;

["TicketRecieved", {
	_this params [
		["_unit", objNull, [objNull]],
		["_amount", 0, [0]]
	];

	if (isNull _unit || { _amount < 0 }) exitWith {};

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Mandat", ["Zapłać", "Odmów"],
		format ["%1 nałożył na Ciebie mandat w wysokości %2%3", [_unit, true] call ULP_fnc_getName, "$", [_amount] call ULP_fnc_numberText], [_unit, _amount],
		{	
			_this params [ "_unit", "_amount" ];

			if (isNull _unit) exitWith {};

			private _name = [player, true] call ULP_fnc_getName;

			if ([_amount, true, "Mandat"] call ULP_fnc_removeMoney) then {
				[format ["Zapłaciłeś mandat w wysokości <t color='#B92DE0'>%1%2</t>", "$", [_amount] call ULP_fnc_numberText]] call fini_fnc_noty;
				["TicketPaid", [_name, _amount, true]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
				["FinePaid", [_name, format ["%1%2", "$", [_amount] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
			} else {
				["Nie masz wystarczająco dużo pieniędzy, aby zapłacić ten mandat..."] call fini_fnc_noty;
				["TicketPaid", [_name, _amount, false]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
				["FinePoor", [_name, format ["%1%2", "$", [_amount] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
			};
		}, {
			_this params [ "_unit", "_amount" ];

			if (isNull _unit) exitWith {};
			
			private _name = [player, true] call ULP_fnc_getName;

			["TicketPaid", [_name, _amount, false]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			["FineRefused", [_name, format ["%1%2", "$", [_amount] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
		}, false
	] call ULP_fnc_confirm;
}] call ULP_fnc_addEventHandler;

["LicensesShown", {
	_this params [
		["_unit", objNull, [objNull]],
		["_licenses", [], [[]]],
		["_shown", false, [true]],
		["_refused", false, [true]]
	];

	if (isNull _unit) exitWith {};

	_unit setVariable ["licenses_requested", nil];

	private _name = [_unit, true] call ULP_fnc_getName;

	if (_licenses isEqualTo []) exitWith {
		[format ["%1 chciał Ci pokazać swoje licencje, ale żadnej nie ma...", _name]] call fini_fnc_noty;
	};

	if (_shown) then {
		if (_refused) exitWith {
			[format ["%1 odmówił pokazania Ci swoich licencji...", _name]] call fini_fnc_noty;
		};

		[format ["<t color='#FF0000'><t size='1.7' align='center'>%1</t></t><br/><t color='#FFD700'><t size='1.5' align='center'>Licencje</t></t><br/><t align='center'>%2</t>", _name, (_licenses apply {
			if (isClass (missionConfigFile >> "CfgLicenses" >> _x >> "displayName"))  exitWith {
				getText (missionConfigFile >> "CfgLicenses" >> _x >> "displayName")
			};

			_x
		}) joinString "<br/>"]] call fini_fnc_noty;
	} else {
		if (createDialog "DialogSeizeLicenses") then {
			private _display = findDisplay 5100;
			if (isNull _display) exitWith {};

			_display setVariable ["unit", _unit];
			
			(_display displayCtrl 5101) ctrlSetText format ["Licencje %1", _name];

			private _list = _display displayCtrl 5102;
			lbClear _list;

			{
				private _license = missionConfigFile >> "CfgLicenses" >> _x;

				if (isClass _license) then {
					private _item = _list lbAdd getText (_license >> "displayName");
					_list lbSetData [_item, _x];
				};
			} forEach _licenses;
		} else {
			[format ["Coś poszło nie tak podczas próby wyświetlenia licencji %1...", _name]] call fini_fnc_noty;
		};
	};
}] call ULP_fnc_addEventHandler;

["RequestLicenses", {
	_this params [
		["_unit", objNull, [objNull]]
	];

	if (isNull _unit) exitWith {};

	if ([player] call ULP_fnc_isRestrained) then {
		["LicensesShown", [player, ULP_Licenses, false]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	} else {
		[
			(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Potwierdzenie", ["Akceptuj", "Odmów"],
			format ["%1 poprosił o wgląd do twoich licencji, zgadzasz się?", [_unit, true] call ULP_fnc_getName], [_unit],
			{
				private _unit = _this param [0, objNull];
				if (isNull _unit) exitWith {};
				["LicensesShown", [player, ULP_Licenses, true]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			}, {
				private _unit = _this param [0, objNull];
				if (isNull _unit) exitWith {};
				["LicensesShown", [player, ULP_Licenses, true, true]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			}, false
		] call ULP_fnc_confirm;
	};
}] call ULP_fnc_addEventHandler;

["LicenseSeized", {
	_this params [
		["_unit", objNull, [objNull]],
		["_license", "", [""]]
	];

	if (isNull _unit || { !([_license] call ULP_fnc_hasLicense) }) exitWith {};
	
	ULP_Licenses deleteAt (ULP_Licenses find _license);

	[format ["%1 zabrał ci licencje: %2", [_unit, true] call ULP_fnc_getName, getText (missionConfigFile >> "CfgLicenses" >> _license >> "displayName")]] call fini_fnc_noty;
}] call ULP_fnc_addEventHandler;

private _display = findDisplay 23000; // Znajdź dialog o ID 1234
private _button = _display displayCtrl 23007; // Znajdź przycisk o ID 23007
_button ctrlEnable true; // Pokaż przycisk