class CfgGroups {
	tax[] = { 0, 25 };

	class Tag {
		MinLength = 1;
		MaxLength = 5;
		Blacklisted[] = { "APC", "APS", "NHS", "AAS", "HATO", "PD", "EMS", "CZA", "NIG", "CWE", "PED", "N1G" };
	};
	
	class Name {
		MinLength = 6;
    	MaxLength = 30;
		Blacklisted[] = { "Policja Altis", "Policja", "Altis Police", "Medycy", "Altis Ambulance Service", "Cywile", "Cywil" };
	};

	ranks[] = {
		"PRIVATE", "CORPORAL", "SERGEANT", "LIEUTENANT", "CAPTAIN", "MAJOR", "COLONEL"
	};

	class Permissions {
		deposit = 3;
		withdraw = 3;
		rank = 4;
		invite = 4;
		kick = 4;
	};

	class Types {
		class Criminal {
			displayName = "Crime";

			class Perks {
				class Hideout {
					displayName = "Przechwytywanie kryjówki";
					icon = "Data\UI\GroupPerks\hideout.paa";
					description = "Masz możliwość przechwytywania kryjówek gangów.";
					level = 1;
				};

				class Blackmarket {
					displayName = "Blackmarket";
					icon = "Data\UI\GroupPerks\blackmarket.paa";
					description = "Masz możliwość dostępu do Blackmarket.";
					level = 2;
				};

				class Ifrits {
					displayName = "Pojazdy opancerzone";
					icon = "Data\UI\GroupPerks\ifrits.paa";
					description = "Masz możliwość dostępu do Ifrytów na Czarnym Rynku.";
					level = 3;
				};

				class Governor {
					displayName = "Gubernatorstwo";
					icon = "Data\UI\GroupPerks\governor.paa";
					description = "Twoi członkowie mają możliwość kandydowania na gubernatora.";
					level = 4;
				};

				class DMT {
					displayName = "Kupno chemikalii";
					icon = "Data\UI\GroupPerks\DMT.paa";
					description = "Twoja grupa może zakupić Dimetylotryptamine do tworzenia narkotyków.";
					level = 5;
				};
			};
		};

		class Corporate {
			displayName = "Firma";

			class Perks {
				class Freight {
					displayName = "Misje ładunkowe";
					icon = "Data\UI\GroupPerks\freight.paa";
					description = "Przyznaje członkom dostęp do Misji ładunkowych.";
					level = 1;
				};

				class HEMTTs {
					displayName = "HEMMT";
					icon = "Data\UI\GroupPerks\HEMTTs.paa";
					description = "Pozwala członkom na dostęp do wszystkich wariantów HEMTT'ów.";
					level = 2;
				};

				class Governor {
					displayName = "Gubernatorstwo";
					icon = "Data\UI\GroupPerks\governor.paa";
					description = "Twoi członkowie mają możliwość kandydowania na gubernatora.";
					level = 3;
				};

				class SecurityContactors {
					displayName = "Ochrona";
					icon = "Data\UI\GroupPerks\securityContactors.paa";
					description = "Daje członkom dostęp do zostania pracownikami ochrony w firmie.";
					level = 4;
				};

				class MilitaryOffices {
					displayName = "Własność biur";
					icon = "Data\UI\GroupPerks\officeBuilding.paa";
					description = "Twoi członkowie mają możliwość zakupu opuszczonego budynku biura wojskowego.";
					level = 5;
				};
			};
		};

		class Party {
			displayName = "Partia Polityczna";

			class Perks {
				class Governor {
					displayName = "Gubernatorstwo";
					icon = "Data\UI\GroupPerks\governor.paa";
					description = "Twoi członkowie mają możliwość kandydowania na gubernatora.";
					level = 1;
				};

				class PersonalProtection {
					displayName = "Ochrona osobista";
					icon = "Data\UI\GroupPerks\personalProtection.paa";
					description = "Daje członkom dostęp do zostania oficerami ochrony osobistej.";
					level = 2;
				};

				class GovernmentSafehouses {
					displayName = "Rządowe kryjówki";
					icon = "Data\UI\GroupPerks\governmentSafehouses.paa";
					description = "Zapewnia członkom dostęp do różnych rządowych kryjówek.";
					level = 3;
				};

				class OfficeBuilding {
					displayName = "Posiadanie biura";
					icon = "Data\UI\GroupPerks\officeBuilding.paa";
					description = "Członkowie mają możliwość zakupu budynku biurowego.";
					level = 4;
				};

				class PollRigging {
					displayName = "Oszustwa wyborcze";
					icon = "Data\UI\GroupPerks\pollRigging.paa";
					description = "Twoi członkowie mają możliwość fałszowania wyników sondaży.";
					level = 5;
				};
			};
		};
	};

	class Leveling {
		baseXp = 2500;
		xpMultiplier = 2;
		maxLevel = 5;

		class XP {
			class HoldingCartel {
				amount = 3;
			};
			class Cartel {
				amount = 25;
			};
			class Popup : Cartel {
				amount = 30;
			};
			class Airdrop : Cartel {};
			class Shipwreck : Cartel {};
			class Freight {
				amount = 10;
			};
			class Election {
				amount = 500;
			}; // TODONOW
			class Rigging {
				amount = 35;
			};
			class Hideout : Cartel {};
			class BaseBid : Election {}; // TODONOW
			class Contraband : Freight {}; // TODONOW
			class CommunityGoals : Freight {}; // TODO
			class MedicalAid {
				amount = 3;
			};
			class Robbery : Freight {};
			class SoldLegalItems : Freight {
				amount = 500; // When dynamic this is the max amount of xp
				amountPerItem = 4; // This is a unique setting for this category
			};
		};
	};

	class Buffs {
		class Missions {
			displayName = "Zwiększone wypłaty z misji";
			icon = "Data\UI\GroupBuffs\missions.paa";
			max = 0.25;
		};
		class Lockpicking : Missions {
			displayName = "Zwiększona szybkość wytrychowania";
			icon = "Data\UI\GroupBuffs\lockpicking.paa";
		};
		class Boltcutting : Missions {
			displayName = "Zwiększona prędkość cięcia nożycami";
			icon = "Data\UI\GroupBuffs\boltcutting.paa";
		};
		class Hacking : Missions {
			displayName = "Zwiększona szybkość hakowania";
			icon = "Data\UI\GroupBuffs\hacking.paa";
		};
		class Surveying : Missions {
			displayName = "Zwiększona szybkość badań archeologicznych";
			icon = "Data\UI\GroupBuffs\surveying.paa";
		};
		class Digging : Missions {
			displayName = "Zwiększona prędkość kopania";
			icon = "Data\UI\GroupBuffs\digging.paa";
		};
	};
};
