class CfgMessages {
	length = 256;

	class Message {
		picture = "\a3\3den\data\Cfg3DEN\Comment\texture_ca.paa";
		displayName = "Prywatna wiadomość";
		sendTo[] = { "Police", "Medic", "Hato", "Civilian" };
		ignoreStreamer = false;
		ignoreComms = false;
		alertSound = true;
		canReply = true;
		confirmSend = true;
		saveInbox = true;
		sender = "%1";
		targets = "";
		condition = "true";
	};

	class StaffMessage : Message {
		displayName = "Wiadomość od Admina";
		ignoreStreamer = true;
		ignoreComms = true;
		sender = "Administrator";
		condition = "[""ULP_Staff"", 2] call ULP_fnc_hasAccess";
	};

	class Reply : Message {
		displayName = "Odpowiedz";
		condition = "false";
	};

	class StaffDispatch : Message {
		picture = "Data\UI\Messaging\staffDispatch.paa";
		displayName = "Kontakt z Administracją";
		ignoreStreamer = true;
		ignoreComms = true;
		targets = "(allPlayers select { [_x] call ULP_fnc_onDuty })";
	};

	class PoliceEmergencyDispatch : Message {
		picture = "Data\UI\Messaging\999.paa";
		displayName = "POLICJA";
		targets = "[""Police""] call ULP_fnc_allMembers";
	};

	class HealthEmergencyDispatch : PoliceEmergencyDispatch {
		displayName = "EMS";
		targets = "[""Medic""] call ULP_fnc_allMembers";
	};

	class PublicAnnoucement : Message {
		picture = "Data\UI\Messaging\publicAnnouncement.paa";
		displayName = "Ogłoszenie (ADM)";
		ignoreStreamer = true;
		canReply = false;
		sender = "Administracja";
		targets = "0";
		condition = "[""ULP_Staff"", 2] call ULP_fnc_hasAccess;";
	};

	class EventsAnnoucement : PublicAnnoucement {
		picture = "Data\UI\Messaging\eventAnnouncement.paa";
		displayName = "Ogłoszenie (EVENT)";
		sender = "Event Team";
		condition = "[""ULP_Staff"", 2] call ULP_fnc_hasAccess || { [""ULP_Event"", 1] call ULP_fnc_hasAccess }";
	};

	class OpenAirBroadcast : PublicAnnoucement {
		displayName = "Radio - Pojazdy Powietrzne";
		sender = "POLICJA";
		targets = "(allPlayers select { !(isNull (objectParent _x)) && { (vehicle _x) isKindOf 'Air'} })";
		condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
	};
	class FromPoliceBroadcast : PublicAnnoucement {
		displayName = "Ogłoszenie (POLICJA)";
		sender = "POLICJA";
		condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
	};

	class OpenSeaBroadcast : OpenAirBroadcast {
		displayName = "Radio - Pojazdy Wodne";
		targets = "(allPlayers select { !(isNull (objectParent _x)) && { (vehicle _x) isKindOf 'Ship'} })";
	};

	class Dispute : Message {
		picture = "Data\UI\dispute.paa";
		displayName = "Wezwanie na TS3";
		ignoreStreamer = true;
		ignoreComms = true;
		condition = "false";
	};

	class MedicRequest : Dispute {
		displayName = "Żądanie medyka";
		confirmSend = false;
		saveInbox = false;
		targets = "[""Medic""] call ULP_fnc_allMembers";
	};

	class Panic : Dispute {
		displayName = "Panic Button";
		ignoreComms = false;
		alertSound = false;
		confirmSend = false;
		saveInbox = false;
		canReply = false;
		onRecieved = "private _sender = _this select 0; if (isNull _sender || { _sender isEqualTo player }) exitWith {}; private _marker = createMarkerLocal [format[""panic_marker_%1_%2"", time, name _sender], getPos _sender]; _marker setMarkerTypeLocal ""mil_warning""; _marker setMarkerColorLocal ""colorRed""; _marker setMarkerTextLocal (name _sender); [120, _marker, { deleteMarkerLocal _this }] call ULP_fnc_waitExecute;";
		targets = "[""Police""] call ULP_fnc_allMembers";
	};

	class Robbery : Panic {
		displayName = "Napad";
        sender = "CENTRALA";
		onRecieved = "private _sender = _this select 0; if (isNull _sender || { _sender isEqualTo player }) exitWith {};";
	};

	class BreakIn : Panic {
		displayName = "Włamanie";
        sender = "CENTRALA";
		onRecieved = "private _sender = _this select 0; if (isNull _sender || { _sender isEqualTo player }) exitWith {}; private _marker = createMarkerLocal [format[""breakin_marker_%1_%2"", time, name _sender], getPos _sender]; _marker setMarkerTypeLocal ""mil_warning""; _marker setMarkerColorLocal ""colorRed""; _marker setMarkerTextLocal ""!!UWAGA - NAPAD!!""; [15, _marker, { deleteMarkerLocal _this }] call ULP_fnc_waitExecute;";
	};
};