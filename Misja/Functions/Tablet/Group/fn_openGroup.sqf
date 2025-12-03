/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_openGroup";

if !(isClass (missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction >> "Groups")) exitWith {
	["Nie masz do tego dostępu!"] call fini_fnc_noty;
};

if (ULP_Group_Creating) exitWith {
	["Obecnie nie można uzyskać dostępu do tej aplikacji, ponieważ przetwarza ona poprzednie żądanie utworzenia!"] call fini_fnc_noty;
};

if ([] call ULP_fnc_isGroup) then {
	["Group"] call ULP_fnc_setScreen;
} else {
	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [], [],
		{
			scopeName "fn_creationCheck";

			_this params [
				["_display", displayNull, [displayNull]],
				["_tagText", "", [""]],
				["_nameText", "", [""]],
				["_type", "", [""]]
			];
			
			private _cfg = missionConfigFile >> "CfgGroups";
			if !(isClass (_cfg >> "Types" >> _type)) exitWith {
				["Wybrany typ grupy nie istnieje!"] call fini_fnc_noty;
			};

			{
				_x params ["_text", "_cfgSettings"];

				private _min = getNumber (_cfgSettings >> "MinLength");
				private _max = getNumber (_cfgSettings >> "MaxLength");
				private _length = count _text;

				switch (true) do {
					case (_length < _min): {
						[format["Długość %1 musi wynosić <t color='#B92DE0'>%2 lub więcej</t>!", configName _cfgSettings, _min]] call fini_fnc_noty;
						false breakOut "fn_creationCheck";
					};
					case (_length > _max): {
						[format["Długość %1 musi być <t color='#B92DE0'>%2 lub krótsza</t>!", configName _cfgSettings, _max]] call fini_fnc_noty;
						false breakOut "fn_creationCheck";
					};
					case (_text in getArray (_cfgSettings >> "Blacklisted")): {
						[format["%1 jest <t color='#B92DE0'>zablokowana</t> i nie może być użyta!", configName _cfgSettings]] call fini_fnc_noty;
						false breakOut "fn_creationCheck";
					};
				};
			} forEach [
				[_tagText, _cfg >> "Tag"],
				[_nameText, _cfg >> "Name"]
			];

			ULP_Group_Creating = true;

			[player, _tagText, _nameText, _type] remoteExecCall ["ULP_SRV_fnc_createGroup", RSERV];
			true
		}
	] call ULP_fnc_inputGroupInfo;
};