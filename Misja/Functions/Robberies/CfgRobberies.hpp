class CfgRobberies {
	personalTimeout = 3 * 60;
	
	class FuelStation {
		name = "Stacja benzynowa";
		time = 5 * 60;
		timeout = 30 * 60;
		factions[] = { "Civilian" };
		reward[] = { 50000, 175000 };
		leveling[] = { { 5, 15 }, "Robbed Fuel Station", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction >= 3";
		onFail = "[""Musi być minimum <t color='#B92DE0'>3 policjantów</t> aby napaść to miejsce!""] call fini_fnc_noty;";
	};

	class Supermarket {
		name = "Supermarket";
		time = 7 * 60;
		timeout = 30 * 60;
		factions[] = { "Civilian" };
		reward[] = { 130000, 350000 };
		leveling[] = { { 5, 15 }, "Robbed Supermarket", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction >= 3";
		onFail = "[""Musi być minimum <t color='#B92DE0'>4 policjantów</t> aby napaść to miejsce""] call fini_fnc_noty;";
	};

	class Jewellery {
		name = "Jubiler";
		time = 8 * 60;
		timeout = 45 * 60;
		factions[] = { "Civilian" };
		reward[] = { 750000, 1250000 };
		leveling[] = { { 5, 15 }, "Robbed Jewellery Store", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction >= 4";
		onFail = "[""Musi być minimum <t color='#B92DE0'>4 policjantów</t> aby napaść to miejsce""] call fini_fnc_noty;";
	};

	class RegionalBank {
		name = "Bank Regionalny";
		time = 10 * 60;
		timeout = 45 * 60;
		factions[] = { "Civilian" };
		reward[] = { 1250000, 1500000 };
		leveling[] = { { 5, 15 }, "Robbed Regional Bank", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction >= 5";
		onFail = "[""Musi być minimum <t color='#B92DE0'>5 policjantów</t> aby napaść to miejsce""] call fini_fnc_noty;";
	};
};