class CfgVehicles {
	retrievalPerc = 0.02;
	chopKeepChance = 80;
	chopPerc = 0.35;
	chopTime = 300;

	class Base {
		virtualSpace = 0;
		garageLimit = 5;
		fuelConsumptionRate = 1.15; // 115% normal rate
		isHouse = false;
		canTransfer = true;
		conditions = "true";
		blacklistedItems[] = { "StolenCargo", "FreightCargo" };
		class Textures {};
	};

	// LIGHTS --------------------------------------------------------------------------------------
	class PoliceColour {
		leftColour[] = {0.1, 0.1, 20};
		rightColour[] = {0.1, 0.1, 20};
	};
	class MedicColour {
		leftColour[] = {0.1, 0.1, 20};
		rightColour[] = {0.1, 0.1, 20};
	};
	class HatoColour {
		leftColour[] = {10, 5, 0};
		rightColour[] = {10, 5, 0};
	};

	// TEXTURES --------------------------------------------------------------------------------------
	class BaseTexture {
		displayName = "Default";
		buyPrice = 0;
		factions[] = { "Civilian" };
		textures[] = {};
		locked = false;
		conditions = "true";
	};

	// Base without siren or lights (for helis)
	class PoliceTextureBase : BaseTexture {
		factions[] = { "Police" };
		class Actions {
			class PNC {
				actionTitle = "Komputer Policyjny";
				actionCode = "[] call ULP_fnc_openPNC";
				params[] = {};
				priority = 1;
				condition = "_target isEqualTo (vehicle _this) && { ([player, [""Police""]] call ULP_fnc_isFaction) || ((driver _this) isEqualTo _target) }";
				radius = 25;
			};
		};
	};

	// Full with sirens and lights
	class PoliceTexture : PoliceTextureBase {
		remoteGates = true;
		class Siren {
			SFX[] = { "Police_One", "Police_Two", "Police_Three"};
		};
		class Lights : PoliceColour {};
	};

	class MedicTextureBase : BaseTexture {
		factions[] = { "Medic" };
		class Actions {
			class NHSDispatcher {
				actionTitle = "Dyspozytor EMS";
				actionCode = "[] call ULP_fnc_openMedicMap";
				params[] = {};
				priority = 1;
				condition = "_target isEqualTo (vehicle _this) && { [player, [""Medic""]] call ULP_fnc_isFaction }";
				radius = 25;
			};
		};
	};

	class MedicTexture : MedicTextureBase {
		remoteGates = true;
		class Siren {
			SFX[] = { "Police_One" };
		};
		class Lights : MedicColour {};
	};

	class HatoTexture : BaseTexture {
		factions[] = { "Hato" };
		remoteGates = true;
		class Siren {};
		class Lights : HatoColour {};
	};

	class BaseChromeGreen : BaseTexture {
		displayName = "Chrome Green";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\green.rvmat" };
		locked = true;
	};
	class BaseChromeBlue : BaseChromeGreen {
		displayName = "Chrome Blue";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\blue.rvmat" };
	};
	class BaseChromeRed : BaseChromeGreen {
		displayName = "Chrome Red";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\red.rvmat" };
	};
	class BaseChromeSilver : BaseChromeGreen {
		displayName = "Chrome Silver";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\silver.rvmat" };
	};
	class BaseChromeGold : BaseChromeGreen {
		displayName = "Chrome Gold";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\gold.rvmat" };
	};

	// CARS --------------------------------------------------------------------------------------
	class C_Kart_01_Blu_F : Base {
		description = "Gokart to mały czterokołowy pojazd napędzany grawitacyjnie, gazem lub elektrycznie. Posiada 4-suwowy silnik o mocy do 20 KM i nie powinien być obsługiwany przez kierowców poniżej 18 roku życia";
		buyPrice = 2500;
		virtualSpace = 0;
		garageLimit = 3;
	};
	class C_Kart_01_Fuel_F : C_Kart_01_Blu_F{};
    class C_Kart_01_Red_F : C_Kart_01_Blu_F{};
    class C_Kart_01_Vrana_F : C_Kart_01_Blu_F{};
    class C_Kart_01_black_F : C_Kart_01_Blu_F{};
    class C_Kart_01_white_F : C_Kart_01_Blu_F{};
    class C_Kart_01_green_F : C_Kart_01_Blu_F{};
    class C_Kart_01_orange_F : C_Kart_01_Blu_F{};
    class C_Kart_01_yellow_F : C_Kart_01_Blu_F{};

	class C_Quadbike_01_F : Base {
		description = "Quad to pojazd terenowy z niskociśnieniowymi oponami. Wojsko używa quadów do celów zwiadowczych i do poruszania się w terenie trudnym dla cięższych pojazdów.";
		buyPrice = 11300;
		virtualSpace = 10;
		class Textures {
			class Black : BaseTexture {
				displayName = "Czarny";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_black_co.paa" };
			};
			class White : BaseTexture {
				displayName = "Biały";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_white_co.paa" };
			};
			class Red : BaseTexture {
				displayName = "Czerwony";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_red_co.paa" };
			};
			class Blue : BaseTexture {
				displayName = "Niebieski";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_blue_co.paa" };
			};
			class Tan : BaseTexture {
				displayName = "Paintjob";
				textures[] = { "\A3\Soft_F\Quadbike_01\Data\Quadbike_01_co.paa" };
			};
		};
	};

