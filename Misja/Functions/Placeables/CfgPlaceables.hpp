class CfgPlaceables {
	maxPlaceables = 50;

	class Objects {
		class SpikeStrip {
			displayName = "Kolczatka";
			className = "Land_Razorwire_F";
			positioning[] = { { 0, 5.5, 0 }, 90 };
			placementTime = 2;
			onPlaced = "(_this select 0) setDamage 1; _this remoteExecCall [""ULP_SRV_fnc_registerStinger"", 2];";
		};

		class RoadCone {
			displayName = "Pachołek";
			className = "RoadCone_F";
			positioning[] = { { 0, 3, 0.5 }, 0 };
			placementTime = 2;
			onPlaced = "";
		};

		class RoadConeWithLight : RoadCone {
			displayName = "Pachołek z lampką";
			className = "RoadCone_L_F";
		};

		class Stretcher {
			displayName = "Nosze";
			className = "Land_Stretcher_01_F";
			positioning[] = { { 0, 1.5, 0.5 }, 90 };
			placementTime = 5;
			onPlaced = "private _stretcher = _this param [0, objNull, [objNull]]; if (isNull _stretcher) exitWith {}; _stretcher allowDammage false; _stretcher enableSimulation false;";
			onRemoved = "private _attachedUnit = (_this select 0) getVariable [""unitAttached"", objNull]; if !(isNull _attachedUnit) then { detach _attachedUnit; };";
		};

		class SinglePortableLight : RoadCone {
			displayName = "Przenośna lampa (pojedyńcza)";
			className = "Land_PortableLight_single_F";
		};

		class DoublePortableLight : RoadCone {
			displayName = "Przenośna lampa  (podwójna)";
			className = "Land_PortableLight_double_F";
		};

		class TapeSign : RoadCone {
			displayName = "Czerwono-biała taśma";
			className = "TapeSign_F";
		};
	};
};