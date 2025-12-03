/*
    BLAH
    BLAH
*/
_clear = nearestObjects [player,["weaponholder"],5];
_clear = _clear + nearestObjects [player,["GroundWeaponHolder"],5];
_clear = _clear + nearestObjects [player,["WeaponHolderSimulated"],5];
_destroyed = 0;
for "_i" from 0 to count _clear - 1
do
{
    _destroyed = _destroyed + 1;
    deleteVehicle (_clear select _i);
};

titleText[format["Usunieto %1 obiektow z ziemi.", _destroyed],"PLAIN"];