/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initChat";

["Initialising Chat"] call ULP_fnc_logIt;

addMissionEventHandler ["HandleChatMessage", {
	_this params [ "", "", "", "_text", "_person" ];

	private _return = false;

	if ((_text select [0, 1]) isEqualTo "/") then {
		if (_person isEqualTo player) then {
			private _command = missionConfigFile >> "CfgChat" >> "Commands" >> (_text select [1, (count _text) - 1]);

			if (isClass _command) then {
				if (call compile getText (_command >> "condition")) then {
					_return = (call compile getText (_command >> "action"));
				} else {
					_return = ["Komendy:", "Nie masz możliwości użycia tej komendy..."];
				};
			} else {
				_return = ["Command:", "Nieznana komenda.."];
			};
		} else {
			_return = true;
		};
	};

	_return
}];