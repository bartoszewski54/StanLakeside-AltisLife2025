class CfgVehicleStores {
	class Base {
		factions[] = { "Civilian" };
		licenses[] = {};
		conditions = "true";
	};

	class PoliceCar : Base {
		storeName = "Sklep z pojazdami - Policja";
		factions[] = { "Police" };
		class Vehicles {
			class C_Quadbike_01_F {
				class Textures {
					class Black {};
					class White {};
				};
			};
			class C_SUV_01_F {
				condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class C_Hatchback_01_sport_F {
				condition = "[""Police_RPU"", 1] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class B_GEN_Van_02_transport_F {
				condition = "[""Police_Main"", 4] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 1] call ULP_fnc_hasAccess } || { [""Police_COL"", 1] call ULP_fnc_hasAccess }";
				class Textures {};
			};
			class B_GEN_Van_02_vehicle_F {
				condition = "[""Police_Main"", 4] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 1] call ULP_fnc_hasAccess } || { [""Police_COL"", 1] call ULP_fnc_hasAccess }";
				class Textures {};
			};
			class B_LSV_01_unarmed_black_F {
				condition = "[""Police_NCA"", 1] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class O_LSV_02_unarmed_F {
				condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_Main"", 6] call ULP_fnc_hasAccess && { [""Police_SFO"", 1] call ULP_fnc_hasAccess } }";
				class Textures {};
			};
			class B_MRAP_01_F {
				condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess";
				class Textures {};
			};
		};
	};

	class PoliceAir : Base {
		storeName = "Sklep z pojazdami - Policja";
		factions[] = { "Police" };
		class Vehicles {
			class B_UAV_01_F {
				condition = "[""Police_NCA"", 2] call ULP_fnc_hasAccess";
			};
			class C_Heli_Light_01_civil_F {
				condition = "[""Police_NPAS"", 1] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class B_Heli_Light_01_F {
				condition = "[""Police_NPAS"", 1] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class I_Heli_light_03_unarmed_F {
				condition = "[""Police_NPAS"", 1] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class O_Heli_Light_02_unarmed_F {
				condition = "[""Police_NPAS"", 2] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class O_Heli_Transport_04_black_F {
				condition = "[""Police_NPAS"", 2] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class O_Heli_Transport_04_covered_black_F {
				condition = "[""Police_NPAS"", 2] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class B_Heli_Transport_03_unarmed_F {
				condition = "[""Police_NPAS"", 2] call ULP_fnc_hasAccess";
				class Textures {
					class Black {};
				};
			};
			class B_Heli_Transport_01_F {
				condition = "[""Police_NPAS"", 3] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class I_Heli_light_03_F {
				condition = "[""Police_NPAS"", 3] call ULP_fnc_hasAccess";
				class Textures {};
			};
		};
	};

	class PoliceBoat : Base {
		storeName = "Sklep z pojazdami - Policja";
		factions[] = { "Police" };
		class Vehicles {
			class C_Boat_Civil_01_police_F {
				condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess || { [""Police_Main"", 2] call ULP_fnc_hasAccess && { ( missionNamespace getVariable [""ULP_SRV_Crime_ResearchFacility"", false] || { missionNamespace getVariable [""ULP_SRV_Crime_HMSLiberty"", false] ) } } }";
				class Textures {};
			};
			class C_Boat_Transport_02_F {
				condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class B_SDV_01_F {
				condition = "[""Police_MPU"", 2] call ULP_fnc_hasAccess";
				class Textures {};
			};
		};
	};

	class MedicCar : Base {
		storeName = "Sklep z pojazdami - Medycy";
		factions[] = { "Medic" };
		class Vehicles {
			class C_Van_02_medevac_F {
				condition = "[""Medic_Main"", 2] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class B_GEN_Van_02_transport_F {
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class B_GEN_Van_02_vehicle_F {
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class C_SUV_01_F {
				condition = "[""Medic_Main"", 3] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class C_Hatchback_01_sport_F {
				condition = "[""Medic_Main"", 4] call ULP_fnc_hasAccess";
				class Textures {};
			};
			/*class C_Offroad_01_comms_F { // TODO TEXTURE
				condition = "[""Medic_Main"", 5] call ULP_fnc_hasAccess";
				class Textures {};
			};*/
			class C_Offroad_02_unarmed_F {
				condition = "[""Medic_Main"", 6] call ULP_fnc_hasAccess";
				class Textures {};
			};
			/*class C_Van_01_box_F { // TODO TEXTURE
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class O_Truck_03_repair_F { // TODO TEXTURE
				condition = "[""Medic_Main"", 7] call ULP_fnc_hasAccess";
				class Textures {};
			};*/
		};
	};

	class MedicAir : Base {
		storeName = "Sklep z pojazdami - Medycy";
		factions[] = { "Medic" };
		class Vehicles {
			class C_UAV_06_medical_F {
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class C_Heli_Light_01_civil_F {
				condition = "[""Medic_AA"", 1] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class O_Heli_Light_02_unarmed_F {
				condition = "[""Medic_AA"", 2] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class O_Heli_Transport_04_medevac_black_F {
				condition = "[""Medic_AA"", 3] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class I_Heli_Transport_02_F {
				condition = "[""Medic_AA"", 3] call ULP_fnc_hasAccess";
				class Textures {};
			};
		};
	};

	class MedicBoat : Base {
		storeName = "Sklep z pojazdami - Medycy";
		factions[] = { "Medic" };
		class Vehicles {
			class C_Boat_Civil_01_police_F {
				condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess";
				class Textures {};
			};
		};
	};

	class HatoCar : Base {
		storeName = "Sklep z pojazdami - HATO";
		factions[] = { "Hato" };
		class Vehicles {
			class C_Offroad_01_repair_F {
				class Textures {};
			};
			class C_Van_02_service_F {
				class Textures {};
			};
			class B_Truck_01_mover_F {
				class Textures {};
			};
			class B_Truck_01_flatbed_F {
				class Textures {};
			};
			class C_SUV_01_F {
				condition = "[""Hato_Main"", 2] call ULP_fnc_hasAccess";
				class Textures {};
			};
			class C_Hatchback_01_sport_F {
				condition = "[""Hato_Main"", 3] call ULP_fnc_hasAccess";
				class Textures {};
			};
		};
	};

	class Kart : Base {
		storeName = "Salon z gokartami";
		class Vehicles {
			class C_Kart_01_Blu_F {};
			class C_Kart_01_Fuel_F {};
			class C_Kart_01_Red_F {};
			class C_Kart_01_Vrana_F {};
			class C_Kart_01_black_F {};
			class C_Kart_01_white_F {};
			class C_Kart_01_green_F {};
			class C_Kart_01_orange_F {};
			class C_Kart_01_yellow_F {};
		};
	};

	class Car : Base {
		storeName = "Salon samochodowy";
		conditions = "[""Driving""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_Quadbike_01_F {};
			class C_Hatchback_01_F {};
			class C_Hatchback_01_sport_F {};
			class C_Offroad_01_F {};
			class C_Offroad_01_covered_F {};
			class C_Offroad_02_unarmed_F {};
			class C_SUV_01_F {};
			class C_Van_02_transport_F {
				class Textures {
					class Black {};
					class White {};
					class Red {};
					class Orange {};
				};
			};
			class C_Van_02_vehicle_F {
				class Textures {
					class Black {};
					class White {};
					class Red {};
					class Orange {};
				};
			};
		};
	};

	class Truck : Base {
		storeName = "Salon z ciężarówkami";
		conditions = "[""Trucking""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_Tractor_01_F {};
			class C_Van_01_transport_F {};
			class C_Van_01_box_F {};
			class C_Van_01_fuel_F {};
			class I_Truck_02_transport_F {};
			class I_Truck_02_covered_F {};
			class I_Truck_02_fuel_F {};
			class O_Truck_03_transport_F {};
			class O_Truck_03_covered_F {};
			class O_Truck_03_ammo_F {};
			class O_Truck_03_fuel_F {};
			class B_Truck_01_cargo_F {};
			class B_Truck_01_transport_F {};
			class B_Truck_01_covered_F {};
			class B_Truck_01_ammo_F {};
			class B_Truck_01_fuel_F {};
			class B_Truck_01_box_F {};
		};
	};

	class Air : Base {
		storeName = "Lotnisko";
		conditions = "[""Piloting""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_Heli_Light_01_civil_F {}; // Cywilny śmigłowiec (np. Hummingbird)
            class C_Plane_Civil_01_F {}; // Cywilny samolot (np. Cessna 208)
            class C_Plane_Civil_01_racing_F {}; // Wyścigowy samolot cywilny (np. Cessna 208 Racing)
		};
	};

	class Boat : Base {
		storeName = "Salon z łódkami";
		conditions = "[""Boating""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_Scooter_Transport_01_F {};
			class C_Rubberboat {};
			class C_Boat_Civil_01_F {};
			class C_Boat_Transport_02_F {};
		};
	};

	class Taxi : Base {
		storeName = "Taxi Pojazdy";
		conditions = "[""Taxi""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_Hatchback_01_F {};
			class C_Hatchback_01_sport_F {};
			class C_SUV_01_F {};
		};
	};

	class News : Base {
		storeName = "AAN Pojazdy";
		conditions = "[""News""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_Van_02_transport_F {
				class Textures { class Press {}; };
			};
			class C_Van_02_vehicle_F {
				class Textures { class Press {}; };
			};
		};
	};

	class IDAP : Base {
		storeName = "IDAP";
		conditions = "[""IDAP""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_IDAP_Offroad_01_F {};
			class C_IDAP_Offroad_02_unarmed_F {};
			class C_IDAP_Van_02_transport_F {};
			class C_IDAP_Van_02_vehicle_F {};
			class C_IDAP_Truck_02_transport_F {};
			class C_IDAP_Truck_02_F {};
			class C_IDAP_Truck_02_water_F {};
			class C_IDAP_Heli_Transport_02_F {};
		};
	};

	class Rebel : Base {
		storeName = "Rebelia";
		conditions = "[""Rebel""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_Quadbike_01_F {};
			class C_Offroad_01_F {};
			class C_Offroad_01_covered_F {};
			class C_Offroad_01_comms_F {};
			class C_Offroad_02_unarmed_F {};
			class I_C_Offroad_02_LMG_F {};
		    class B_Heli_Light_01_F {};                   // Lekki śmigłowiec (Hummingbird)
            class I_Heli_light_03_unarmed_F {};           // Lekki śmigłowiec (Hellcat, bez uzbrojenia)
            class O_Heli_Light_02_unarmed_F {}; // Lekki śmigłowiec dla frakcji Opfor (np. Mi-24V)
            class I_Heli_Transport_02_F {}; // Śmigłowiec transportowy dla frakcji Blufor (np. CH-67 Huron)
            class B_Heli_Transport_03_unarmed_F {}; // Śmigłowiec transportowy dla frakcji Blufor (np. CH-47 Chinook, wersja bez uzbrojenia)
			class O_LSV_02_unarmed_F {};
			class C_Van_01_transport_F {};
			class C_Van_01_box_F {};
			class C_Van_01_fuel_F {};
		};
	};

	class Blackmarket : Base {
		storeName = "Blackmarket";
		conditions = "[""Blackmarket""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk || [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
		class Vehicles {
			class C_Quadbike_01_F {};
			class C_Offroad_01_F {};
			class C_Offroad_01_covered_F {};
			class C_Offroad_01_comms_F {};
			class C_Offroad_02_unarmed_F {};
			class I_C_Offroad_02_LMG_F {};
			class B_CTRG_LSV_01_light_F {};
			class B_LSV_01_unarmed_black_F {};
			class O_LSV_02_unarmed_F {};
			class O_MRAP_02_F {};
			class I_MRAP_03_F {};
			class C_Van_01_transport_F {};
			class C_Van_01_box_F {};
			class C_Van_01_fuel_F {};
			class B_Heli_Light_01_F {};
			class I_Heli_light_03_unarmed_F {};
			class O_T_VTOL_02_infantry_F {};
			class O_T_VTOL_02_vehicle_F {};
		};
	};

	class GangBase : Base {
		storeName = "Baza gangu";
		class Vehicles {
			// Pojazdy cywilne
            class C_Quadbike_01_F {}; // Quad
            class C_Offroad_01_F {}; // Offroad
            class C_Offroad_01_covered_F {}; // Offroad z osłoną
            class C_Offroad_01_comms_F {}; // Offroad z systemem łączności
            class C_Offroad_02_unarmed_F {}; // Offroad bez uzbrojenia
            class C_Van_01_transport_F {}; // Van transportowy
            class C_Van_01_box_F {}; // Van z przestrzenią ładunkową
            class C_Van_01_fuel_F {}; // Van z paliwem

            // Pojazdy wojskowe
            class B_G_Offroad_01_armed_F {}; // Uzbrojony offroad NATO
            class B_CTRG_LSV_01_light_F {}; // Lekki pojazd specjalny NATO
            class B_LSV_01_unarmed_black_F {}; // Czarny lekki pojazd specjalny NATO bez uzbrojenia
            class O_LSV_02_armed_black_F {}; // Czarny uzbrojony lekki pojazd specjalny OPFOR
            class O_LSV_02_unarmed_F {}; // Lekki pojazd specjalny OPFOR bez uzbrojenia
            class O_MRAP_02_F {}; // Opancerzony pojazd wielozadaniowy OPFOR
            class I_MRAP_03_F {}; // Opancerzony pojazd wielozadaniowy Independent

            // Pojazdy powietrzne
            class B_Heli_Light_01_F {}; // Lekki śmigłowiec NATO
            class I_Heli_light_03_unarmed_F {}; // Lekki śmigłowiec Independent bez uzbrojenia
            class O_Heli_Transport_04_black_F {}; // Czarny śmigłowiec transportowy OPFOR
            class O_Heli_Transport_04_bench_black_F {}; // Czarny śmigłowiec transportowy OPFOR z ławkami
            class O_Heli_Transport_04_covered_black_F {}; // Czarny śmigłowiec transportowy OPFOR z osłoną
            class O_Heli_Transport_04_box_black_F {}; // Czarny śmigłowiec transportowy OPFOR z przestrzenią ładunkową
            class O_Heli_Transport_04_ammo_black_F {}; // Czarny śmigłowiec transportowy OPFOR z amunicją
            class O_Heli_Transport_04_fuel_black_F {}; // Czarny śmigłowiec transportowy OPFOR z paliwem

            // Pojazdy VTOL
            class O_T_VTOL_02_infantry_F {}; // VTOL OPFOR dla piechoty
            class O_T_VTOL_02_vehicle_F {}; // VTOL OPFOR dla pojazdów
		};
	};
};