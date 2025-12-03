class CfgVirtualStores {
	class Police {
		storeName = "Wyposażenie - Policja";
		conditions = "[player, [""Police""]] call ULP_fnc_isFaction";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class FuelCan {};
			//class Breathalyser {};
			class PanicButton {};
			class Stinger {};
			class Blindfold {};
			class Lockpick {};
			class BigRedKey {};
			//class Painkillers {};
			class FieldDressing {};
			class BloodBag {};
			//class Morphine {};
			//class Epinephrine {};
			class FirstAidKit {};
			class MediKit {};
			class AutomatedExternalDefibrillator {};
			class TapeSign_F {};
			//class PlasticBarrier_02_yellow_F {};
			//class PlasticBarrier_02_grey_F {};
			//class PlasticBarrier_03_orange_F {};
			//class PlasticBarrier_03_blue_F {};
			//class RoadBarrier_small_F {};
			//class RoadBarrier_F {};
			class RoadCone_F {};
			class RoadCone_L_F {};
			class Land_PortableLight_single_F {};
			class Land_PortableLight_double_F {};
			//class TargetP_Inf4_F {};
			//class TargetP_Civ_F {};
			//class TargetP_Civ3_F {};
		};
	};

	class Medic {
		storeName = "Wyposażenie - Medycy";
		conditions = "[player, [""Medic""]] call ULP_fnc_isFaction";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class Sweetie {};
			class FuelCan {};
			class PanicButton {};
			class Lockpick {};
			//class Painkillers {};
			class FieldDressing {};
			class Elastic {};
			class Packing {};
			class QuickClot {};
			class BloodBag {};
			//class Morphine {};
			//class Epinephrine {};
			class FirstAidKit {};
			class MediKit {};
			class AutomatedExternalDefibrillator {};
			class Stretcher {};
			class TapeSign_F {};
			//class PlasticBarrier_02_yellow_F {};
			//class PlasticBarrier_02_grey_F {};
			//class PlasticBarrier_03_orange_F {};
			//class PlasticBarrier_03_blue_F {};
			//class RoadBarrier_small_F {};
			//class RoadBarrier_F {};
			class RoadCone_F {};
			class RoadCone_L_F {};
			class Land_PortableLight_single_F {};
			class Land_PortableLight_double_F {};
		};
	};
	class Hato {
		storeName = "Wyposażenie - HATO";
		conditions = "[player, [""Hato""]] call ULP_fnc_isFaction";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class FuelCan {};
			class PanicButton {};
			class Lockpick {};
			class VehicleClamp {};
			class FieldDressing {};
			class BloodBag {};
			//class Morphine {};
			//class Epinephrine {};
			class FirstAidKit {};
			class MediKit {};
			class AutomatedExternalDefibrillator {};
			class TapeSign_F {};
			//class PlasticBarrier_02_yellow_F {};
			//class PlasticBarrier_02_grey_F {};
			//class PlasticBarrier_03_orange_F {};
			//class PlasticBarrier_03_blue_F {};
			//class RoadBarrier_small_F {};
			//class RoadBarrier_F {};
			class RoadCone_F {};
			class RoadCone_L_F {};
			class Land_PortableLight_single_F {};
			class Land_PortableLight_double_F {};
		};
	};

	class Civilian {
		storeName = "Wielobranżowy";
		conditions = "true";
		class Items {
			class FreshApple {};
			class Apple {};
			class FreshPeach {};
			class Peach {};
			class Bacon {};
			class Water {};
			class Pickaxe {};
			class LumberAxe {};
            class Extractor {};
			class Shovel {};
			class FishingNet {};
			class FirstAidKit {};
			class MediKit {};
			class Painkillers {};
			class FuelCan {};
			class Lighter {};
			class Lockpick {};
			class Toolbox {};
			class Plank {};
		};
	};

	class Investor {
		storeName = "Donatorka";
		conditions = "([] call ULP_fnc_donatorLevel > 0)";
		class Items {
			class FreshApple {};
			class Apple {};
			class FreshPeach {};
			class Peach {};
			class Bacon {};
			class Water {};
			class Pickaxe {};
			class LumberAxe {};
            class Extractor {};
			class Shovel {};
			class FishingNet {};
			class FirstAidKit {};
			class Painkillers {};
			class FuelCan {};
			class Lighter {};
			class Lockpick {};
			class Toolbox {};
			class Plank {};
		};
	};

	class Government {
		storeName = "Sklep rządu";
		conditions = "[] call ULP_fnc_isGovernor || { [] call ULP_fnc_isProtection }";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class PanicButton {};
			class Painkillers {};
			class FieldDressing {};
			class BloodBag {};
			class FirstAidKit {};
			class MediKit {};
		};
	};

	class Hideout {
		storeName = "Szmugler";
		conditions = "true";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lockpick {};
			//class Painkillers {};
			class FieldDressing {};
			class FirstAidKit {};
			class BoltCutter {};
		};
	};

	class Rebel {
		storeName = "Rebelia";
		conditions = "[""Rebel""] call ULP_fnc_hasLicense";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lockpick {};
			class BoltCutter {};
			class FirstAidKit {};
			class Med {};
			class MediKit {};
		};
	};

	class Blackmarket {
		storeName = "Blackmarket";
		conditions = "[""Blackmarket""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk || [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lockpick {};
			class BoltCutter {};
			class HackingDevice {};
			class ExplosiveCharge {};
			class IndustrialDrill {};
			//class Painkillers {};
			class FieldDressing {};
			class FirstAidKit {};
			class MediKit {};
		};
	};

	class Base : Rebel {
		storeName = "Sklep gangowy - ogólne";
		conditions = "true";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lockpick {};
			class BoltCutter {};
			class HackingDevice {};
			class ExplosiveCharge {};
			class IndustrialDrill {};
			//class Painkillers {};
			class FieldDressing {};
			class FirstAidKit {};
		};
	};

	class Burger {
		storeName = "Redburger";
		conditions = "true";
		class Items {
			class Burger {};
			class Hotdog {};
			class Chips {};
			class Water {};
			class Redbull {};
		};
	};

	class Tea {
		storeName = "Kawiarenka";
		conditions = "true";
		class Items {
			class Doughnut {};
			class Coffee {};
			class Tea {};
		};
	};

	class Pub {
		storeName = "Pub";
		conditions = "true";
		class Items {
			class Beer {};
			class Schnapps {};
			class Gin {};
			class Whiskey {};
		};
	};

	class Medical {
		storeName = "Magazyn medyczny";
		conditions = "true";
		class Items {
			class Painkillers {};
			class Bandage {};
			class FieldDressing {};
			class Elastic {};
			class Packing {};
			class QuickClot {};
			class BloodBag {};
			class Morphine {};
			class Epinephrine {};
			class FirstAidKit {};
			class AutomatedExternalDefibrillator {};
		};
	};

	class Fish {
		storeName = "Sklep rybny";
		conditions = "true";
		class Items {
			class Salema_F_Raw {};
			class CookedSalema {};
			class Ornate_random_F_Raw {};
			class CookedOrnate {};
			class Mackerel_F_Raw {};
			class CookedMackerel {};
			class Tuna_F_Raw {};
			class CookedTuna {};
			class Mullet_F_Raw {};
			class CookedMullet {};
			class CatShark_F_Raw {};
			class CookedCatshark {};
		};
	};

	class Turtle {
		storeName = "Skup turtusi";
		conditions = "true";
		class Items {
			class Turtle_F_Raw {};
		};
	};
	
	class Cigarette {
		storeName = "Skup papierosów";
		conditions = "true";
		class Items {
			class Lighter {};
			class Cigarette {};
		};
	};

	class Cigar {
		storeName = "Skup cygar";
		conditions = "true";
		class Items {
			class Lighter {};
			class Cigar {};
		};
	};

	class Coal {
		storeName = "Skup węgla";
		conditions = "true";
		class Items {
			class Coal {};
		};
	};

	class Coral {
		storeName = "Skup raf koralowych";
		conditions = "true";
		class Items {
			class Coral {};
		};
	};

	class Glass {
		storeName = "Skup szkła";
		conditions = "true";
		class Items {
			class Glass {};
		};
	};

	class Salt {
		storeName = "Skup Soli";
		conditions = "true";
		class Items {
			class RefinedSalt {};
		};
	};

	class Diamond {
		storeName = "Handlarz diamentami";
		conditions = "true";
		class Items {
			class CutDiamond {};
		};
	};

	class Oil {
		storeName = "Skup oleju";
		conditions = "true";
		class Items {
			class ProcessedOil {};
		};
	};

	class Metal {
		storeName = "Export metali";
		conditions = "true";
		class Items {
			class CopperBar {};
			class SilverBar {};
			class IronBar {};
		};
	};

	class Uranium {
		storeName = "Skup uranu";
		conditions = "true";
		class Items {
			class UraniumBar {};
		};
	};

	class Gold {
		storeName = "Skup złota";
		conditions = "true";
		class Items {
			class MarkedGold {};
			class UnmarkedGold {};
		};
	};

	class Secrets {
		storeName = "Nieznany kupiec";
		conditions = "true";
		class Items {
			class SpaceCapsuleDataDrive {};
			class EncryptedDrive {};
			class DecryptedDrive {};
		};
	};

	class Contraband {
		storeName = "Handlarz kontrabandą";
		conditions = "true";
		class Items {
			class SeizedContraband {};
		};
	};

	class Dispensary {
		storeName = "Dystrybutor metamfetaminy";
		conditions = "true";
		class Items {
			class EphedrineBarrel {};
		};
	};

	class Art {
		storeName = "Skup obrazów";
		conditions = "true";
		class Items {
			class SmallGalleryPiece {};
			class MediumGalleryPiece {};
			class LargeGalleryPiece {};
		};
	};

	class Drug {
		storeName = "Dealer narkotyków";
		conditions = "true";
		class Items {
			class ProcessedWeed {};
			class PurifiedWeed {};
			class ProcessedHeroin {};
			class PurifiedHeroin {};
			class ProcessedCocaine {};
			class PurifiedCocaine {};
			class ProcessedMeth {};
			class PurifiedMeth {};
			class Moonshine {};
			class PurifiedMoonshine {};
			class Ecstasy {};
		};
	};

	class HMP {
		storeName = "Kantyna";
		conditions = "ULP_Imprisioned";
		class Items {
			class RationPack {};
			class Water {};
			class Pickaxe {};
			class Rock {};
		};
	};

	class Archaeology {
		storeName = "Archeolog";
		class Items {
			class CommonMap {};
			class UncommonMap {};
			class RareMap {};
			class SurveyingEquipment {};
			class ArchaeologistsEquipment {};
		};
	};

	class Artifact {
		storeName = "Handlarz artefaktami";
		class Items {
			class CommonMapFragment {};
			class UncommonMapFragment {};
			class RareMapFragment {};
			class OldCoin {};
			class CoinBundle {};
			class BrokenPot {};
			class RestoredPot {};
			class BluntStoneKnife {};
			class SharpStoneKnife {};
			class FossilisedBone {};
			class UnidentifiedSkull {};
			class IdentifiedSkull {};
			class PetrifiedShield {};
			class WeatheredSculpture {};
			class AncientAmber {};
			class ReligiousTotem {};
			class StrongMetalRing {};
			class DiamondRing {};
			class EmeraldAmulet {};
			class AncientLedger {};
			class HandSmoothedRunestone {};
			class JeweledNecklace {};
			class BrokenTimepiece {};
		};
	};
};
