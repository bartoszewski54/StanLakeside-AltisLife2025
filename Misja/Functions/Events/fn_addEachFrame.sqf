/*
** Author: Jack "Scarso" Farhall
** Description: Basically just an eachFrame handler like arma's onEachFrame event but this allows everything to be put into one handler.
*/
scopeName "fn_addEachFrame";

_this params [
	["_params", []],
	["_function", {}, [{}]]
];

if (_function isEqualTo {}) exitWith { -1 };

private _handle = ULP_eachFrameEventsHandles pushBack (count ULP_eachFrameEventsHandlers);
ULP_eachFrameEventsHandlers pushBack [_params, _function, _handle];

_handle