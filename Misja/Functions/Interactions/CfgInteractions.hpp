class CfgInteractions {
	class Money {
		class Pickup {
			title = "Podnieś gotówkę";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_pickupMoney";
			condition = "(_this getVariable [""ULP_MoneyStack"", 0]) > 0";
		};
		class Burn : Pickup {
			title = "Spal pieniądze";
			onClick = "deleteVehicle (_this select 0)";
			condition = "(_this getVariable [""ULP_MoneyStack"", 0]) > 0 && { (([""Lighter""] call ULP_fnc_hasItem) > 0) }";
		};
	};

	class Placeable {
		class Remove {
			title = "Usuń obiekty";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_removeObject; closeDialog 0;";
			condition = "isNull (_this getVariable [""unitDragging"", objNull]) && { [player, [""Police"", ""Medic"", ""Hato""]] call ULP_fnc_isFaction || { [] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""RemovePlaceable"", false] call ULP_fnc_checkPower } } }";
		};
		class Drag {
			title = "Przenieś obiekt";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "[_this select 0, ""Stretcher""] call ULP_fnc_dragPlaceable; closeDialog 0;";
			condition = "_this isKindOf ""Land_Stretcher_01_F"" && { isNull (_this getVariable [""unitDragging"", objNull]) } && { [player, [""Police"", ""Medic"", ""Hato""]] call ULP_fnc_isFaction || { [] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""RemovePlaceable"", false] call ULP_fnc_checkPower } } }";
		};
	};

	class Person {
		class GiveKeys {
			title = "Daj klucze";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_giveVehicleKeys";
			condition = "!([player] call ULP_fnc_isRestrained)";
		};
		class GiveCash : GiveKeys {
			title = "Daj gotówkę";
			onClick = "if ([_this select 0] call ULP_fnc_giveMoney) then { closeDialog 0; };";
		};
		class GiveItems : GiveKeys {
			title = "Daj przedmioty";
			onClick = "_this call ULP_fnc_giveVirtualItems";
		};
		class ShowLicenses : GiveKeys {
			title = "Pokaż licencje";
			onClick = "private _unit = _this select 0; if (isNull _unit) exitWith {}; if (time < (_unit getVariable [""licenses_shown"", 0])) exitWith { [""Ostatnio pokazywałeś tej osobie swoje licencje, poczekaj przed ponowną próbą...""] call fini_fnc_noty; }; _unit setVariable [""licenses_shown"", time + 5]; [""LicensesShown"", [player, ULP_Licenses, true]] remoteExecCall [""ULP_fnc_invokeEvent"", _unit]; [format [""Pokazałeś %1 swoje licencje..."", [_unit, true] call ULP_fnc_getName]] call fini_fnc_noty;";
		};

		class RobCash {
			title = "Okradnij";
			factions[] = { "Medic", "Hato", "Civilian" };
			onClick = "[0, _this] call ULP_fnc_robMoney; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isKnocked || { [_this] call ULP_fnc_isSurrendered } || { [_this] call ULP_fnc_isRestrained && (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) }";
		};

		class Unrestrain : GiveKeys {
			title = "Odkuj";
			onClick = "[_this select 0, player, false] call ULP_fnc_restrain; closeDialog 0;";
            condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || { [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup } || { [player] call ULP_fnc_onDuty } }";
		};
		class Escort : Unrestrain {
			title = "Eskortuj";
			onClick = "[_this select 0, player, true] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || { [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup } || { [player] call ULP_fnc_onDuty } } && { !([_this] call ULP_fnc_isEscorted) }";
		};
		class StopEscort : Unrestrain {
			title = "Anuluj eskortowanie";
			onClick = "[_this select 0, player, false] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || { [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup } || { [player] call ULP_fnc_onDuty } } && { [_this] call ULP_fnc_isEscorted }";
		};
		class Blindfold : Unrestrain {
			title = "Załóż opaskę na oczy";
			onClick = "_this call ULP_fnc_blindfold";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || { [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup } || { [player] call ULP_fnc_onDuty } } && { ([""Blindfold""] call ULP_fnc_hasItem) > 0 } && { !(_this getVariable [""blindfold"", false]) }";
		};
		class Unblindfold : Blindfold {
			title = "Usuń opaskę na oczy";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || { [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup } || { [player] call ULP_fnc_onDuty } } && { _this getVariable [""blindfold"", false] }";
		};
		class CountCash : Unrestrain {
			title = "Sprawdź pieniądze";
			onClick = "[0, _this] call ULP_fnc_checkMoney;";
		};
		class SeizeCash : RobCash {
			title = "Konfiskuj pieniądze";
			factions[] = { "Police" };
		};
		class InventoryCheck : Unrestrain {
			title = "Przeszukaj";
			onClick = "player action [""Gear"", cursorObject]; closeDialog 0;";
		};
		class LicenseCheck : Unrestrain {
			title = "Sprawdź Licencje";
			factions[] = { "Police" };
			onClick = "private _unit = _this select 0; if (isNull _unit) exitWith {}; if (_unit getVariable [""licenses_requested"", false]) exitWith { [""You've already requested this person's licenses...""] call fini_fnc_noty; }; _unit setVariable [""licenses_requested"", true]; [""RequestLicenses"", [player]] remoteExecCall [""ULP_fnc_invokeEvent"", _unit]; if !([_unit] call ULP_fnc_isRestrained) then { [format [""You have requested %1's licenses..."", [_unit, true] call ULP_fnc_getName]] call fini_fnc_noty; };";
		};
		class LicenseRequest : LicenseCheck {
			title = "Sprawdź licencje";
			condition = "!([_this] call ULP_fnc_isRestrained)";
		};
		class Ticket {
			title = "Wystaw mandat";
			factions[] = { "Police" };
			onClick = "_this call ULP_fnc_issueTicket;";
			condition = "true";
		};
		class Imprision : Unrestrain {
			title = "Wsadź do więzienia";
			onClick = "_this call ULP_fnc_setPrisonTime; closeDialog 0;";
			condition = "[player] call ULP_fnc_canImprison && { [_this] call ULP_fnc_canImprisoned }";
		};

		// Admin Commands...
		class AdminHeal {
			title = "Admin Heal";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "(_this select 0) setDamage 0; [format[""Uleczyłeś gracza jako admin...""]] call fini_fnc_noty; [getPlayerUID player, ""Admin"", [""AdminHeal"", serverTime, [name (_this select 0)]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2]; closeDialog 0;";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { (damage _this) > 0 } && { [""Medical"", false] call ULP_fnc_checkPower }";
		};
	};

	class PersonMedical {
		class Revive {
			title = "Monitor medyczny";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_openMedical";
			condition = "true";
		};
		class PutOnStretcher {
			title = "Wrzuć na nosze";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_toggleOnStretcher; closeDialog 0;";
			condition = "private _stretcher = [_this] call ULP_fnc_nearestStretcher; !isNull (_stretcher) && { (animationState _this) in [""unconsciousrevivedefault"", ""deadstate""] } && { isNull (_stretcher getVariable [""unitAttached"", objNull]) }";
		};
		class TakeOffStretcher : PutOnStretcher {
			title = "Zdejmij z noszy";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_toggleOnStretcher; closeDialog 0;";
			condition = "private _stretcher = attachedTo _this; !isNull _stretcher && { _stretcher isKindOf ""Land_Stretcher_01_F"" }";
		};
		class PutInNearbyVehicle : TakeOffStretcher {
			title = "Wrzuć do auta";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "private _vehicle = (nearestObjects[_this param [0, player, [objNull]], [""Car""], 5]) param [0, objNull]; if (isNull _vehicle || { !(_vehicle in ULP_Keys) }) exitWith { [""Musisz mieć klucze do pojazdu, do którego chcesz wrzucić tą osobę...""] call fini_fnc_noty; }; if !(((fullCrew _vehicle) findIf { isNull (_x param [0, objNull]) }) isEqualTo -1) exitWith { [""Ten pojazd nie ma miejsca!""] call fini_fnc_noty; }; if (_this call ULP_fnc_toggleOnStretcher) then { [_vehicle, _this select 0] remoteExecCall [""ULP_fnc_putVehicleUnit"", _this select 0]; [format [""Wrzuciłeś %1 do pojazdu..."", [_this select 0, true] call ULP_fnc_getName]] call fini_fnc_noty; }; closeDialog 0;";
		};
		class AdministerBlood : Revive {
			title = "Podaj krew";
			onClick = "_this call ULP_fnc_administerBlood";
			condition = "(0 max ([""BloodBag""] call ULP_fnc_hasItem)) > 0";
		};

		// Admin Commands...
		class AdminRevive : Revive {
			title = "Admin Revive";
			onClick = "[player] remoteExecCall [""ULP_fnc_revived"", _this select 0]; (_this select 0) setDamage 0; [format[""Zrevivowales gracza...""]] call fini_fnc_noty; [getPlayerUID player, ""Admin"", [""AdminRevive"", serverTime, [name (_this select 0)]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2]; closeDialog 0;";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Medical"", false] call ULP_fnc_checkPower }";
		};
	};

	class PersonEscortOnly {
		class StopEscort {
			title = "Przestań Eskortować";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "[_this select 0, player, false] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [_this] call ULP_fnc_isEscorted }";
		};
		class PutInVehicle : StopEscort {
			title = "Wrzuć do auta";
			onClick = "private _vehicle = cursorObject; if (isNull _vehicle || { !((((typeOf _vehicle) call BIS_fnc_objectType) param [1, """"]) in [""Car"", ""Helicopter"", ""Plane"", ""Ship""]) }) exitWith { [""Musisz zabrać zakutego do pojazdu, aby go do niego włożyć...""] call fini_fnc_noty; }; if !(((fullCrew _vehicle) findIf { isNull (_x param [0, objNull]) }) isEqualTo -1) exitWith { [""Ten pojazd jest pełny...""] call fini_fnc_noty; }; [_this select 0, player, false] call ULP_fnc_escort; [_vehicle, _this select 0] remoteExecCall [""ULP_fnc_putVehicleUnit"", _this select 0]; closeDialog 0; [format [""Umieściłeś %1 w pojeździe..."", [_this select 0, true] call ULP_fnc_getName]] call fini_fnc_noty;";
		};
	};

	class House {
		class BuyHouse {
			title = "Kup Dom";
			factions[] = { "Civilian" };
			onClick = "_this call ULP_fnc_buyHouse;";
			condition = "isClass (missionConfigFile >> ""CfgFactions"" >> [player] call ULP_fnc_getFaction >> ""Housing"") && { !([_this] call ULP_fnc_isHouseOwned) } && { !(_this getVariable [""blacklisted"", false]) }";
		};
	};

	class HouseOwner {
		class SellHouse {
			title = "Sprzedaj Dom";
			factions[] = { "Civilian" };
			onClick = "_this call ULP_fnc_sellHouse;";
			condition = "[_this, player, false] call ULP_fnc_isHouseOwner";
		};
	};

	class HouseStorage {
		class OpenStorage {
			title = "Otwórz schowek";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "if ((missionNamespace getVariable [""ULP_HouseStorageEvent"", -1]) > -1) exitWith { [""Czekaj..""] call fini_fnc_noty; }; ULP_HouseStorageEvent = [""HouseStorage"", { _this params [ ""_house"", ""_storage"" ]; ULP_HouseStorageEvent = nil; if (isNull _house || { (player distance _house) > 15 }) exitWith { [""Jesteś zbyt daleko od domu, aby uzyskać dostęp do fizycznego magazynu...""] call fini_fnc_noty; }; if (isNull _storage) exitWith { [""Ten dom nie ma fizycznego magazynu...""] call fini_fnc_noty; }; player action [""gear"", _storage]; }, true] call ULP_fnc_addEventHandler; [(_this select 0) getVariable [""building"", objNull]] remoteExecCall [""ULP_SRV_fnc_getStorage"", 2]; [""Otwieranie..""] call fini_fnc_noty; closeDialog 0;";
			condition = "[_this getVariable [""building"", objNull], player, false] call ULP_fnc_isHouseOwner && { (player distance _this) <= 2 }";
		};
	};

	class EquipmentBox {
		class ClearBox {
			title = "Wyczyść cargo";
			factions[] = { "Police" };
			onClick = "_this call ULP_fnc_clearCargo;";
			condition = "true";
		};
		
		class ResetLoadout {
			title = "Resetuj Ubrania";
			factions[] = { "Police", "Medic", "Hato" };
			onClick = "[] call ULP_fnc_setLoadout;";
			condition = "[[player] call ULP_fnc_getFaction] call ULP_fnc_canResetLoadout;";
		};
	};

	class Konfiskata {
		class Ziemia {
			title = "Skonfiskuj itemy z ziemi";
			factions[] = { "Police" };
			onClick = "_this call ULP_fnc_seizeItems;";
			condition = "true";
		};
	};

	class Vault {
		class Repair {
			title = "Napraw Sejf";
			factions[] = { "Police" };
			onClick = "closeDialog 0; [""Naprawianie zamka..."", 60, _this, { (player distance (_this select 0)) <= 5 }, { private _object = _this select 0; [""Pomyślnie naprawiono zamek!""] call fini_fnc_noty; _object setVariable [""locked"", true, true]; }, {}, [""GRAB"", ""CROUCH""]] call ULP_UI_fnc_startProgress;";
			condition = "!(_this getVariable [""locked"", false])";
		};
	};

	class Vehicle {

		class Repair {
			title = "Napraw";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_repairVehicle";
			condition = """ToolKit"" in (items player)";
		};

		class PatchTyres : Repair {
			title = "Wymień koło";
			condition = "_this call ULP_fnc_hasTyreDamage";
		};

		class Refuel : Repair {
			title = "Zatankuj z kanistra";
			onClick = "_this call ULP_fnc_fuelCan";
			condition = "[""FuelCan""] call ULP_fnc_hasItem > 0";
		};

		class Lockpick : Repair {
			title = "Włam się";
			onClick = "_this call ULP_fnc_lockpickVehicle";
			condition = "!(_this in ULP_Keys) && { [""Lockpick""] call ULP_fnc_hasItem > 0 }";
		};

		class Registration : Repair {
			title = "Sprawdź rejestrację";
			onClick = "closeDialog 0; [(_this select 0)] call ULP_fnc_vehicleRegistration";
			factions[] = { "Police", "Hato" };
			condition = "true";
		};

		class Clamp : Repair {
			title = "Załóż blokadę na koła";
			onClick = "_this call ULP_fnc_clampVehicle";
			factions[] = { "Police", "Hato" };
			condition = "(_this getVariable [""clamp_fine"", []]) isEqualTo [] && { [""VehicleClamp""] call ULP_fnc_hasItem > 0 }";
		};

		class RemoveClamp : Clamp {
			title = "Usuń blokadę";
			onClick = "_this call ULP_fnc_removeVehicleClamp";
			condition = "!((_this getVariable [""clamp_fine"", []]) isEqualTo []) && { [""VehicleClamp""] call ULP_fnc_hasItem > 0 }";
		};

		class Garage : Repair {
			title = "Do garażu";
			onClick = "_this call ULP_fnc_garageVehicle";
			factions[] = { "Police", "Hato", "Medic" };
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess || { [""Hato_Main"", 1] call ULP_fnc_hasAccess } || { [""Medic_Main"", 1] call ULP_fnc_hasAccess }";
		};

		class Impound : Garage {
			title = "Parking policyjny";
			onClick = "_this call ULP_fnc_impoundVehicle";
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess || { [""Hato_Main"", 2] call ULP_fnc_hasAccess }";
		};

		class Scrap : Repair {
			title = "Zezłomuj";
			onClick = "_this call ULP_fnc_crushVehicle";
			factions[] = { "Police" };
			condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess && { [""bluezone_""] call ULP_fnc_isUnitsInZone }";
		};

		class PulloutOccupants : Repair {
			title = "Wyciągnij wszystkich";
			onClick = "if (_this call ULP_fnc_ejectVehicleCrew) then { closeDialog 0; };";
			condition = "(speed _this) <= 4 && { _this in ULP_Keys || [player, [""Police"", ""Medic""]] call ULP_fnc_isFaction }";
		};

		class Unflip : Repair {
			title = "Odwróć";
			onClick = "[_this select 0, 0] call ULP_fnc_flipVehicle";
			condition = "_this in ULP_Keys || { ""ToolKit"" in (items player) }";
		};

		/*
		class Push : Repair { // TODONOW (for boats)
			title = "Push";
			onClick = "hint ""Hello"";";
		};
		*/

		// Admin Commands...
		class AdminRepair {
			title = "Admin Repair";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "(_this select 0) setDamage 0; [format[""You've repaired this vehicle using admin powers.""]] call fini_fnc_noty; [getPlayerUID player, ""Admin"", [""AdminRepair"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Vehicle"", false] call ULP_fnc_checkPower }";
		};
		class AdminRefuel : AdminRepair {
			title = "Admin Refuel";
			onClick = "if ((count (units (_this select 0))) > 0) exitWith { [""No one can be in the vehicle while its refueled!""] call ULP_fnc_hint; }; [(_this select 0), 1] remoteExecCall [""ULP_fnc_setFuel"", (_this select 0)]; hint format[""You've refueled this vehicle using admin powers...""]; [getPlayerUID player, ""Admin"", [""AdminFuel"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
		};
		class AdminGarage : AdminRepair {
			title = "Admin Garage";
			onClick = "_this call ULP_fnc_garageVehicle; [getPlayerUID player, ""Admin"", [""AdminGarage"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
		};
		class AdminImpound : AdminRepair {
			title = "Admin Policyjny";
			onClick = "_this call ULP_fnc_impoundVehicle; [getPlayerUID player, ""Admin"", [""AdminImpound"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
		};
		class AdminScrap : AdminRepair {
			title = "Admin Złom";
			onClick = "_this call ULP_fnc_crushVehicle; [getPlayerUID player, ""Admin"", [""AdminScrap"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
		};
		class AdminPulloutOccupants : AdminRepair {
			title = "Admin Wyciągnij osoby";
			onClick = "if (_this call ULP_fnc_ejectVehicleCrew) then { closeDialog 0; }; [getPlayerUID player, ""Admin"", [""AdminPulloutOccupants"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
			condition = "(speed _this) <= 4 && { [] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Vehicle"", false] call ULP_fnc_checkPower } }";
		};
		class AdminUnflip : AdminRepair {
			title = "Admin Obróć";
			onClick = "_this call ULP_fnc_flipVehicle; [getPlayerUID player, ""Admin"", [""AdminUnflip"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
		};
	};
};