	class C_Hatchback_01_F : Base {
		description = "Czteromiejscowy hatchback produkowany masowo na Dalekim Wschodzie w celu zaspokojenia rosnącego popytu na samochody rodzinne. Występuje również w wersji sportowej.";
		buyPrice = 21450;
		virtualSpace = 25;
		class Textures {
			class PoliceWhite : PoliceTexture {
				displayName = "Standardowy";
				textures[] = { "Data\Textures\Vehicles\Land\Police\hatchback_white.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class PoliceBlack : PoliceWhite {
				displayName = "SWAT";
				conditions = "[] call ULP_fnc_donatorLevel > 0";
				textures[] = { "Data\Textures\Vehicles\Land\Police\hatchback_black.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class PoliceANPR : PoliceWhite {
				displayName = "Pościgowe";
				conditions = "[""Police_RPU"", 1] call ULP_fnc_hasAccess";
				anpr = true;
				textures[] = { "Data\Textures\Vehicles\Land\Police\hatchback_ANPR.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class UnmarkedBlack : PoliceTexture {
				displayName = "Czarny";
				conditions = "[""Police_NCA"", 1] call ULP_fnc_hasAccess || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base09_co.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class UnmarkedBlackWhiteSport : UnmarkedBlack {
				displayName = "Czarno-biały Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedGrey : UnmarkedBlack {
				displayName = "Szary";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base08_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedWhite : UnmarkedBlack {
				displayName = "Biały";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base07_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedBeige : UnmarkedBlack {
				displayName = "Beżowy";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base01_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedBeigeSport : UnmarkedBlack {
				displayName = "Beżowy Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport05_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedRedSport : UnmarkedBlack {
				displayName = "Czerwony Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport01_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedBlue : UnmarkedBlack {
				displayName = "Niebieski";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base03_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedBlueSport : UnmarkedBlack {
				displayName = "Niebieski Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa" };
				class Lights : Lights {};
			};
			class UnmarkedDarkBlue : UnmarkedBlack {
				displayName = "Ciemny Niebieski";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base04_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedDarkBlueSport : UnmarkedBlack {
				displayName = "Ciemny Niebieski Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport02_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedGreen : UnmarkedBlack {
				displayName = "Zielony";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base02_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedGreenSport : UnmarkedBlack {
				displayName = "Zielony Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa" };
				class Lights : Lights {};
			};
			class UnmarkedYellow : UnmarkedBlack {
				displayName = "Żółty";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base06_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedOrangeSport : UnmarkedBlack {
				displayName = "Pomarańczowy Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport03_co.paa" };
				class Lights : Lights {};
			};
			class Medic : MedicTexture {
				textures[] = { "Data\Textures\Vehicles\Land\Medic\hatchback.paa" };
				class Lights : MedicColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class Hato : HatoTexture {
				textures[] = { "Data\Textures\Vehicles\Land\Hato\hatchback.paa" };
				class Lights : HatoColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class Black : BaseTexture {
                displayName = "Czarny";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base09_co.paa" };
            };
            class BlackWhiteSport : BaseTexture {
                displayName = "Czarno-Biały Sport";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa" };
            };
            class Grey : BaseTexture {
                displayName = "Szary";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base08_co.paa" };
            };
            class White : BaseTexture {
                displayName = "Biały";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base07_co.paa" };
            };
            class Beige : BaseTexture {
                displayName = "Beżowy";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base01_co.paa" };
            };
            class BeigeSport : BaseTexture {
                displayName = "Beżowy Sport";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport05_co.paa" };
            };
            class RedSport : BaseTexture {
                displayName = "Czerwony Sport";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport01_co.paa" };
            };
            class Blue : BaseTexture {
                displayName = "Niebieski";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base03_co.paa" };
            };
            class BlueSport : BaseTexture {
                displayName = "Niebieski Sport";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa" };
            };
            class DarkBlue : BaseTexture {
                displayName = "Ciemnoniebieski";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base04_co.paa" };
            };
            class DarkBlueSport : BaseTexture {
                displayName = "Ciemnoniebieski Sport";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport02_co.paa" };
            };
            class Green : BaseTexture {
                displayName = "Zielony";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base02_co.paa" };
            };
            class GreenSport : BaseTexture {
                displayName = "Zielony Sport";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa" };
            };
            class Yellow : BaseTexture {
                displayName = "Żółty";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base06_co.paa" };
            };
            class OrangeSport : BaseTexture {
                displayName = "Pomarańczowy Sport";
                textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport03_co.paa" };
            };
		};
	};
	class C_Hatchback_01_sport_F : C_Hatchback_01_F { buyPrice = 276500; };

	class C_Offroad_01_F : Base {
		description = "Pickup 4x4 firmy Generic Motors ma wytrzymałe podwozie i mocny silnik i został zaprojektowany tak, aby wytrzymać trudny teren Morza Śródziemnego.";
		buyPrice = 42800;
		virtualSpace = 60;
		class Textures {
			class White : BaseTexture {
				displayName = "Biały";
				textures[] = {
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa",
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa"
				};
			};
			class Red : BaseTexture {
				displayName = "Czerwony";
				textures[] = {
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa",
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa"
				};
			};
			class DarkRed : BaseTexture {
				displayName = "Ciemny czerwony";
				textures[] = {
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa",
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa"
				};
			};
			class Blue : BaseTexture {
				displayName = "Niebieski";
				textures[] = {
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa",
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa"
				};
			};
			class BlueWhite : BaseTexture {
				displayName = "Niebiesko-biały";
				textures[] = {
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa",
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa"
				};
			};
			class Ridge : BaseTexture {
				displayName = "Ridge";
				locked = true;
				textures[] = { "Data\Textures\Vehicles\Land\Civilian\Offroad\ridge.paa" };
			};
		};
	};
	class B_G_Offroad_01_armed_F : C_Offroad_01_F { buyPrice = 4280000; };
	class B_GEN_Offroad_01_gen_F : C_Offroad_01_F {};
	class C_IDAP_Offroad_01_F : C_Offroad_01_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP";
				textures[] = {
					"\a3\soft_f_orange\Data\Offroad_01_ext_IDAP_CO.paa"
				};
			};
		};
	};
	class C_Offroad_01_covered_F : C_Offroad_01_F {
		buyPrice = 49100;
		virtualSpace = 75;
		class Textures {
			class Hato : HatoTexture {
				displayName = "HATO";
				textures[] = { "Data\Textures\Vehicles\Land\Hato\offroad.paa" };
			};
			class Black : BaseTexture {
				displayName = "Czarny";
				textures[] = {
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_blk_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_blk_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_cover_blk_co.paa"
				};
			};
			class Green : BaseTexture {
				displayName = "Zielony";
				textures[] = {
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_grn_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_grn_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_cover_grn_co.paa"
				};
			};
		};
	};
	class C_Offroad_01_comms_F : C_Offroad_01_covered_F { buyPrice = 54450; };
	class C_Offroad_01_repair_F : C_Offroad_01_covered_F { buyPrice = 132400; };

	class C_Offroad_02_unarmed_F : Base {
		description = "MB 4WD to nowoczesny pojazd terenowy z napędem na cztery koła o charakterystycznej konstrukcji, mocnym silniku, wytrzymałym podwoziu i doskonałej zwrotności.";
		buyPrice = 38750;
		virtualSpace = 60;
		class Textures {
			class Medic : MedicTexture {
				textures[] = { "Data\Textures\Vehicles\Land\Medic\MB4.paa" };
				class Lights : MedicColour {
					leftPos[] = {0.757324,1.83252,-0.379596};
					rightPos[] = {-0.844727,1.82861,-0.379596};
				};
			};
			class Black : BaseTexture {
				displayName = "Czarny";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa" };
			};
			class White : BaseTexture {
				displayName = "Biały";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_white_co.paa" };
			};
			class Red : BaseTexture {
				displayName = "Czerwony";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_red_co.paa" };
			};
			class Blue : BaseTexture {
				displayName = "Niebieski";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa" };
			};
			class Orange : BaseTexture {
				displayName = "Pomarańczowy";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_orange_co.paa" };
			};
			class Ridge : BaseTexture {
				displayName = "Ridge";
				locked = true;
				textures[] = { "Data\Textures\Vehicles\Land\Civilian\MB4_WD\ridge.paa" };
			};
		};
	};
	class C_IDAP_Offroad_02_unarmed_F : C_Offroad_02_unarmed_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP";
				textures[] = {
					"\a3\soft_f_orange\Data\Offroad_02_ext_IDAP_CO.paa"
				};
			};
		};
	};
	class I_C_Offroad_02_LMG_F : C_Offroad_02_unarmed_F { buyPrice = 670300; };

