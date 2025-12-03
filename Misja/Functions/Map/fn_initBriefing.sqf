/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initBriefing";

if (isServer) exitWith {};

waitUntil { !isNull player && { local player } };

player createDiarySubject ["controls", "Sterowanie"];

player createDiaryRecord ["controls", ["Pojazd", "<br />
	<font face='PuristaSemiBold'>Zamknij Drzwi / Pojazd</font><br />
	Key: <font color='#B92DE0'>U</font><br /><br />
	<font face='PuristaSemiBold'>Sygnały świetlne</font><br />
	Key: <font color='#B92DE0'>Lewy Shift + F</font><br /><br />
	<font face='PuristaSemiBold'>Sygnały dzwiękowe</font><br />
	Key: <font color='#B92DE0'>Lewy Control + F</font><br /><br />
	<font face='PuristaSemiBold'>Światła</font><br />
	Key: <font color='#B92DE0'>Lewy Shift + L</font><br /><br />
	<font face='PuristaSemiBold'>Pasy</font><br />
	Key: <font color='#B92DE0'>Num /</font> or <font color='#B92DE0'>Custom Controls > User Action 1</font>
	"], taskNull, "NONE", false];

player createDiaryRecord ["controls", ["Ogólne", "<br />
	<font face='PuristaSemiBold'>Ogólna interakcja</font><br />
	Key: <font color='#B92DE0'>Lewy Windows</font> lub <font color='#B92DE0'>Custom Controls > User Action 10</font><br /><br />
	<font face='PuristaSemiBold'>Zatyczki</font><br />
    Key: <font color='#B92DE0'>Shift + O</font><br /><br />
	<font face='PuristaSemiBold'>Tablet</font><br />
	Key: <font color='#B92DE0'>Y</font><br /><br />
	<font face='PuristaSemiBold'>Bagażniki / Schowki</font><br />
	Key: <font color='#B92DE0'>T</font><br /><br />
	<font face='PuristaSemiBold'>Poddaj się</font><br />
	Key: <font color='#B92DE0'>Left Shift + 6</font><br /><br />
	<font face='PuristaSemiBold'>Animacje</font><br />
	Key: <font color='#B92DE0'>9</font><br /><br />
	<font face='PuristaSemiBold'>EMP (dla policji)</font><br />
	Key: <font color='#B92DE0'>K</font><br /><br />
	<font face='PuristaSemiBold'>Schowaj broń</font><br />
	Key: <font color='#B92DE0'>Left Shift + H</font><br /><br />
	<font face='PuristaSemiBold'>Powal kogoś</font><br />
	Key: <font color='#B92DE0'>Left Shift + G</font><br /><br />
	<font face='PuristaSemiBold'>Otwórz najbliższą bramę</font><br />
	Key: <font color='#B92DE0'>P</font><br /><br />
	<font face='PuristaSemiBold'>Panic Button</font><br />
	Key: <font color='#B92DE0'>Left Shift + J</font>"], taskNull, "NONE", false];

player createDiarySubject ["wiki", "Wiki"];

private _licenses = configProperties [missionConfigFile >> "CfgLicenses", "isClass _x && { isText (_x >> ""displayName"") } && { getNumber (_x >> ""buyPrice"") > 0 }", true] apply {
	format [
		"<font face='PuristaSemiBold'>%1</font><br/><font color='#B92DE0'>$%2</font>", getText (_x >> "displayName"), [getNumber (_x >> "buyPrice")] call ULP_fnc_numberText]
};

player createDiaryRecord ["wiki", ["Licencje", format ["<br />%1", _licenses joinString "<br/>"]], taskNull, "NONE", false];

(getArray (missionConfigFile >> "CfgBases" >> "Restart")) params [ "_start", "_end" ];

private _bidIncrement = getNumber (missionConfigFile >> "CfgBases" >> "BidIncrement");
private _startingBid = getNumber (missionConfigFile >> "CfgBases" >> "StartingBid");
private _initialBid = _startingBid + _bidIncrement;

player createDiaryRecord ["wiki", ["Wojny gangów", format["Wojny Gangów odbywają się co tydzień w <font color='#B92DE0'>%1</font> pomiędzy <font color='#B92DE0'>%2</font> a <font color='#B92DE0'>%3</font>. Aby wziąć udział, musisz należeć do grupy, nie ma ograniczeń co do rodzaju grupy. Celem jest przejęcie centralnej flagi znajdującej się na środku każdej bazy gangu, która służy do licytacji.<br /><br />Licytacja rozpoczyna się od <font color='#B92DE0'>$%4</font>, a minimalne podbicie wynosi <font color='#B92DE0'>$%5</font>. Pieniądze na licytację pobierane są z funduszy grupy, a Waszym zadaniem jest przelicytowanie i uniemożliwienie innym grupom złożenia wyższych ofert, aby przejąć kontrolę nad bazą.<br /><br />Wygranie licytacji zapewnia Twojej grupie pełny dostęp do niemal całego nielegalnego sprzętu dostępnego na wyspie, a także punkt odrodzenia do następnej wojny gangów. Baza staje się twierdzą Twojego gangu, zapewniając zasoby i przewagę strategiczną na czas trwania Waszych rządów.",
	getText(missionConfigFile >> "CfgBases" >> "Day"), _start, _end, [_initialBid] call ULP_fnc_numberText, [_bidIncrement] call ULP_fnc_numberText]], taskNull, "NONE", false];

player createDiarySubject ["majorcrimes", "Napady"];

{
	private _crimeStages = configProperties [_x >> "Stages", "isClass _x && { isText (_x >> ""description"") }", true] apply {
		format ["<font face='PuristaSemiBold'>%1</font><br/>%2", getText (_x >> "displayName"), getText (_x >> "description")]
	};

	player createDiaryRecord ["majorcrimes", [getText(_x >> "title"), format [
		"<br />%1<br /><br /><font size='15' face='PuristaSemiBold'>Stages</font><br /><br />%2", 
		getText (_x >> "description"),
		_crimeStages joinString "<br/>"]], taskNull, "NONE", false];
} forEach ("isClass _x && { isText (_x >> ""description"") }" configClasses (missionConfigFile >> "CfgCrimes" >> worldName));

player createDiarySubject ["serverinfo", "Serwerowe"];

player createDiaryRecord ["serverinfo", ["Linki", "<br />
	<font face='PuristaSemiBold'>Strona</font><br />
	Link: <font color='#B92DE0'>https://stanlakeside.pl/</font><br /><br />
	<font face='PuristaSemiBold'>Discord</font><br />
	Link: <font color='#B92DE0'>https://discord.gg/DAgR3c5D8V</font>"], taskNull, "NONE", false];
