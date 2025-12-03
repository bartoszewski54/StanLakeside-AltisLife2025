class CfgCrimes {
	class Altis {
		class HMTreasury {
			title = "Skarbiec";
			description = "Położony w pobliżu głównego lotniska na wyspie, Skarbiec państwa jest silnie ufortyfikowanym centrum zarządzania gospodarczego. Mieszczący się w nowoczesnej, żelbetonowej strukturze, nadzoruje finanse publiczne, stabilność waluty i politykę gospodarczą wyspy.<br /><br /> Chroniony wysokimi środkami bezpieczeństwa, skarbiec zapewnia bezpieczeństwo kluczowych operacji finansowych, jednocześnie utrzymując bliskie powiązania ze strategiczną infrastrukturą Altis. Pomimo swojej utylitarnej konstrukcji, instytucja ta symbolizuje odporność i stabilność, chroniąc przyszłość gospodarczą wyspy w niestabilnym krajobrazie geopolitycznym";
			factions[] = { "Civilian" };
			cooldown = 1000;
			class Stages {
				class Hack {
					displayName = "Zabezpieczenia Skarbca";
					description = "Aby sforsować zabezpieczenia skarbca, należy najpierw uzyskać dostęp do dwóch zewnętrznych biur wojskowych, używając <font color='#B92DE0'>nożyc do metalu</font>. Wewnątrz można użyć <font color='#B92DE0'>urządzenia hakerskiego</font>, aby wyłączyć główny system bezpieczeństwa skarbca. Po jego dezaktywacji wewnętrzne kopuły można przeciąć nożycami i wejść do środka, uzyskując dostęp do zawartości skarbca.";
					time = 600;
					onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Ktoś grzebie przy zabezpieczeniach skarbca!""], _targets] call ULP_fnc_sendMessage; [""Włamywanie rozpoczęte. Policja została powiadomiona!""] call fini_fnc_noty;"; // Notify Police...
					onCompleted = "[""HMTreasury"", 1] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""Wyłączyłeś systemy zabezpieczające skarbiec...""] call fini_fnc_noty;"; // Call to fill vaults, allow vaults to be drilled...
					onEachFrame = "";
					onProgressStop = "";
					onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 8) : { ""Musi być minimum <t color='#B92DE0'>8 policjantów</t> do zaczęcia napadu..."" }; case ([""HackingDevice""] call ULP_fnc_hasItem < 1) : { ""Potrzebujesz HackRF do tego napadu..."" }; default { ""Zabezpiezenia Skarbca są już wyłączone..."" }; })] call fini_fnc_noty;";
				    condition = "!(missionNamespace getVariable [""ULP_SRV_Crime_HMTreasury"", false]) && { [""HackingDevice""] call ULP_fnc_hasItem > 0 } && { (count ([""Police""] call ULP_fnc_allMembers)) >= 8 }";
				};
			};
			class Buildings {
				class MilitaryOfficeOne {
					classname = "Land_MilOffices_V1_F";
					position[] = {16009.7, 16900.3, 0.372055};
					class BreakIn {
						breakIn = 240;
						onBreakIn = "if (([""SilentLocksmith"", (random 1)] call ULP_fnc_activatePerk) < 0.8) exitWith {}; private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Ktoś włamuje się do biura ochrony skarbca.""], _targets] call ULP_fnc_sendMessage; [""Przypadkowo uruchomiłeś alarm podczas włamywania się do zamka... Gratulacje. Policja została wezwana.""] call fini_fnc_noty;";
						onFail = "[""Musi być minimum <t color='#B92DE0'>8 policjantów</t> do zaczęcia włamu...""] call fini_fnc_noty;";
						condition = "(count ([""Police""] call ULP_fnc_allMembers)) >= 8 || { missionNamespace getVariable [""ULP_SRV_Crime_HMTreasury"", false] }";
					};
				};
				class MilitaryOfficeTwo : MilitaryOfficeOne { position[] = {16216.4, 17071.3, 0.0516109}; };

				class DomeOne : MilitaryOfficeOne {
					classname = "Land_Dome_Big_F";
					position[] = {16019, 16953.4, 0};
					class BreakIn : BreakIn {
						breakIn = 300;
					};
				};
				class DomeTwo : DomeOne { position[] = {16015.1, 17043.1, 0}; };
				class DomeThree : DomeOne { position[] = {16084, 17082.7, 0}; };
				class DomeFour : DomeOne { position[] = {16152.7, 17044.1, 0}; };
				class DomeFive : DomeOne { position[] = {16152.6, 16961.7, 0}; };
				class DomeSix : DomeOne { position[] = {16084.9, 16915.2, 0}; };

				class VaultOne {
					classname = "Land_Research_house_V1_F";
					position[] = {16015.1, 16958.1, 0};
					vaults[] = { { "Land_CargoBox_V1_F", {-1.71973, 3.15625, 0.0583897}, 0.16 } };
				};
				class VaultThree : VaultOne { position[] = {16092.7, 17092.8, 0}; };
				class VaultFive : VaultOne { position[] = {16146.8, 16951.2, 0}; };

				class VaultTwo : VaultOne {
					classname = "Land_Research_HQ_F";
					position[] = {16023.7, 17031.4, 0};
					vaults[] = { { "Land_CargoBox_V1_F", {6.24316, 5.4707, -3.1177}, 0.16 } };
				};
				class VaultFour : VaultTwo { position[] = {16151.8, 17044.7, 0}; };
				class VaultSix : VaultTwo { position[] = {16076.4, 16917.9, 0}; };
			};
			class Items {
				class MarkedGold {
					amount = 40;
					extra = "((count playableUnits) / 4) + ((time / 2) / 240)";
				};
			};
		};
		class HMSLiberty {
			title = "Okręt HMS Liberty";
			description = "HMS Liberty, niszczyciel marynarki wojennej, który teraz leży opuszczony po zderzeniu z zdradzieckimi skałami u wybrzeży Altis. Niegdyś symbol morskiej potęgi, zardzewiały kadłub statku wystaje z płytkich wód, stanowiąc wyraźne przypomnienie o jego przedwczesnym końcu.<br /><br />Wśród wraku znajduje się serwer zawierający wartościowe zaszyfrowane dyski (z systemem KamilOS), potencjalną kopalnię złota dla tych, którzy odważą się je odzyskać. Dyski te można sprzedać w stanie surowym lub odszyfrować, aby odblokować i sprzedać ich wrażliwe dane za jeszcze większą nagrodę. Niebezpieczne położenie HMS Liberty oraz jego niszczejąca konstrukcja sprawiają, że jest to trudny, ale opłacalny cel dla odważnych.";
			factions[] = { "Civilian" };
			cooldown = 1000;
			class Stages {
				class Hack {
					displayName = "Zabezpieczenia serwerów";
					description = "Na mostku opuszczonego HMS Liberty znajduje się serwer zawierający wartościowe dyski. Aby uzyskać do niego dostęp, należy użyć <font color='#B92DE0'>urządzenia hakerskiego</font>, aby wyłączyć systemy bezpieczeństwa serwera, odblokowując dyski do odzyskania.";
					time = 750;
					onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Zabezpieczenia na statku są wyłączane!""], _targets] call ULP_fnc_sendMessage; [""Rozpoczęto wyłączanie systemów, policja została o tym powiadomiona!""] call fini_fnc_noty;";
					onCompleted = "[""HMSLiberty"", 1, hms_liberty_server] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""Udało ci się wyłączyć zabezpieczenia...""] call fini_fnc_noty;";
					onEachFrame = "hms_liberty_server animateSource [""server_move_source"", (_this / 100)];";
					onProgressStop = "hms_liberty_server animateSource [""server_move_source"", 0]";
					onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 8) : { ""Musi być minimum<t color='#B92DE0'>10 policjantów</t> do tego napadu..."" }; case ([""HackingDevice""] call ULP_fnc_hasItem < 1) : { ""Musisz mieć HackRF do tego napadu..."" }; default { ""Zabezpieczenia są już wyłączone..."" }; })] call fini_fnc_noty;";
					condition = "!(missionNamespace getVariable [""ULP_SRV_Crime_HMSLiberty"", false]) && { [""HackingDevice""] call ULP_fnc_hasItem > 0 }";
				};
			};
			class Buildings {
				class Ship {
					classname = "Land_Destroyer_01_interior_02_F";
					position[] = {14054.8, 11509.4, -2.1181};
					class BreakIn {
						breakIn = 360;
						onBreakIn = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Most do Statku został nielegalnie przekroczony!""], _targets] call ULP_fnc_sendMessage; [""Przypadkiem uruchomiłeś alarm, policja została powiadomiona.""] call fini_fnc_noty;";
						onFail = "[""Musi być minimum<t color='#B92DE0'>8 policjantów</t> do tego napadu...""] call fini_fnc_noty;";
						condition = "true";
					};
				};
			};
			class Items {
				class EncryptedDrive {
					amount = 8;
					extra = "((count playableUnits) / 4) + ((time / 4) / 240)";
				};
			};
		};
		class PoliceEvidenceStorage {
			title = "Magazyn dowodowy";
			description = "Zlokalizowany na południe od Kavali, Policyjny Magazyn Dowodów to silnie strzeżony obiekt przechowujący wszystkie skonfiskowane dowody z wyspy. W jego murach znajduje się skarbnica kontrabandy, od nielegalnych substancji po rzadkie przedmioty, które osiągają wysokie ceny na czarnym rynku.<br /><br />Włamanie się do magazynu wymaga obejścia wzmocnionych systemów bezpieczeństwa i unikania patroli. Dla tych, którzy odważą się podjąć wyzwanie i odniosą sukces, nagrody mogą być ogromne, co czyni go głównym celem przestępców.";
			factions[] = { "Civilian" };
			cooldown = 1000;
			class Stages {
				class Drill {
					displayName = "Wiercenie zamka";
					description = "Aby uzyskać dostęp do skarbca, wymagane jest użycie <font color='#B92DE0'>wiertła przemysłowego</font>, aby przebić jego wzmocnione ściany, co dodaje dodatkowy poziom trudności do napadu. Dla tych, którzy odważą się włamać, nagroda może być znaczna, ale ryzyko jest równie wysokie.";
					time = 600;
					onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Ktoś włamuje się do magazynu dowodowego!""], _targets] call ULP_fnc_sendMessage; [""Rozpoczęto włamywanie, policja została powiadomiona!""] call fini_fnc_noty;";
					onCompleted = "[""PoliceEvidenceStorage"", 1, evidence_storage_vault] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""Włamywanie zakończone, zamek został zniszczony...""] call fini_fnc_noty;";
					onEachFrame = "";
					onProgressStop = "";
					onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 8) : { ""Musi być minimum<t color='#B92DE0'>8 policjantów</t> do tego napadu..."" }; case ([""IndustrialDrill""] call ULP_fnc_hasItem < 1) : { ""Potrzebujesz wiertło przemysłowe..."" }; default { ""Zamek jest już zniszczony..."" }; })] call fini_fnc_noty;";
					condition = "(count ([""Police""] call ULP_fnc_allMembers)) >= 8 || { missionNamespace getVariable [""ULP_SRV_Crime_PoliceEvidenceStorage"", false] }";
				};
			};
			class Buildings {
				class MilitaryOffice {
					classname = "Land_MilOffices_V1_F";
					position[] = {3266.77, 12448.9, 0.117};
					class BreakIn {
						breakIn = 240;
						onBreakIn = "if (([""SilentLocksmith"", (random 1)] call ULP_fnc_activatePerk) < 0.8) exitWith {}; private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Drzwi do magazynu dowodów zostały zniszczone!""], _targets] call ULP_fnc_sendMessage; [""Przy zniszczeniu drzwi, uruchomił się alarm.""] call fini_fnc_noty;";
						onFail = "[""Musi być minimum<t color='#B92DE0'>8 policjantów</t> do tego napadu...""] call fini_fnc_noty;";
						condition = "(count [""Police""] call ULP_fnc_allMembers) >= 8 || { missionNamespace getVariable [""ULP_SRV_Crime_PoliceEvidenceStorage"", false] }";
					};
				};
			};
			class Items {
				class SeizedContraband {
					amount = 30;
					extra = "((count playableUnits) / 2) + ((time / 2) / 240)";
				};
			};
		};
		class ResearchFacility {
			title = "Baza odkrywcza";
			description = "Ukryta pod falami Zatoki Pygros, ta tajemnicza podwodna placówka badawcza otoczona jest aurą tajemnicy, a plotki mówią o przeprowadzaniu eksperymentów z technologią obcych. Dostępna tylko przez nurkowanie lub specjalistyczne okręty podwodne, wzmocniona struktura obiektu zaprojektowana jest tak, aby wytrzymać ogromne ciśnienie i ukrywać jego operacje.<br /><br />Wewnątrz zaawansowane laboratoria i zabezpieczone pomieszczenia sugerują przełomowe odkrycia, a szepcze się o artefaktach pozaziemskich zamkniętych za drzwiami o wysokim stopniu bezpieczeństwa. Dla tych, którzy odważą się zmierzyć z głębinami, możliwość odkrycia i czerpania zysków z tajemnic tej placówki jest równie kusząca, co niebezpieczna.";
			factions[] = { "Civilian" };
			cooldown = 1000;
			class Stages {
				class Drill {
					displayName = "Wiercenie do sejfu";
                    description = "Uzyskanie dostępu do skarbca wymaga użycia <font color='#B92DE0'>wiertła przemysłowego</font>, aby przebić jego wzmocnione ściany. Wewnątrz zawartość można sprzedać zagranicznym agentom za świetną kasę, co czyni go celem wysokiego ryzyka, ale bardzo opłacalnym dla odważnych gangsterów.";
					time = 1200;
					onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Ktoś uruchomił alarm w podwodnej bazie odkrywkowej!""], _targets] call ULP_fnc_sendMessage; [""Rozpoczęto wiercenie do sejfu, uruchomił się alarm""] call fini_fnc_noty;";
					onCompleted = "[""ResearchFacility"", 1, researchFacilityCapsule] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""Udało ci się wyłączyć alarm...""] call fini_fnc_noty;";
					onEachFrame = "";
					onProgressStop = "";
					onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 10) : { ""Musi być minimum<t color='#B92DE0'>8 policjantów</t> do tego napadu..."" }; case ([""IndustrialDrill""] call ULP_fnc_hasItem < 1) : { ""Potrzebujesz wiertła przemysłowego..."" }; default { ""Zamek sejfu jest już przewiercony..."" }; })] call fini_fnc_noty;";
					condition = "!(missionNamespace getVariable [""ULP_SRV_Crime_ResearchFacility"", false]) && { [""IndustrialDrill""] call ULP_fnc_hasItem > 0 }";
				};
			};
			class Buildings {
				class OuterDome {
					classname = "Land_Dome_Big_F";
					position[] = {24842,13219.9,0};
					class BreakIn {
						breakIn = 300;
						onBreakIn = "if (([""SilentLocksmith"", (random 1)] call ULP_fnc_activatePerk) < 0.8) exitWith {}; private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Ktoś włamuje się do drzwi podwodnej placówki odkrywkowej.""], _targets] call ULP_fnc_sendMessage; [""Przypadkiem uruchomiłeś alarm!""] call fini_fnc_noty;";
						onFail = "[""Musi być minimum<t color='#B92DE0'>8 policjantów</t> do tego napadu...""] call fini_fnc_noty;";
						condition = "(count ([""Police""] call ULP_fnc_allMembers)) >= 10 || { missionNamespace getVariable [""ULP_SRV_Crime_ResearchFacility"", false] }";
					};
				};
				class InnerDome {
					classname = "Land_Dome_Small_F";
					position[] = {24844.1,13219.7,0};
				};
				class InnerVault {
					classname = "Land_Research_HQ_F";
					position[] = {24844.1,13219.7,0};
				};
			};
			class Items {
				class SpaceCapsuleDataDrive {
					amount = 2;
					extra = "0";
				};
			};
		};
	};
};