	class C_SUV_01_F : Base {
		description = "Pełnowymiarowy luksusowy SUV typu crossover, który nie nadaje się szczególnie do jazdy w terenie, ale ma dobre właściwości jezdne. Jego mocny silnik i napęd 4x4 przyczyniają się do przyjemnej jazdy przy wyższych prędkościach.";
		buyPrice = 71200;
		virtualSpace = 25;
		class Textures {
			class PoliceWhite : PoliceTexture {
				displayName = "Standardowy";
				textures[] = { "Data\Textures\Vehicles\Land\Police\SUV_white.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};
			class PoliceBlack : PoliceWhite {
				displayName = "SWAT";
				conditions = "[] call ULP_fnc_donatorLevel > 0";
				textures[] = { "Data\Textures\Vehicles\Land\Police\SUV_black.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};
			class PoliceANPR : PoliceWhite {
				displayName = "Pościgowy";
				conditions = "[""Police_RPU"", 1] call ULP_fnc_hasAccess";
				anpr = true;
				textures[] = { "Data\Textures\Vehicles\Land\Police\SUV_ANPR.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};
			class UnmarkedBlack : PoliceTexture {
				displayName = "Czarny";
				conditions = "[""Police_NCA"", 1] call ULP_fnc_hasAccess || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_02_co.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};
			class UnmarkedSilver : UnmarkedBlack {
				displayName = "Srebrny";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_03_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedRed : UnmarkedBlack {
				displayName = "Czerwony";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedOrange : UnmarkedBlack {
				displayName = "Pomarańczowy";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_04_co.paa" };
				class Lights : Lights {};
			};
			class Medic : MedicTexture {
				textures[] = { "Data\Textures\Vehicles\Land\Medic\SUV.paa" };
				class Lights : MedicColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};
			class Hato : HatoTexture {
				textures[] = { "Data\Textures\Vehicles\Land\Hato\SUV.paa" };
				class Lights : HatoColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};
			class Black : BaseTexture {
				displayName = "Czarny";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_02_co.paa" };
			};
			class Silver : BaseTexture {
				displayName = "Srebrny";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_03_co.paa" };
			};
			class Red : BaseTexture {
				displayName = "Czerwony";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa" };
			};
			class Orange : BaseTexture {
				displayName = "Pomarańczowy";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_04_co.paa" };
			};
		};
	};

	class C_Van_02_transport_F : Base {
		description = "Furgonetka może być wykorzystywana do wielu praktycznych celów. Charakteryzuje się dużą długością ładunkową i doskonałą wysokością dachu, umożliwiając transport pasażerów, ładunków i mniejszych pojazdów.";
		buyPrice = 88000;
		virtualSpace = 90;
		class Textures {
			class PoliceWhite : PoliceTexture {
				displayName = "Standardowy";
				textures[] = { "Data\Textures\Vehicles\Land\Police\van.paa" };
			};
			class UnmarkedBlack : PoliceTexture {
				displayName = "Czarny";
				conditions = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_black_CO.paa" };
			};
			class UnmarkedWhite : UnmarkedBlack {
				displayName = "Biały";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_white_CO.paa" };
			};
			class UnmarkedRed : UnmarkedBlack {
				displayName = "Czerwony";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Red_CO.paa" };
			};
			class UnmarkedOrange : UnmarkedBlack {
				displayName = "Pomarańczowy";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Orange_CO.paa" };
			};
			class Medic : MedicTexture {
				displayName = "Ambulans";
				conditions = "[""Medic_Main"", 1] call ULP_fnc_hasAccess";
				textures[] = { "Data\Textures\Vehicles\Land\Medic\van.paa" };
			};
			class Hato : HatoTexture {
				displayName = "HATO";
				conditions = "[""Hato_Main"", 1] call ULP_fnc_hasAccess";
				textures[] = { "Data\Textures\Vehicles\Land\Hato\van.paa" };
			};
			class Black : BaseTexture {
				displayName = "Czarny";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_black_CO.paa" };
			};
			class White : BaseTexture {
				displayName = "Biały";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_white_CO.paa" };
			};
			class Red : BaseTexture {
				displayName = "Czerwony";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Red_CO.paa" };
			};
			class Orange : BaseTexture {
				displayName = "Pomarańczowy";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Orange_CO.paa" };
			};
			class Press : BaseTexture {
				displayName = "Prasa";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_AAN_CO.paa" };
			};
		};
	};
	class B_GEN_Van_02_transport_F : C_Van_02_transport_F {};
	class C_Van_02_medevac_F : C_Van_02_transport_F {};
	class C_IDAP_Van_02_transport_F : C_Van_02_transport_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_IDAP_CO.paa" };
			};
		};
	};
	class C_Van_02_vehicle_F : C_Van_02_transport_F {
		buyPrice = 96650;
		virtualSpace = 110;
	};
	class B_GEN_Van_02_vehicle_F : C_Van_02_vehicle_F {};
	class C_IDAP_Van_02_vehicle_F : C_Van_02_vehicle_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_IDAP_CO.paa" };
			};
		};
	};
	class C_Van_02_service_F : C_Van_02_vehicle_F {};

	class B_CTRG_LSV_01_light_F : Base {
		description = "Prowler - zwinny, lekko opancerzony, i pancerny. Bardzo dobry w ciężkim terenie.";
		buyPrice = 580000;
		virtualSpace = 50;
		garageLimit = 3;
		class Textures {
			class Police : PoliceTexture {
				textures[] = { "Data\Textures\Vehicles\Land\Police\prowler.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.75293,1.99902,-0.930151};
					rightPos[] = {-0.681152,2.01074,-0.930151};
				};
			};
			class Black : BaseTexture {
				displayName = "Czarny";
				textures[] = {
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_black_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_black_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_black_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_black_co.paa"
				};
			};
			class Sand : BaseTexture {
				displayName = "Pustynny";
				textures[] = {
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_sand_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_sand_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_sand_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_sand_co.paa"
				};
			};
			class Olive : BaseTexture {
				displayName = "Oliwkowy";
				textures[] = {
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_olive_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_olive_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_olive_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_olive_co.paa"
				};
			};
			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};
	class B_LSV_01_unarmed_black_F : B_CTRG_LSV_01_light_F { buyPrice = 675000; };

	class O_LSV_02_unarmed_F : Base {
		description = "Qilin - szybki i zwrotny pojazd offroadowy. Doskonały do trudnych warunków terenowych.";
		buyPrice = 800000;
		virtualSpace = 50;
		garageLimit = 3;
		class Textures {
			class Police : PoliceTexture {
				textures[] = { "Data\Textures\Vehicles\Land\Police\qilin.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.615234,2.03467,-0.40501};
					rightPos[] = {-0.943359,2.02881,-0.398304};
				};
			};
			class Black : BaseTexture {
				displayName = "Czarny";
				textures[] = { "\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_01_black_CO.paa", };
			};
			class Hex : BaseTexture {
				displayName = "Hex";
				textures[] = { "\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_01_arid_CO.paa", };
			};
			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};
	class O_LSV_02_armed_black_F : O_LSV_02_unarmed_F {
		buyPrice = 6590000;
		garageLimit = 3;
	};

	class B_MRAP_01_F : Base {
		description = "Hunter to pojazd MRAP z opancerzonym kadłubem, który może wytrzymać lekką broń i oferuje mocny silnik.";
		buyPrice = 9800000;
		virtualSpace = 65;
		garageLimit = 3;
		garageDelay = 15;
		repairTime = 20;
		crushTime = 60;
		chopKeepChance = 95;
		chopTime = 300;
		class Textures {
			class Police : PoliceTexture {
				textures[] = {
					"Data\Textures\Vehicles\Land\Police\hunter_01.paa",
					"Data\Textures\Vehicles\Land\Police\hunter_02.paa"
				};
				class Lights : PoliceColour {
					leftPos[] = {0.95459,-2.73975,0.559029};
					rightPos[] = {-0.94873,-2.73975,0.557981};
				};
			};
		};
	};

