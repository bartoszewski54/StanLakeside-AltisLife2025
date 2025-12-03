class CfgOptions {
	class General {
		title = "Ogólne";

		class EnableWelcome {
			name = "Włącz komunikat powitalny";
			tooltip = "Po włączeniu tej opcji tekst z informacjami o serwerze będzie wyświetlany przy wejściu na serwer.";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 1 };
			condition = "true";
		};

		class EnableStreamerMode : EnableWelcome {
			name = "Włącz tryb streamera";
			tooltip = "Po włączeniu tej opcji niektóre aspekty gry mogą zostać ukryte lub ocenzurowane w celu zachowania prywatności.";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 0 };
		};

		class EnableAutoDecline : EnableWelcome {
			name = "Włącz opcję Ignoruj zaproszenia do grup";
			tooltip = "Po włączeniu tej opcji zaproszenia grupowe będą automatycznie odrzucane.";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 0 };
		};

		class NightLight : EnableWelcome {
			name = "Światło nocne otoczenia";
			tooltip = "Jest to poziom światła, który oświetla mapę w nocy.";
			type = "SLIDER";
			values[] = { { 0, 0.5 }, 0.5, { 0.1, 0.1 } };
		};

		class EnableAutoChatSwitch : EnableWelcome {
			name = "Włącz przełącznik czatu pojazdu";
			tooltip = "Po włączeniu tej funkcji wejście do pojazdu spowoduje automatyczne przełączenie kanału.";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 1 };
		};
	};

	class Audio {
		title = "Audio";

		class EffectsFade {
			name = "Głośność efektów";
			tooltip = "Jest to głośność efektów, która będzie używana podczas korzystania z zatyczek do uszu.";
			type = "SLIDER";
			values[] = { { 0, 1 }, 0.25, { 0.1, 0.1 } };
			condition = "true";
		};

		class MusicFade : EffectsFade {
			name = "Głośność muzyki";
			tooltip = "Jest to głośność muzyki, która będzie używana podczas korzystania z zatyczek do uszu.";
			type = "SLIDER";
			values[] = { { 0, 1 }, 0.25, { 0.1, 0.1 } };
		};

		class EnableMessageAlert : EffectsFade {
			name = "Włącz alert wiadomości";
			tooltip = "Po włączeniu tej funkcji użytkownik otrzyma powiadomienie dźwiękowe o odebraniu wiadomości.";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 1 };
		};

		class EnableAmbientSounds : EffectsFade {
			name = "Dźwięki otoczenia";
			tooltip = "Włącz dźwięki otoczeniaPo włączeniu tej opcji będzie można usłyszeć dźwięki otoczenia ArmA";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 1 };
		};
	};

	class ViewDistance {
		title = "Rendering";

		class FootViewDistance {
			name = "Odległość renderowania- pieszo";
			tooltip = "Jest to odległość widoczności podczas chodzenia. (500 - 10000m)";
			type = "SLIDER";
			values[] = { { 500, 10000 }, 3000, { 1, 1 } };
			condition = "true";
		};

		class LandViewDistance : FootViewDistance {
			name = "Odległość renderowania - pojazd";
			tooltip = "Jest to odległość widzenia w pojeździe lądowym. (500 - 10000m)";
		};

		class AirViewDistance : FootViewDistance {
			name = "Odległość renderowania - samoloty/helikoptery";
			tooltip = "Jest to odległość widzenia w pojeździe powietrznym. (500 - 10000m)";
		};
	};

	class HUD {
		title = "UI";

		class EnableHUD {
			name = "HUD";
			tooltip = "Po włączeniu na ekranie wyświetlane są informacje takie jak stan zdrowia, woda itp.";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 1 };
			condition = "true";
		};

		class EnableXPBar : EnableHUD {
			name = "XP";
			tooltip = "Jeśli hud jest włączony, a także pasek xp, będziesz mieć swój xp wyświetlany na ekranie.";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 1 };
		};

		class EnablePlayerTags : EnableHUD  {
			name = "Nick nad głową - inni";
			tooltip = "Po włączeniu tej funkcji informacje o innych są wyświetlane nad głową.";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 1 };
		};

		class ShowOwnTags : EnableHUD  {
			name = "Nick nad głową - Ty";
			tooltip = "Jeśli włączone, zobaczysz swój własny tag gracza.";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 0 };
		};

		class SideChat : EnableHUD  {
			name = "SideChannel";
			tooltip = "Gdy włącząne, widzisz wiadomości z SideChannela";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 1 };
		};
	};

class Indicators {
    title = "Tagi grupowe";

    class EnableIndicators {
        name = "Znaczniki";
        tooltip = "Po włączeniu, hexagony pokazujące lokalizację członków grupy będą wyświetlane.";
        type = "DROPDOWN";
        values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 1 };
        condition = "true";
    };

    class EnableFactionColouring {
        name = "Kolory na znaczniku";
        tooltip = "Po włączeniu, znaczniki będa mieć kolor.";
        type = "DROPDOWN";
        values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 1 };
        condition =  "[player, [""Police"", ""Medic""]] call ULP_fnc_isFaction";
    };

    class EnableNamesOnIndicators : EnableIndicators {
        name = "Nicki na znacznikach";
        tooltip = "Po włączeniu, nicki członków grupy będą wyświetlane pod ich hexagonami.";
    };

    class IndicatorDistance : EnableIndicators {
        name = "Odległość renderowania znaczników";
        tooltip = "To odległość, przy której znaczniki grupy będą wyświetlane. (20 - 6000m)";
        type = "SLIDER";
        values[] = { { 20, 6000 }, 2000, { 1, 1, 1 } };
    };
};


	class Cartels {
		title = "Kartele";

		class NotifyPayment {
			name = "Pokazuj wypłaty z kartelu";
			tooltip = "Po włączeniu tej funkcji zostaniesz dokładnie poinformowany, ile ty i grupa otrzymaliście od karteli.";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 1 };
			condition = "true";
		};
	};

	class Chat {
		title = "Chat";

		class EnableMessagesIncapacitated {
			name = "Wiadomości o powaleniach i zranieniach";
			tooltip = "Po włączeniu tej opcji na czacie będą wyświetlane komunikaty o powaleniu i zranieniach.";
			type = "DROPDOWN";
			values[] = { { {"Włączone", 1}, {"Wyłączone", 0} }, 1 };
			condition = "true";
		};

		class EnableMessagesTicket : EnableMessagesIncapacitated {
			name = "Mandaty";
			tooltip = "Po włączeniu tej opcji wiadomości o mandatach będą wyświetlane na czacie.";
		};

		class EnableMessagesPrisoned : EnableMessagesIncapacitated {
			name = "Więzienie";
			tooltip = "Po włączeniu tej opcji wiadomości o wsadzeniu do więzienia będą wyświetlane na czacie.";
		};

		class EnableMessagesVehicle : EnableMessagesIncapacitated {
			name = "Pojazdy";
			tooltip = "Po włączeniu tej opcji na czacie będą wyświetlane komunikaty o garażowaniu, skonfiskowaniu i zniszczeniu pojazdów.";
		};
	};
};