params["_textPosRef", "_ctrlProgressPosRef"];

private _textPos = +_textPosRef;
private _ctrlProgressPos = +_ctrlProgressPosRef;

private _posText = _textPos # 1;
private _textHigh = _textPos # 3;

if (isNil "Fini_Notifications") exitWith {Fini_Notifications = [];};
if (Fini_Notifications isEqualTo []) exitWith {};

private _activeNotifications = 0;
{ 
	_x params ["_ctrlText", "_ctrlProgress"];

	if (!isNull _ctrlProgress && { !isNull _ctrlText }) then {

		private _height = (_textHigh + 1.5 * 0.011 * safezoneH);

		_textPos set [1, _posText + _height];
		_textPos set [3, (ctrlTextHeight _ctrlText) + (0.004 * safezoneH)];
		
		_ctrlText ctrlSetPosition _textPos;

		_ctrlProgressPos set [1, (_posText + _height + (ctrlTextHeight _ctrlText))];
		_ctrlProgress ctrlSetPosition _ctrlProgressPos;
		
		_ctrlText ctrlCommit 0.25;
		_ctrlProgress ctrlCommit 0.25;

		_posText = (_posText + _textHigh + 1.5*(0.011 * safezoneH));

		_textHigh = (ctrlPosition _ctrlText) # 3;
		if (_activeNotifications > 3) then {
			_ctrlText ctrlSetFade 1;
			_ctrlProgress ctrlSetFade 1;
			_ctrlText ctrlCommit 0.2;
			_ctrlProgress ctrlCommit 0.2;

			_ctrlProgress setVariable ["faded", true];
		}; 
		_activeNotifications = _activeNotifications + 1;
	} else {
		Fini_Notifications deleteAt _forEachIndex; 
	};
} forEach Fini_Notifications;