	class O_MRAP_02_F : Base {
		description = "Ifrit to pojazd MRAP zaprojektowany i wyprodukowany w Rosji. Jego mocne strony to niezawodność w ekstremalnych warunkach pogodowych i ochrona załogi.";
		buyPrice = 7500000;
		virtualSpace = 100;
		garageLimit = 2;
		garageDelay = 15;
		repairTime = 20;
		crushTime = 60;
		chopKeepChance = 90;
		chopTime = 300;
		canTransfer = false;
		turrets[] = { { "SmokeLauncher" } };
		conditions = "[""Ifrits""] call ULP_fnc_hasGroupPerk || { [""PersonalTank""] call ULP_fnc_hasPerk }";
		class Textures {
			class Hex : BaseTexture {
				displayName = "Hex";
				textures[] = {
					"\A3\soft_F\MRAP_02\data\MRAP_02_ext_01_CO.paa",
					"\A3\soft_F\MRAP_02\data\MRAP_02_ext_02_CO.paa"
				};
			};
			class GoldLine : BaseTexture {
				displayName = "Złoty pasek";
				buyPrice = 450000;
				condition = "[] call ULP_fnc_donatorLevel > 0";
				textures[] = {
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\goldLine_01.paa",
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\goldLine_02.paa"
				};
			};
			class Oil : GoldLine {
				displayName = "Wyciek oleju";
				buyPrice = 315700;
				textures[] = {
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\oil_01.paa",
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\oil_02.paa"
				};
			};
			class ChromeGreen : BaseChromeGreen {
				materials[] = {
					"Data\Textures\Vehicles\Global\Chrome\green.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\green.rvmat"
				};
			};
			class ChromeBlue : BaseChromeBlue {
				materials[] = {
					"Data\Textures\Vehicles\Global\Chrome\blue.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\blue.rvmat"
				};
			};
			class ChromeRed : BaseChromeRed {
				materials[] = {
					"Data\Textures\Vehicles\Global\Chrome\red.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\red.rvmat"
				};
			};
			class ChromeSilver : BaseChromeSilver {
				materials[] = {
					"Data\Textures\Vehicles\Global\Chrome\silver.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\silver.rvmat"
				};
			};
			class ChromeGold : BaseChromeGold {
				materials[] = {
					"Data\Textures\Vehicles\Global\Chrome\gold.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\gold.rvmat"
				};
			};
		};
	};

	class I_MRAP_03_F : Base {
		description = "Strider to średni pojazd terenowy ze zdolnościami amfibijnymi i zwiększoną ochroną załogi, zaprojektowany do zadań zwiadowczych i transportu wojsk.";
		buyPrice = 5750000;
		virtualSpace = 65;
		garageLimit = 2;
		garageDelay = 15;
		repairTime = 20;
		crushTime = 60;
		chopKeepChance = 90;
		chopTime = 300;
		class Textures {
			class Tan : BaseTexture {
				displayName = "Ciemny";
				textures[] = {
					"\A3\soft_f_beta\mrap_03\data\mrap_03_ext_co.paa",
					"\A3\data_f\vehicles\turret_co.paa"
				};
			};
			class Asiimov : BaseTexture {
				displayName = "Asiimov";
				locked = true;
				textures[] = { "Data\Textures\Vehicles\Land\Civilian\Strider\asiimov.paa" };
			};
			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};

	// TRUCKS --------------------------------------------------------------------------------------
	class C_Tractor_01_F : Base {
		description = "Spotykany w stodołach rolniczych na całym świecie, zwykły ciągnik jest niezawodnym pojazdem inżynieryjnym o wysokim momencie obrotowym, używanym do holowania przyczep i wielu innych zadań rolniczych.";
		buyPrice = 23150;
		virtualSpace = 10;
		garageLimit = 3;
		blacklistedItems[] = { "StolenCargo" };
		class Textures {
			class Red : BaseTexture {
				displayName = "Czerwony";
				textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_red_co.paa" };
			};
			class Blue : BaseTexture {
				displayName = "Niebieski";
				textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_blue_co.paa" };
			};
			class Green : BaseTexture {
				displayName = "Zielony";
				textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_green_co.paa" };
			};
		};
	};

	class C_Van_01_transport_F : Base {
		description = "Cywilna ciężarówka 4x4 to wysoce konfigurowalna ciężarówka z możliwościami terenowymi. Opiera się na stylistyce retro, ale wykorzystuje nowoczesny silnik i elektronikę.";
		buyPrice = 190500;
		virtualSpace = 65;
		garageLimit = 3;
		enableRope = false;
		blacklistedItems[] = { "StolenCargo" };
		class Textures {
			class Black : BaseTexture {
				displayName = "Czarny";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_black_co.paa" };
			};
			class White : BaseTexture {
				displayName = "Biały";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_co.paa" };
			};
			class Red : BaseTexture {
				displayName = "Czerwony";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_red_co.paa" };
			};
			class Brown : BaseTexture {
				displayName = "Brąz";
				textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_brn_co.paa" };
			};
			class Olive : BaseTexture {
				displayName = "Oliwkowy";
				textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_oli_co.paa" };
			};
			class Aldsa : BaseTexture {
				displayName = "Aldsa";
				locked = true;
				textures[] = {
					"Data\Textures\Vehicles\Land\Civilian\Truck\aldsa_01.paa",
					"Data\Textures\Vehicles\Land\Civilian\Truck\aldsa_02.paa"
				};
			};
		};
	};
	class C_Van_01_box_F : C_Van_01_transport_F {
		buyPrice = 245000;
		virtualSpace = 150;
	};
	class C_Van_01_fuel_F : C_Van_01_transport_F {
		buyPrice = 210500;
		virtualSpace = 75;
		class Textures {
			class Black : BaseTexture {
				displayName = "Czarny";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_black_co.paa" };
			};
			class White : BaseTexture {
				displayName = "Biały";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_co.paa" };
			};
			class Red : BaseTexture {
				displayName = "Czerwony";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_red_co.paa" };
			};
			class Brown : BaseTexture {
				displayName = "Brązowy";
				textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_brn_co.paa" };
			};
			class Olive : BaseTexture {
				displayName = "Oliwkowy";
				textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_oli_co.paa" };
			};
		};
	};

	class I_Truck_02_transport_F : Base {
		description = "Ciężarówka Zamak jest pojazdem 6x6 używanym do transportu i użyteczności. Wyposażone w potężny silnik V8, ciężarówki te są niezawodne nawet w trudnych warunkach.";
		buyPrice = 505000;
		virtualSpace = 280;
		garageLimit = 2;
		enableRope = false;
		blacklistedItems[] = { "StolenCargo" };
		class Textures {
			class Orange : BaseTexture {
				displayName = "Pomarańczowy";
				textures[] = {
					"\A3\Soft_F_Beta\Truck_02\data\truck_02_kab_co.paa",
					"\a3\soft_f_beta\Truck_02\data\truck_02_kuz_co.paa"
				 };
			};
			class Blue : BaseTexture {
				displayName = "Niebieski";
				textures[] = {
					"\a3\soft_f_beta\truck_02\data\truck_02_kab_blue_co.paa",
					"\a3\soft_f_beta\truck_02\data\truck_02_kuz_co.paa",
					"\a3\soft_f_beta\truck_02\data\truck_02_int_co.paa"
				};
			};
		};
	};
	class C_IDAP_Truck_02_transport_F : I_Truck_02_transport_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP";
				textures[] = {
					"\a3\soft_f_orange\Truck_02\Data\truck_02_int_IDAP_CO.paa",
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kab_IDAP_CO.paa",
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kuz_IDAP_CO.paa",
					"\a3\soft_f_orange\Truck_02\Data\truck_02_water_IDAP_CO.paa"
				 };
			};
		};
	};
	class I_Truck_02_covered_F : I_Truck_02_transport_F {
		buyPrice = 560000;
		virtualSpace = 350;
	};
	class C_IDAP_Truck_02_F : I_Truck_02_covered_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP";
				textures[] = {
					"\a3\soft_f_orange\Truck_02\Data\truck_02_int_IDAP_CO.paa",
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kab_IDAP_CO.paa",
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kuz_IDAP_CO.paa",
					"\a3\soft_f_orange\Truck_02\Data\truck_02_water_IDAP_CO.paa"
				 };
			};
		};
	};
	class I_Truck_02_fuel_F : I_Truck_02_transport_F {
		buyPrice = 435000;
		virtualSpace = 125;
	};
	class C_IDAP_Truck_02_water_F : I_Truck_02_fuel_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP";
				textures[] = {
					"\a3\soft_f_orange\Truck_02\Data\truck_02_int_IDAP_CO.paa",
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kab_IDAP_CO.paa",
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kuz_IDAP_CO.paa",
					"\a3\soft_f_orange\Truck_02\Data\truck_02_water_IDAP_CO.paa"
				 };
			};
		};
	};

