class CfgPerks {
	baseLimit = 5;
	maxLimit = 15;
	removalCost = 100000;

	class SecondNature {
		icon = "Data\UI\Perks\secondNature.paa";
		displayName = "Anioł stróż";
		description = "Automatycznie zapina pasy po wejściu do samochodu.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 1;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params setVariable [""seatbelt"", true]; _params";
	};

	class ImprovedMetabolism {
		icon = "Data\UI\Perks\improvedMetabolism.paa";
		displayName = "Metabolizm+";
		description = "Spowalnia głód i odwodnienie o 50%.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 2;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class GovernmentBonus {
		icon = "Data\UI\Perks\governmentBonus.paa";
		displayName = "Awans";
		description = "Zwiększa wynagrodzenie o 5%.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 3;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class Muscleman {
		icon = "Data\UI\Perks\muscleman.paa";
		displayName = "Siłacz";
		description = "Zwiększa limit przedmiotów o  25%.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 4;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "[] call ULP_fnc_maxCarry;";
		onActivated = "";
	};

	class GeneralMechanic {
		icon = "Data\UI\Perks\generalMechanic.paa";
		displayName = "Majster";
		description = "Zmniejsza prawdopodobieństwo uszkodzenia narzędzi o %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic" };
			level = 5;
			prestige = 0;
			profession[] = { "Repairing", 1 };
		};
		onChanged = "";
		onActivated = "_params + (_bonus / 100)";
	};

	class MindfulPlanner {
		icon = "Data\UI\Perks\mindfulPlanner.paa";
		displayName = "Zawsze gotowy";
		description = "Pojawisz się z mapą, radiem i GPS-em.";
		removalMultiplier = 2;
		class Requirements {
			factions[] = { "Civilian" };
			level = 6;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class StreetCleaner {
		icon = "Data\UI\Perks\vehicleCollector.paa";
		displayName = "Służbista";
		description = "Zwiększa prędkość konfiskaty i niszczenia pojazdów o %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "10 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Police" };
			level = 6;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class SpeedyLocksmith {
		icon = "Data\UI\Perks\speedyLocksmith.paa";
		displayName = "Mistrz wytrychowania";
		description = "Zwiększa szybkość lockpickingu o %1%2.";
		removalMultiplier = 1.3;
		class Leveling {
			maxLevel = 3;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "20 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 7;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class WideTraveller {
		icon = "Data\UI\Perks\wideTraveller.paa";
		displayName = "Podróżnik";
		description = "Umożliwia odradzanie się w Sofii, Agios i Neochori.";
		removalMultiplier = 5;
		class Requirements {
			factions[] = { "Civilian" };
			level = 8;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class CompletedCV {
		icon = "Data\UI\Perks\completedCV.paa";
		displayName = "CV";
		description = "Umożliwia zatrudnienie w różnych miejscach pracy.";
		removalMultiplier = 3;
		class Requirements {
			factions[] = { "Civilian" };
			level = 9;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class LegalTrader {
		icon = "Data\UI\Perks\legalTrader.paa";
		displayName = "Dobry sprzedawca";
		description = "Zwiększa ceny sprzedaży legalnych przedmiotów o %1%2.";
		removalMultiplier = 3;
		class Leveling {
			maxLevel = 3;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "5 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 10;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params + (_params * (_bonus / 100))";
	};

	class RapidSurveyor {
		icon = "Data\UI\Perks\rapidSurveyor.paa";
		displayName = "Archeolog";
		description = "Zwiększa szybkość pomiarów na stronach kopania o %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "15 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian" };
			level = 11;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class BoltCutter {
		icon = "Data\UI\Perks\boltCutter.paa";
		displayName = "Włamywacz";
		description = "Zwiększa prędkość używania nożyc do metalu o %1%2.";
		removalMultiplier = 1.3;
		class Leveling {
			maxLevel = 2;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 12;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class ShadyTrader {
		icon = "Data\UI\Perks\shadyTrader.paa";
		displayName = "Cichy handlarz";
		description = "Zwiększ cenę sprzedaży nielegalnych przedmiotów o %1%2.";
		removalMultiplier = 3;
		class Leveling {
			maxLevel = 2;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "5 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 13;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params + (_params * (_bonus / 100))";
	};

	class cuffCourier {
		icon = "Data\UI\Perks\cuffCourier.paa";
		displayName = "Zakuwacz";
		description = "Pozwala na związywanie innych bez noszenia opasek zaciskowych.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian" };
			level = 14;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class IDForger {
		icon = "Data\UI\Perks\idForger.paa";
		displayName = "Nowe życie";
		description = "Umożliwia podrabianie fałszywych dokumentów tożsamości.";
		removalMultiplier = 3;
		class Requirements {
			factions[] = { "Civilian" };
			level = 15;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class EcoDriver { // TODO
		icon = "Data\UI\Perks\ecoDriver.paa";
		displayName = "Eco Driver";
		description = "Zmniejsza cene paliwa na litr o %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 2;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 16;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class MatesRates {
		icon = "Data\UI\Perks\matesRates.paa";
		displayName = "Lepsza stawka";
		description = "Zmniejsza opłaty za wyciągniecie pojazdów o 50%.";
		removalMultiplier = 6;
		class Requirements {
			factions[] = { "Civilian" };
			level = 17;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class PartsCarrier {
		icon = "Data\UI\Perks\partsCarrier.paa";
		displayName = "Fuszerka";
		description = "Zmniejsza koszty serwisowania samolotu o %1%2.";
		removalMultiplier = 2;
		class Leveling {
			maxLevel = 3;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian" };
			level = 18;
			prestige = 0;
			profession[] = { "Repairing", 3 };
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class ScrapDealer {
		icon = "Data\UI\Perks\scrapDealer.paa";
		displayName = "Złomiarz";
		description = "Zwiększa ilość pieniędzy zarobionych na pocięciu pojazdu o %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 5;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "3 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian" };
			level = 19;
			prestige = 0;
			profession[] = { "Repairing", 3 };
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class SlightofHand { // done
		icon = "Data\UI\Perks\slightOfHand.paa";
		displayName = "Szybkie rączki";
		description = "Zwiększa szybkość przepakowywania magazynków o %1%2.";
		removalMultiplier = 1.5;
		class Leveling {
			maxLevel = 2;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "15 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police" };
			level = 20;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

/*
class SilentKiller {
		icon = "Data\UI\Achievements\UC.paa";
		displayName = "Cichy zabójca";
		description = "Permits access to purchase sound suppressors";
		removalMultiplier = 10;
		class Requirements {
			factions[] = { "Civilian" };
			level = 29;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};
	// do przegadania czy dodajemy
*/

	class VehicleCollector {
		icon = "Data\UI\Perks\vehicleCollector.paa";
		displayName = "Kolekcjoner";
		description = "Zwiększa limit garażu dla każdego typu pojazdu o 1.";
		removalMultiplier = 10;
		class Requirements {
			factions[] = { "Civilian" };
			level = 21;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class BloodCarrier {
		icon = "Data\UI\Perks\bloodCarrier.paa";
		displayName = "Nosiciel krwi";
		description = "Zwiększa wydajność worka z krwią o %1%2.";
		removalMultiplier = 1.2;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 22;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params + (_params * (_bonus / 100))";
	};

	class IntelligentBanker { // TODONOW
		icon = "Data\UI\Perks\intelligentBanker.paa";
		displayName = "Bankier";
		description = "Zmniejsza koszty przelewów bankowych o %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 23;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class HGVDriver {
		icon = "Data\UI\GroupPerks\HEMTTs.paa";
		displayName = "HEMMT";
		description = "Pozwala używać HEMMTów, bez grupy.";
		removalMultiplier = 10;
		class Requirements {
			factions[] = { "Civilian" };
			level = 23;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};


	class FirstAider {
		icon = "Data\UI\Perks\firstAider.paa";
		displayName = "First Aider";
		description = "Zwiększenie skuteczności zestawów pierwszej pomocy o %1%2.";
		removalMultiplier = 1.2;
		class Leveling {
			maxLevel = 5;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "5 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 24;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params + (_params * (_bonus / 100))";
	};

	class PersonalTank {
		icon = "Data\UI\GroupPerks\ifrits.paa";
		displayName = "Czołgista";
		description = "Umożliwia kupno Ifrytów, bez grupy.";
		removalMultiplier = 10;
		class Requirements {
			factions[] = { "Civilian" };
			level = 27;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};


	class SilentLocksmith { // TODO : Add to vehicle lockpicking...
		icon = "Data\UI\Perks\silentLocksmith.paa";
		displayName = "Tajny Agent";
		description = "Zmniejsza prawdopodobieństwo włączenia alarmu o %1%2.";
		removalMultiplier = 1.3;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 25;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class Blackmarketer {
		icon = "Data\UI\Perks\blackmarketer.paa";
		displayName = "Blackmarket";
		description = "Zezwala na dostęp do Blackmarketu.";
		removalMultiplier = 10;
		class Requirements {
			factions[] = { "Civilian" };
			level = 26;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class QuickLearner {
		icon = "Data\UI\Perks\quickLearner.paa";
		displayName = "Szybki uczeń";
		description = "Zwiększa liczbę XP profesji zdobywanych przez 10%.";
		removalMultiplier = 1.5;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 27;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params + (_params * (_bonus / 100))";
	};

	class LandLord {
		icon = "Data\UI\Perks\landLord.paa";
		displayName = "Land Lord";
		description = "Umożliwia zakup dodatkowej nieruchomości.";
		removalMultiplier = 4;
		class Requirements {
			factions[] = { "Civilian" };
			level = 28;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class LifeSaver {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Injury_ca.paa";
		displayName = "Ratownik";
		description = "Zwiększa szybkość odradzania się o %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 5;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "10 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 24;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params + (_params * (_bonus / 100))";
	};


	class rapidStorer {
		icon = "Data\UI\Perks\rapidStorer.paa";
		displayName = "Walet";
		description = "Skraca czas potrzebny na garażowanie pojazdu o %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 3;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "10 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Hato" };
			level = 29;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class UncertainMind {
		icon = "Data\UI\Perks\uncertainPerson.paa";
		displayName = "Lewe Papiery";
		description = "Dodaje szanse na dodanie auta które złomujesz, do garażu.";
		removalMultiplier = 2;
		class Requirements {
			factions[] = { "Civilian" };
			level = 30;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "((random 100) max 1)";
	};
};