class CfgSettings {
    developers[] = { "76561198022957865", "76561197971322689" };
    
    framework_version = "1.2.6";

    total_maxWeight = 5;

    sync_delay = 5 * 60;
    abort_delay = 10;

    starting_bank = 125000;
    paycheck_period = 15;

    buffedSellIncrease = 1.5;

    disabledDamageInGreenzone = true;

    class DonationRewards {
        sellIncrease = 1.50;
        profChanceIncrease = 1.50;
        xpIncrease = 1.50;
        payIncrease = 1.50;
        vehicleDecrease = 1.25;
        weaponDecrease = 1.25;
    };

    class CfgMedical {
        /* Bleed Out */
        // Left is no medics - right is medics
        AllowBleedoutPercentage[] = { 0.75, 0.4 };
        BleedOutTime = 20 * 60;
        RedzonePercentage = 0.1;

        /* Blood */
        BloodBagIncrease = 5 * 60;
    };

    class Toxic_Bus_Config {

    payment = CASH; //Change whether you want them to pay from their bank or CASH on hand
    bus_3d = true; //True or False

    class Civilian {
        multipler = 0.1; //Price per KM multiplyer
        stops[] = {
            //{"Display Name","Marker_Name"}
            {"Kavala","bus_kavala"},
            {"Pygros","Bus_Pyrgos"},
            {"Athira","bus_athira"},
            {"Paros","bus_paros"},
			{"Sofia","Bus_Sofia"}
        };
    };
    class Cop {
        multipler = 0.05;
        stops[] = {
            {"Kavala PD HQ","bus_kavalaPD"},
            {"Posterunek Athira","bus_athiraPD"},
            {"Pygros PD HQ","bus_pygrosPD"},
			{"Posterunek Sofia","bus_SofiaPD"},
			{"Baza lotnicza PD","bus_LotniskoPD"}
        };
    };
    class Medic {
        multipler = 0.05;
        stops[] = {
            {"Kavala Hospital","bus_kavalaMed"},
            {"Athira Hospital","bus_AthiratMed"},
            {"Pygros Hospital","bus_pygrosMed"},
			{"Sofia Clinic","bus_sofiaMed"}
        };
    };
};

    class CfgCredits {
        screenTime = 10;
        
        class Informacja {
            items[] = {"""Witaj na""", """Stan Lakeside!"""};
            condition = "true";
        };
        class Kontakt : Informacja {
            items[] = {"""Discord:""", """discord.gg/DMkxetD"""};
        };
        class Powodzenia : Informacja {
            items[] = {"""Pamiętaj o przestrzeganiu zasad!"""};
        };
        class Burmistrz  {
            items[] = {"(missionNamespace getVariable [""ULP_SRV_Setting_Governor"", []]) param [0, """"]"};
            condition = "!((missionNamespace getVariable [""ULP_SRV_Setting_Governor"", []]) isEqualTo [])";
        };
        class Eventy {
            title = "Aktywne eventy";
            items[] = {
                { """Wojny gangów""", "missionNamespace getVariable [""ULP_SRV_Setting_BaseBidsActive"", false]" },
                { """Wybory""", "missionNamespace getVariable [""ULP_SRV_Setting_Election"", false]" }
            };
            condition = "missionNamespace getVariable [""ULP_SRV_Setting_BaseBidsActive"", false] || { missionNamespace getVariable [""ULP_SRV_Setting_Election"", false] }";
        };
    };

    class NLR {
        nlrTimer = 15 * 60;
        nlrDistance = 350;
    };
    
    class Police {
        impoundTime = 30;
        ticketFee[] = { 100, 5000000 };
        impoundFee[] = { 5000, 150000 };
        clampFee[] = { 5000, 50000 };
        crushTime = 60;
    };
    
    garageDelay = 15;

    communicationDevices[] = { "ItemRadio", "ItemGPS", "B_UavTerminal", "O_UavTerminal", "I_UavTerminal" };

    doesntThreaten[] = { "", "Binocular", "Rangefinder", "hgun_Pistol_Signal_F" };

    allowedCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789(),.!:;ĄĆĘÓŁŹŻĆ-/'ąłóńŃżźę ";

    threatLevels[] = { "Zielony", "Pomarańczowy", "Czerwony", "Czarny", "Krytyczny" };

    repackingTime = 40;
    
    class Remotes {
        class Sound {
            maxDistance = 100;
            sounds[] = { "taserSound", "unlockCarSound", "lockCarSound", "panicButton", "handCuff", "klakson" };
        };
    };

    class Player {
        aimPrecision = false;
        loadCoef = 0.75;
    };

    class Identity {
        nameLength = 24;
    };

    class Gates {
        class Land_BarGate_F { anim = "Door_1_rot"; };
        class Land_RoadBarrier_01_F : Land_BarGate_F {};
        class Land_ConcreteWall_01_m_gate_F { anim = "Door_1_move"; };
        class Land_ConcreteWall_01_l_gate_F : Land_ConcreteWall_01_m_gate_F {};
    };

    class Weather {
        maxFog = 0.1;
        maxRain = 0.1;
    };
};

#include "CfgSurvival.hpp"