	class O_Truck_03_transport_F : Base {
		description = "Tempest to standardowa ciężarówka transportowa 6x6 odporna na miny. Modułowa konstrukcja ciężarówki pozwala na kilka wersji transportowych.";
		buyPrice = 615500;
		virtualSpace = 450;
		garageLimit = 2;
		enableRope = false;
		blacklistedItems[] = { "StolenCargo" };
		class Textures {
			class BrownHex : BaseTexture {
				displayName = "Brązowy Hex";
				textures[] = {
					"\a3\soft_f_epc\truck_03\data\truck_03_ext01_co.paa",
					"\a3\soft_f_epc\truck_03\data\truck_03_ext02_co.paa",
					"\a3\soft_f_epc\truck_03\data\truck_03_cargo_co.paa"
				 };
			};
			class GreenHex : BaseTexture {
				displayName = "Zielony Hex";
				textures[] = {
					"\a3\soft_f_exp\truck_03\data\truck_03_ext01_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_ext02_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_cargo_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_cover_ghex_co.paa"
				};
			};
		};
	};
	class O_Truck_03_covered_F : O_Truck_03_transport_F {
		buyPrice = 670500;
		virtualSpace = 410;
	};
	class O_Truck_03_repair_F : O_Truck_03_transport_F {
		buyPrice = 728000;
		virtualSpace = 485;
	};
	class O_Truck_03_ammo_F : O_Truck_03_transport_F {
		buyPrice = 710000;
		virtualSpace = 460;
	};
	class O_Truck_03_fuel_F : O_Truck_03_transport_F {
		buyPrice = 590500;
		virtualSpace = 350;
	};
	class O_Truck_03_device_F : O_Truck_03_transport_F {
		buyPrice = 1150000;
		virtualSpace = 150;
	};

	class B_Truck_01_mover_F : Base {
		description = "Ciężka ciężarówka taktyczna o rozszerzonej mobilności to napędzana silnikiem wysokoprężnym ciężarówka terenowa 8x8. Istnieje kilka wersji obejmujących podstawowe funkcje transportowe.";
		buyPrice = 334000;
		virtualSpace = 10;
		garageLimit = 2;
		enableRope = false;
		canTransfer = false;
		conditions = "[""HEMTTs""] call ULP_fnc_hasGroupPerk || { [""HGVDriver""] call ULP_fnc_hasPerk } || { [""Hato_Main"", 1] call ULP_fnc_hasAccess }";
		blacklistedItems[] = { "StolenCargo" };
		class Textures {
			class Hato : HatoTexture {
				displayName = "HATO";
				textures[] = {
					"data\textures\vehicles\land\HATO\hemtt_1.paa",
					"data\textures\vehicles\land\HATO\hemtt_2.paa",
					"data\textures\vehicles\land\HATO\hemtt_primer.paa"
				};
				class Lights : HatoColour {
					leftPos[] = {0.814453,5.87402,-0.947113};
					rightPos[] = {-0.736816,5.86328,-0.947113};
				};
			};
		};
	};
	class B_Truck_01_flatbed_F : B_Truck_01_mover_F {
		buyPrice = 376000;
		virtualSpace = 100;
		class Textures {
			class Hato : HatoTexture {
				displayName = "HATO";
				textures[] = {
					"data\textures\vehicles\land\HATO\hemtt_1.paa",
					"data\textures\vehicles\land\HATO\hemtt_2.paa",
					"data\textures\vehicles\land\HATO\hemtt_flatbed.paa"
				};
				class Lights : HatoColour {
					leftPos[] = {0.814453,5.87402,-0.947113};
					rightPos[] = {-0.736816,5.86328,-0.947113};
				};
			};
		};
	};
	class B_Truck_01_cargo_F : B_Truck_01_mover_F {
		buyPrice = 690500;
		virtualSpace = 800;
		class Textures {
			class Sand : BaseTexture {
				displayName = "Pustynny";
				textures[] = {
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_ammo_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_cargo_co.paa"
				 };
			};
			class Olive : BaseTexture {
				displayName = "Oliwkowy";
				textures[] = {
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_ammo_pacific_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_cargo_pacific_co.paa"
				};
			};
		};
	};
	class B_Truck_01_transport_F : B_Truck_01_mover_F {
		buyPrice = 750000;
		virtualSpace = 535;
		class Textures {
			class Sand : BaseTexture {
				displayName = "Pustynny";
				textures[] = {
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_cargo_co.paa"
				 };
			};
			class Olive : BaseTexture {
				displayName = "Oliwkowy";
				textures[] = {
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_cargo_olive_co.paa"
				};
			};
		};
	};
	class B_Truck_01_covered_F : B_Truck_01_mover_F {
		buyPrice = 865000;
		virtualSpace = 590;
		class Textures {
			class Sand : BaseTexture {
				displayName = "Pustynny";
				textures[] = {
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_cargo_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_cover_co.paa"
				 };
			};
			class Olive : BaseTexture {
				displayName = "Oliwkowy";
				textures[] = {
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_cargo_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_cover_olive_co.paa"
				};
			};
		};
	};
	class B_Truck_01_ammo_F : B_Truck_01_mover_F {
		buyPrice = 905000;
		virtualSpace = 650;
		class Textures {
			class Sand : BaseTexture {
				displayName = "Pustynny";
				textures[] = {
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_gamma\truck_01\data\truck_01_ammo_co.paa"
				 };
			};
			class Olive : BaseTexture {
				displayName = "Oliwkowy";
				textures[] = {
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ammo_olive_co.paa"
				};
			};
		};
	};
	class B_Truck_01_fuel_F : B_Truck_01_mover_F {
		buyPrice = 880000;
		virtualSpace = 150;
		class Textures {
			class Sand : BaseTexture {
				displayName = "Pustynny";
				textures[] = {
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_gamma\truck_01\data\truck_01_fuel_co.paa"
				 };
			};
			class Olive : BaseTexture {
				displayName = "Oliwkowy";
				textures[] = {
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_fuel_olive_co.paa"
				};
			};
		};
	};
	class B_Truck_01_box_F : Base {
		buyPrice = 1000000;
		virtualSpace = 1000;
		garageLimit = 3;
		garageDelay = 30;
		repairTime = 15;
		crushTime = 30;
		chopKeepChance = 85;
		chopTime = 120;
		enableRope = false;
		canTransfer = false;
		conditions = "[""HEMTTs""] call ULP_fnc_hasGroupPerk";
		blacklistedItems[] = { "StolenCargo" };
		class Textures {
			class Sand : BaseTexture {
				displayName = "Pustynny";
				textures[] = {
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_gamma\truck_01\data\truck_01_mprimer_co.paa",
					"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
				 };
			};
			class Olive : BaseTexture {
				displayName = "Oliwkowy";
				textures[] = {
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ammo_olive_co.paa",
					"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
				};
			};
			class Ridge : BaseTexture {
				displayName = "Ridge";
				locked = true;
				textures[] = {
					"data\textures\vehicles\land\civilian\ridge_hemtt_1.paa",
					"data\textures\vehicles\land\civilian\ridge_hemtt_2.paa",
					"data\textures\vehicles\land\civilian\ridge_hemtt_3.paa",
					"data\textures\vehicles\land\civilian\ridge_hemtt_4.paa"
				};
			};
		};
	};

