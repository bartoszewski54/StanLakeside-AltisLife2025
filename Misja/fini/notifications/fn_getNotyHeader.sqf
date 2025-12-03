params [["_text", ""], ["_header", ""], ["_type", ""], ["_use", false]];

if (_header isEqualType true) then {
	_use = _header;
	_header = _type;
} else {
	_use = count _header > 0;
};

if (_use) exitWith {
	parseText format ["<t font='RobotoCondensedBold'>%1</t><br/><t>%2</t>",_header,_text];
};
parseText _text;