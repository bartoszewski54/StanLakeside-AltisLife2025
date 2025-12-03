class CfgWarrants {
    NoteLength = 128;

    class CommonLaw {
        displayName = "Prawo powszechne";

        class PervertingJustice {
			displayName = "Utrudnianie pracy funkcjonariusza/medyka";
			bounty = 50000;
            allowManual = true;
        };
        class EscapeCustody : PervertingJustice { // Escaping Prison
			displayName = "Ucieczka z aresztu";
			bounty = 300000;
        };
        class FalseImprisonment : PervertingJustice {
			displayName = "Bezpodstawne uwięzienie";
			bounty = 300000;
        };
    };

    class TreasonAct {
        displayName = "Ustawa o zdradzie";

        class Treason {
            displayName = "Zdrada państwa";
            allowManual = true;
			bounty = 300000;
        };
    };

    class TerrorismAct {
        displayName = "Ustawa o terroryzmie";

        class Membership {
            displayName = "Członkostwo w grupie kryminalnej";
            allowManual = true;
            bounty = 300000;
        };
        class Support : Membership {
            displayName = "Wspieranie grup kryminalnych";
            bounty = 80000;
        };
    };

    class PrisonAct {
        displayName = "Ustawa więzienna";

        class Assisting {
            displayName = "Pomoc więźniowi w ucieczce";
            allowManual = true;
            bounty = 300000;
        };
        class Smuggling : Assisting {
            displayName = "Przemyt kontrabandy";
            bounty = 30000;
        };
    };

    class OffencesAct {
        displayName = "Ustawa o przestępstwach przeciwko osobom";

        class S1 { // Execute Player
            displayName = "Morderstwo";
            allowManual = true;
            bounty = 300000;
        };
        class S5 : S1 { displayName = "Nieumyślne spowodowanie śmierci"; };
        class S16 : S1 {
            displayName = "Groźby śmiertelne";
            bounty = 50000;
        };
        class S18 : S1 { // Incap Player
            displayName = "Ciężkie uszkodzenie ciała";
            bounty = 180000;
        };
        class S38 : S1 { // Knocking Non-Civilian Out
            displayName = "Atak na funkcjonariusza służb ratunkowych";
            bounty = 150000;
        };
        class S47 : S1 { // Knocking Civilian Out
            displayName = "Uszkodzenie ciała";
            bounty = 100000;
        };
        class S66 : S1 {
            displayName = "Grożenie z zamiarem zabicia";
            bounty = 30000;
        };
    };

    class FirearmsAct {
        displayName = "Ustawa o broni palnej";

        class S1 {
            displayName = "Posiadanie broni bez zezwolenia";
            allowManual = true;
            bounty = 45000;
        };
        class S5 : S1 {
            displayName = "Posiadanie zakazanej broni palnej";
            bounty = 65000;
        };
        class S18 : S1 {
            displayName = "Posiadanie broni z zamiarem popełnienia przestępstwa";
            bounty = 55000;
        };
        class S19 : S1 {
            displayName = "Wyciąganie broni palnej w miejscu publicznym";
            bounty = 20000;
        };
    };

    class PublicOrderAct {
        displayName = "Ustawa o porządku publicznym";

        class S1 {
            displayName = "Zamieszki";
            allowManual = true;
            bounty = 75000;
        };
        class S2 : S1 {
            displayName = "Agresywne zakłócanie porządku";
            bounty = 80000;
        };
        class S3 : S1 {
            displayName = "Bójka";
            bounty = 30000;
        };
        class S4 : S1 {
            displayName = "Grożenie/prowokowanie przemocy";
            bounty = 55000;
        };
        class S5 : S1 {
            displayName = "Nękanie, alarmowanie lub wywoływanie niepokoju";
            bounty = 15000;
        };
    };

    class DrugsAct {
        displayName = "Ustawa o narkotykach";

        class S3 {
            displayName = "Zamiar dystrybucji substancji ograniczonych";
            allowManual = true;
            bounty = 150000;
        };
        class S5 : S3 {
            displayName = "Posiadanie substancji ograniczonych";
            bounty = 50000;
        };
    };

    class TheftAct {
        displayName = "Ustawa o kradzieży";

        class S7 {
            displayName = "Kradzież";
            allowManual = true;
            bounty = 20000;
        };
        class S8 : S7 { // Robbing Player or Store
            displayName = "Rozbój";
            bounty = 100000;
        };
        class S9 : S7 {
            displayName = "Włamanie";
            bounty = 70000;
        };
        class S12 : S7 { // Successfully Lockpicking
            displayName = "Kradzież pojazdu bez zgody właściciela";
            bounty = 75000;
        };
        class S21 : S7 {
            displayName = "Szantaż";
            bounty = 20000;
        };
        class S22 : S7 {
            displayName = "Obrót skradzionymi przedmiotami";
            bounty = 30000;
        };
        class S25 : S7 {
            displayName = "Posiadanie sprzętu używanego do kradzieży";
            bounty = 15000;
        };
    };

    class FraudAct {
        displayName = "Ustawa o oszustwach";

        class S2 {
            displayName = "Fałszywa tożsamość";
            allowManual = true;
            bounty = 40000;
        };
        class S3 : S2 {
            displayName = "Krycie informacji";
            bounty = 20000;
        };
        class S4 : S2 {
            displayName = "Używanie rangi do nielegalnych rzeczy";
            bounty = 75000;
        };
        class S6 : S2 {
            displayName = "Posiadanie rzeczy do fałszowania wyborów";
            bounty = 5000;
        };
    };

    class RoadsAct {
        displayName = "Kodeks drogowy";

        class S1 {
            displayName = "Jazda uszkodzonym pojazdem";
            allowManual = true;
            bounty = 300000;
        };
        class S2 : S1 {
            displayName = "Brawurowa jazda";
            bounty = 80000;
        };
        class S3 : S1 {
            displayName = "Nieostrożna/nieuważna jazda";
            bounty = 45000;
        };
        class S4 : S1 {
            displayName = "Prowadzenie pod wpływem";
            bounty = 35000;
        };
        class S6 : S1 {
            displayName = "Odmowa testu na trzeźwość";
            bounty = 55000;
        };
        class S14 : S1 {
            displayName = "Niezałożenie pasa bezpieczeństwa";
            bounty = 5000;
        };
        class S25 : S1 { // Attempting to Lockpick
            displayName = "Włamywanie się do pojazdu";
            bounty = 16000;
        };
        class S40 : S1 {
            displayName = "Pojazd w kiepskim stanie technicznym";
            bounty = 10000;
        };
        class S87 : S1 {
            displayName = "Jazda bez prawa jazdy";
            bounty = 20000;
        };
        class S163 : S1 {
            displayName = "Nieuzasadniona ucieczka przed policją";
            bounty = 65000;
        };
        class S170 : S1 {
            displayName = "Nieudzielenie pomocy na miejscu wypadku";
            bounty = 5000;
        };
        class Speed : S1 {
            displayName = "Przekroczenie prędkości";
            bounty = 15000;
        };
    };

    class Other {
        displayName = "Inne";

        class Note {
            displayName = "Notatka";
            allowManual = true;
            bounty = 0;
        };
    };
};