	// BOATS --------------------------------------------------------------------------------------
	class C_Scooter_Transport_01_F : Base {
		description = "Osobisty skuter wodny typu sit-down. Jego mocny silnik i świetna zwrotność sprawiają, że prowadzenie tej jednostki sprawia wiele radości.";
		buyPrice = 14300;
		virtualSpace = 5;
		class Textures {
			class Black : BaseTexture {
				displayName = "Czarny";
				textures[] = {
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_black_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_black_co.paa"
				 };
			};
			class White : BaseTexture {
				displayName = "Biały";
				textures[] = {
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_White_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_White_co.paa"
				};
			};
			class Grey : BaseTexture {
				displayName = "Szary";
				textures[] = {
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Grey_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Grey_co.paa"
				};
			};
			class Red : BaseTexture {
				displayName = "Czerwony";
				textures[] = {
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Red_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Red_co.paa"
				};
			};
			class Blue : BaseTexture {
				displayName = "Niebieski";
				textures[] = {
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_blue_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_blue_co.paa"
				};
			};
			class Green : BaseTexture {
				displayName = "Zielony";
				textures[] = {
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Green_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Green_co.paa"
				};
			};
			class Yellow : BaseTexture {
				displayName = "Żółty";
				textures[] = {
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Yellow_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Yellow_co.paa"
				};
			};
		};
	};

	class C_Rubberboat : Base {
		description = "Nadmuchiwana łódź, często nazywana „gumową kaczuszką”, to lekka łódź zbudowana z rur zawierających sprężony gaz.";
		buyPrice = 4150;
		virtualSpace = 50;
	};

	class C_Boat_Civil_01_F : Base {
		description = "Luksusowa motorówka to łódź napędzana mocnym silnikiem, używana przez policję i najbogatszych mieszkańców Altis.";
		buyPrice = 153200;
		virtualSpace = 75;
		class Textures {
			class Civilian : BaseTexture {};
			class Police : PoliceTexture { textures[] = { "Data\Textures\Vehicles\Sea\Police\motorboat.paa" }; };
			class Medic : MedicTexture { textures[] = { "Data\Textures\Vehicles\Sea\Medic\motorboat.paa" }; };
		};
	};
	class C_Boat_Civil_01_police_F : C_Boat_Civil_01_F {};

	class C_Boat_Transport_02_F : Base {
		description = "Szybka łódź o dużej wyporności, zaprojektowana do transportu w pełni wyposażonego zespołu składającego się z ośmiu osób i trzech członków załogi.";
		buyPrice = 297600;
		virtualSpace = 150;
		class Textures {
			class Civilian : BaseTexture {};
			class Police : PoliceTexture {
				textures[] = {
					"Data\Textures\Vehicles\Sea\Police\RHIB_01.paa",
					"Data\Textures\Vehicles\Sea\Police\RHIB_02.paa"
				};
			};
		};
	};

	class B_Boat_Armed_01_minigun_F : Base {
		description = "Ta łódź wyróżnia się szybkością i zwrotnością i jest używana jako łódź do ochrony wybrzeża i do operacji specjalnych.";
		buyPrice = 14360500;
		virtualSpace = 80;
		garageLimit = 3;
		repairTime = 15;
		crushTime = 30;
		chopKeepChance = 85;
		chopTime = 120;
		turrets[] = { { "GMG_40mm" } };
		class Textures {
			class Police : PoliceTexture {
				textures[] = {
					"Data\Textures\Vehicles\Sea\Police\speedboat_01.paa",
					"Data\Textures\Vehicles\Sea\Police\speedboat_02.paa"
				};
			};
		};
	};

	class B_SDV_01_F : Base {
		description = "SDV to załogowy pojazd podwodny wykorzystywany do transportu zespołów nurków na duże odległości pod wodą lub przy użyciu własnego sprzętu SCUBA.";
		buyPrice = 389500;
		virtualSpace = 5;
	};

	// HELICOPTERS --------------------------------------------------------------------------------------
	class B_UAV_01_F : Base {
		description = "Darter AR-2 to miniaturowy, zdalnie sterowany quadkopter idealny do zwiadu i obserwacji.";
		buyPrice = 98700;
		virtualSpace = 0;
	};
	class C_UAV_06_medical_F : B_UAV_01_F {
		description = "Ten komercyjny dron użytkowy wykorzystuje 6 wirników do transportu niewielkich ładunków wewnątrz siebie.";
		buyPrice = 109700;
	};

	class C_Heli_Light_01_civil_F : Base {
		description = "Lekki jednosilnikowy śmigłowiec używany w operacjach specjalnych przez armię amerykańską od czasów wojny w Wietnamie.";
		buyPrice = 565000;
		virtualSpace = 35;
		garageLimit = 2;
		blacklistedItems[] = { "StolenCargo" };
		class Textures {
			class Police : PoliceTextureBase { textures[] = { "Data\Textures\Vehicles\Air\Police\hummingbird.paa" }; };
			class Medic : MedicTextureBase { textures[] = { "Data\Textures\Vehicles\Air\Medic\hummingbird.paa" }; };
			class TotalRed : BaseTexture {
				displayName = "Żywy Czerwony";
				factions[] = { "Civilian", "Police" };
				textures[] = { "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa" };
			};
			class TotalBlue : TotalRed {
				displayName = "Żywy Niebieski";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa" };
			};
			class Sheriff : TotalRed {
				displayName = "Szeryfi";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa" };
			};
			class Blueline : TotalRed {
				displayName = "Niebieska linia";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueline_co.paa" };
			};
			class Elliptical : TotalRed {
				displayName = "Elliptical";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa" };
			};
			class Furious : TotalRed {
				displayName = "Furious";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa" };
			};
			class JeansBlue : TotalRed {
				displayName = "Jasny niebieski";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa" };
			};
			class SpeedyRedline : TotalRed {
				displayName = "Czerwona linia";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa" };
			};
			class Sunset : TotalRed {
				displayName = "Zachód słonca";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa" };
			};
			class Vrana : TotalRed {
				displayName = "Vrana";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa" };
			};
			class WavesBlue : TotalRed {
				displayName = "Niebieskie fale";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa" };
			};
			class Shadow : TotalRed {
				displayName = "Cień";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\Heli_Light_01_ext_shadow_co.paa" };
			};
			class GrayWatcher : TotalRed {
				displayName = "Gray Watcher";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\Heli_Light_01_ext_graywatcher_co.paa" };
			};
			class Wasp : TotalRed {
				displayName = "Pszczoła";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wasp_co.paa" };
			};
			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};
	class B_Heli_Light_01_F : C_Heli_Light_01_civil_F { buyPrice = 780000; };

	class O_Heli_Light_02_unarmed_F : Base {
		description = "PO-30 Orca to śmigłowiec transportowo-użytkowy opracowany głównie dla rosyjskich sił powietrznych.";
		buyPrice = 2000000;
		virtualSpace = 150;
		garageLimit = 3;
		blacklistedItems[] = { "StolenCargo" };
		turrets[] = { { "CMFlareLauncher" } };
		class Textures {
			class Police : PoliceTextureBase { textures[] = { "Data\Textures\Vehicles\Air\Police\orca.paa" }; };
			class Medic : MedicTextureBase { textures[] = { "Data\Textures\Vehicles\Air\Medic\orca.paa" }; };
			class Black : BaseTexture {
				displayName = "Czarny";
				textures[] = { "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_CO.paa" };
			};
			class BlackWhite : BaseTexture {
				displayName = "Czarno / Biały";
				textures[] = { "\a3\air_f_heli\heli_light_02\data\heli_light_02_ext_opfor_v2_co.paa" };
			};
			class WhiteBlue : BaseTexture {
				displayName = "Biało / Niebieski";
				textures[] = { "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_civilian_co.paa" };
			};
		};
	};

