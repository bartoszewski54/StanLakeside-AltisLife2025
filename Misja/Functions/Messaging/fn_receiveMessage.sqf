/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_recieveMessage";

_this params [
	["_type", configNull, [configNull]],
	["_message", "", [""]],
	["_sender", [], [[]]]
];

if (isNull _type || { _message isEqualTo "" } || { _sender isEqualTo [] } || { (count _message) > getNumber (missionConfigFile >> "CfgMessages" >> "length") }) exitWith {};

if (!([getNumber (_type >> "ignoreComms")] call ULP_fnc_bool) && { !([] call ULP_fnc_hasComms) }) exitWith {
	["Otrzymałeś wiadomość, ale ponieważ nie masz łączności, nie mogłeś jej odebrać...."] call fini_fnc_noty;
};

if ([getNumber (_type >> "saveInbox")] call ULP_fnc_bool) then {
	private _messages = + (missionProfileNamespace getVariable ["ULP_Messages", []]);
	_messages pushBack [configName _type, _sender, _message, false];

	private _count = count _messages;
	if (_count > 25) then {
		_messages = _messages select [_count - 25, 25];
	};

	missionProfileNamespace setVariable ["ULP_Messages", _messages];
	saveMissionProfileNamespace;
};

if ([["EnableMessageAlert", "Audio"] call ULP_fnc_getOption] call ULP_fnc_bool && { [getNumber (_type >> "alertSound")] call ULP_fnc_bool }) then {
	playSound "messageNotification";
};

if ([["EnableStreamerMode"] call ULP_fnc_getOption] call ULP_fnc_bool && { [getNumber (_type >> "saveInbox")] call ULP_fnc_bool } && { !([getNumber (_type >> "ignoreStreamer")] call ULP_fnc_bool) }) then {
	["Otrzymałeś wiadomość, jej treść została ukryta."/*, "Phone Notification" TODO */] call fini_fnc_noty;
} else {
	_sender params [
		["_name", "", [""]]
	];

	[format ["Otrzymałeś wiadomość od <t color='#B92DE0'>%1</t>: %2", _name, _message]/*, "Phone Notification"*/] call fini_fnc_noty;
};

if (isText (_type >> "onRecieved")) then {
	[[_sender select 1] call ULP_fnc_playerByUID, _message] call compile getText (_type >> "onRecieved");
};

["MessageReceived", _messages] call ULP_fnc_invokeEvent;