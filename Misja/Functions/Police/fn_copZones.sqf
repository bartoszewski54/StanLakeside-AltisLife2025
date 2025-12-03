/*
	File: fn_copZones.sqf
	Author: Hank
	Description: Policyjne strefy
	[[player], "life_fnc_restrain", _unit, false] call life_fnc_MP;

*/
//Error Checks
if (playerSide != west) exitWith {hint "Musisz być policjantem!"};  //cops only
_markernumber =  [_this, 0, 0] call BIS_fnc_param;
_close = [_this, 1, false] call BIS_fnc_param;
_promien = [_this, 2, 300] call BIS_fnc_param;
_type = [_this, 3, 0] call BIS_fnc_param;
if(_markernumber == 0) exitWith {hint "Brak numerku markera";};
if(_close) exitWith {
_markername1 = "Restricted_Area"+ str _markernumber;
_markername2 = "Restricted_Area"+ str _markernumber + "b";
systemChat format["Usuwam: %1",_markername1];
systemChat format["Usuwam: %1",_markername2];
deleteMarker _markername1;
deleteMarker _markername2;
_msg = "Akcja policji została zakończona a strefa została ponownie otwarta!";
[_msg, "Strefa otwarta", "Strefa"] remoteExec ["fini_fnc_noty", 0];
_at = life_placedmarkers find str _markernumber;
life_placedmarkers deleteAt _at;
};
closeDialog 0;
Marker={
	_pos = [_this select 0, _this select 1, _this select 2];
	_markernumber =  [_this, 3] call BIS_fnc_param;
	_promien =  [_this, 4] call BIS_fnc_param;
	_type =  [_this, 5] call BIS_fnc_param;
	_markername1 = "Restricted_Area"+ str _markernumber;
	_markername2 = "Restricted_Area"+ str _markernumber + "b";

	_marker = createMarker [_markername1, [(_pos select 0), (_pos select 1), 0]];
	_marker setMarkerShape "ELLIPSE";

	systemChat format["%1", _promien];
	_marker setMarkerSize [_promien, _promien];
	_marker setMarkerBrush "SOLID";
	_marker setMarkerColor "ColorWEST";
	if (_type == 1) then {
		_marker setMarkerBrush "Grid";
	};
	_marker2 = createMarker [_markername2, [(_pos select 0), (_pos select 1), 0]];
	_marker2 setMarkerColor "ColorBlack";
	_marker2 setMarkerType "mil_warning";
	_marker2 setMarkerShape "ICON";
	_marker2 setMarkerSize [1,1];
	if (_type == 1) then {
	_marker2 setMarkerText "Punkt kontrolny otwarty!";
	} else {
	_marker2 setMarkerText "Strefa " + str _markernumber + " Zamknięta!";
	};

	onMapSingleClick "";
	openMap [false, false];
	life_placedmarkers pushBack (str _markernumber);
if (_type == 1) then {
    _msg = "Policja utworzyła Punkt Kontrolny! Na terenie tego punktu obowiązuje zakaz strzelania!";
    // Wyświetlenie komunikatu wszystkim graczom
    [_msg, "Punkt Kontrolny", "Strefa"] remoteExec ["fini_fnc_noty", 0]; // 0 oznacza, że wykonanie ma być globalne
} else {
    _msg = "Policja zamknęła strefę. Wszyscy cywile znajdujący się w jej obszarze mają natychmiast schować broń i stanąć z rękami założonymi za głowę aż do przybycia policji, w przeciwnym razie zostaną zastrzeleni!";
    // Wyświetlenie komunikatu wszystkim graczom
    [_msg, "Strefa zamknięta", "Strefa"] remoteExec ["fini_fnc_noty", 0];
};
};

openMap [true, false];
["Kliknij w punkt na mapie na którym ma się znaleźć środek tworzonej strefy"] call fini_fnc_noty;
[_markernumber,_promien,_type] onMapSingleClick "[_pos select 0, _pos select 1, _pos select 2, _this select 0, _this select 1,_this select 2] spawn Marker";
