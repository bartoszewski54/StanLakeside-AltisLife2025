class CfgBlueprints {
	class CraftingMaterials {
		displayName = "Materiały do craftingu";

		class B_Clay {
			icon = "Data\Icons\clay.paa";
			displayName = "Glina";
			description = "Zwykły materiał do craftingu.";
			materials[] = { {"Sand", 2}, {"Water", 1} };
			item = "Clay";
			isDefault = true;
			workbench = false;
			time = 2;
		};
		class B_Plank : B_Clay {
			icon = "Data\Icons\wood.paa";
			displayName = "Deska";
			description = "Przetworzone drewno.";
			materials[] = { {"Wood", 2} };
			item = "Plank";
			time = 2;
		};
		class B_Steel : B_Clay {
			icon = "Data\Icons\ingot.paa";
			displayName = "Sztabka stali";
			description = "Przetworzony metal.";
			materials[] = { {"IronBar", 2}, {"ProcessedOil", 1} };
			item = "SteelBar";
			workbench = true;
			time = 3;
		};
		class B_ExplosiveMaterials : B_Steel {
			icon = "Data\Icons\explosiveMaterials.paa";
			displayName = "Ładunki wybuchowe";
			description = "Pakiet ładunków wybuchowych, często potrzebne do craftingu.";
			materials[] = { {"IronBar", 64}, {"ProcessedOil", 18}, {"SeizedContraband", 2} };
			item = "ExplosiveMaterials";
			isDefault = false;
			workbench = true;
			time = 90;
		};
	};

	class Tools {
		displayName = "Narzędzia";

		class B_Toolbox {
			icon = "Data\Icons\toolbox.paa";
			displayName = "Toolbox";
			description = "Używany głównie w rozkładaniu różnych rzeczy na kawałki.";
			materials[] = { {"IronBar", 4} };
			item = "Toolbox";
			isDefault = true;
			workbench = false;
			time = 40;
		};
		class B_Pickaxe : B_Toolbox {
			icon = "Data\Icons\pickaxe.paa";
			displayName = "Kilof";
			description = "Używany w pozyskiwaniu różnych minerałów.";
			materials[] = { {"IronBar", 3}, {"Wood", 2} };
			item = "Pickaxe";
			isDefault = false;
		};
		class B_LumberAxe : B_Pickaxe {
			icon = "Data\Icons\lumberAxe.paa";
			displayName = "Siekiera";
			item = "LumberAxe";
		};
		class B_Shovel : B_Pickaxe {
			icon = "Data\Icons\shovel.paa";
			displayName = "Łopata";
			materials[] = { {"IronBar", 1}, {"Wood", 2} };
			item = "Shovel";
		};
		class B_Extractor : B_Pickaxe {
			icon = "Data\Icons\extractor.paa";
			displayName = "Ekstraktor";
			materials[] = { {"SteelBar", 4}, {"SilverBar", 2} };
			item = "Extractor";
		};
		class B_SurveyingEquipment : B_Pickaxe {
			icon = "Data\Icons\surveyingEquipment.paa";
			displayName = "Narzędzia badawcze";
			description = "Możesz go użyć na strefach archeologicznych.";
			materials[] = { {"CopperBar", 4}, {"SilverBar", 2}, {"Glass", 1} };
			item = "SurveyingEquipment";
			workbench = true;
			time = 60;
		};
		class B_ArchaeologistsEquipment : B_SurveyingEquipment {
			icon = "Data\Icons\archaeologistsEquipment.paa";
			displayName = "Narzędzia Archeologa";
			description = "Używany do delikatnych wykopów na strefach archeologicznych.";
			materials[] = { {"Pickaxe", 1}, {"Shovel", 1}, {"SharpStoneKnife", 1} };
			item = "ArchaeologistsEquipment";
		};
		class B_FuelCan : B_Pickaxe {
			icon = "Data\Icons\fuelCan.paa";
			displayName = "Kanister";
			description = "Przydatny, gdy zabraknie ci paliwa.";
			materials[] = { {"IronBar", 7}, {"ProcessedOil", 2} };
			item = "fuelCan";
			time = 30;
		};
		class B_Lighter : B_Pickaxe {
			icon = "Data\Icons\lighter.paa";
			displayName = "Zapalniczka";
			description = "Masz ognia?";
			materials[] = { {"Iron", 3}, {"ProcessedOil", 1} };
			item = "Lighter";
			time = 20;
		};
		class B_Lockpick : B_Pickaxe {
			icon = "Data\Icons\lockpick.paa";
			displayName = "Wytrych";
			description = "Używany do włamywania się do pojazdów lub kajdanek.";
			materials[] = { {"Iron", 4} };
			item = "Lockpick";
			time = 30;
		};
		class B_BoltCutter : B_Pickaxe {
			icon = "Data\Icons\boltCutter.paa";
			displayName = "Nożyce do metalu";
			description = "Może przeciąć wzmacniane kłódki, drzwi i Airdropy.";
			materials[] = { {"SteelBar", 16} };
			item = "BoltCutter";
			workbench = true;
			time = 60;
		};
		class B_HackingDevice : B_BoltCutter {
			icon = "Data\Icons\hackingDevice.paa";
			displayName = "HackRF";
			description = "Służy do włamywania się do róznych systemów.";
			materials[] = { {"Silver", 8}, {"CutDiamond", 4}, {"DecryptedDrive", 1} };
			item = "HackingDevice";
			time = 300;
		};
		class B_ExplosiveCharge : B_BoltCutter {
			icon = "Data\Icons\explosiveCharge.paa";
			displayName = "Pakiet ładunków wybuchowych";
			description = "Może zniszczyc wiele zabarykadowanych miejsc.";
			materials[] = { {"ExplosiveMaterials", 8}, {"Coal", 14}, {"CutDiamond", 6}, {"BrokenTimepiece", 1} };
			item = "ExplosiveCharge";
			time = 360;
		};
		class B_IndustrialDrill : B_ExplosiveCharge {
			icon = "Data\Icons\industrialDrill.paa";
			displayName = "Wiertło przemysłowe";
			materials[] = { {"SteelBar", 16}, {"CutDiamond", 4}, {"DrillBit", 1} };
			item = "IndustrialDrill";
		};
	};

	class PoliceEquipment {
		displayName = "Policyjne";

		class B_PanicButton {
			icon = "Data\Icons\panicButton.paa";
			displayName = "Panic Button";
			description = "Gdy naciśnięty, informuje wszystkich policjantów o tym że jesteś w niebezpieczeństwie.";
			materials[] = { {"CopperBar", 20}, {"SilverBar", 16}, {"Glass", 2} };
			item = "PanicButton";
			isDefault = false;
			workbench = true;
			time = 90;
		};
		class B_MakeshiftStinger : B_PanicButton {
			icon = "Data\Icons\stinger.paa";
			displayName = "Kolczatka";
			description = "Przydatna na zbyt długich pościgach.";
			materials[] = { {"SteelBar", 45}, {"Ziptie", 6} };
			item = "MakeshiftStinger";
			time = 180;
		};
	};

	class MedicalEquipment {
		displayName = "Medyczne";

		class B_FieldDressing {
			icon = "Data\Icons\fieldDressing.paa";
			displayName = "Plasterek";
			description = "Na otarcia powinien wystarczyć.";
			materials[] = { {"Bandage", 1} };
			item = "FieldDressing";
			isDefault = true;
			workbench = false;
			time = 15;
		};
		class B_Packing : B_FieldDressing {
			icon = "Data\Icons\packingBandage.paa";
			displayName = "Bandaż";
			description = "Do poważniejszych obrażeń.";
			materials[] = { {"Bandage", 2} };
			item = "Packing";
		};
		class B_Elastic : B_FieldDressing {
			icon = "Data\Icons\elasticBandage.paa";
			displayName = "Bandaż elastyczny";
			description = "Uciska tam gdzie musi.";
			item = "Elastic";
		};
		class B_QuickClot : B_FieldDressing {
			icon = "Data\Icons\quikClot.paa";
			displayName = "Bandaż wojskowy";
			description = "Do naprawde poważnych obrażeń.";
			materials[] = { {"Bandage", 1}, {"Sand", 1} };
			item = "Elastic";
		};
		class B_FirstAidKit : B_FieldDressing {
			icon = "Data\Icons\firstAidKit.paa";
			displayName = "Apteczka pierwszej pomocy";
			description = "Przydatna, na mniejsze obrażenia";
			materials[] = { {"Painkillers", 2}, {"Bandage", 4}, {"BloodBag", 1} };
			item = "FirstAidKit";
			workbench = true;
			time = 120;
		};
		class B_MediKit : B_FirstAidKit {
			icon = "Data\Icons\mediKit.paa";
			displayName = "MediKit";
			materials[] = { {"Painkillers", 5}, {"Morphine", 2}, {"Epinephrine", 1}, {"Bandage", 10}, {"BloodBag", 3} };
			item = "MediKit";
		};
		class B_AutomatedExternalDefibrillator : B_FirstAidKit {
			icon = "Data\Icons\defibrillator.paa";
			displayName = "Automatyczny defibrylator";
			materials[] = { {"SilverBar", 6}, {"CutDiamond", 2} };
			item = "AutomatedExternalDefibrillator";
			time = 180;
		};
	};

	class Electronics {
		displayName = "Elektronika";

		class B_MiningRig {
			icon = "Data\Icons\miningRig.paa";
			ddisplayName = "Koparka Kryptowalut";
			description = "Możesz ją postawić w magazynie.";
			materials[] = { {"Motherboard", 1}, {"CPU", 1}, {"GPU", 2}, {"RAM", 4}, {"PSU", 1} };
			item = "MiningRig";
			isDefault = false;
			workbench = true;
			time = 300;
		};
		class B_Motherboard : B_MiningRig {
			icon = "Data\Icons\motherboard.paa";
			displayName = "Płyta główna";
			description = "Główny komponent komputera.";
			materials[] = { {"Motherboard", 1} };
			item = "Motherboard";
			time = 180;
		};
		class B_CPU : B_Motherboard {
			icon = "Data\Icons\cpu.paa";
			displayName = "CPU";
			item = "CPU";
		};
		class B_GPU : B_Motherboard {
			icon = "Data\Icons\gpu.paa";
			displayName = "GPU";
			item = "GPU";
		};
		class B_RAM : B_Motherboard {
			icon = "Data\Icons\ram.paa";
			displayName = "Kość RAM";
			item = "RAM";
		};
		class B_PSU : B_Motherboard {
			icon = "Data\Icons\psu.paa";
			displayName = "Zasilacz";
			item = "PSU";
		};
	};

	class Archaeology {
		displayName = "Archeologia";
		
		class B_CommonMap {
			icon = "Data\Icons\map.paa";
			displayName = "Zwykła mapa";
			description = "Zawiera znane miejscówki do kopania na Altisie.";
			materials[] = { {"CommonMapFragment", 4} };
			item = "CommonMap";
			isDefault = true;
			workbench = false;
			time = 90;
		};
		class B_UncommonMap : B_CommonMap {
			icon = "Data\Icons\map.paa";
			displayName = "Niezwykła mapa";
			materials[] = { {"UncommonMapFragment", 4} };
			item = "UncommonMap";
		};
		class B_RareMap : B_CommonMap {
			icon = "Data\Icons\map.paa";
			displayName = "Rzadka Mapa";
			materials[] = { {"RareMapFragment", 4} };
			item = "RareMap";
		};
		class B_CoinBundle : B_CommonMap {
			icon = "Data\Icons\coinBundle.paa";
			displayName = "Worek z monetami";
			description = "Możesz to sprzedać u archeologików.";
			materials[] = { {"OldCoin", 30} };
			item = "CoinBundle";
		};
		class B_RestoredPot : B_CoinBundle {
			icon = "Data\Icons\restoredPot.paa";
			displayName = "Odrestaurtowana Doniczka";
			description = "Możesz to sprzedać u archeologików.";
			materials[] = { {"BrokenPot", 1}, {"Clay", 3} };
			item = "RestoredPot";
			time = 300;
		};
		class B_SharpStoneKnife : B_RestoredPot {
			icon = "Data\Icons\sharpStoneKnife.paa";
			displayName = "Ostry Nóż";
			materials[] = { {"BluntStoneKnife", 1}, {"Rock", 1} };
			item = "SharpStoneKnife";
		};
		class B_IdentifiedSkull : B_RestoredPot {
			icon = "Data\Icons\unidentifiedSkull.paa";
			displayName = "Czaszka";
			materials[] = { {"UnidentifiedSkull", 1}, {"DecryptedDrive", 1} };
			item = "IdentifiedSkull";
			time = 60;
		};
		class B_DiamondRing : B_RestoredPot {
			icon = "Data\Icons\diamondRing.paa";
			displayName = "Diamentowy pierścionek";
			materials[] = { {"StrongMetalRing", 1}, {"CutDiamond", 1} };
			item = "DiamondRing";
			time = 25;
		};
	};
};