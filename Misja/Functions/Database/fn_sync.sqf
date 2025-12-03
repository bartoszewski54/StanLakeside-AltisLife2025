/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_sync";

if ([player] call ULP_fnc_onDuty) exitWith {
	["Nie możesz zrobić synchronizacji jako Administrator na służbie!"] call fini_fnc_noty;
};

if (time <= (ULP_Last_Sync + getNumber(missionConfigFile >> "CfgSettings" >> "sync_delay"))) exitWith {
	["Twoje dane zostały niedawno zsynchronizowane, odczekaj chwilę..."] call fini_fnc_noty;
};

[] call ULP_fnc_syncPlayerInfo;
ULP_Last_Sync = time;

["Synchronizowanie danych, poczekaj do <t color='#B92DE0'>20 sekund</t> przed wyjściem..."] call fini_fnc_noty;