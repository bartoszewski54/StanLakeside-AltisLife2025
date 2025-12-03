params [["_text",""],["_header",false,[false, ""]],["_type","Notification",[""]]];

if !(hasInterface) exitWith {}; 

(call {
	private _conf = (missionConfigFile / "FiniNotifications" / "Types");
	private _notyClass = (_conf / _type);

	if !(isClass _notyClass) exitWith {
		_type = "Notification";
		[
			[0.016,0.184,0.239,1],
			[0.043,0.325,0.42,1],
			4
		];
	};

	_type = configName _notyClass;
	[
		getArray (_notyClass / "ProgressColor"),
		getArray (_notyClass / "BackgroundColor"),
		getNumber (_notyClass / "Time")
	];
}) params ["_ctrlProgressColor", "_ctrlBgColor", "_time"];

if (isClass (missionConfigFile / "CfgSounds" / "fini_notification")) then {
	playSound "fini_notification";
};

disableSerialization;
private _display = findDisplay 46;

private _ctrlText = _display ctrlCreate ["RscStructuredText", -1]; 
private _ctrlProgress = _display ctrlCreate ["RscProgress", -1]; 

private _textWidth = 0.2 * safezoneW; 

_ctrlText ctrlSetStructuredText ([_text, _header, _type] call fini_fnc_getNotyHeader);
_ctrlText ctrlSetPosition [0, 0, _textWidth, 0]; 
_ctrlText ctrlCommit 0;


private _textHeight = ctrlTextHeight _ctrlText; 
private _offScreenPos = [safezoneW + safezoneX, 0.171 * safezoneH + safezoneY, _textWidth, _textHeight + (0.004 * safezoneH)]; 
private _ctrlProgressPos = [0.795 * safezoneW + safezoneX, 0.1715 * safezoneH + safezoneY + _textHeight, _textWidth, 0.004 * safezoneH]; 

_ctrlProgress ctrlSetPosition _ctrlProgressPos;
_ctrlProgress ctrlSetTextColor _ctrlProgressColor;
_ctrlProgress ctrlSetFade 1;
_ctrlProgress ctrlCommit 0;

private _finalPos = +_offScreenPos;

_finalPos set [0, 0.795 * safezoneW + safezoneX];

_ctrlText ctrlSetPosition _offScreenPos;

[_finalPos, _ctrlProgressPos] call fini_fnc_moveNoty;
Fini_Notifications = [[_ctrlText,_ctrlProgress]] + Fini_Notifications;

_ctrlText ctrlSetBackgroundColor _ctrlBgColor;
_ctrlText ctrlSetFade 1;
_ctrlText ctrlCommit 0;

_ctrlText ctrlSetPosition _finalPos;
_ctrlText ctrlSetFade 0;
_ctrlText ctrlCommit 0.4;

[_ctrlText,_ctrlProgress, _time] spawn fini_fnc_doNotyProgress;