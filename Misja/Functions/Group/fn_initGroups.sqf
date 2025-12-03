/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initGroups";

["Initialising Groups"] call ULP_fnc_logIt;

["GroupCreationSucceeded", {
	_this params [
		["_groupId", -1, [0]]
	];
	
	["Twoja grupa została stworzona."] call fini_fnc_noty;
	ULP_Group_Creating = false;

	[format["Created Group (%1)", _groupId]] call ULP_fnc_logIt;

	[ { [] call ULP_fnc_isGroup }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler;

["GroupCreationFailed", {
	_this params [
		["_reason", "Unknown", [""]]
	];

	[_reason] call fini_fnc_noty;
	ULP_Group_Creating = false;

	[format["Group Creation Failed (%1)", _reason]] call ULP_fnc_logIt;
}] call ULP_fnc_addEventHandler;

["GroupWithdraw", {
	_this params [
		["_message", "", [""]],
		["_amount", 0, [0]],
		["_total", 0, [0]]
	];

	if (_amount > 0) then {
		[_amount, false, format ["Fundusze grupowe"]] call ULP_fnc_addMoney;
	};

	[_message] call fini_fnc_noty;
}] call ULP_fnc_addEventHandler;

["GroupRankChanged", {
	_this params [
		["_rank", 0, [0]],
		["_actioner", objNull, [objNull]]
	];

	_rank = [_rank] call ULP_fnc_rankName;
	[format ["Twoja ranga została ustawiona na <t color='#B92DE0'>%1</t>", ([format["%1 by %2!", _rank, name _actioner], _rank] select (isNull _actioner))]] call fini_fnc_noty;
}] call ULP_fnc_addEventHandler;

["GroupOwner", {
	[format ["<t color='#B92DE0'>%1</t> przeniósł rangę <t color='#B92DE0'>lidera grupy</t> na Ciebie!", name (_this param [0, objNull])]] call fini_fnc_noty;
}] call ULP_fnc_addEventHandler;

["GroupInvite", {
	_this params [
		["_group", grpNull, [grpNull]],
		["_unit", objNull, [objNull]]
	];

	if (isNull _group || { isNull _unit }) exitWith {};

	if ([["EnableAutoDecline"] call ULP_fnc_getOption] call ULP_fnc_bool) then {
		["GroupInviteRejected", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	};

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Potwierdzenie", ["Tak", "Nie"],
		format ["<t color='#B92DE0'>%1</t> zaprosił cię do grupy: <t color='#B92DE0'>%2</t>, akceptujesz?", name _unit, [_group] call ULP_fnc_getGroupName], [_group, _unit],
		{
			_this params [ "_group", "_unit" ];

			[_group, player] remoteExecCall ["ULP_SRV_fnc_addGroupMember", RSERV];
		}, {
			private _unit = _this param [1, objNull];
			if (isNull _unit) exitWith {};
			["GroupInviteRejected", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
		}, false
	] call ULP_fnc_confirm;
}] call ULP_fnc_addEventHandler;

["GroupInviteRejected", {
	_this params [
		["_unit", objNull, [objNull]]
	];

	if (isNull _unit) exitWith {};

	_unit setVariable ["group_invited", nil];
	[format ["<t color='#B92DE0'>%1</t> odrzucił zaproszenie do grupy!", name _unit]] call fini_fnc_noty;
}] call ULP_fnc_addEventHandler;

["GroupJoined", {
	_this params [
		["_unit", objNull, [objNull]]
	];

	if (isNull _unit) exitWith {};
	
	if (_unit isEqualTo player) then {
		[ { [] call ULP_fnc_isGroup }, [], {
			["JoinGroup"] call ULP_fnc_achieve;

			[format ["<t color='#B92DE0'>Dołączyłeś do %1</t>", [] call ULP_fnc_getGroupName]] call fini_fnc_noty;
			[] call ULP_fnc_setTags;
		}] call ULP_fnc_waitUntilExecute;
	} else {
		_unit setVariable ["group_invited", nil];
		[format ["<t color='#B92DE0'>%1</t> dołączył do twojej grupy", name _unit]] call fini_fnc_noty;
	};
}] call ULP_fnc_addEventHandler;

["GroupKicked", {
	[format ["<t color='#B92DE0'>%1</t> wyrzucił cię z grupy!", name (_this param [0, objNull])]] call fini_fnc_noty;
	[ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler;

["GroupDisbanded", {
	[format ["<t color='#B92DE0'>%1</t> usunął grupę!", name (_this param [0, objNull])]] call fini_fnc_noty;
	[ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler;

["SoldVirtualItem", {
	_this params [ "_soldItem", "_amount", "", "_illegal" ];

	private _group = group player;
	private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _soldItem;

	if !(isClass _itemCfg 
		|| { [getNumber (_itemCfg >> "Settings" >> "isEventItem")] call ULP_fnc_bool } 
		|| { !(_illegal) } 
		|| { [] call ULP_fnc_isGroup } 
		|| { (_group getVariable ["group_type", ""]) isEqualTo "Corporate" }) exitWith {};

	private _xpAmountPerItem = getNumber (missionConfigFile >> "CfgGroups" >> "Leveling" >> "XP" >> "SoldLegalItems" >> "amountPerItem");
	private _groupXp = floor (_xpAmountPerItem * _amount);

	[_group, "SoldLegalItems", _groupXp] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];
	[format ["Otrzymałeś <t color='#B92DE0'>%1</t> grupowego XP za tą sprzedaż.", [_groupXp] call ULP_fnc_numberText]] call fini_fnc_noty;
}] call ULP_fnc_addEventHandler;