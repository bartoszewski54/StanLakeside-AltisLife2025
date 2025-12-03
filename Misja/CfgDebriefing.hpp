class CfgDebriefing {
    class Abort {
        title = "DISCONNECT";
        subtitle = "Dzięki za grę!";
        description = "Dane zapisane, możesz wyjść do lobby.";
        pictureBackground = "";
        picture = "\A3\ui_f\data\GUI\Cfg\Hints\Doors_ca.paa";
        pictureColor[] = {1,1,1,1};
    };
    class InitFailed : Abort {
        title = "Nie można dołączyć";
        subtitle = "Zapytanie o dane gracza nie powiodło się";
        description = "Prosimy o kontakt z administracją w celu uzyskania pomocy";
    };
    class NotWhitelisted : Abort {
        title = "Nie masz dostępu do tego slota";
        subtitle = "Nie jesteś w tej frakcji...";
        description = "Aby uzyskać więcej informacji, skontaktuj się z zarządem tej frakcji.";
    };
    class Blacklisted : Abort {
        title = "Nie wejdziesz...";
        subtitle = "BLACKLISTA";
        description = "Aby uzyskać więcej informacji, skontaktuj się z zarządem tej frakcji.";
    };
    class CheatCheck : InitFailed {
         title = "Anticheat";
         subtitle = "Błąd anticheata, spróbój wejść ponownie (nie alt tabuj)";
    };
    class BadName {
        title = "Forbidden Player Name";
        subtitle = "You shall not pass!";
        description = "Your player name contains non standard A-Z letters that cannot be used on this server.";
        pictureBackground = "";
        picture = "";
        pictureColor[] = {0,0.3,0.6,1};
    };

    class GlobalBan {
        title = "You are Global Banned!";
        subtitle = "You shall not pass!";
        description = "You are global banned and cannot play on this server, sorry!";
        pictureBackground = "";
        picture = "";
        pictureColor[] = {0,0.3,0.6,1};
    };

    class LoadFailed {
        title = "Loading client scripts failed";
        subtitle = "Please rejoin";
        description = "Some client side scripts failed to load. Please do not alt+tab while joining. If this issue persists, contact a developer.";
        pictureBackground = "";
        picture = "";
        pictureColor[] = {0,0.3,0.6,1};
    };
};