/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_issueWarrant";

if (canSuspend) exitWith {
    [ULP_fnc_issueWarrant, _this] call ULP_fnc_directCall;
};

_this params [
	["_ctrl", controlNull, [controlNull]]
];

private _display = ctrlParent _ctrl;
if (isNull _display || { !([player, ["Police"]] call ULP_fnc_isFaction) }) exitWith {};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), ["Civilian"], [_display], {
	_this params [
		["_pnc", displayNull, [displayNull]],
		["_display", displayNull, [displayNull]]
	];

	if (isNull _display) exitWith {};

	private _list = _display displayCtrl 3809;
	private _unit = (_list tvData (tvCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _unit) exitWith {
		["Nie wybrałeś nikogo, do kogo mógłbyś przenieść!"] call fini_fnc_noty;
	};

	[0.01, [_pnc, _unit], {
		[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), _this, {
			_this params [
				["_pnc", displayNull, [displayNull]],
				["_unit", objNull, [objNull]],
				["_display", displayNull, [displayNull]],
				["_note", "", [""]],
				["_type", "", [""]]
			];

			if (isNull _unit) exitWith {};

			private _length = count _note;
			private _max = getNumber (missionConfigFile >> "CfgWarrants" >> "NoteLength");

			if (_length < 0 || { _length > _max }) exitWith {
				[format ["Notatka nie może być dłuższa niż %1 znaków...", [_max] call ULP_fnc_numberText]] call fini_fnc_noty;
			};

			private _params = [getPlayerUID _unit];
			_params append (parseSimpleArray _type);
			_params append [_note, name player];

			_params remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];

			if !(isNull _pnc) then {
				_pnc setVariable ["warrant_steam_id", nil];
				_pnc setVariable ["act_cfg_name", nil];
				_pnc setVariable ["crime_cfg_name", nil];
				_pnc setVariable ["selected_crime_id", nil];

				private _group = _pnc displayCtrl 4703;

				tvClear (_group controlsGroupCtrl 102);
				lnbClear (_group controlsGroupCtrl 106);
				(_group controlsGroupCtrl 107) ctrlSetText "";
				
				[0.1, [], { [] remoteExecCall ["ULP_SRV_fnc_fetchWarrants", RSERV]; }] call ULP_fnc_waitExecute;
			};

			[format ["Wydałeś lub zmieniłeś nakaz dotyczący <t color='#B92DE0'>%1</t>...", name _unit]] call fini_fnc_noty;
			["IssueWarrant"] call ULP_fnc_achieve;
		}] call ULP_fnc_inputWarrantInfo;
	}] call ULP_fnc_waitExecute;
}, true, false] call ULP_fnc_selectPlayer;