	class I_Heli_light_03_unarmed_F : Base {
		description = "WY-55 Hellcat to śmigłowiec wielozadaniowy, najbardziej odpowiedni do zastosowań użytkowych i ograniczonego transportu.";
		buyPrice = 2130000;
		virtualSpace = 170;
		garageLimit = 3;
		blacklistedItems[] = { "StolenCargo" };
		turrets[] = { { "CMFlareLauncher" } };
		class Textures {
			class Police : PoliceTextureBase {
				textures[] = { "Data\Textures\Vehicles\Air\Police\hellcat.paa" };
				turrets[] = { { "missiles_DAR", "CMFlareLauncher" } };
			};
			class Black : BaseTexture {
				displayName = "Czarny";
				textures[] = { "#(rgb,8,8,3)color(0.03,0.03,0.03,1)" };
			};
			class Green : BaseTexture {
				displayName = "Zielony";
				textures[] = { "\a3\air_f_epb\Heli_Light_03\data\Heli_Light_03_base_CO.paa" };
			};
		};
	};
	class I_Heli_light_03_F : I_Heli_light_03_unarmed_F {
		buyPrice = 23450000;
		turrets[] = { { "M134_minigun", "missiles_DAR", "CMFlareLauncher" } };
	};

	class B_Heli_Transport_01_F : Base {
		description = "UH-80 Ghost Hawk to średni śmigłowiec użytkowy o konstrukcji stealth.";
		buyPrice = 250000000;
		virtualSpace = 30;
		garageLimit = 3;
		blacklistedItems[] = { "StolenCargo" };
		turrets[] = { { "LMG_Minigun_Transport", "LMG_Minigun_Transport2", "CMFlareLauncher" } };
		class Textures {
			class Police : PoliceTextureBase { turrets[] = { { "CMFlareLauncher" } }; };
			class Civilian : BaseTexture {};
		};
	};

