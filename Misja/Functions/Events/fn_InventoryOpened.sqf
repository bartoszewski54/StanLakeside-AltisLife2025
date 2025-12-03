/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_InventoryOpened";

_this params [
	["_unit", objNull, [objNull]],
	["_container", objNull, [objNull]],
	["_secondaryContainer", objNull, [objNull]]
];

private _uniform = (uniformContainer player) getVariable ["texture", ""];
private _backpack = (backpackContainer player) getVariable ["texture", ""];

if !(_uniform isEqualTo "") then { [player, uniform player, uniformContainer player, _uniform] call ULP_fnc_setTextures; };
if !(_backpack isEqualTo "") then { [unitBackpack player, typeOf (unitBackpack player), backpackContainer player, _backpack] call ULP_fnc_setTextures; };

if ([getNumber (configFile >> "CfgVehicles" >> (typeOf _container) >> "isBackpack")] call ULP_fnc_bool) exitWith {
    ["Nie możesz zaglądać do plecaków innych osób!"] call fini_fnc_noty;
    true
};

if ([_container, ["LandVehicle", "Air", "Ship"]] call ULP_fnc_isKindOf) exitWith {
    if (!(_container in ULP_Keys) && ((locked _container) isEqualTo 2)) exitWith {
        ["Ten pojazd jest zamknięty..."] call fini_fnc_noty;
        true
    };

    if ([] call ULP_fnc_isRestrained || { [] call ULP_fnc_isKnocked } || { [] call ULP_fnc_isSurrendered }) exitWith {
        ["Nie możesz integrować z pojazdami będąc zakutym, związanym, lub poddanym."] call fini_fnc_noty;
        true
    };
};

if (_container isKindOf "Man" && { !alive _container }) exitWith {
    ["Nie możesz przeszukiwać ciał."] call fini_fnc_noty;
    true
};
[{ !isNull (findDisplay 602) }, [], {
    private _display = findDisplay 602;
    private _repackButton = _display ctrlCreate ["ULP_RscInventoryButton", -1];
    _repackButton ctrlSetPosition [36.8 * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2)) / 2),
        1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2)) / 2),
        1 * (((safezoneW / safezoneH) min 1.2) / 40),
        1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)];
    _repackButton ctrlCommit 0;
    _repackButton ctrlSetText "\A3\ui_f\data\IGUI\Cfg\Actions\reload_ca.paa";
    _repackButton ctrlSetTooltip "Przepakuj magazynki";

    _repackButton ctrlAddEventHandler ["ButtonClick", {
        private _button = _this param [0, controlNull, [controlNull]];
        private _display = ctrlParent _button;
        _display closeDisplay 2;
        [] call ULP_fnc_repackAmmo;
    }];
}] call ULP_fnc_waitUntilExecute;