class CfgProfessions {
	class Repairing {
		displayName = "Naprawianie";
		icon = "Data\UI\Professions\repairing.paa";
		effectDescription = "Skraca czas potrzebny na naprawę o %1%2";
		effectCalculation = "5 * (_this select 0)"; // (_this select 0) refers to the level of this profession and (_this select 1) is the current xp.
		xpLevel = 100;
		xpMultipler = 2; // XP REQUIRED FOR LEVEL = xpLevel * (xpMultipler * CURRENT LEVEL) (If CURRENT LEVEL = 0 THEN xpMultipler isn't added)
		maxLevel = 5;
	};

	class Fishing {
		displayName = "Łowienie";
		icon = "Data\UI\Professions\fishing.paa";
		effectDescription = "Zmniejsza czas potrzebny na złowienie ryby o %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Gathering {
		displayName = "Zbieranie";
		icon = "Data\UI\Professions\gathering.paa";
		effectDescription = "Skraca czas potrzebny na zebranie danych o %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Mining {
		displayName = "Kopanie";
		icon = "Data\UI\Professions\mining.paa";
		effectDescription = "Skraca czas potrzebny na wydobycie o %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Processing {
		displayName = "Przetwórka";
		icon = "Data\UI\Professions\processing.paa";
		effectDescription = "Skraca czas przetwarzania o %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Cooking {
		displayName = "Gotowanie";
		icon = "Data\UI\Professions\cooking.paa";
		effectDescription = "Zmniejsza czas potrzebny na gotowanie o %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Smelting {
		displayName = "Przetapianie";
		icon = "Data\UI\Professions\smelting.paa";
		effectDescription = "Zmniejsza czas potrzebny do wytopu o %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Archeology {
		displayName = "Archeologia";
		icon = "Data\UI\Professions\archeology.paa";
		effectDescription = "Skraca czas potrzebny na badanie i kopanie o %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};
};