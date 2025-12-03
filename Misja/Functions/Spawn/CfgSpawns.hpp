class CfgSpawns {
    class BaseSpawn {
        factions[] = { "Civilian" };
        buildings[] = {};
        radius = 100;
        conditions = "true";
    };
    class Police : BaseSpawn { factions[] = { "Police" }; };
    class HATO : BaseSpawn { factions[] = { "Hato" }; };
    class Medic : BaseSpawn { factions[] = { "Medic" }; };
    class Civilian : BaseSpawn {
        buildings[] = {
            "Land_i_Shop_01_V1_F",
            "Land_i_Shop_02_V1_F",
            "Land_i_Shop_03_V1_F",
            "Land_i_Stone_HouseBig_V1_F",
            "Land_Chapel_V1_F",
            "Land_Chapel_V2_F",
            "Land_u_House_Big_02_V1_F",
            "Land_u_House_Big_01_V1_F",
            "Land_d_Stone_HouseBig_V1_F",
            "Land_d_Stone_HouseSmall_V1_F",
            "Land_d_House_Big_01_V1_F"
        };
    };

    class Altis {
        // Altis Police Service
        class KavalaStation : Police {
            displayName = "Komenda główna Kavala";
            marker = "apc_spawn_kavala";
            icon = "Data\UI\Spawns\kavala.paa";
        };
        class PunktKontrolny : Police {
            displayName = "Punkt Kontrolny Kavala";
            marker = "cop_spawn_pk_kav";
            icon = "Data\UI\Spawns\lighthouse.paa";
        };
        class KavalaStationNCA : Civilian {
            displayName = "Siedziba główna NCA Frontline";
            marker = "apc_spawn_nca";
            icon = "Data\UI\Spawns\kavala.paa";
            radius = 1;
            conditions = "[] call ULP_fnc_isUndercover";
        };
        class AthiraStation : Police {
            displayName = "Komenda Athira";
            marker = "apc_spawn_athira";
            icon = "Data\UI\Spawns\athira.paa";
        };
        class PyrgosStation : Police {
            displayName = "Komenda Pyrgos";
            marker = "apc_spawn_pyrgos";
            icon = "Data\UI\Spawns\pyrgos.paa";
        };
        class AgiosStation : Police {
            displayName = "Komenda Agios";
            marker = "apc_spawn_agios";
            icon = "Data\UI\Spawns\agios.paa";
        };
        class SofiaStation : Police {
            displayName = "Komenda Sofia";
            marker = "apc_spawn_sofia";
            icon = "Data\UI\Spawns\sofia.paa";
        };
        class UndercoverHeadquarters : BaseSpawn {
            displayName = "Siedziba NCA Covert";
            marker = "apc_spawn_uc";
            icon = "Data\UI\Spawns\neochori.paa";
            radius = 1;
            conditions = "[] call ULP_fnc_isUndercover";
        };

        // Altis Ambulance Service
        class KavalaHospital : Medic {
            displayName = "Szpital Kavala";
            marker = "nhs_spawn_kavala";
            icon = "Data\UI\Spawns\kavala.paa";
        };
        class AthiraClinic : Medic {
            displayName = "Klinika Athira";
            marker = "nhs_spawn_athira";
            icon = "Data\UI\Spawns\athira.paa";
        };
        class PyrgosClinic : Medic {
            displayName = "Klinika Pyrgos";
            marker = "nhs_spawn_pyrgos";
            icon = "Data\UI\Spawns\pyrgos.paa";
        };
        class AgiosClinic : Medic {
            displayName = "Klinika Agios";
            marker = "nhs_spawn_agios";
            icon = "Data\UI\Spawns\agios.paa";
        };
        class SofiaClinic : Medic {
            displayName = "Klinika Sofia";
            marker = "nhs_spawn_sofia";
            icon = "Data\UI\Spawns\sofia.paa";
        };
        class AirAmbulance : Medic {
            displayName = "Lotnisko LPR";
            marker = "nhs_spawn_aa";
            icon = "Data\UI\Spawns\garage.paa";
            conditions = "[""Medic_AA"", 1] call ULP_fnc_hasAccess";
        };

        // Altis Police Service / Altis Ambulance Service
        class MarineStation : Police {
            displayName = "Baza morska";
            factions[] = { "Police", "Medic" };
            marker = "joint_spawn_marine";
            icon = "Data\UI\Spawns\marine.paa";
        };

        // HATO
        class HatoKavala : HATO {
            displayName = "Kavala Facility";
            marker = "hato_spawn_kavala";
            icon = "Data\UI\Spawns\kavala.paa";
        };
        class HatoAgios : HATO {
            displayName = "Agios Facility";
            marker = "hato_spawn_agios";
            icon = "Data\UI\Spawns\agios.paa";
        };

        // Government
        class GovernorResidence : BaseSpawn {
            displayName = "Dom burmistrza";
            marker = "civ_spawn_residence";
            icon = "Data\UI\Spawns\government.paa";
            conditions = "[] call ULP_fnc_isGovernor || { [] call ULP_fnc_isProtection }";
        };
        class GovernmentOffices : GovernorResidence {
            displayName = "Biura rządowe";
            marker = "civ_spawn_government";
        };
        class KavalaSafehouse : GovernorResidence {
            displayName = "Safehouse Kavala";
            marker = "civ_spawn_kavSafehouse";
            conditions = "[] call ULP_fnc_isGovernor || { [] call ULP_fnc_isProtection && { [""GovernmentSafehouses""] call ULP_fnc_hasGroupPerk } }";
        };
        class PyrgosSafehouse : KavalaSafehouse {
            displayName = "Safehouse Pyrgos";
            marker = "civ_spawn_pyrSafehouse";
        };
        
        // Civilian
        class Kavala : Civilian {
            displayName = "Kavala";
            marker = "civ_spawn_kavala";
            icon = "Data\UI\Spawns\kavala.paa";
        };
        class Athira : Civilian {
            displayName = "Athira";
            marker = "civ_spawn_athira";
            icon = "Data\UI\Spawns\athira.paa";
        };
        class Pyrgos : Civilian {
            displayName = "Pyrgos";
            marker = "civ_spawn_pyrgos";
            icon = "Data\UI\Spawns\pyrgos.paa";
        };
        class Sofia : Civilian {
            displayName = "Sofia";
            marker = "civ_spawn_sofia";
            icon = "Data\UI\Spawns\sofia.paa";
            conditions = "[""WideTraveller""] call ULP_fnc_hasPerk";
        };
        class Agios : Civilian {
            displayName = "Agios";
            marker = "civ_spawn_agios";
            icon = "Data\UI\Spawns\agios.paa";
            conditions = "[""WideTraveller""] call ULP_fnc_hasPerk";
        };
        class Neochori : Civilian {
            displayName = "Neochori";
            marker = "civ_spawn_neochori";
            icon = "Data\UI\Spawns\neochori.paa";
            conditions = "[""WideTraveller""] call ULP_fnc_hasPerk";
        };

        class Rebel1 : BaseSpawn {
            displayName = "Rebelia - Sofia";
            marker = "rebelia_sofia";
            icon = "Data\UI\Spawns\rebel.paa";
            conditions = "[""Rebel""] call ULP_fnc_hasLicense";
        };
        class Rebel2 : BaseSpawn {
            displayName = "Rebelia - Wyspa";
            marker = "wyspa_rebelia";
            icon = "Data\UI\Spawns\rebel.paa";
            conditions = "[""Rebel""] call ULP_fnc_hasLicense";
        };
        class Rebel3 : BaseSpawn {
            displayName = "Rebelia - Dolna";
            marker = "dolna_rebelia";
            icon = "Data\UI\Spawns\rebel.paa";
            conditions = "[""Rebel""] call ULP_fnc_hasLicense";
        };
        class Rebel4 : BaseSpawn {
            displayName = "Rebelia - Aktinarki";
            marker = "prawa_rebelia";
            icon = "Data\UI\Spawns\rebel.paa";
            conditions = "[""Rebel""] call ULP_fnc_hasLicense";
        };

        class Taxi : BaseSpawn {
            displayName = "Taxi Altis";
            marker = "civ_spawn_taxi";
            icon = "Data\UI\Spawns\taxi.paa";
            conditions = "[""Taxi""] call ULP_fnc_hasLicense";
        };
        class Solicitor : BaseSpawn {
            displayName = "Adwokaci Altis";
            marker = "civ_spawn_solicitor";
            icon = "Data\UI\Spawns\solicitor.paa";
            conditions = "[""Solicitor""] call ULP_fnc_hasLicense";
        };
        class News : BaseSpawn {
            displayName = "AAN World News";
            marker = "civ_spawn_news";
            icon = "Data\UI\Spawns\news.paa";
            conditions = "[""News""] call ULP_fnc_hasLicense";
        };
        class Rebel : BaseSpawn {
            displayName = "Rebelka";
            marker = "civ_spawn_rebel";
            icon = "Data\UI\Spawns\rebel.paa";
            conditions = "[""Rebel""] call ULP_fnc_hasLicense";
        };
        class BIXA : BaseSpawn {
            displayName = "Baza BIXA";
            marker = "spawn_gangowy";
            icon = "Data\UI\Spawns\rebel.paa";
            conditions = "[""BIXA""] call ULP_fnc_hasLicense";
        };
        class CVL : BaseSpawn {
            displayName = "Baza CVL";
            marker = "spawn_gangowy_1";
            icon = "Data\UI\Spawns\rebel.paa";
            conditions = "([group player] call ULP_fnc_getGroupName) isEqualTo 'Podwalina'";
        };
    };

    class Malden {
        class LaTriniteConstabulary : Police {
            displayName = "La Trinité Constabulary";
            marker = "cop_spawn_1";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };

        class test : Police {
            displayName = "Another Option";
            marker = "cop_spawn_2";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };

        class LaTriniteHospital : Medic {
            displayName = "La Trinité HQ";
            marker = "medic_spawn";
            icon = "\a3\ui_f\data\map\VehicleIcons\pictureLogic_ca.paa";
        };

        class LaTrinite : BaseSpawn {
            displayName = "La Trinité";
            marker = "civ_spawn_1";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };
    };
};