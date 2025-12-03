/*
** Author: Jack "Scarso" Farhall
** Description: Shares keys with everyone in vehicle as long as you're in it
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_shareKeys";
_this params [ "_button" ];
private _display = ctrlParent _button;
if (isNull _display) exitWith {};
private _carView = _display displayCtrl 23092;
private _vehicle = _display getVariable ["vehicle", objNull];
if (isNull _vehicle) exitWith { _carView ctrlShow false; };
if !(ctrlShown _carView) then { _carView ctrlShow true; };
if !((vehicle player) isEqualTo _vehicle) exitWith { ["Musisz być w pojeździe aby dać każdemu klucze."] call fini_fnc_noty; };
private _crew = (crew _vehicle) - [player];
if ((count _crew) isEqualTo 0) exitWith { ["Nie ma nikogo w pojeździe do dania kluczy."] call fini_fnc_noty; };
["KeysGiven", [_vehicle, player]] remoteExecCall ["ULP_fnc_invokeEvent", _crew];
["Dałeś każdemu klucz do tego pojazdu"] call fini_fnc_noty;