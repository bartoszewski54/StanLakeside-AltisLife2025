/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_panic";

if !((["PanicButton"] call ULP_fnc_hasItem) >= 1 && { [player, ["Police", "Medic", "Hato"]] call ULP_fnc_isFaction || { ["PanicButton", 1, true] call ULP_fnc_handleItem } }) exitWith { false };

// Stop spam...
private _cd = player getVariable ["panic_cooldown", 0];
if (time < _cd) exitWith {
	[format ["Niedawno użyłeś panic buttona i nie możesz go użyć ponownie. <t color='#B92DE0'>%1</t> sekund...", [_cd - time] call ULP_fnc_numberText]] call fini_fnc_noty;
	false
};
player setVariable ["panic_cooldown", time + 60];

private _cfg = missionConfigFile >> "CfgMessages" >> "Panic";
private _targets = getText (_cfg >> "targets");

[_cfg, "PANIC BUTTON!!! Oficer w niebezpieczeństwie!", _targets] call ULP_fnc_sendMessage;
["Wcisnąłeś panic button, wszystkie osoby w policji zostały poinformowane!"] call fini_fnc_noty;
["Panic"] call ULP_fnc_achieve;

[player, "panicButton", 100, 1] remoteExecCall ["ULP_fnc_say3D"];

true