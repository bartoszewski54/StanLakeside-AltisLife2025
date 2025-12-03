/*
** Author: Jack "Scarso" Farhall
** Description: Kliencki skrypt obsługujący wrak statku
*/

#include "..\..\script_macros.hpp"
scopeName "fn_onShipwreckSpawn";

_this params [
    ["_shipwreck", objNull, [objNull]],  // Obiekt wraku
    ["_message", "", [""]]              // Wiadomość wyświetlana graczowi
];

if (isNull _shipwreck) exitWith {}; // Jeśli nie ma wraku, zakończ skrypt

// Wyświetlenie wiadomości
[_message] call fini_fnc_noty;

// Dodanie akcji do wraku statku
_shipwreck addAction [
    "Zbierz łup", { // Nazwa akcji
        _this params [ "_shipwreck", "", "_actionId" ];

        // Rozpoczęcie procesu claimowania
        ["Przejmowanie statku", 30, [_shipwreck, _actionId], { true }, {
            _this params [ "_shipwreck", "_actionId" ];

            _shipwreck removeAction _actionId; // Usunięcie akcji
            ["Zbierasz łup ze statku..."] call fini_fnc_noty;

            // Wywołanie serwerowego skryptu obsługującego looting
            [player, _shipwreck] remoteExecCall ["ULP_SRV_fnc_claimShipwreck", RSERV];
        }, {}] call ULP_UI_fnc_startProgress;
    },
    nil,    // Argumenty do akcji
    8,      // Odległość interakcji
    true,   // Warunek widoczności
    true,   // Warunek aktywności
    "",     // Kod do sprawdzania warunku
    "true", // Warunek dostępności
    20      // Czas interakcji
];
