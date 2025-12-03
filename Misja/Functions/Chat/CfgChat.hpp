class CfgChat {
	class Messages {
		class Injured {
			message = "%1 jest nieprzytomny.";
			params = 1;
			condition = "[[""EnableMessagesIncapacitated"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Executed {
			message = "%1 został odstrzelony przez %2.";
			params = 2;
			condition = "[[""EnableMessagesBleedout"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class InjuredBy : Executed {
			message = "%1 został zabity przez %2.";
		};
		//class Revived : Executed {
		//	message = "%1 został zreanimowany przez %2.";
		//	condition = "[[""EnableMessagesRevived"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		//};
		class Prisoned {
			message = "%1 został zamknięty w więzieniu przez %2 na %3 minut/y.";
			params = 3;
			condition = "[[""EnableMessagesPrisoned"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Garaged : Prisoned {
			message = "Pojazd %1 (%2) został odholowany przez %3.";
			condition = "[[""EnableMessagesVehicle"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Crushed : Garaged {
			message = "Pojazd %1 (%2) został ZEZŁOMOWANY przez %3.";
		};
		class Impounded : Garaged {
			message = "Pojazd %1 (%2) został odholowany na parking policyjny przez %3 z kaucją %4.";
			params = 4;
		};
		class IssuedFine : Prisoned {
			message = "%1 wstawił %2 mandat na kwotę %3.";
			condition = "[[""EnableMessagesTicket"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class FinePaid : IssuedFine {
			message = "%1 zapłacił mandat na kwotę %2.";
			params = 2;
		};
		class FineRefused : FinePaid {
			message = "%1 odmówił mandatu na kwotę %2.";
		};
		class FinePoor : FinePaid {
			message = "%1 nie jest w stanie pokryć mandatu na kwotę %2.";
		};
		class ReturnedToLobby : Injured {
			message = "%1 wyszedł do lobby.";
			condition = "true";
		};
	};
	class Commands {
		class Players {
			action = "[""Ilośc osób: "", format [""%1"", count allPlayers]]";
			condition = "true";
		};
		class PID {
			action = "[""ARP ID:"", format [""%1"", [ULP_ID] call ULP_fnc_numberText]]";
			condition = "(missionNamespace getVariable [""ULP_ID"", -1]) > -1";
		};
		class SteamID : Players {
			action = "[""Steam ID:"", format [""%1"", getPlayerUID player]]";
		};
	};
};