/*
	author: bartoszewski
	description: none
	returns: nothing
*/

private["_object"];
_object = _this select 0; // Pobieramy obiekt (gracza) z argumentu

// Zbieramy wszystkich graczy w frakcji Independent
_independentPlayers = allPlayers select {side _x == independent};

// Sprawdzamy odległość do każdego gracza z frakcji Independent
_distances = [];
{
    _distances pushBack (getPos _object distance getPos _x);
} forEach _independentPlayers;

// Zwracamy najmniejszą odległość
if (count _distances > 0) then {
    _distances call BIS_fnc_sort; // Sortujemy rosnąco
    _distances select 0; // Zwracamy najmniejszą odległość
} else {
    "Brak medyków"; // Zwracamy dużą wartość, jeśli nie ma graczy w frakcji Independent
};