	class I_Heli_Transport_02_F : Base {
		description = "Następca szeroko rozpowszechnionego Merlina, CH-49 Mohawk jest podstawowym środkiem transportu w wielu innych wersjach, służąc skutecznie w ewakuacji, walce z okrętami podwodnymi lub jako uzbrojone wsparcie powietrzne.";
		buyPrice = 5240000;
		virtualSpace = 300;
		garageLimit = 3;
		chopKeepChance = 85;
		blacklistedItems[] = { "StolenCargo" };
		turrets[] = { { "CMFlareLauncher" } };
		class Textures {
			class Medic : MedicTextureBase {
				textures[] = {
					"Data\Textures\Vehicles\Air\Medic\mohawk_01.paa",
					"Data\Textures\Vehicles\Air\Medic\mohawk_02.paa",
					"Data\Textures\Vehicles\Air\Medic\mohawk_03.paa"
				};
			};
			class Ion : BaseTexture {
				displayName = "Ion";
				textures[] = {
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_1_ion_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_2_ion_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_3_ion_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\heli_transport_02_int_02_co.paa"
				 };
			};
			class Dahoman : BaseTexture {
				displayName = "Dahoman";
				textures[] = {
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_1_dahoman_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_2_dahoman_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_3_dahoman_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\heli_transport_02_int_02_co.paa"
				};
			};
		};
	};
	class C_IDAP_Heli_Transport_02_F : I_Heli_Transport_02_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP";
				textures[] = {
					"\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_1_IDAP_CO.paa",
					"\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_2_IDAP_CO.paa",
					"\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_3_IDAP_CO.paa",
					"\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_int_02_IDAP_CO.paa"
				};
			};
		};
	};

	class O_Heli_Transport_04_black_F : Base {
		description = "Mi-290 Taru to ciężki śmigłowiec użytkowy z wirnikami współosiowymi i unikalną konstrukcją modułową. Dzięki różnym kapsułom misyjnym Taru może pełnić wiele różnych ról.";
		buyPrice = 11350000;
		virtualSpace = 0;
		garageLimit = 3;
		blacklistedItems[] = { "StolenCargo" };
		chopKeepChance = 85;
		chopPerc = 0.20;
		chopTime = 60;
		turrets[] = { { "CMFlareLauncher" } };
	};
	class O_Heli_Transport_04_bench_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 11176500;
		virtualSpace = 0;
	};
	class O_Heli_Transport_04_covered_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 12670000;
		virtualSpace = 50;
	};
	class O_Heli_Transport_04_box_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 28900500;
		virtualSpace = 120;
	};
	class O_Heli_Transport_04_ammo_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 29460000;
		virtualSpace = 100;
	};
	class O_Heli_Transport_04_fuel_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 13640000;
		virtualSpace = 90;
	};
	class O_Heli_Transport_04_medevac_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 11983000;
		virtualSpace = 90;
		class Textures {
			class Medic : MedicTextureBase {
				textures[] = {
					"Data\Textures\Vehicles\Air\Medic\taru_01.paa",
					"Data\Textures\Vehicles\Air\Medic\taru_02.paa",
					"Data\Textures\Vehicles\Air\Medic\taru_03.paa",
					"Data\Textures\Vehicles\Air\Medic\taru_04.paa"
				};
			};
		};
	};

	class B_Heli_Transport_03_unarmed_F : Base {
		description = "Dwusilnikowy śmigłowiec ciężki z wirnikiem tandemowym. Jego podstawową rolą jest transport żołnierzy, pojazdów i ładunków.";
		buyPrice = 26400750;
		virtualSpace = 400;
		garageLimit = 3;
		blacklistedItems[] = { "StolenCargo" };
		chopKeepChance = 95;
		chopPerc = 0.20;
		chopTime = 300;
		turrets[] = { { "CMFlareLauncher" } };
		class Textures {
			class Black : BaseTexture {
				displayName = "Czarny";
				factions[] = { "Civilian", "Police" };
				textures[] = {
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_black_co.paa",
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_black_co.paa"
				 };
			};
			class Olive : BaseTexture {
				displayName = "Oliwkowy";
				textures[] = {
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_co.paa",
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_co.paa"
				};
			};
		};
	};

	class B_Heli_Attack_01_F : Base {
		description = "Dwumiejscowy śmigłowiec zwiadowczy służący do poszukiwania celów dla okrętów bojowych.";
		buyPrice = 146560000;
		virtualSpace = 0;
		garageLimit = 3;
		blacklistedItems[] = { "StolenCargo" };
		chopKeepChance = 97;
		chopPerc = 0.20;
		chopTime = 600;
		turrets[] = { { "CMFlareLauncher", "gatling_20mm", "missiles_DAGR", "missiles_ASRAAM" } };
	};
	class O_Heli_Attack_02_F : B_Heli_Attack_01_F {
		description = "Wielozadaniowy następca Mi-24, Mi-48 Kajman (oznaczony jako „Hornet”) to duży śmigłowiec bojowy i szturmowy z możliwością transportu 8 pasażerów";
		buyPrice = 212340000;
		virtualSpace = 30;
		turrets[] = { { "CMFlareLauncher", "gatling_30mm", "missiles_SCALPEL", "rockets_Skyfire", "Laserdesignator_mounted" } };
	};

	// PLANES --------------------------------------------------------------------------------------
	class C_Plane_Civil_01_F : Base {
		description = "Caesar BTT to jeden z najszybszych jednosilnikowych samolotów tłokowych z przekładnią stałą, osiągający prędkość 235 węzłów (435 km/h) na wysokości 7 600 m (25 000 stóp).";
		buyPrice = 1256000;
		virtualSpace = 5;
		garageLimit = 2;
		blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
	};
	class C_Plane_Civil_01_racing_F : C_Plane_Civil_01_F {};

	class B_T_VTOL_01_infantry_F : Base {
		description = "Technologia VTOL trzeciej generacji V-44X Blackfish umożliwia temu długodystansowemu samolotowi wygodne korzystanie z szerokiej gamy lotnisk i pasów startowych.";
		buyPrice = 75500000;
		virtualSpace = 175;
		garageLimit = 3;
		blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
		retrievalPerc = 0.01;
		chopKeepChance = 95;
		chopPerc = 0.15;
		chopTime = 180;
		turrets[] = { { "CMFlareLauncher_Triples" } };
	};
	class B_T_VTOL_01_vehicle_F : B_T_VTOL_01_infantry_F {
		buyPrice = 85750000;
		virtualSpace = 225;
	};

	class O_T_VTOL_02_infantry_F : B_T_VTOL_01_infantry_F {
		description = "Najbardziej obiecujący prototyp zbudowany przez inżynierów CSAT prezentuje niezwykle progresywną konstrukcję z wieloma unikalnymi funkcjami i najnowocześniejszymi technologiami.";
		buyPrice = 115650000;
		virtualSpace = 80;
		blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
		turrets[] = { { "CMFlareLauncher", "gatling_30mm_VTOL_02", "missiles_SCALPEL", "rockets_Skyfire" } };
	};
	class O_T_VTOL_02_vehicle_F : O_T_VTOL_02_infantry_F {
		buyPrice = 125530000;
		virtualSpace = 95;
		turrets[] = { { "CMFlareLauncher", "gatling_30mm_VTOL_02", "missiles_SCALPEL", "rockets_Skyfire" } };
	};

	class I_Plane_Fighter_03_CAS_F : Base {
		description = "A-143 Buzzard to jednomiejscowy, lekki, wielozadaniowy samolot bojowy zdolny do przenoszenia szerokiej gamy sprzętu i uzbrojenia.";
		buyPrice = 73350000;
		virtualSpace = 0;
		garageLimit = 3;
		retrievalPerc = 0.01;
		chopKeepChance = 99;
		chopPerc = 0.10;
		chopTime = 300;
		turrets[] = { { "CMFlareLauncher", "Twin_Cannon_20mm", "missiles_SCALPEL", "missiles_ASRAAM", "GBU12BombLauncher_Plane_Fighter_03_F" } };
	};
	class I_Plane_Fighter_04_F : I_Plane_Fighter_03_CAS_F {
		description = "A-149 Gryphon to jednomiejscowy, jednosilnikowy i taktyczny myśliwiec czwartej generacji.";
		buyPrice = 75500000;
		turrets[] = { { "CMFlareLauncher_Singles", "weapon_Fighter_Gun20mm_AA" } };
	};
	class B_Plane_CAS_01_F : I_Plane_Fighter_03_CAS_F {
		description = "A-164 Wipeout jest jednomiejscowym samolotem używanym do bliskiego wsparcia powietrznego i interwencji powietrznych.";
		buyPrice = 90500000;
		turrets[] = { { "CMFlareLauncher", "Gatling_30mm_Plane_CAS_01_F", "Missile_AA_04_Plane_CAS_01_F", "Missile_AGM_02_Plane_CAS_01_F", "Rocket_04_HE_Plane_CAS_01_F", "Rocket_04_AP_Plane_CAS_01_F", "Bomb_04_Plane_CAS_01_F" } };
	};
	class B_Plane_Fighter_01_F : I_Plane_Fighter_03_CAS_F {
		description = "F/A-181 Black Wasp II to jednomiejscowy, dwusilnikowy myśliwiec taktyczny piątej generacji.";
		buyPrice = 105500000;
		turrets[] = { { "CMFlareLauncher_Singles", "weapon_Fighter_Gun20mm_AA" } };
	};
	class B_Plane_Fighter_01_Stealth_F : B_Plane_Fighter_01_F {
		buyPrice = 115600000;
		turrets[] = { { "CMFlareLauncher_Singles", "weapon_Fighter_Gun20mm_AA" } };
	};
	class O_Plane_CAS_02_F : I_Plane_Fighter_03_CAS_F {
		description = "To-199 Neophron to nowy dodatek do sił powietrznych CSAT. Zwinny, jednomiejscowy samolot jest używany do bliskiego wsparcia powietrznego, ale może również zestrzeliwać zagrożenia powietrzne.";
		buyPrice = 86500000;
		turrets[] = { { "CMFlareLauncher", "Cannon_30mm_Plane_CAS_02_F", "Missile_AA_03_Plane_CAS_02_F", "Missile_AGM_01_Plane_CAS_02_F", "Rocket_03_HE_Plane_CAS_02_F", "Rocket_03_AP_Plane_CAS_02_F", "Bomb_03_Plane_CAS_02_F" } };
	};
	class O_Plane_Fighter_02_F : I_Plane_Fighter_03_CAS_F {
		description = "To-201 Shikra to jednomiejscowy, dwusilnikowy, taktyczny myśliwiec piątej generacji.";
		buyPrice = 115500000;
		turrets[] = { { "CMFlareLauncher", "weapon_Fighter_Gun_30mm" } };
	};
	class O_Plane_Fighter_02_Stealth_F : O_Plane_Fighter_02_F {
		buyPrice = 130500000;
		turrets[] = { { "CMFlareLauncher", "weapon_Fighter_Gun_30mm" } };
	};

	// CONTAINERS --------------------------------------------------------------------------------------
	class B_Slingload_01_Cargo_F : Base {
		description = "";
		buyPrice = 0;
		virtualSpace = 250;
		garageLimit = 3;
	};
	class B_Slingload_01_Fuel_F : B_Slingload_01_Cargo_F {
		description = "";
		buyPrice = 0;
		virtualSpace = 100;
	};

	class Land_Pod_Heli_Transport_04_box_black_F : B_Slingload_01_Cargo_F {
		description = "";
		buyPrice = 0;
		virtualSpace = 125;
	};
	class Land_Pod_Heli_Transport_04_fuel_black_F : B_Slingload_01_Cargo_F {
		description = "";
		buyPrice = 0;
		virtualSpace = 50;
	};

	// TEMP --------------------------------------------------------------------------------------
	class Land_Suitcase_F : Base {
		virtualSpace = 0;
		garageLimit = 0;
		tempStorage = true;
	};

	// HOUSING --------------------------------------------------------------------------------------
	class Land_PlasticCase_01_small_F : Base { // Addon House
		virtualSpace = 500;
		garageLimit = 0;
		isHouse = true;
	};

	class Land_PlasticCase_01_medium_F : Land_PlasticCase_01_small_F { virtualSpace = 1000; }; // Small House
	class Land_PlasticCase_01_large_F : Land_PlasticCase_01_small_F { virtualSpace = 2000; }; // Small House
	class Land_PlasticCase_01_large_gray_F : Land_PlasticCase_01_small_F { virtualSpace = 1000; }; // Lighthouse
	class B_supplyCrate_F : Land_PlasticCase_01_small_F { virtualSpace = 3000; }; // Big House
	class Land_Cargo20_white_F : Land_PlasticCase_01_small_F { virtualSpace = 5000; }; // Warehouse / Boat
	class Land_Cargo20_grey_F : Land_PlasticCase_01_small_F { virtualSpace = 20000; }; // Military Offices
	class CargoNet_01_box_F : Land_PlasticCase_01_small_F { virtualSpace = 10000; }; // DMT
	class C_IDAP_supplyCrate_F : Land_PlasticCase_01_small_F { virtualSpace = 8500; }; // Office Building
	class Land_CargoBox_V1_F : Land_Suitcase_F {
		requireItems = true;
	};
	class Land_PortableServer_01_black_F : Land_CargoBox_V1_F {};

	// SOUNDS --------------------------------------------------------------------------------------

	class Police_One { sound = "Police_One"; };

	class Police_Two { sound = "Police_Two"; };

	class Police_Three { sound = "Police_Three"; };
};