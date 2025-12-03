class CfgMusic {
     tracks[] = {};
     class cam_intro {
        name = "cam_intro";
        sound[] = {"\Data\Sounds\intro_song.ogg", 1.0, 1};
    };
};

class CfgSounds {
    sounds[] = {};
	
    class britishSiren {
        name = "britishSiren";
        sound[] = {"\Data\Sounds\britishSiren.ogg", 1.0, 1};
        titles[] = {};
    };

    class flashbang {
        name = "flashbang";
        sound[] = {"\Data\Sounds\flashbang.ogg", 1.0, 1};
        titles[] = {};
    };

    class fini_notification {
        name = "fini_notification";
        sound[] = {"\fini\notifications\sounds\notify.ogg", 1, 1};
        titles[] = {};
    };

     class empwarn {
     name = "empwarn";
     sound[] = {"\Data\Sounds\empwarn.ogg", 1.0, 1};
     titles[] = {};
     };

     class empacsound {
     name = "empacsound";
     sound[] = {"\Data\Sounds\empac.ogg", 1.0, 1};
     titles[] = {};
     };

    class restart {
        name = "restart";
        sound[] = {"\Data\Sounds\restart.ogg", 1.0, 1};
        titles[] = {};
    };

    class Siren1 {
        name = "siren1";
        sound[] = {"\Data\Sounds\Sirens\siren_1.ogg", 1.0, 1};
        titles[] = {};
    };

    class Siren2 : Siren1 {
        name = "siren1";
        sound[] = {"\Data\Sounds\Sirens\siren_2.ogg", 1.0, 1};
    };

    class Siren3 : Siren1 {
        name = "siren1";
        sound[] = {"\Data\Sounds\Sirens\siren_3.ogg", 1.0, 1};
    };

    class Siren4 : Siren1 {
        name = "siren1";
        sound[] = {"\Data\Sounds\Sirens\siren_4.ogg", 1.0, 1};
    };

    class taserSound {
        name = "taserSound";
        sound[] = {"\Data\Sounds\taser.ogg", 0.5, 1};
        titles[] = {};
    };

    class lockCarSound {
        name = "lockCarSound";
        sound[] = {"\Data\Sounds\carLock.ogg", 1.0, 1};
        titles[] = {};
    };

    	class cam_first {
            name = "cam_first";
            sound[] = {"\Data\Sounds\first.ogg", db + 50, 1};
            titles[] = {};
        };
    	class cam_bum {
            name = "cam_bum";
            sound[] = {"\Data\Sounds\bum.ogg", db + 50, 1};
            titles[] = {};
        };
    	class cam_lastbum {
            name = "cam_lastbum";
            sound[] = {"\Data\Sounds\lastbum.ogg", db + 50, 1};
            titles[] = {};
        };

    class unlockCarSound {
        name = "unlockCarSound";
        sound[] = {"\Data\Sounds\carUnlock.ogg", 0.75, 1};
        titles[] = {};
    };

    class metalDetector {
        name = "metalDetector";
        sound[] = {"\Data\Sounds\metalDetector.ogg", 0.75, 1}; 
        titles[] = {};
    };

    class klakson {
        name = "klakson";
        sound[] = {"\Data\Sounds\klakson.ogg", 1.0, 1};
        titles[] = {};
    };

    class panicButton {
        name = "panicButton";
        sound[] = {"\Data\Sounds\panicButton.ogg", 1.0, 1};
        titles[] = {};
    };

    class messageNotification {
        name = "messageNotification";
        sound[] = {"\Data\Sounds\messageNotification.ogg", 1.0, 1};
        titles[] = {};
    };

    class powiadomienie {
        name = "powiadomienia";
        sound[] = {"\Data\Sounds\slideout.ogg", 1.0, 1};
        titles[] = {};
    };

    class ping {
        name = "ping";
        sound[] = {"\Data\Sounds\ping.ogg", 1.0, 1};
        titles[] = {};
    };

    class handCuff {
        name = "handCuff";
        sound[] = {"\Data\Sounds\handCuff.ogg", 0.5, 1};
        titles[] = {};
    };
};