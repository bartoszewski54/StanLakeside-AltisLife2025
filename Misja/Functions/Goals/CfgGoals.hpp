class CfgGoals {
	class Personal {
		class Daily {
			Amount = 3;

			class ArrestPeople {
				item = ""; // For goals like these we don't provide an item, the field is still required
				icon = "Data\UI\Goals\arrests.paa"; // Optional override
				title = "Aresztuj Przestępców";
				description = "Aresztuj troche przestępców przed końcem dnia!";
				tiers[] = { 1, 5, 10 };
				factions[] = { "Police" };
				class Event {
					eventType = "ArrestedSomeone";
					getQuantity = "1";
				};
				condition = "true";
			};

			class RevivePeople  : ArrestPeople {
				icon = "\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\heal_ca.paa";
				title = "Zreanimuj osoby";
				description = "Podnieś osoby przed końcem dnia!";
				tiers[] = { 1, 10, 25 };
				factions[] = { "Medic" };
				class Event {
					eventType = "RevivedSomeone";
					getQuantity = "1";
				};
			};

			class GatherApple {
				item = "FreshApple";
				title = "Zbierz jabłka";
				description = "Zbierz świeże jabłka przed końcem dnia!";
				tiers[] = { 250, 500, 1000 };
				factions[] = { "Civilian" };
				class Event {
					eventType = "GatheredVirtualItem";
					getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
				};
				condition = "true";
			};

			class GatherPeach : GatherApple {
				item = "FreshPeach";
				title = "Zbierz brzoskwinie";
				description = "Zbierz świeże brzoskwinie przed końcem dnia!";
			};

			class GatherCoral : GatherApple {
				item = "Coral";
				title = "Zbierz rafę koralową";
				description = "Zbierz rafe koralową przed końcem dnia!";
				tiers[] = { 100, 300, 500 };
			};

			class GatherCorn : GatherApple {
				item = "Corn";
				title = "Zbierz Kukurydzę";
				description = "Zbierz kukurydzę przed końcem dnia!";
			};

			class MineCoal : GatherApple {
				item = "Coal";
				title = "Wykop Węgiel";
				description = "Wykop węgiel przed końcem dnia!";
				tiers[] = { 100, 300, 750 };
			};

			class MineCopper : MineCoal {
				item = "CopperOre";
				title = "Wykop miedź";
				description = "Wykop miedź przed końcem dnia!";
			};

			class MineSilver : MineCoal {
				item = "SilverOre";
				title = "Wykop Srebro";
				description = "Wykop Srebro przed końcem dnia!";
			};

			class MineIron : MineCoal {
				item = "IronOre";
				title = "Wykop żelazo";
				description = "Wykop żelazo przed końcem dnia!";
			};

			class ProcessTobacco {
				item = "Tobacco";
				title = "Przetwórz Tytoń";
				description = "Przetwórz tytoń przed końcem dnia!!";
				tiers[] = { 100, 250, 500 };
				factions[] = { "Civilian" };
				class Event {
					eventType = "ProcessedVirtualItem";
					getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
				};
				condition = "true";
			};

			class ProcessOil : ProcessTobacco {
				item = "UnprocessedOil";
				title = "Przetwórz Olej";
				description = "Przetwórz olej przed końcem dnia!";
			};
			
			class ProcessSand : ProcessTobacco {
				item = "Sand";
				title = "Przetwórz Piasek";
				description = "Przetwórz piasek przed końcem dnia!";
			};

			class ProcessSalt : ProcessTobacco {
				item = "UnrefinedSalt";
				title = "Przetwórz Sól";
				description = "Przetwórz sól przed końcem dnia!";
			};

			class UncutDiamond : ProcessTobacco {
				item = "UncutDiamond";
				title = "Oszlifuj Diamenty";
				description = "Oszlifuj diamenty przed końcem dnia!";
			};

			class ProcessUranium : ProcessTobacco {
				item = "UraniumOre";
				title = "Przetwórz Uran";
				description = "Przetwórz Uran przed końcem dnia!";
				tiers[] = { 100, 200, 300 };
			};
		};

		class Weekly {
			Amount = 2;

			class SellSchnapps {
				item = "Schnapps";
				title = "Sprzedaj Wódkę";
				description = "Sprzedaj wódkę do końca tygodnia!";
				tiers[] = { 1000, 2000, 3000 };
				factions[] = { "Civilian" };
				class Event {
					eventType = "SoldVirtualItem";
					getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
				};
				condition = "true";
			};

			class SellCigarette : SellSchnapps {
				item = "Cigarette";
				title = "Sprzedaj papierosy";
				description = "Sprzedaj papierosy do końca tygodnia!";
			};

			class SellCigar : SellSchnapps {
				item = "Cigar";
				title = "Sprzedaj Cygara";
				description = "Sprzedaj cygara do końca tygodnia!";
			};

			class SellCopper : SellSchnapps {
				item = "CopperBar";
				title = "Sprzedaj Miedź";
				description = "Sprzedaj miedź do końca tygodnia!";
			};

			class SellSilver : SellSchnapps {
				item = "SilverBar";
				title = "Sprzeadj Srebro";
				description = "Sprzedaj srebro do końca tygodnia!";
			};

			class SellIron : SellSchnapps {
				item = "IronBar";
				title = "Sprzedaj Żelazo";
				description = "Sprzedaj Żelazo do końca tygodnia!";
			};

			class SellSand : SellSchnapps {
				item = "Glass";
				title = "Sprzedaj Szkło";
				description = "Sprzedaj Szkło do końca tygodnia!";
			};

			class SellSalt : SellSchnapps {
				item = "RefinedSalt";
				title = "Sprzedaj Sól";
				description = "Sprzedaj Sól do końca tygodnia!";
			};

			class SellDiamond : SellSchnapps {
				item = "CutDiamond";
				title = "Sprzedaj Diamenty";
				description = "Sprzedaj Diamenty do końca tygodnia!";
			};

			class SellMoonshine : SellSchnapps {
				item = "Moonshine";
				title = "Sprzedaj Bimber";
				description = "Sprzedaj Bimber do końca tygodnia!";
			};
		};
	};

	class Community {
		amountPerFaction[] =  { { "Police", 1 }, { "Medic", 1 }, { "Hato", 1 }, { "Civilian", 2 } };

		class ArrestPeople {
			item = ""; // For goals like these we don't provide an item, the field is still required
			icon = "Data\UI\Goals\arrests.paa"; // Optional override
			title = "Aresztuj przestępców";
			basePayout = 50000;
			maxPayout = 500000;
			tiers[] = { 25, 100, 200 };
			duration = 14;
			factions[] = { "Police" };
			class Event {
				eventType = "ArrestedSomeone";
				getQuantity = "1";
			};
		};

		class IssueTickets : ArrestPeople {
			title = "Wystaw mandat (opłacony)";
			maxPayout = 5000000;
			tiers[] = { 5000000, 7000000, 10000000 };
			class Event {
				eventType = "TicketPaid";
				getQuantity = "(_this select 1) params [ """", ""_amount"", ""_paid"" ]; if !(_paid) exitWith { 0 }; _amount";
			};
		};
		class RevivePeople {
			item = ""; // For goals like these we don't provide an item, the field is still required
			icon = "\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\heal_ca.paa"; // Optional override
			title = "Zreanimuj graczy";
			basePayout = 50000;
			maxPayout = 500000;
			tiers[] = { 25, 100, 200 };
			duration = 7;
			factions[] = { "Medic" };
			class Event {
				eventType = "RevivedSomeone";
				getQuantity = "1";
			};
		};
		
		class GatherApple {
			item = "FreshApple";
			title = "Zbierz jabłka";
			basePayout = 1000000;
			maxPayout = 16000000;
			tiers[] = { 2000, 3600, 4880, 5904, 6723, 7378, 7902, 8321, 8656, 9000 };
			duration = 14; // In days
			factions[] = { "Civilian" };
			class Event {
				eventType = "GatheredVirtualItem";
				getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
			};
		};

		class SellSchnapps {
			item = "Schnapps";
			title = "Sprzedaj Wódkę";
			basePayout = 1000000;
			maxPayout = 16000000;
			tiers[] = { 2000, 3600, 4880, 5904, 6723, 7378, 7902, 8321, 8656, 9000 };
			duration = 14; // In days
			factions[] = { "Civilian" };
			class Event {
				eventType = "SoldVirtualItem";
				getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
			};
		};

		class SellCigarette : SellSchnapps {
			item = "Cigarette";
			title = "Sprzedaj Papierosy";
		};

		class SellCigar : SellSchnapps {
			item = "Cigar";
			title = "Sprzedaj Cygara";
		};

		class SellCopper : SellSchnapps {
			item = "CopperBar";
			title = "Sprzedaj Miedź";
		};

		class SellSilver : SellSchnapps {
			item = "SilverBar";
			title = "Sprzedaj Srebro";
		};

		class SellIron : SellSchnapps {
			item = "IronBar";
			title = "Sprzedaj Żelazo";
		};

		class SellSand : SellSchnapps {
			item = "Glass";
			title = "Sprzedaj Szkło";
		};

		class SellSalt : SellSchnapps {
			item = "RefinedSalt";
			title = "Sprzedaj Sól";
		};

		class SellDiamond : SellSchnapps {
			item = "CutDiamond";
			title = "Sprzedaj Diamenty";
		};

		class SellMoonshine : SellSchnapps {
			item = "Moonshine";
			title = "Sprzedaj Bimber";
		};
	};
};