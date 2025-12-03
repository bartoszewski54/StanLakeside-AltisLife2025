/*
	File: slot_machine.hpp
        Author: JimSub
*/

////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Joe Dobrodziej, v1.063, #Bosome)
////////////////////////////////////////////////////////

class SlotMachineGUI
{
	idd = 5780;
	movingEnabled = 0;
	enableSimulation = 1;
	
	class controlsBackground
	{
	
		class RscPicture_1800: Life_RscPicture
		{
			idc = 5770;
			text = "Data\Textures\Casino\background.paa";
			x = -4 * 0.025 + 0;
			y = -6 * 0.04 + 0;
			w = 48 * 0.025;
			h = 37 * 0.04;
		};
		
		class RscText_1000: Life_RscText
		{
			idc = 5774;
			text = "Wygrana: $"; //--- ToDo: Localize;
			x = 13 * 0.025 + 0;
			y = 21 * 0.04 + 0;
			w = 5 * 0.025;
			h = 2 * 0.04;
		};
		
		class RscText_1003: Life_RscText
		{
			idc = 5783;
			text = "OBSTAW"; //--- ToDo: Localize;
			x = 5 * 0.025 + 0;
			y = 14 * 0.04 + 0;
			w = 3.5 * 0.025;
			h = 1 * 0.04;
		};
		class RscText_1004: Life_RscText
		{
			idc = 5784;
			text = "OBSTAW"; //--- ToDo: Localize;
			x = 14 * 0.025 + 0;
			y = 14 * 0.04 + 0;
			w = 3.5 * 0.025;
			h = 1 * 0.04;
		};
		class RscText_1005: Life_RscText
		{
			idc = 5786;
			text = "OBSTAW"; //--- ToDo: Localize;
			x = 22 * 0.025 + 0;
			y = 14 * 0.04 + 0;
			w = 3.5 * 0.025;
			h = 1 * 0.04;
		};
		class RscText_1006: Life_RscText
		{
			idc = 5787;
			text = "OBSTAW"; //--- ToDo: Localize;
			x = 31 * 0.025 + 0;
			y = 14 * 0.04 + 0;
			w = 3.5 * 0.025;
			h = 1 * 0.04;
		};
	};
	
	class controls
	{
		class SLOT_1: Life_RscPicture
		{
			idc = 5771;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 4 * 0.025 + 0;
			y = 4 * 0.04 + 0;
			w = 8 * 0.025;
			h = 9 * 0.04;
		};
		class SLOT_2: Life_RscPicture
		{
			idc = 5772;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 16 * 0.025 + 0;
			y = 4 * 0.04 + 0;
			w = 8 * 0.025;
			h = 9 * 0.04;
		};
		class SLOT_3: Life_RscPicture
		{
			idc = 5773;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 28 * 0.025 + 0;
			y = 4 * 0.04 + 0;
			w = 8 * 0.025;
			h = 9 * 0.04;
		};
		
		class Winnings: Life_RscText
		{
			idc = 5775;
			test = "";
			x = 18.5 * 0.025 + 0;
			y = 21 * 0.04 + 0;
			w = 7 * 0.025;
			h = 2 * 0.04;
		};
		
		class EXIT_BTN: Life_RscButtonMenu
		{
			idc = -1;
			text = "WYJDŹ"; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "closeDialog 0;";
			x = 35.5 * 0.025 + 0;
			y = 1 * 0.04 + 0;
			w = 3.5 * 0.025;
			h = 1 * 0.04;
		};
		class BET_5K: Life_RscButtonMenu
		{
			idc = 5778;
			text = "25k"; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[25000] spawn ULP_fnc_spinSlot;";
			x = 5 * 0.025 + 0;
			y = 15 * 0.04 + 0;
			w = 4 * 0.025;
			h = 2 * 0.04;
		};

		class BET_10K: Life_RscButtonMenu
		{
			idc = 5782;
			text = "50k"; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[50000] spawn ULP_fnc_spinSlot;";
			x = 14 * 0.025 + 0;
			y = 15 * 0.04 + 0;
			w = 4 * 0.025;
			h = 2 * 0.04;
		};
		
		class BET_25K: Life_RscButtonMenu
		{
			idc = 5781;
			text = "100k"; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[100000] spawn ULP_fnc_spinSlot;";
			x = 22 * 0.025 + 0;
			y = 15 * 0.04 + 0;
			w = 4 * 0.025;
			h = 2 * 0.04;
		};

		class BET_50K: Life_RscButtonMenu
		{
			idc = 5779;
			text = "500k"; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[500000] spawn ULP_fnc_spinSlot;";
			x = 31 * 0.025 + 0;
			y = 15 * 0.04 + 0;
			w = 4 * 0.025;
			h = 2 * 0.04;
		};

	};

};


