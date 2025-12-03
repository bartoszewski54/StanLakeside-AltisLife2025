class CfgVirtualItems {
	// Fresh Food
	class FreshApple {
		displayName = "Świeże jabłko";
		description = "Świeży owoc - prosto z drzewka.";
		icon = "Data\Icons\freshApples.paa";
		buyPrice = -1;
		sellPrice = 45;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 40;
			thirst = 0;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class FreshPeach : FreshApple {
		displayName = "Świeża brzoskwinia";
		icon = "Data\Icons\freshPeaches.paa";
		sellPrice = 51;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};

	// Regular Food
	class Apple {
		displayName = "Jabłko";
		description = "Kupne jabłko z marketu.";
		icon = "Data\Icons\apple.paa";
		buyPrice = 90;
		sellPrice = 45;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 20;
			thirst = 10;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class Peach : Apple {
		displayName = "Brzoskwinia";
		icon = "Data\Icons\peach.paa";
		buyPrice = 102;
		sellPrice = 51;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	class Bacon : Apple {
		displayName = "Bekon";
		description = "Zwykły fastfood - nabyty w kioskach.";
		icon = "Data\Icons\bacon.paa";
		buyPrice = 130;
		sellPrice = 65;
		class Settings : Settings {};
		class Sustain {
			hunger = 25;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Burger : Bacon {
		displayName = "Burger";
		icon = "Data\Icons\burger.paa";
		buyPrice = 165;
		sellPrice = 83;
		class Settings : Settings {};
		class Sustain {
			hunger = 70;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Hotdog : Bacon {
		displayName = "Hotdog";
		icon = "Data\Icons\hotdog.paa";
		buyPrice = 140;
		sellPrice = 70;
		class Settings : Settings {};
		class Sustain {
			hunger = 40;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Chips : Bacon {
		displayName = "Frytki";
		icon = "Data\Icons\chips.paa";
		buyPrice = 105;
		sellPrice = 53;
		class Settings : Settings {};
		class Sustain {
			hunger = 30;
			thirst = 0;
		};
		class Events : Events {};
	};
	class RationPack : Bacon {
		displayName = "Racja żywnościowa";
		icon = "Data\Icons\rationPack.paa";
		buyPrice = 325;
		sellPrice = 162;
		class Settings : Settings {};
		class Sustain {
			hunger = 50;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Doughnut : Bacon {
		displayName = "Donut";
		icon = "Data\Icons\doughnut.paa";
		buyPrice = 20;
		sellPrice = 10;
		class Settings : Settings {};
		class Sustain {
			hunger = 15;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Sweetie : Bacon {
		displayName = "Cukierki";
		icon = "Data\Icons\sweetie.paa";
		buyPrice = 8;
		sellPrice = 4;
		class Settings : Settings {};
		class Sustain {
			hunger = 5;
			thirst = 0;
		};
		class Events : Events {};
	};

	// Regular Drinks
	class Water {
		displayName = "Woda";
		description = "Zwykły napój.";
		icon = "Data\Icons\bottle.paa";
		buyPrice = 10;
		sellPrice = 5;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 50;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class Coffee : Water {
		displayName = "Kawa";
		icon = "Data\Icons\coffee.paa";
		buyPrice = 35;
		sellPrice = 18;
		class Settings : Settings {};
		class Sustain {
			hunger = 0;
			thirst = 25;
		};
		class Events : Events {};
	};
	class Tea : Coffee {
		displayName = "Herbata";
		icon = "Data\Icons\tea.paa";
		buyPrice = 30;
		sellPrice = 15;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};

	// Energy Drinks
	class Redbull {
		displayName = "Redbull";
		description = "Pomaga w koncentracji.";
		icon = "Data\Icons\can.paa";
		buyPrice = 2100;
		sellPrice = 1050;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 30;
		};
		class Events { onUse = "if ([(_this select 0)] call ULP_fnc_addSustenance) then { player setCustomAimCoef 0.5; [ { !(alive player) || { player getVariable [""isIncapacitated"", false] } || { diag_tickTime > (_this select 0) } }, [diag_tickTime + (3 * 60)], { player setCustomAimCoef 1; }] call ULP_fnc_waitUntilExecute; };"; };
		conditions = "true";
	};

	// Alcoholic Drinks
	class Beer {
		displayName = "Piwo";
		description = "Napój z dodatkiem %.";
		icon = "Data\Icons\beer.paa";
		buyPrice = 290;
		sellPrice = 145;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 10;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class Schnapps : Beer {
		displayName = "Wódka";
		icon = "Data\Icons\schnapps.paa";
		buyPrice = 580;
		sellPrice = 290;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 10;
		};
		class Events : Events {};
		conditions = "true";
	};
	class Gin : Beer {
		displayName = "Gin";
		icon = "Data\Icons\gin.paa";
		buyPrice = 375;
		sellPrice = 188;
		class Settings : Settings {};
		class Sustain {
			hunger = 0;
			thirst = 10;
		};
		class Events : Events {};
	};
	class Whiskey : Beer {
		displayName = "Whisky";
		icon = "Data\Icons\whiskey.paa";
		buyPrice = 495;
		sellPrice = 248;
		class Settings : Settings {};
		class Sustain {
			hunger = 0;
			thirst = 10;
		};
		class Events : Events {};
	};

	// XP Rewards
	class TinyXPReward {
		displayName = "Mini pakunek z XP";
		description = "A bottle that, when used, will provide valuable experience.";
		icon = "Data\Icons\xpReward.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [100, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
		conditions = "true";
	};
	class SmallXPReward : TinyXPReward {
		displayName = "Mały pakunek z XP";
		icon = "Data\Icons\xpReward.paa";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [500, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};
	class MediumXPReward : TinyXPReward {
		displayName = "Średni pakunek z XP";
		icon = "Data\Icons\xpReward.paa";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [1000, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};
	class LargeXPReward : TinyXPReward {
		displayName = "Duży pakunek z XP";
		icon = "Data\Icons\xpReward.paa";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [5000, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};
	class HugeXPReward : TinyXPReward {
		displayName = "Ogromny pakunek z XP";
		icon = "Data\Icons\xpReward.paa";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [10000, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};

	// Event Triggers
	class AirdropTrigger {
		displayName = "Zrzut (EVENT)";
		description = "Item używany do wymuszenia zrespienia się eventu.";
		icon = "Data\Icons\airdropTrigger.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "[_this # 0, missionConfigFile >> ""CfgRandomEvents"" >> ""Airdrop""] call ULP_fnc_triggerEvent"; };
		conditions = "true";
	};

	class ShipwreckTrigger : AirdropTrigger {
		displayName = "Wrak statku (EVENT)";
		icon = "Data\Icons\shipwreckTrigger.paa";
		class Settings : Settings {};
		class Events { onUse = "[_this # 0, missionConfigFile >> ""CfgRandomEvents"" >> ""Shipwreck""] call ULP_fnc_triggerEvent"; };
	};

	class CartelTrigger : AirdropTrigger {
		displayName = "Cartel (EVENT)";
		icon = "Data\Icons\shipwreckTrigger.paa";
		class Settings : Settings {};
		class Events { onUse = "[_this # 0, missionConfigFile >> ""CfgRandomEvents"" >> ""PopupCartel""] call ULP_fnc_triggerEvent"; };
	};

	// General Items
	class DroppedMoney {
		displayName = "$%1";
		description = "Pieniądze wyrzucane przez martwych.";
		icon = "Data\Icons\oldCoin.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
			isScripted = true;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Identification {
		displayName = "Dowód osobisty - %1";
		description = "Bardzo łatwy do podrobienia - dokument tożsamości.";
		icon = "Data\Icons\identification.paa";
		buyPrice = 75000;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = true;
			isSystemItem = false;
		};
		class Events {
			onUse = "_this call ULP_fnc_disguiseIdentity;";
			onRemove = "if ((player getVariable [""name"", """"]) isEqualTo (_this select 1)) then { player setVariable [""name"", nil, true]; [""Nie masz już przy sobie swojej fałszywej karty, więc ta przestała działać!""] call fini_fnc_noty; };";
		};
		conditions = "true";
	};

	class Pickaxe {
		displayName = "Kilof";
		description = "Prosty przedmiot do zbierania przedmiotów.";
		icon = "Data\Icons\pickaxe.paa";
		buyPrice = 1200;
		sellPrice = 600;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Deconstruction {
			time = 20;
			workbench = false;
			blueprints[] = { { "Tools", "B_Pickaxe" } };
			materials[] = { {"IronBar", 1}, {"Wood", 1} };
		};
		conditions = "true";
	};
	class LumberAxe : Pickaxe {
		displayName = "Siekiera";
		icon = "Data\Icons\lumberAxe.paa";
		buyPrice = 1180;
		sellPrice = 590;
		class Settings : Settings {};
		class Deconstruction {
			time = 20;
			workbench = false;
			blueprints[] = { { "Tools", "B_LuberAxe" } };
			materials[] = { {"IronBar", 1}, {"Wood", 1} };
		};
	};
	class Shovel : Pickaxe {
		displayName = "Łopata";
		icon = "Data\Icons\shovel.paa";
		buyPrice = 1100;
		sellPrice = 550;
		class Settings : Settings {};
		class Deconstruction {
			time = 20;
			workbench = false;
			blueprints[] = { { "Tools", "B_Shovel" } };
			materials[] = { {"Wood", 1} };
		};
	};
	class Extractor : Pickaxe {
		displayName = "Extraktor";
		icon = "Data\Icons\extractor.paa";
		buyPrice = 1950;
		sellPrice = 975;
		class Settings : Settings {};
		class Deconstruction {
			time = 20;
			workbench = false;
			blueprints[] = { { "Tools", "B_Extractor" } };
			materials[] = { {"IronBar", 2}, {"SilverBar", 1} };
		};
	};
	class FishingNet : Pickaxe {
		displayName = "Siatka na ryby";
		description = "Można ją zarzucić z łodzi i czekać aż coś się złapie.";
		icon = "Data\Icons\fishingNet.paa";
		buyPrice = 750;
		sellPrice = 375;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[] call ULP_fnc_dropFishingNet;"; };
		class Deconstruction {
			time = 30;
			workbench = false;
			blueprints[] = { { "Tools", "B_FishingNet" } };
			materials[] = { {"Rope", 2} };
		};
	};
	class FuelCan : Pickaxe {
		displayName = "Kanister";
		description = "Dzięki temu zatankujesz swój pojazd gdziekolwiek.";
		icon = "Data\Icons\fuelCan.paa";
		buyPrice = 3000;
		sellPrice = 1500;
		weight = 12;
		class Settings : Settings {};
		class Deconstruction {
			time = 30;
			workbench = false;
			blueprints[] = { { "Tools", "B_FuelCan" } };
			materials[] = { {"IronBar", 3} };
		};
	};
	class Breathalyser : Pickaxe { // TODO
		displayName = "Alkomat";
		description = "Używany do badania kierowców.";
		icon = "Data\Icons\breathalyser.paa";
		buyPrice = 8400;
		sellPrice = 4200;
		weight = 1;
		class Settings : Settings {};
	};
	class PanicButton : Pickaxe {
		displayName = "Panic Button";
		description = "Używany gdy przegrywasz.";
		icon = "Data\Icons\panicButton.paa";
		buyPrice = 900;
		sellPrice = 450;
		weight = 0;
		class Settings : Settings {};
		class Deconstruction {
			time = 60;
			workbench = true;
			blueprints[] = { { "PoliceEquipment", "B_PanicButton" } };
			materials[] = { {"CopperBar", 10}, {"SilverBar", 8} };
		};
		class Events { onUse = "[] call ULP_fnc_panic;"; };
	};
	class Ziptie : Pickaxe {
		displayName = "Opaska zaciskowa";
		description = "Używany do szybkich napraw wokół domu, lub do zakucia kogoś.";
		icon = "Data\Icons\ziptie.paa";
		buyPrice = 13500;
		sellPrice = 1;
		weight = 1;
		class Settings : Settings {};
	};
	class Blindfold : Pickaxe { // TODO
		displayName = "Opaska na oczy";
		description = "Kto zgasił światło?";
		icon = "Data\Icons\blindfold.paa";
		buyPrice = 17000;
		sellPrice = 8500;
		weight = 1;
		class Settings : Settings {};
		conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_Main"", 1] call ULP_fnc_hasAccess }";
	};
	class Stinger {
		displayName = "Kolczatka";
		description = "Rozkładany pasek kolców używany do przebijania karoserii pojazdu.";
		icon = "Data\Icons\stinger.paa";
		buyPrice = 8400;
		sellPrice = 2200;
		weight = 10;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Deconstruction {
			time = 30;
			workbench = true;
			blueprints[] = { { "Tools", "B_MakeshiftStinger" } };
			materials[] = { {"SteelBar", 22} };
		};
		class Events { onUse = "_this call ULP_fnc_spikeStrip;"; };
		conditions = "true";
	};
	class MakeshiftStinger : Stinger {
		displayName = "Prowizoryczna kolczatka";
		class Settings : Settings {};
	};
	class VehicleClamp : Stinger {
		displayName = "Blokada na koła";
		description = "Rozkładana blokada używana do zapobiegania ruchu danego pojazdu.";
		icon = "Data\Icons\vehicleClamp.paa";
		buyPrice = 18200;
		sellPrice = 9700;
		weight = 8;
		class Settings : Settings {};
		class Events { onUse = "[] call ULP_fnc_clampVehicle;"; };
	};
	class Lighter : Stinger {
		displayName = "Zapalniczka";
		description = "Prosta zapalniczka używana do rozpalania ognia.";
		icon = "Data\Icons\lighter.paa";
		buyPrice = 890;
		sellPrice = 445;
		weight = 1;
		class Settings : Settings {};
		class Events {};
		class Deconstruction {
			time = 10;
			workbench = false;
			blueprints[] = { { "Tools", "B_Lighter" } };
			materials[] = { {"Iron", 1} };
		};
	};
	class Lockpick : Stinger {
		displayName = "Wytrych";
		description = "Narzędzie używane do otwierania zamków pojazdów i kajdanek.";
		icon = "Data\Icons\lockpick.paa";
		buyPrice = 15000;
		sellPrice = 3500;
		weight = 1;
		class Settings : Settings {};
		class Events {};
		class Deconstruction {
			time = 10;
			workbench = false;
			blueprints[] = { { "Tools", "B_Lockpick" } };
			materials[] = { {"Iron", 2} };
		};
	};
	class BoltCutter : Stinger {
		displayName = "Nożyce do metalu";
		description = "Narzędzie używane do przecinania mocnych zamków w domach, zrzutach i wzmacnianych drzwiach.";
		icon = "Data\Icons\boltCutter.paa";
		buyPrice = 345000;
		sellPrice = 172500;
		weight = 8;
		class Settings : Settings {};
		class Events { onUse = "[] call ULP_fnc_boltcut;"; };
		class Deconstruction {
			time = 40;
			workbench = false;
			blueprints[] = { { "Tools", "B_BoltCutter" } };
			materials[] = { {"Iron", 8} };
		};
	};
	class BigRedKey : BoltCutter {
		displayName = "Duży czerwony klucz";
		buyPrice = 31200;
		sellPrice = 15600;
		weight = 14;
		class Settings : Settings {};
		class Events : Events {};
		conditions = "[""Police_Main"", 5] call ULP_fnc_hasAccess";
	};
	class signalJammer : Stinger { // TODO (crafting)
		displayName = "Zagłuszacz sygnału";
		description = "Narzędzie używane do zagłuszania dowolnych sygnałów elektronicznych w ograniczonym promieniu.";
		icon = "Data\Icons\signalJammer.paa";
		buyPrice = 110300;
		sellPrice = 55150;
		weight = 2;
		class Settings : Settings {};
	};
	class HackingDevice : Stinger {
		displayName = "HackRF";
		description = "Narzędzie używane do hakowania różnych systemów i złośliwego uzyskiwania do nich dostępu.";
		icon = "Data\Icons\hackingDevice.paa";
		buyPrice = 475000;
		sellPrice = 237500;
		weight = 1;
		class Settings : Settings {};
		class Events {};
		class Deconstruction {
			time = 120;
			workbench = true;
			blueprints[] = { { "Tools", "B_HackingDevice" } };
			materials[] = { {"Silver", 4}, {"CutDiamond", 2} };
		};
	};
	class ExplosiveCharge : Stinger {
		displayName = "Ładunek wybuchowy";
		description = "Narzędzie używane do niszczenia ufortyfikowanych zamków.";
		icon = "Data\Icons\explosiveCharge.paa";
		buyPrice = 750000;
		sellPrice = 375000;
		weight = 3;
		class Settings : Settings {};
		class Events {};
		class Deconstruction {
			time = 180;
			workbench = true;
			blueprints[] = { { "Tools", "B_ExplosiveCharge" } };
			materials[] = { {"ExplosiveMaterials", 4}, {"Coal", 7}, {"CutDiamond", 3} };
		};
	};
	class IndustrialDrill : ExplosiveCharge {
		displayName = "Wiertło przemysłowe";
		icon = "Data\Icons\industrialDrill.paa";
		buyPrice = 600000;
		sellPrice = 300000;
		weight = 16;
		class Settings : Settings {};
		class Events { onUse = "[] call ULP_fnc_drill;"; };
		class Deconstruction {
			time = 180;
			workbench = true;
			blueprints[] = { { "Tools", "B_IndustrialDrill" } };
			materials[] = { {"IronBar", 8}, {"CutDiamond", 2} };
		};
	};
	class Toolbox : Stinger {
		displayName = "Toolbox";
		description = "Zestaw narzędzi służących do rozkładania przedmiotów na ich podstawowe elementy.";
		icon = "Data\Icons\toolbox.paa";
		buyPrice = 25000;
		sellPrice = 12500;
		weight = 4;
		class Settings : Settings {};
		class Events {};
	};

	// Medical Equipment
	class Painkillers { // TODO (Will give health immedately after use)
		displayName = "Środki przeciwbólowe";
		description = "Dwie pigułki przywracające niewielką ilość zdrowia.";
		icon = "Data\Icons\painkillers.paa";
		buyPrice = 800;
		sellPrice = 400;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Bandage : Painkillers {
		displayName = "Ogólny bandaż";
		description = "Używany do craftingu sprzętu medycznego.";
		icon = "Data\Icons\bandage.paa";
		buyPrice = 850;
		sellPrice = 425;
		class Settings : Settings {};
	};
	class FieldDressing : Bandage {
		displayName = "Opatrunek polowy";
		icon = "Data\Icons\fieldDressing.paa";
		description = "Bandaż najlepiej sprawdzający się w leczeniu otarć.";
	};
	class Packing : Bandage {
		displayName = "Bandaż";
		icon = "Data\Icons\packingBandage.paa";
		description = "Bandaż najlepiej sprawdzający się w leczeniu otarć i skaleczeń.";
		buyPrice = 1000;
		sellPrice = 655;
	};
	class Elastic : Bandage {
		displayName = "Bandaż elastyczny";
		icon = "Data\Icons\elasticBandage.paa";
		description = "Opatrunek najlepiej nadający się do leczenia otarć i skaleczeń.";
		buyPrice = 1085;
		sellPrice = 750;
	};
	class QuickClot : Bandage {
		displayName = "QuikClot";
		icon = "Data\Icons\quikClot.paa";
		description = "Opatrunek najlepiej sprawdzający się w leczeniu otarć i skaleczeń.";
		buyPrice = 345;
		sellPrice = 125;
	};
	class BloodBag : Painkillers {
		displayName = "Worek na krew";
		description = "Służy do zapobiegania wykrwawieniu się obezwładnionej osoby.";
		icon = "Data\Icons\bloodbag.paa";
		buyPrice = 1000;
		sellPrice = 500;
		class Settings : Settings {};
	};
	class Morphine : Painkillers {
		displayName = "Morfina";
		description = "Used to raise a person's heart rate in order to revive them.";
		icon = "Data\Icons\injector.paa";
		buyPrice = 1200;
		sellPrice = 600;
		class Settings : Settings {};
	};
	class Epinephrine : Morphine {
		displayName = "Adrenalina";
		description = "Używany do obniżenia tętna osoby w celu jej ożywienia.";
		class Settings : Settings {};
	};
	class FirstAidKit : Painkillers {
		displayName = "Apteczka pierwszej pomocy";
		description = "Zestaw zawierający różne narzędzia medyczne, które mogą zapewnić pomoc.";
		icon = "Data\Icons\firstAidKit.paa";
		buyPrice = 1500;
		sellPrice = 750;
		class Settings : Settings {};
	};
	class MediKit : FirstAidKit {
		displayName = "MediKit";
		icon = "Data\Icons\mediKit.paa";
		buyPrice = 18700;
		sellPrice = 9350;
		weight = 2;
		class Settings : Settings {};
	};
	class AutomatedExternalDefibrillator : MediKit {
		displayName = "Automatyczny Defibrylator";
		description = "Przenośne urządzenie elektroniczne, które automatycznie diagnozuje zagrażające życiu zaburzenia rytmu serca.";
		icon = "Data\Icons\defibrillator.paa";
		buyPrice = 22600;
		sellPrice = 11300;
		weight = 3;
		class Settings : Settings {};
	};

	class TapeSign_F {
		displayName = "Czerwono-biała taśma";
		description = "Zapakowany przedmiot gotowy do złożenia.";
		icon = "Data\Icons\roadBarrier.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "[""TapeSign"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "true";
	};
	class PlasticBarrier_02_yellow_F : TapeSign_F {
		displayName = "Plastikowa bariera (średnia, żółta)";
		buyPrice = 0;
		sellPrice = 0;
		weight = 3;
		class Settings : Settings {};
	};
	class PlasticBarrier_02_grey_F : PlasticBarrier_02_yellow_F {
		displayName = "Plastikowa bariera (średnia, szara)";
		class Settings : Settings {};
	};
	class PlasticBarrier_03_orange_F : TapeSign_F {
		displayName = "Plastikowa bariera (duża, pomarańczowa)";
		buyPrice = 0;
		sellPrice = 0;
		weight = 4;
		class Settings : Settings {};
	};
	class PlasticBarrier_03_blue_F : PlasticBarrier_03_orange_F {
		displayName = "Plastikowa bariera (duża, niebieska)";
		class Settings : Settings {};
	};
	class RoadBarrier_small_F : TapeSign_F {
		displayName = "Barierka (mała)";
		buyPrice = 0;
		sellPrice = 0;
		weight = 3;
		class Settings : Settings {};
	};
	class RoadBarrier_F : TapeSign_F {
		displayName = "Barierka (duża)";
		buyPrice = 0;
		sellPrice = 0;
		weight = 5;
		class Settings : Settings {};
	};
	class RoadCone_F : TapeSign_F {
		displayName = "Pachołek";
		icon = "Data\Icons\cone.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[""RoadCone"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class RoadCone_L_F : RoadCone_F {
		displayName = "Pachołek (światło)";
		class Settings : Settings {};
		class Events { onUse = "[""RoadConeWithLight"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_PortableLight_single_F : TapeSign_F {
		displayName = "Przenośne światło (pojedyncze)";
		icon = "Data\Icons\portableLight.paa";
		buyPrice = 0;
		sellPrice = 0;
		class Settings : Settings {};
		class Events { onUse = "[""SinglePortableLight"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_PortableLight_double_F : Land_PortableLight_single_F {
		displayName = "Przenośne światło (podwójne)";
		buyPrice = 0;
		sellPrice = 0;
		class Settings : Settings {};
		class Events { onUse = "[""DoublePortableLight"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class TargetP_Inf4_F : TapeSign_F {
		displayName = "Wyskakujący cel (wrogi)";
		icon = "Data\Icons\popupTarget.paa";
		buyPrice = 0;
		sellPrice = 0;
		class Settings : Settings {};
	};
	class TargetP_Civ_F : TargetP_Inf4_F {
		displayName = "Cel (Kryminalista)";
		class Settings : Settings {};
	};
	class TargetP_Civ3_F : TargetP_Inf4_F {
		displayName = "Cel (Zakładnik)";
		class Settings : Settings {};
	};
	class Stretcher : TapeSign_F {
		displayName = "Nosze";
		description = "Proste narzędzie do przenoszenia rannych.";
		icon = "Data\Icons\stretcher.paa";
		buyPrice = 12500;
		sellPrice = 4350;
		weight = 5;
		class Events { onUse = "[""Stretcher"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[player, [""Police"", ""Medic""]] call ULP_fnc_isFaction || { ULP_Level >= 3 }";
	};

// Farming Items (TODO - Farmers' Market, Tractor)
	class FarmingEquipment { // TODO (crafting)
		displayName = "Sprzęt rolniczy";
		description = "Zestaw narzędzi wykorzystywanych do pracy w wyspecjalizowanych magazynach.";
		icon = "Data\Icons\farmingEquipment.paa";
		buyPrice = 8900;
		sellPrice = 4450;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class FertileSoil : FarmingEquipment { // TODO
		displayName = "Nasiona";
		description = "Mała paczka nasion gotowa do zasadzenia w żyznej glebie w specjalistycznym magazynie.";
		icon = "Data\Icons\fertileSoil.paa";
		buyPrice = 1230;
		sellPrice = 615;
		weight = 1;
		class Settings : Settings {};
	};
	class CropSeeds : FertileSoil { // TODO
		displayName = "Nasiona";
		description = "Mała paczka nasion gotowa do zasadzenia w żyznej glebie w specjalistycznym magazynie.";
		icon = "Data\Icons\seeds.paa";
		buyPrice = 900;
		sellPrice = 450;
		class Settings : Settings {};
	};


	// Computer Components (TODO - some store for all this)
	class MiningRig { // TODO (crafting)
		displayName = "Mining Rig";
		description = "A constructed rig for mining crypto in specialised warehouses.";
		icon = "Data\Icons\miningRig.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Motherboard : MiningRig { // TODO (crafting)
		displayName = "Motherboard";
		description = "A component used for crafting mining rigs.";
		icon = "Data\Icons\motherboard.paa";
		weight = 1;
		class Settings : Settings {};
	};
	class CPU : Motherboard { // TODO (crafting)
		displayName = "CPU";
		icon = "Data\Icons\cpu.paa";
		class Settings : Settings {};
	};
	class GPU : Motherboard { // TODO (crafting)
		displayName = "GPU";
		icon = "Data\Icons\gpu.paa";
		class Settings : Settings {};
	};
	class RAM : Motherboard { // TODO (crafting)
		displayName = "RAM";
		icon = "Data\Icons\ram.paa";
		class Settings : Settings {};
	};
	class PSU : Motherboard { // TODO (crafting)
		displayName = "PSU";
		icon = "Data\Icons\psu.paa";
		class Settings : Settings {};
	};


	// Misc. Run Items
	class StolenCargo {
		displayName = "Skradziony ładunek";
		description = "Zapieczętowane skrzynie ładunkowe wypełnione skradzionymi towarami.";
		icon = "Data\Icons\crate.paa";
		buyPrice = -1;
		sellPrice = 71360;
		weight = 24;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = true;
		};
		conditions = "true";
	};
	class FreightCargo : StolenCargo {
		displayName = "Ładunek";
		description = "Zaplombowane skrzynie ładunkowe wypełnione towarem.";
		icon = "Data\Icons\freightCargo.paa";
		sellPrice = 35680;
		weight = 24;
		class Settings : Settings {
			isIllegal = false;
		};
	};
	class SeizedContraband : StolenCargo {
		displayName = "Przechwycona kontrabanda";
		description = "Kontrabanda zajęta przez policję i przechowywana w magazynie dowodów.";
		icon = "Data\Icons\seizedContraband.paa";
		sellPrice = 237600;
		weight = 4;
		class Settings : Settings {
			isSystemItem = false;
		};
	};
	class SpaceCapsuleDataDrive : SeizedContraband {
		displayName = "Dysk nieznanego pochodzenia";
		description = "Dysk z danymi zawierający nieznane sekrety.";
		icon = "Data\Icons\drive.paa";
		sellPrice = 20000000;
		weight = 25;
		class Settings : Settings {};
	};
	class SmallGalleryPiece : SeizedContraband {
		displayName = "Mały obraz";
		description = "Dzieło sztuki powszechnie przechowywane w Galerii Altis.";
		icon = "Data\Icons\galleryPiece.paa";
		sellPrice = 365000;
		weight = 6;
		class Settings : Settings {};
	};
	class MediumGalleryPiece : SmallGalleryPiece {
		displayName = "Średni obraz";
		icon = "Data\Icons\galleryPiece.paa";
		sellPrice = 496000;
		weight = 10;
		class Settings : Settings {};
	};
	class LargeGalleryPiece : SmallGalleryPiece {
		displayName = "Duży obraz";
		icon = "Data\Icons\galleryPiece.paa";
		sellPrice = 732500;
		weight = 14;
		class Settings : Settings {};
	};
	class MarkedGold : SeizedContraband {
		displayName = "Oznakowane złoto";
		description = "Sztabka złota z skarbca państwa.";
		icon = "Data\Icons\ingot.paa";
		sellPrice = 250000;
		weight = 16;
		class Settings : Settings {};
	};
	class UnmarkedGold : MarkedGold {
		displayName = "Nieoznaczone złoto";
		description = "Nieoznaczona sztabka złota, która została zeszlifowana przez złotnika.";
		sellPrice = 700000;
		class Settings : Settings {};
	};
	class EncryptedDrive : SeizedContraband {
		displayName = "Zaszyfrowany dysk";
		description = "Zaszyfrowany dysk zawierający tajne pliki pobrane z pokładu dowodzenia statku.";
		icon = "Data\Icons\drive.paa";
		sellPrice = 400000;
		weight = 8;
		class Settings : Settings {};
	};
	class DecryptedDrive : EncryptedDrive {
		displayName = "Odszyfrowany dysk";
		description = "Odszyfrowany dysk zawierający tajne pliki pobrane z pokładu dowodzenia statku.";
		icon = "Data\Icons\drive.paa";
		sellPrice = 1000000;
		class Settings : Settings {};
	};

	// Legal Unprocessed
	class Tobacco {
		displayName = "Tytoń";
		description = "Zwykły liść, który może być przetwarzany na papierosy lub cygara.";
		icon = "Data\Icons\tobacco.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Clay : Tobacco {
		displayName = "Glina";
		description = "Prosty materiał wykorzystywany w craftingu.";
		icon = "Data\Icons\clay.paa";
		weight = 1;
		class Settings : Settings {};
	};
	class Wood : Tobacco {
		displayName = "Drewno";
		description = "Kawałek drewna.";
		icon = "Data\Icons\wood.paa";
		sellPrice = 450;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
	};
	class Plank : Wood {
		displayName = "Deska";
		description = "Ważne że płaska...";
		icon = "Data\Icons\wood.paa";
		sellPrice = 1350;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
	};
	class Rope : Tobacco {
		displayName = "Lina";
		description = "Zwykły kawałek liny często spotykany w craftingach";
		icon = "Data\Icons\rope.paa";
		weight = 1;
		class Settings : Settings {};
	};
	class DrillBit : Tobacco {
		displayName = "Wiertło";
		description = "Mocne wiertło powszechnie spotykane w craftingach.";
		icon = "Data\Icons\drillBit.paa";
		weight = 1;
		class Settings : Settings {};
	};
	class Rock : Tobacco {
		displayName = "Kamień";
		description = "Zwykły kamień z więzienia";
		icon = "Data\Icons\ore.paa";
		sellPrice = 3;
		weight = 3;
		class Settings : Settings {};
		conditions = "ULP_Imprisioned";
	};
	class CopperOre : Tobacco {
		displayName = "Ruda miedzi";
		description = "Ruda zebrana z kopalni minerałów.";
		icon = "Data\Icons\ore.paa";
		weight = 3;
		class Settings : Settings {};
	};
	class SilverOre : CopperOre {
		displayName = "Ruda srebra";
		icon = "Data\Icons\ore.paa";
		class Settings : Settings {};
	};
	class IronOre : CopperOre {
		displayName = "Ruda żelaza";
		icon = "Data\Icons\ore.paa";
		weight = 5;
		class Settings : Settings {};
	};
	class Sand : Tobacco {
		displayName = "Piasek";
		description = "Ziarna piasku, które można przetworzyć na szkło.";
		icon = "Data\Icons\sand.paa";
		weight = 2;
		class Settings : Settings {};
	};
	class UnrefinedSalt : Tobacco {
		displayName = "Nieprzetworzona sól";
		description = "Salt gathered from the salt flats.";
		icon = "Data\Icons\saltUnrefined.paa";
		weight = 3;
		class Settings : Settings {};
	};
	class UnprocessedOil : Tobacco {
		displayName = "Nierafinowany olej";
		description = "Nierafinowana ropa naftowa wydobyta z pól roponośnych przy użyciu ekstraktora.";
		icon = "Data\Icons\oilUnrefinded.paa";
		weight = 6;
		class Settings : Settings {};
	};
	class UncutDiamond : CopperOre {
		displayName = "Ruda diamentu";
		icon = "Data\Icons\ore.paa";
		class Settings : Settings {};
	};

	// Legal Processed
	class Cigarette {
		displayName = "Papierosy";
		description = "Rolka tytoniu, która może być sprzedawana lub palona.";
		icon = "Data\Icons\cigarette.paa";
		buyPrice = 5700;
		sellPrice = 2850;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = true;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Cigar : Cigarette {
		displayName = "Cygaro";
		icon = "Data\Icons\cigar.paa";
		buyPrice = 6720;
		sellPrice = 3360;
		class Settings : Settings {};
	};
	class Coal : Cigarette {
		displayName = "Węgiel";
		description = "Zwykła bryła węgla, którą można sprzedać w fabryce węgla.";
		icon = "Data\Icons\ore.paa";
		buyPrice = -1;
		sellPrice = 2400;
		weight = 4;
		class Settings : Settings {};
	};
	class CopperBar : Coal {
		displayName = "Sztabka miedzi";
		description = "Przetworzony metal.";
		icon = "Data\Icons\ingot.paa";
		sellPrice = 1900;
		weight = 2;
		class Settings : Settings {};
	};
	class SilverBar : CopperBar {
		displayName = "Sztabka srebra";
		sellPrice = 2200;
		class Settings : Settings {};
	};
	class IronBar : CopperBar {
		displayName = "Sztabka żelaza";
		sellPrice = 7350;
		class Settings : Settings {};
	};
	class SteelBar : CopperBar {
		displayName = "Sztabka stali";
		sellPrice = 9670;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
	};
	class Glass : CopperBar {
		displayName = "Szkło";
		description = "Mocne szkło gotowe do sprzedaży.";
		icon = "Data\Icons\glass.paa";
		sellPrice = 2450;
		weight = 1;
		class Settings : Settings {};
	};
	class RefinedSalt : CopperBar {
		displayName = "Sól rafinowana";
		description = "Sól rafinowana gotowa do sprzedaży.";
		icon = "Data\Icons\saltRefined.paa";
		sellPrice = 3200;
		class Settings : Settings {};
	};
	class ProcessedOil : CopperBar {
		displayName = "Olej rafinowany";
		description = "Rafinowany olej, który pozostaje łatwopalny.";
		icon = "Data\Icons\oilRefinded.paa";
		sellPrice = 9850;
		weight = 4;
		class Settings : Settings {};
	};
	class CutDiamond : CopperBar {
		displayName = "Oszlifowany diament";
		description = "Drobno oszlifowany diament, który kobiety uwielbiają.";
		icon = "Data\Icons\diamond.paa";
		sellPrice = 6100;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
	};

	// Illegal Unprocessed
	class UraniumOre : CopperOre {
		displayName = "Ruda uranu";
		icon = "Data\Icons\ore.paa";
		weight = 6;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
	};
	class ExplosiveMaterials : UraniumOre {
		displayName = "Proch";
		description = "Wybuchowy... używany do craftingu.";
		icon = "Data\Icons\explosiveMaterials.paa";
		weight = 6;
		class Settings : Settings {};
		class Deconstruction {
			time = 180;
			workbench = true;
			blueprints[] = { { "CraftingMaterials", "B_ExplosiveMaterials" } };
			materials[] = { {"IronBar", 32}, {"ProcessedOil", 9} };
		};
	};
	class Corn : UraniumOre {
		displayName = "Kukurydza";
		description = "Przedmiot, który pozostaje nielegalny ze względu na popularność bimbru.";
		icon = "Data\Icons\corn.paa";
		weight = 3;
		class Settings : Settings {};
	};
	class EphedrineBarrel : CopperOre {
		displayName = "Beczka z efedryną";
		description = "Podstawowy materiał do produkcji metamfetaminy.";
		icon = "Data\Icons\methUnprocessed.paa";
		buyPrice = 6050;
		weight = 12;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
	};
	class UnprocessedWeed : UraniumOre {
		displayName = "Nieprzetworzone zioło";
		description = "A drug, useless until processed.";
		icon = "Data\Icons\weedUnprocessed.paa";
		weight = 4;
		class Settings : Settings {};
	};
	class UnprocessedHeroin : UnprocessedWeed {
		displayName = "Opium";
		icon = "Data\Icons\heroinUnprocessed.paa";
		weight = 5;
		class Settings : Settings {};
	};
	class UnprocessedCocaine : UnprocessedHeroin {
		displayName = "Liść koki";
		icon = "Data\Icons\cocaineUnprocessed.paa";
		weight = 6;
		class Settings : Settings {};
	};

	// Illegal Processed
	class Coral {
		displayName = "Koralowiec";
		description = "Koralowiec zebrany z rafy koralowej w pobliżu Kavali.";
		icon = "Data\Icons\coral.paa";
		buyPrice = -1;
		sellPrice = 6700;
		weight = 7;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class ProcessedWeed : Coral {
		displayName = "Przetworzone zioło";
		description = "Przetworzone narkotyki, które można wykorzystać lub sprzedać/kupić u dilera narkotyków.";
		icon = "Data\Icons\weedProcessed.paa";
		buyPrice = 10020;
		sellPrice = 3340;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
	};
	class ProcessedHeroin : ProcessedWeed {
		displayName = "Przetworzona heroina";
		icon = "Data\Icons\heroinProcessed.paa";
		buyPrice = 21240;
		sellPrice = 7080;
		weight = 4;
		class Settings : Settings {};
	};
	class ProcessedCocaine : ProcessedWeed {
		displayName = "Przetworzona kokaina";
		icon = "Data\Icons\cocaineProcessed.paa";
		buyPrice = 34350;
		sellPrice = 11450;
		weight = 5;
		class Settings : Settings {};
	};
	class ProcessedMeth : ProcessedWeed {
		displayName = "Metaamfetamina";
		icon = "Data\Icons\methProcessed.paa";
		buyPrice = 91500;
		sellPrice = 30500;
		weight = 5;
		class Settings : Settings {};
	};
	class Moonshine : ProcessedWeed {
		displayName = "Bimber";
		icon = "Data\Icons\moonshine.paa";
		buyPrice = 20100;
		sellPrice = 6700;
		weight = 2;
		class Settings : Settings {};
	};
	class Ecstasy : ProcessedWeed {
		displayName = "Ecstasy";
		icon = "Data\Icons\ecstasy.paa";
		buyPrice = 10500;
		sellPrice = 5250;
		weight = 1;
		class Settings : Settings {};
	};
	class UraniumBar : ProcessedWeed {
		displayName = "Sztabka uranu";
		description = "Niezwykle niebezpieczny minerał przetwarzany w strefie promieniowania.";
		icon = "Data\Icons\ingot.paa";
		buyPrice = -1;
		sellPrice = 22150;
		weight = 3;
		class Settings : Settings {};
	};

	// Illegal Purified
	class PurifiedWeed {
		displayName = "Oczyszczone zioło";
		description = "Najwyższa jakość leków na Altis, najbardziej ceniony towar.";
		icon = "Data\Icons\weedProcessed.paa";
		buyPrice = 13527;
		sellPrice = 4509;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class PurifiedHeroin : PurifiedWeed {
		displayName = "Oczyszczona heroina";
		icon = "Data\Icons\heroinProcessed.paa";
		buyPrice = 28674;
		sellPrice = 9558;
		weight = 4;
		class Settings : Settings {};
	};
	class PurifiedCocaine : PurifiedWeed {
		displayName = "Oczyszczona kokaina";
		icon = "Data\Icons\cocaineProcessed.paa";
		buyPrice = 46371;
		sellPrice = 15457;
		weight = 5;
		class Settings : Settings {};
	};
	class PurifiedMeth : PurifiedWeed {
		displayName = "Oczyszczona Meta";
		icon = "Data\Icons\methProcessed.paa";
		buyPrice = 111525;
		sellPrice = 37175;
		weight = 5;
		class Settings : Settings {};
	};
	class PurifiedMoonshine : PurifiedWeed {
		displayName = "Oczyszczony bimber";
		icon = "Data\Icons\moonshine.paa";
		buyPrice = 24135;
		sellPrice = 8045;
		weight = 1;
		class Settings : Settings {};
	};

	// Raw Fish
	class Salema_F_Raw {
		displayName = "Surowa Salema";
		description = "Surowa ryba, która może być sprzedawana na targu rybnym lub gotowana w publicznej kuchni.";
		icon = "Data\Icons\fish.paa";
		buyPrice = -1;
		sellPrice = 450;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
			isScripted = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Ornate_random_F_Raw : Salema_F_Raw {
		displayName = "Surowy Ornat";
		sellPrice = 660;
		class Settings : Settings {};
	};
	class Mackerel_F_Raw : Salema_F_Raw {
		displayName = "Surowa makrela";
		sellPrice = 740;
		class Settings : Settings {};
	};
	class Tuna_F_Raw : Salema_F_Raw {
		displayName = "Surowy tuńczyk";
		sellPrice = 822;
		class Settings : Settings {};
	};
	class Mullet_F_Raw : Salema_F_Raw {
		displayName = "Surowa barwena";
		sellPrice = 990;
		class Settings : Settings {};
	};
	class CatShark_F_Raw : Salema_F_Raw {
		displayName = "Surowy sum";
		sellPrice = 1237;
		class Settings : Settings {};
	};
	class Turtle_F_Raw : Salema_F_Raw {
		displayName = "Turtuś";
		icon = "Data\Icons\turtle.paa";
		sellPrice = 28500;
		weight = 5;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
		};
	};

	// Cooked Fish
	class CookedSalema {
		displayName = "Gotowana Salema";
		description = "Gotowana ryba, którą można sprzedać na targu rybnym.";
		icon = "Data\Icons\fish.paa";
		buyPrice = 2250;
		sellPrice = 1125;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class CookedOrnate : CookedSalema {
		displayName = "Gotowany Ornat";
		buyPrice = 3300;
		sellPrice = 1650;
		class Settings : Settings {};
	};
	class CookedMackerel : CookedSalema {
		displayName = "Gotowana makrela";
		buyPrice = 3700;
		sellPrice = 1850;
		class Settings : Settings {};
	};
	class CookedTuna : CookedSalema {
		displayName = "Gotowany tuńczyk";
		buyPrice = 4112;
		sellPrice = 2056;
		class Settings : Settings {};
	};
	class CookedMullet : CookedSalema {
		displayName = "Gotowana barwena";
		buyPrice = 4950;
		sellPrice = 2475;
		class Settings : Settings {};
	};
	class CookedCatshark : CookedSalema {
		displayName = "Gotowany sum";
		buyPrice = 6187;
		sellPrice = 3093;
		class Settings : Settings {};
	};

	// Archaeology Items
	class CommonMap {
		displayName = "Zwykła mapa";
		description = "Mapa zawierająca różne znane lokalizacje artefaktów w Altis.";
		icon = "Data\Icons\map.paa";
		buyPrice = 20000;
		sellPrice = 10000;
		weight = 12;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "[""Common""] call ULP_fnc_getSite;"; };
		conditions = "true";
	};
	class UncommonMap : CommonMap {
		displayName = "Niezwykła mapa";
		buyPrice = -1;
		sellPrice = 135000;
		class Settings : Settings {};
		class Events { onUse = "[""Uncommon""] call ULP_fnc_getSite;"; };
	};
	class RareMap : UncommonMap {
		displayName = "Rzadka Mapa";
		sellPrice = 180000;
		class Settings : Settings {};
		class Events { onUse = "[""Rare""] call ULP_fnc_getSite;"; };
	};
	class LegendaryMap : UncommonMap {
		displayName = "Legendarna mapa";
		sellPrice = 250000;
		class Settings : Settings {};
		class Events { onUse = "[""Legendary""] call ULP_fnc_getSite;"; };
	};

	class CommonMapFragment : UncommonMap {
		displayName = "Fragment zwykłej mapy";
		description = "Niepełny fragment mapy.";
		icon = "Data\Icons\mapFragment.paa";
		sellPrice = 15000;
		class Settings : Settings {};
		class Events { onUse = ""; };
	};
	class UncommonMapFragment : CommonMapFragment {
		displayName = "Fragment niezwykłej mapy";
		sellPrice = 30000;
		class Settings : Settings {};
	};
	class RareMapFragment : CommonMapFragment {
		displayName = "Fragment rzadkiej mapy";
		sellPrice = 45000;
		class Settings : Settings {};
	};
	class LegendaryMapFragment : CommonMapFragment {
		displayName = "Fragment legendarnej mapy";
		sellPrice = 60000;
		class Settings : Settings {};
	};

	class SurveyingEquipment {
		displayName = "Narzędzia do badań";
		description = "Sprzęt używany do badania miejsca wykopalisk w celu zlokalizowania artefaktów.";
		icon = "Data\Icons\surveyingEquipment.paa";
		buyPrice = 28900;
		sellPrice = 14450;
		weight = 8;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "[ULP_Archaeology] call ULP_fnc_surveySite;"; };
		class Deconstruction {
			time = 120;
			workbench = true;
			blueprints[] = { { "Tools", "B_SurveyingEquipment" } };
			materials[] = { {"CopperBar", 2}, {"SilverBar", 1} };
		};
		conditions = "true";
	};
	class ArchaeologistsEquipment : SurveyingEquipment {
		displayName = "Narzędzia archeologa";
		description = "Sprzęt używany do ostrożnego wykopywania artefaktów z wykopalisk.";
		icon = "Data\Icons\archaeologistsEquipment.paa";
		buyPrice = 24500;
		sellPrice = 12250;
		weight = 6;
		class Settings : Settings {};
		class Events { onUse = "[ULP_Archaeology] call ULP_fnc_digSite;"; };
		class Deconstruction {
			time = 120;
			workbench = true;
			blueprints[] = { { "Tools", "B_ArchaeologistsEquipment" } };
			materials[] = { {"IronBar", 4}, {"Wood", 2}, {"Rock", 1} };
		};
	};

	/// Common Rewards
	class OldCoin {
		displayName = "Stara moneta";
		description = "Artefakty zebrane z wykopalisk i sprzedawane u archeologów.";
		icon = "Data\Icons\oldCoin.paa";
		buyPrice = -1;
		sellPrice = 7287;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class CoinBundle : OldCoin {
		displayName = "Worek starych monet";
		icon = "Data\Icons\coinBundle.paa";
		sellPrice = 310781;
		weight = 2;
		class Settings : Settings {};
	};
	class BrokenPot : OldCoin {
		displayName = "Zniszczona doniczka";
		icon = "Data\Icons\brokenPot.paa";
		sellPrice = 15575;
		weight = 4;
		class Settings : Settings {};
	};
	class RestoredPot : BrokenPot {
		displayName = "Odrestaurowana doniczka";
		icon = "Data\Icons\restoredPot.paa";
		sellPrice = 39437;
		class Settings : Settings {};
	};
	class BluntStoneKnife : OldCoin {
		displayName = "Tępy nóż kamienny";
		icon = "Data\Icons\bluntStoneKnife.paa";
		sellPrice = 24775;
		weight = 2;
		class Settings : Settings {};
	};
	class SharpStoneKnife : OldCoin {
		displayName = "Nóż z ostrym kamieniem";
		icon = "Data\Icons\sharpStoneKnife.paa";
		sellPrice = 76937;
		weight = 2;
		class Settings : Settings {};
	};
	class FossilisedBone : OldCoin {
		displayName = "Skamieniała kość";
		icon = "Data\Icons\fossilisedBone.paa";
		sellPrice = 31595;
		weight = 2;
		class Settings : Settings {};
	};
	class UnidentifiedSkull : OldCoin {
		displayName = "Niezidentyfikowana czaszka";
		sellPrice = 65850;
		weight = 4;
		class Settings : Settings {};
	};
	class IdentifiedSkull : UnidentifiedSkull {
		displayName = "Zidentyfikowana czaszka";
		icon = "Data\Icons\unidentifiedSkull.paa";
		sellPrice = 1939000;
		class Settings : Settings {};
	};
	/// Uncommon Rewards
	class PetrifiedShield : OldCoin {
		displayName = "Skamieniała Tarcza";
		icon = "Data\Icons\petrifiedShield.paa";
		sellPrice = 70300;
		weight = 6;
		class Settings : Settings {};
	};
	class WeatheredSculpture : OldCoin {
		displayName = "Zwietrzała rzeźba";
		icon = "Data\Icons\weatheredSculpture.paa";
		sellPrice = 81750;
		weight = 5;
		class Settings : Settings {};
	};
	class AncientAmber : OldCoin {
		displayName = "Starożytny bursztyn";
		icon = "Data\Icons\ancientAmber.paa";
		sellPrice = 90927;
		class Settings : Settings {};
	};
	class ReligiousTotem : OldCoin {
		displayName = "Totem religijny";
		icon = "Data\Icons\religiousTotem.paa";
		sellPrice = 97950;
		weight = 2;
		class Settings : Settings {};
	};
	class StrongMetalRing : OldCoin {
		displayName = "Mocny metalowy pierścień";
		icon = "Data\Icons\strongMetalRing.paa";
		sellPrice = 118900;
		class Settings : Settings {};
	};
	class DiamondRing : OldCoin {
		displayName = "Metalowy pierścionek z diamentem";
		icon = "Data\Icons\diamondRing.paa";
		sellPrice = 246100;
		class Settings : Settings {};
	};
	/// Rare Rewards
	class EmeraldAmulet : OldCoin {
		displayName = "Szmaragdowy Amulet";
		icon = "Data\Icons\emeraldAmulet.paa";
		sellPrice = 200625;
		weight = 1;
		class Settings : Settings {};
	};
	class AncientLedger : OldCoin {
		displayName = "Antyczna księga";
		icon = "Data\Icons\ancientLedger.paa";
		sellPrice = 237237;
		weight = 3;
		class Settings : Settings {};
	};
	class HandSmoothedRunestone : OldCoin {
		displayName = "Ręcznie wygładzany kamień runiczny";
		icon = "Data\Icons\handSmoothedRunestone.paa";
		sellPrice = 279037;
		weight = 4;
		class Settings : Settings {};
	};
	class JeweledNecklace : OldCoin {
		displayName = "Wysadzany naszyjnik";
		icon = "Data\Icons\jeweledNecklace.paa";
		sellPrice = 332337;
		class Settings : Settings {};
	};
	class BrokenTimepiece : OldCoin {
		displayName = "Zepsuty czasomierz";
		icon = "Data\Icons\brokenTimepiece.paa";
		sellPrice = 308475;
		weight = 1;
		class Settings : Settings {};
	};
	class UncutBloodDiamond : CopperOre {
		displayName = "Ruda Krwistego Diamentu";
		icon = "Data\Icons\ore.paa";
		class Settings : Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
	};
	class CutBloodDiamond : CutDiamond {
		displayName = "Oszlifowany Krwisty Diament";
		description = "A finely cut diamond that women appear to love.";
		icon = "Data\Icons\diamond.paa";
		sellPrice = 9500;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
	};
	class WeaponParts : UnprocessedHeroin {
		displayName = "Części do broni";
		description = "Parts used to assemble weapons at weapons processing";
		icon = "Data\Icons\weaponParts.paa";
		buyPrice = 5900;
		weight = 6;
		class Settings : Settings {};
	};
	class WeaponCrate : ProcessedWeed {
		displayName = "Skrzynia z bronią";
		description = "A crate packed with assembled weapons ready to be sold near the Church Arms Cartel";
		icon = "Data\Icons\weaponCrate.paa";
		buyPrice = -1;
		sellPrice = 58700;
		weight = 5;
		class Settings : Settings {};
	};
};