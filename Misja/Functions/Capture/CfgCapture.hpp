class CfgCapture {
	class Altis {
		class WestHideout {
			displayName = "Zachodnia kryjówka";
			time = 180;
			condition = "[""Hideout""] call ULP_fnc_hasGroupPerk";
		};
		class EastHideout : WestHideout { displayName = "Wschodnia kryjówka"; };
	};
};