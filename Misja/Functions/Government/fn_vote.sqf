/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vote";

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _pollingStation = _display getVariable ["pollingStation", objNull];
if (isNull _pollingStation) exitWith {};

private _list = _display displayCtrl 5202;

private _candidate = (_list lbData (lbCurSel _list));
if (_candidate isEqualTo "") exitWith {
	["Musisz wybrać osobę, na którą chcesz zagłosować..."] call fini_fnc_noty;
};

closeDialog 0;

if !(missionNamespace getVariable ["ULP_SRV_Setting_Election", false]) exitWith {
	["Obecnie nie odbywają się żadne wybory..."] call fini_fnc_noty;
};

// Easy way to avoid spam, they'd have to relog to get past and server side would block multiple votes
if (player getVariable ["voted", false]) exitWith {
	["Głosowałeś już w tych wyborach!"] call fini_fnc_noty;
};

if (player getVariable ["voting", false]) exitWith {
	["Twój głos jest już przetwarzany!"] call fini_fnc_noty;
};

player setVariable ["voting", true];

["ElectionVoteSubmitted", {
	private _message = _this param [0, "Udało Ci się oddać głos w wyborach..."];
	[_message] call fini_fnc_noty;

	player setVariable ["voting", nil];

	if (_message isEqualTo "Udało Ci się oddać głos w wyborach...") then {
		player setVariable ["voted", true];
		[player, "Vote"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];
	};
}, true] call ULP_fnc_addEventHandler;

["Oddawanie głosu..."] call fini_fnc_noty;
[_pollingStation, player, _candidate] remoteExecCall ["ULP_SRV_fnc_submitVote", RSERV];