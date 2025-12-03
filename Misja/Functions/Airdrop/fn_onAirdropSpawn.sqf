/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onAirdropSpawn";

_this params [
	["_airdrop", objNull, [objNull]],
	["_message", "", [""]]
];

if (isNull _airdrop) exitWith {};

[_message] call fini_fnc_noty;

_airdrop addAction [
	"Przejmij Airdrop", {
		_this params [ "_airdrop", "", "_actionId" ];

		if (_airdrop getVariable ["locked", false]) exitWith {
			["Airdrop jest zablokowany, musisz przeciąć kłódke nożycami do metalu, aby go przejąć..."]  call fini_fnc_noty;
		};

		["Przejmowanie dropu", 90, [_airdrop, _actionId], { true }, {
			_this params [ "_airdrop", "_actionId" ];

			_airdrop removeAction _actionId;
			["Przejmujesz drop... Powodzenia!"] call fini_fnc_noty;

			[player, _airdrop] remoteExecCall ["ULP_SRV_fnc_claimAirdrop", RSERV];
		}, {}] call ULP_UI_fnc_startProgress;
	}, nil, 8, true, true, "", "(((getPos _target) select 2) <= 1)", 5
];