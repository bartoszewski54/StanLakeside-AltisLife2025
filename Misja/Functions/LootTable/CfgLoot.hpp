class CfgLoot {
	class VehicleTextures {
		class ChromeRedIfrit {
			chance = 0.99;
			class O_MRAP_02_F {
				amount = 0;
				texture = "ChromeRed";
			};
		};

		class ChromeRedStrider {
			chance = 0.98;
			class I_MRAP_03_F {
				amount = 0;
				texture = "ChromeRed";
			};
		};

		class ChromeBlueIfrit {
			chance = 0.96;
			class O_MRAP_02_F {
				amount = 0;
				texture = "ChromeBlue";
			};
		};
		
		class ChromeBlueStrider {
			chance = 0.94;
			class I_MRAP_03_F {
				amount = 0;
				texture = "ChromeBlue";
			};
		};

		class ChromeGreenIfrit {
			chance = 0.91;
			class O_MRAP_02_F {
				amount = 0;
				texture = "ChromeGreen";
			};
		};

		class ChromeGreenStrider {
			chance = 0.88;
			class I_MRAP_03_F {
				amount = 0;
				texture = "ChromeGreen";
			};
		};

		class ChromeRedHummingbird {
			chance = 0.84;
			class C_Heli_Light_01_civil_F {
				amount = 0;
				texture = "ChromeRed";
			};
		};

		class ChromeBlueHummingbird {
			chance = 0.80;
			class C_Heli_Light_01_civil_F {
				amount = 0;
				texture = "ChromeBlue";
			};
		};
		
		class ChromeGreenHummingbird {
			chance = 0.74;
			class C_Heli_Light_01_civil_F {
				amount = 0;
				texture = "ChromeGreen";
			};
		};

		class ExperienceBundle {
			chance = 0;
			class SmallXPReward { amount = 3; };
			class MediumXPReward { amount = 2; };
			class LargeXPReward { amount = 1; };
		};
	};

	class GeneralItems {

		class Suppressors {
			chance = 0.90;
			class muzzle_snds_L { amount = 1; };
			class muzzle_snds_acp { amount = 1; };
			class muzzle_snds_m_snd_F { amount = 1; };
		};

		class ImportedWeapons {
		chance = 0.01;
		class SMG_03C_khaki { amount = 1; };  // Subkarabin maszynowy (SMG) w wersji kompaktowej, wykończony w kolorze khaki. Idealny do walki na bliskim dystansie.
        class SMG_03_TR_hex { amount = 1; };  // Subkarabin maszynowy (SMG) w wersji TR, wykończony w kolorze heksagonalnym.
        class arifle_AKS_F { amount = 1; };  // Karabin szturmowy AKS w wersji złożonej, popularny w wielu armiach.
        class arifle_CTARS_ghex_F { amount = 1; };  // Karabin szturmowy CTARS, wersja z kamuflażem, przeznaczony do walki w terenie górskim lub leśnym.
        class srifle_DMR_07_hex_F { amount = 1; };  // Karabin snajperski DMR-07, wersja z heksagonalnym kamuflażem, przeznaczony do precyzyjnych strzałów na średnim dystansie.
        class arifle_Katiba_C_F { amount = 1; };  // Karabin szturmowy Katiba, wersja z kamuflażem miejskim, uznawany za nowoczesny i wszechstronny.
        class arifle_MSBS65_sand_F { amount = 1; };  // Karabin szturmowy MSBS-65, wersja piaskowa, współczesny karabin dla jednostek specjalnych i armii.
        class arifle_ARX_blk_F { amount = 1; };  // Karabin ARX, wersja w kolorze czarnym, popularny w niektórych jednostkach specjalnych.
        class arifle_AKM_F { amount = 1; };  // Karabin AKM, ulepszona wersja klasycznego AK, znana z dużej niezawodności, używana w wielu armiach.
        class srifle_DMR_01_F { amount = 1; };  // Karabin snajperski DMR-01, klasyczny wybór dla strzelców wyborowych, o dużej celności na średnim dystansie.
		};

		class SmokersPack {
			chance = 74;
			class Cigarette { amount = 82; };
			class Cigar { amount = 67; };
		};


		class ArtifactBag {
			chance = 0.58;
			class RareMap { amount = 1; };
			class OldCoin { amount = 1; };
			class BrokenPot { amount = 1; };
			class BluntStoneKnife { amount = 1; };
		};

		class RandomAttachments {
			chance = 0.51;
			class acc_flashlight { amount = 1; };
			class acc_pointer_IR { amount = 1; };
			class optic_Aco { amount = 1; };
			class optic_ACO_grn_smg { amount = 1; };
			class optic_Holosight { amount = 1; };
			class optic_Holosight_smg { amount = 1; };
			class optic_Holosight_smg_blk_F { amount = 1; };
			class optic_Hamr { amount = 2; };
			class optic_MRCO { amount = 3; };
			class optic_Arco { amount = 2; };
			class optic_Arco_blk_F { amount = 1; };
			class optic_DMS_weathered_F { amount = 1; };
			class optic_NVS { amount = 1; };
			class optic_KHS_blk { amount = 1; };
		};

		class RandomMagazines {
			chance = 0.43;
			class 30Rnd_9x21_Mag { amount = 4; };
			class 9Rnd_45ACP_Mag { amount = 1; };
			class 11Rnd_45ACP_Mag { amount = 2; };
			class 6Rnd_45ACP_Cylinder { amount = 1; };
			class 10Rnd_50BW_Mag_F { amount = 1; };
			class 2Rnd_12Gauge_Pellets { amount = 2; };
			class 2Rnd_12Gauge_Slug { amount = 3; };
			class 30Rnd_545x39_Mag_F { amount = 7; };
			class 50Rnd_570x28_SMG_03 { amount = 1; };
			class 30Rnd_556x45_Stanag { amount = 4; };
			class 150Rnd_556x45_Drum_Mag_F { amount = 1; };
			class 30Rnd_580x42_Mag_F { amount = 1; };
			class 30Rnd_65x39_caseless_green { amount = 4; };
			class 30Rnd_65x39_caseless_msbs_mag { amount = 3; };
			class 30Rnd_65x39_caseless_mag { amount = 5; };
			class 200Rnd_65x39_cased_Box { amount = 1; };
			class 20Rnd_762x51_Mag { amount = 3; };
			class 10Rnd_127x54_Mag { amount = 4; };
			class 10Rnd_338_Mag { amount = 2; };
			class 7Rnd_408_Mag { amount = 1; };
		};

		class StolenGold {
			chance = 0.08;
			class MarkedGold { amount = 4; };
		};

		class MineralCrate {
			chance = 37;
			class Coal { amount = 30; };
			class CopperBar { amount = 14; };
			class SilverBar { amount = 21; };
			class IronBar { amount = 25; };
		};

		class HuntersPack {
			chance = 0.31;
			class sgun_HunterShotgun_01_F { amount = 1; };
			class srifle_DMR_06_hunter_F { amount = 1; };
			class 2Rnd_12Gauge_Slug { amount = 3; };
			class 10Rnd_Mk14_762x51_Mag { amount = 4; };
			class optic_KHS_old { amount = 1; };
		};

		class VerminSet {
			chance = 0.25;
			class SMG_01_F { amount = 1; };
			class 30Rnd_45ACP_Mag_SMG_01 { amount = 7; };
			class optic_Aco_smg { amount = 1; };
			class muzzle_snds_acp { amount = 1; };
		};

		class BootleggerCrate {
			chance = 0.20;
			class Gin { amount = 42; };
			class Whiskey { amount = 39; };
			class Moonshine { amount = 26; };
			class PurifiedMoonshine { amount = 34; };
		};

		class MedicalEquipment {
			chance = 0.18;
			class Painkillers { amount = 197; };
			class Bandage { amount = 131; };
			class BloodBag { amount = 34; };
		};

		class SDAR {
			chance = 0.17;
			class arifle_SDAR_F { amount = 1; };
			class 20Rnd_556x45_UW_mag { amount = 9; };
		};

		class VariousPistols {
			chance = 0.03;
			class hgun_Pistol_01_F { amount = 1; };
			class hgun_Rook40_F { amount = 2; };
			class hgun_ACPC2_F { amount = 1; };
			class 10Rnd_9x21_Mag { amount = 3; };
			class 16Rnd_9x21_Mag { amount = 6; };
			class 30Rnd_9x21_Mag { amount = 2; };
			class 9Rnd_45ACP_Mag { amount = 4; };
		};

		class ExperienceBundle {
			chance = 0;
			class SmallXPReward { amount = 3; };
			class MediumXPReward { amount = 2; };
			class LargeXPReward { amount = 1; };
		};
	};
};