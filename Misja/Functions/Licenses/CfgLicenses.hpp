class CfgLicenses {
    class BaseLicense {
        factions[] = { "Civilian" };
        description = "Wymagana do przetworzenia danego towaru.";
        class Settings {
            isVisible = false;
            isRemovable = false;
        };
        conditions = "true";
    };

    class Driving : BaseLicense {
        displayName = "Prawo Jazdy";
        description = "Podstawowy wymóg zakupu samochodu/trucka.";
        buyPrice = 1000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Trucking : Driving {
        displayName = "Licencja Kierowcy Ciężarówki";
        description = "Podstawowy wymóg zakupu pojazdu do przewozu towarów.";
        buyPrice = 95000;
        class Settings : Settings {};
    };

    class Boating : Driving {
        displayName = "Licencja Żeglarska";
        description = "Podstawowy wymóg zakupu łodzi.";
        buyPrice = 6500;
        class Settings : Settings {};
    };

    class BIXA : BaseLicense {
        displayName = "BIXA - Gang";
        description = "";
        buyPrice = 999999999;
        class Settings {
            isVisible = false;
            isRemovable = false;
        };
    };

    class CVL : BaseLicense {
        displayName = "CVL - Gang";
        description = "";
        buyPrice = 999999999;
        class Settings {
            isVisible = false;
            isRemovable = false;
        };
    };

    class Piloting : Driving {
        displayName = "Licencja Pilota";
        description = "Podstawowy wymóg zakupu helikoptera/samolotu.";
        buyPrice = 380000;
        class Settings : Settings {};
    };

    class Home : Driving {
        displayName = "Licencja na dom";
        description = "Podstawowy wymóg zakupu nieruchomości.";
        buyPrice = 300000;
        class Settings : Settings {};
    };

    class Taxi : Driving {
        displayName = "Pracownik Taxi Altis";
        description = "Zatwierdzenie do pracy jako kierowca taksówki na Altis.";
        buyPrice = 35000;
        onBought = "[""Employment""] call ULP_fnc_achieve;";
        class Settings : Settings {};
        conditions = "[""CompletedCV""] call ULP_fnc_hasPerk";
    };

    class Solicitor : Taxi {
        displayName = "Adwokat Altis";
        description = "Zatwierdzenie do pracy jako adwokat na Altis.";
         buyPrice = 2000000;
        class Settings : Settings {};
    };

    class News : Taxi {
        displayName = "Reporter AAN World News";
        description = "Zatwierdzenie do pracy jako reporter na Altis.";
        buyPrice = 700000;
        class Settings : Settings {};
    };

    class IDAP : Driving {
        displayName = "Wolontariusz IDAP";
        description = "Zadeklarowano pracę dla Międzynarodowego Projektu Pomocy i Rozwoju.";
        buyPrice = 0;
        class Settings : Settings {};
    };

    class Handgun : Driving {
        displayName = "Licencja na broń krótką";
        description = "Certyfikat umożliwiający posiadanie broni krótkiej.";
        buyPrice = 65000;
        class Settings : Settings {};
    };

    class Security : Driving {
        displayName = "Ochrona - Firma";
        description = "Ochroniarz danej firmy";
        buyPrice = 350000;
        class Settings : Settings {};
        conditions = "[""SecurityContactors""] call ULP_fnc_hasGroupPerk";
    };
    class Protection : Driving {
        displayName = "Ochrona - Rządowa";
        description = "Ochroniarz rządowy";
        buyPrice = 350000;
        class Settings : Settings {};
        conditions = "[""PersonalProtection""] call ULP_fnc_hasGroupPerk";
    };

    class Hunting : Driving {
        displayName = "Licencja łowiecka";
        description = "Certyfikat pozwalający na polowanie na dzikie zwierzęta.";
        buyPrice = 1140000;
        class Settings : Settings {};
    };

    class Rebel : BaseLicense {
        displayName = "Rebelia";
        description = "Dostęp do rebelii.";
        buyPrice = 3500000;
        onBought = "[""JoinRebel""] call ULP_fnc_achieve;";
        class Settings {};
    };

    class Blackmarket : BaseLicense {
        displayName = "Dostęp do Czarnego Rynku";
        description = "Dzięki tej licencji masz dostęp do blackmarketu.";
        buyPrice = 5000000;
        class Settings {};
        conditions = "[""Rebel""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk || [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
    };

    // Lokacje przetwarzania
    class Schnapps : BaseLicense {
        displayName = "Przetwarzanie Wódki";
        buyPrice = 15000;
        class Settings {};
    };

    class Tobacco : BaseLicense {
        displayName = "Przetwarzanie tytoniu";
        buyPrice = 45000;
        class Settings {};
    };

    class Copper : BaseLicense {
        displayName = "Przetwarzanie miedzi";
        buyPrice = 30000;
        class Settings {};
    };

    class Silver : BaseLicense {
        displayName = "Przetwarzanie srebra";
        buyPrice = 35000;
        class Settings {};
    };

    class Iron : BaseLicense {
        displayName = "Przetwarzanie żelaza";
        buyPrice = 290000;
        class Settings {};
    };

    class Salt : BaseLicense {
        displayName = "Przetwarzanie soli";
        buyPrice = 340000;
        class Settings {};
    };

    class Sand : BaseLicense {
        displayName = "Przetwarzanie piasku";
        buyPrice = 155000;
        class Settings {};
    };

    class Oil : BaseLicense {
        displayName = "Przetwarzanie ropy";
        buyPrice = 565000;
        class Settings {};
    };

    class Diamond : BaseLicense {
        displayName = "Przetwarzanie diamentów";
        buyPrice = 836500;
        class Settings {};
    };

    class Uranium : BaseLicense {
        displayName = "Przetwarzanie uranu";
        buyPrice = 1500000;
        class Settings {};
    };

    class Weed : BaseLicense {
        displayName = "Przetwarzanie marihuany";
        buyPrice = 180000;
        class Settings {};
    };

    class Heroin : BaseLicense {
        displayName = "Przetwarzanie heroiny";
        buyPrice = 495000;
        class Settings {};
    };

    class Cocaine : BaseLicense {
        displayName = "Przetwarzanie kokainy";
        buyPrice = 770000;
        class Settings {};
    };

    class Meth : BaseLicense {
        displayName = "Przetwarzanie metamfetaminy";
        buyPrice = 885000;
        class Settings {};
    };

    class Moonshine : BaseLicense {
        displayName = "Przetwarzanie bimbru";
        buyPrice = 1100000;
        class Settings {};
    };
};
