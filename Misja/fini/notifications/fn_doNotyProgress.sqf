params ["_ctrlText", "_ctrlProgress", "_time"];
disableSerialization;

waitUntil {ctrlCommitted _ctrlText};

if !(_ctrlProgress getVariable ["faded", false]) then {
	_ctrlProgress ctrlSetFade 0;
	_ctrlProgress ctrlCommit 0.4;
};

_ctrlProgress progressSetPosition 1;
private _timeStart = time;

while {true} do {
	private _timeUsed = time - _timeStart;
	private _percentage = _timeUsed / _time;
	_ctrlProgress progressSetPosition (1 - _percentage);
	uiSleep 0.008;
	if (progressPosition _ctrlProgress <= 0) exitWith {};
}; 

_ctrlText ctrlSetFade 1;
_ctrlText ctrlCommit 0.3;
_ctrlProgress ctrlSetFade 1;
_ctrlProgress ctrlCommit 0.3;
uiSleep 0.3;
ctrlDelete _ctrlProgress;
ctrlDelete _ctrlText;