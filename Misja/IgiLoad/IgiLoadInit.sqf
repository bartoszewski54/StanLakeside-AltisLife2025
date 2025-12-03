waitUntil {!isNil "bis_fnc_init"};

waitUntil {time > 0};

IL_EV_Count = 0;
IL_Veh_Array = [];

systemChat "IgiLoad jest wczytywany. Proszę czekać...";
sleep (random 30);

systemChat format ["IgiLoad wczytuje: %1", player];

_null = [player] execVM "IgiLoad\IgiLoad.sqf";
waitUntil {scriptDone _null};

sleep (random (IL_Check_Veh_Max - IL_Check_Veh_Min));

{
    if ((typeOf _x) in (IL_Supported_Vehicles_All)) then {
        IL_Veh_Array = IL_Veh_Array + [_x];
        _null = [_x] execVM "IgiLoad\IgiLoad.sqf";
        waitUntil {scriptDone _null};
    };
} forEach (vehicles);

systemChat "IgiLoad wczytany. :)";

while {true} do {
    sleep (IL_Check_Veh_Min + (random (IL_Check_Veh_Max - IL_Check_Veh_Min)));

    // Usuwanie pojazdów z "IL_Veh_Array" jeśli nie są już w "vehicles"
    {
        if !(_x in vehicles) then {
            IL_Veh_Array = IL_Veh_Array - [_x];
        };
    } forEach (IL_Veh_Array);

    {
        if (((typeOf _x) in (IL_Supported_Vehicles_All)) && !(_x in IL_Veh_Array)) then {
            IL_Veh_Array = IL_Veh_Array + [_x];
            _null = [_x] execVM "IgiLoad\IgiLoad.sqf";
            waitUntil {scriptDone _null};
        };
    } forEach (vehicles);
};
