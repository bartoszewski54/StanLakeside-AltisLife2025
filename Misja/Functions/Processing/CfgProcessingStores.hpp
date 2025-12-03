class CfgProcessingStores {
	class Base {
		factions[] = { "Civilian" };
		condition = "true";
	};

	class Gold : Base {
		title = "Kupiec złota";
		factions[] = { "Civilian", "Police" };
		processes[] = { "Gold" };
	};

	class Decrypter : Base {
		title = "Hacker";
		factions[] = { "Civilian", "Police" };
		processes[] = { "Secrets" };
	};

	class PublicCookhouse : Base {
		title = "Publiczna kuchnia";
		processes[] = { "Salema", "Ornate", "Mackerel", "Tuna", "Mullet", "Catshark" };
	};

	class Schnapps : Base {
		title = "Przetwarzanie mocnych alkoholi";
		processes[] = { "SchnapsApple", "SchnapsPeach" };
	};

	class Tobacco : Base {
		title = "Przetwarzanie tytoniu";
		processes[] = { "Cigarette", "Cigar" };
	};

	class Copper : Base {
		title = "Przetwarzanie miedzi";
		processes[] = { "Copper" };
	};

	class Silver : Base {
		title = "Przetwarzanie srebra";
		processes[] = { "Silver" };
	};

	class Iron : Base {
		title = "Przetwarzanie żelaza";
		processes[] = { "Iron" };
	};

	class Uranium : Base {
		title = "Przetwarzanie uranu";
		processes[] = { "Uranium" };
	};

	class Diamond : Base {
		title = "Przetwarzanie diamentów";
		processes[] = { "Diamond" };
	};

	class Salt : Base {
		title = "Przetwarzanie soli";
		processes[] = { "Salt" };
	};

	class Sand : Base {
		title = "Przetwarzanie piasku";
		processes[] = { "Sand" };
	};

	class Oil : Base {
		title = "Przetwarzanie oleju";
		processes[] = { "Oil" };
	};

	class Weed : Base {
		title = "Przetwarzanie zioła";
		processes[] = { "Weed" };
	};

	class Heroin : Base {
		title = "Przetwarzanie heroiny";
		processes[] = { "Heroin" };
	};

	class Cocaine : Base {
		title = "Przetwarzanie kokainy";
		processes[] = { "Cocaine" };
	};

	class Meth : Base {
		title = "Przetwarzanie mety";
		processes[] = { "Meth" };
	};

	class Moonshine : Base {
		title = "Przetwarzanie bimbru";
		processes[] = { "Moonshine" };
	};

	class Purifier : Base {
		title = "Oczyszczalnia narkotyków";
		processes[] = { "PurifiedWeed", "PurifiedHeroin", "PurifiedCocaine", "PurifiedMeth", "PurifiedMoonshine" };
		condition = "[""Northern""] call ULP_fnc_ownsCartel";
	};

	class MultiDrug : Base {
		title = "Oczyszczalnia wielu narkotyków";
		processes[] = { "Weed", "Heroin", "Cocaine", "Meth", "Moonshine" };
	};
};