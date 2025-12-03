class CfgAchievements {
	class FirstSpawn {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa";
		displayName = "Pierwsze kroki";
		description = "Wejdź pierwszy raz na serwer.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// TODONOW
	class FirstDrink {
		icon = "Data\UI\Achievements\firstDrink.paa";
		displayName = "Alkoholik";
		description = "Od czegoś trzeba zacząć";
		onUnlocked = "[""FirstDrink""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// TODONOW
	class FirstDrug {
		icon = "Data\UI\Achievements\firstDrug.paa";
		displayName = "Ćpunek";
		description = "Poczuj się ciutke lżej.";
		onUnlocked = "[""FirstDrug""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// TODONOW
	class GirlsBestFriend {
		icon = "Data\UI\Achievements\girlsBestFriend.paa";
		displayName = "Diamenty";
		description = "Zdobądź oszlifowany diament";
		onUnlocked = "[""GirlsBestFriend""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// TODONOW
	class Salty {
		icon = "Data\UI\Achievements\salty.paa";
		displayName = "Extremalnie słony";
		description = "Miej na sobie dużą ilość soli.";
		onUnlocked = "[""Salty""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Captain {
		icon = "Data\UI\Achievements\captain.paa";
		displayName = "Kapitan tego statku";
		description = "Wejdź do sterowni statku.";
		onUnlocked = "[""Captain""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Archaeologist {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Waypoint_ca.paa";
		displayName = "Archeolog";
		description = "Odkryj swoje pierwsze znalezisko w ziemi.";
		onUnlocked = "[""Archaeologist""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinRebel {
		icon = "Data\UI\Achievements\rebel.paa";
		displayName = "Rebeliant";
		description = "Dołącz do rebelii.";
		onUnlocked = "[""JoinRebel""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinGroup {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Chat_ca.paa";
		displayName = "Grupowicz";
		description = "Dołącz do grupy.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinStaff {
		icon = "Data\UI\Achievements\staff.paa";
		displayName = "Administracja";
		description = "Dołącz w szeregi administracji";
		onUnlocked = "[""JoinStaff""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinAPC {
		icon = "Data\UI\Achievements\APC.paa";
		displayName = "Stróż prawa";
		description = "Dołącz do policji.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinCOL {
		icon = "Data\UI\Achievements\COL.paa";
		displayName = "Instruktor";
		description = "Dołącz do akademii policji.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinNPAS {
		icon = "Data\UI\Achievements\NPAS.paa";
		displayName = "Pilot policji";
		description = "Otrzymaj rangę pilota.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinSCO19 {
		icon = "Data\UI\Achievements\SCO.paa";
		displayName = "SWAT";
		description = "Otrzymaj rangę SWATu.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinNCA {
		icon = "Data\UI\Achievements\NCA.paa";
		displayName = "Łowca przestępców";
		description = "Otrzymaj range ds. przestępst";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinMPU {
		icon = "Data\UI\Achievements\MPU.paa";
		displayName = "Coast Guard";
		description = "Dołącz do CG";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinRPU {
		icon = "Data\UI\Achievements\RPU.paa";
		displayName = "Pościgowiec";
		description = "Dołącz do wydziału pościgów";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinSFO {
		icon = "Data\UI\Achievements\SFO.paa";
		displayName = "Policyjny Strzelec";
		description = "Otrzymaj dostęp do lepszych broni w policji.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinUC {
		icon = "Data\UI\Achievements\UC.paa";
		displayName = "Undercover";
		description = "Nikt się Ciebie nie spodziewa!";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class FirstTicket {
		icon = "Data\UI\Achievements\firstTicket.paa";
		displayName = "MANDAT!";
		description = "Wystaw mandat tym którzy nie łopatują.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class FirstArrest {
		icon = "Data\UI\Achievements\firstArrest.paa";
		displayName = "PDW";
		description = "Wyślij kogoś do więzienia.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinNHS {
		icon = "Data\UI\Achievements\NHS.paa";
		displayName = "Medyk";
		description = "Dołącz do EMS";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinHR {
		icon = "Data\UI\Achievements\HR.paa";
		displayName = "Recepcja";
		description = "Od czegoś musisz zacząć.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinAA {
		icon = "Data\UI\Achievements\AA.paa";
		displayName = "LPR";
		description = "Zdaj egzamin na śmigłowce.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class LifeSaver {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Injury_ca.paa";
		displayName = "Ratownik";
		description = "Podnieś inną osobę";
		onUnlocked = "[""LifeSaver""] call ULP_fnc_unlockTitle;";
		leveling[] = { 350, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinHATO {
		icon = "Data\UI\Achievements\HATO.paa";
		displayName = "Służby miejskie";
		description = "Dołącz do służb miejskich";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class FirstImpound {
		icon = "Data\UI\Achievements\firstImpound.paa";
		displayName = "Czyściciel dróg";
		description = "Odholuj pojazd na parking policyjny";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class FirstCrush {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Use_ca.paa";
		displayName = "Złomiarz";
		description = "Zezłomuj jakikolwiek pojazd.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Governor {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Rules_ca.paa";
		displayName = "Burmistrz";
		description = "Zostań burmistrzem.";
		onUnlocked = "[""Governor""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Employment {
		icon = "Data\UI\Achievements\employment.paa";
		displayName = "Stażysta";
		description = "Zatrudnij się.";
		onUnlocked = "[""Employment""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Convict {
		icon = "Data\UI\Achievements\convict.paa";
		displayName = "Oskarżony";
		description = "Zostań wsadzony do więzienia.";
		onUnlocked = "[""Convict""] call ULP_fnc_unlockTitle;";
		leveling[] = { 10, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class SuccessfulRobber {
		icon = "Data\UI\Achievements\successfulRobber.paa";
		displayName = "Złodziej";
		description = "Pomyślnie przeprowadź napad.";
		onUnlocked = "[""SuccessfulRobber""] call ULP_fnc_unlockTitle;";
		leveling[] = { 10, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class TaskMaster {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Tasks_ca.paa";
		displayName = "Rozwój";
		description = "Ukończ swój pierwszy task.";
		onUnlocked = "[""TaskMaster""] call ULP_fnc_unlockTitle;";
		leveling[] = { 75, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class CartelLord {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Miss_icon_ca.paa";
		displayName = "Plata O Plomo";
		description = "Otrzymaj wypłate z kartelu.";
		onUnlocked = "[""Cartel""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class BuyVehicle {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Driving_ca.paa";
		displayName = "Pierwsza fura";
		description = "Kup swój pierwszy bolid";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class BuyHouse {
		icon = "Data\UI\Achievements\house.paa";
		displayName = "Pierwszy dom";
		description = "Czas na domówke!";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class BuyWarehouse {
		icon = "Data\UI\Achievements\warehouse.paa";
		displayName = "Magazynier";
		description = "Kup swój pierwszy magazyn";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class OneMillion {
		icon = "Data\UI\Achievements\money1.paa";
		displayName = "$1,000,000";
		description = "Miej milion w banku.";
		onUnlocked = "[""OneMillion""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class TenMillion {
		icon = "Data\UI\Achievements\money10.paa";
		displayName = "$10,000,000";
		description = "Miej 10 milionów w banku";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class HundredMillion {
		icon = "Data\UI\Achievements\money100.paa";
		displayName = "$100,000,000";
		description = "Miej 100MLN w banku.";
		leveling[] = { 300, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// MYSTERY ---------------------------------------------------------
	class Barrel {
		icon = "Data\UI\Achievements\barrel.paa";
		displayName = "Beczka";
		description = "Znajdź tajną beczkę Jim'a Subway'a.";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};
	
	class Prestige {
		icon = "Data\UI\Achievements\prestige.paa";
		displayName = "Prestiż";
		description = "Użyj prestiżu poraz pierwszy.";
		onUnlocked = "[""Prestige""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Racing {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Time_trials_ca.paa";
		displayName = "WYŚCIGOWIEC";
		description = "Odwiedziłeś tor gokartowy.";
		onUnlocked = "[""Racing""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};
	class Spawn {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Zeus_ca.paa";
		displayName = "Wyspa klapków";
		description = "Odwiedź prawdziwy spawn";
		onUnlocked = "[""SpawnCamp""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};
	class BrokenNLR {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Timing_ca.paa";
		displayName = "NLR";
		description = "Wejdź na strefe NLR, bardzo nie ładnie :(";
		onUnlocked = "[""RuleBreaker""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = true;
	};
	class Surrender {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Checkpoints_ca.paa";
		displayName = "Łapy, Łapy!";
		description = "Załóż ręce na głowe.";
		onUnlocked = "[""Frenchman""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};
	class KnockOut {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Switch_ca.paa";
		displayName = "Boxer";
		description = "Powal kogoś.";
		onUnlocked = "[""ProfessionalBoxer""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};
	class Snoop {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Head_ca.paa";
		displayName = "Złodziej";
		description = "Napewno zajrzałeś do mission.sqm";
		onUnlocked = "[""Snoop""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Nothing {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicLook_ca.paa";
		displayName = "Nicość";
		description = "Znalazłeś nic otoczone przez jeszcze więcej nic.";
		onUnlocked = "[""Nothing""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};
	class Restrain {
		icon = "Data\UI\Achievements\convict.paa";
		displayName = "Zakuwacz";
		description = "Mam nadzieje że chodzi o kajdanki...";
		onUnlocked = "[""BondageEnthusiast""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};
	class Overweight {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Fatigue_ca.paa";
		displayName = "Ciężarny";
		description = "Nie, nie chodzi o ciąże. Po prostu masz na sobie za dużo rzeczy.-";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};
	class LockpickVeh {
		icon = "Data\UI\GroupBuffs\lockpicking.paa";
		displayName = "Ślusarz";
		description = "Włam się do auta używając lockpicka";
		onUnlocked = "[""Locksmith""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};
	class RepairVeh {
		icon = "Data\UI\Perks\scrapDealer.paa";
		displayName = "Mechanik";
		description = "No, to ja robiłem!";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};
	class Placeables {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicMove_ca.paa";
		displayName = "Mapper";
		description = "Postawiłeś jakikolwiek obiekt. Możesz teraz na siebie mówić 'DOBRO'.";
		onUnlocked = "[""WorldBuilder""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Blindfold {
    	icon = "\A3\ui_f_orange\data\CfgHints\codeofconduct3_ca.paa";
    	displayName = "Ślepy";
    	description = "Ktoś założył ci opaske na głowe";
    	onUnlocked = "[""BlindManWalking""] call ULP_fnc_unlockTitle;";
    	leveling[] = { 100, "Achievement Unlocked", 100 };
    	isMystery = false;
    };
	class DisguiseID {
		icon = "Data\UI\GroupPerks\blackmarket.paa";
		displayName = "Człowiek zagadka";
		description = "Kim ty tak właściwie jesteś? (Zmień swoją tożsamość)";
		onUnlocked = "[""FacelessMan""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Panic {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\NormalDamage_ca.paa";
		displayName = "Panika Gaming";
		description = "Uruchomiłeś panic button, must winie...";
		onUnlocked = "[""FightFlight""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	// TODO
	class FanGirl {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\PilotingQuadrotor_ca.paa";
		displayName = "Fan Girl";
		description = "";
		onUnlocked = "[""FanGirl""] call ULP_fnc_unlockTitle;";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Uncharted {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Map_ca.paa";
		displayName = "Eksplorer";
		description = "Opuściłeś tą wyspę, lecz wróciłeś.";
		onUnlocked = "[""Uncharted""] call ULP_fnc_unlockTitle;";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Radiation {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Chat_ca.paa";
		displayName = "Radioaktywny";
		description = "Jesteś tak radioaktywny, że świecisz się w nocy.";
		onUnlocked = "[""Radiation""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Protest {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Voice_ca.paa";
		displayName = "Protest";
		description = "Przyklej się do drogi jeszcze...";
		onUnlocked = "[""Protest""] call ULP_fnc_unlockTitle;";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class MileHighClub {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\TakeOff_ca.paa";
		displayName = "Wysokie loty";
		description = "Wznieś się ponad 1 mile w góre.";
		onUnlocked = "[""MileHighClub""] call ULP_fnc_unlockTitle;";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class DeepSeaDiver {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicDive_ca.paa";
		displayName = "Głębiniarz";
		description = "Dotknij dna głębokiego oceanu.";
		onUnlocked = "[""DeepSeaDiver""] call ULP_fnc_unlockTitle;";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class DeathWish {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Targets_ca.paa";
		displayName = "Ryzykant";
		description = "Wejdź do centrum czerwonej strefy.";
		onUnlocked = "[""DeathWish""] call ULP_fnc_unlockTitle;";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class NLRPC {
		icon = "Data\UI\Achievements\nlrpc.paa";
		displayName = "Odkrywca";
		description = "Znalazłeś tajny artefakt Altis.";
		onUnlocked = "[""NLRPC""] call ULP_fnc_unlockTitle;";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = true;
	};

class Stonehenge {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Direction_ca.paa";
    displayName = "Stonehenge";
    description = "Odkryłeś Stonehenge na Altis.";
    leveling[] = { 1000, "Achievement Unlocked", 100 };
    isMystery = true;
};

class Sub {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\SDV_ca.paa";
    displayName = "Łódź podwodna";
    description = "Przeszedłeś po HMS Proteus.";
    onUnlocked = "[""Sub""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Achievement Unlocked", 100 };
    isMystery = true;
};

class PirateDen {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Death_ca.paa";
    displayName = "Kryjówka piratów";
    description = "Odkryłeś kryjówkę piratów na Altis.";
    onUnlocked = "[""PirateDen""] call ULP_fnc_unlockTitle;";
    leveling[] = { 2000, "Achievement Unlocked", 100 };
    isMystery = true;
};

class Atlantis {
    icon = "Data\UI\Achievements\atlantis.paa";
    displayName = "Atlantyda";
    description = "Odkryłeś Atlantydę na Altis.";
    onUnlocked = "[""Atlantis""] call ULP_fnc_unlockTitle;";
    leveling[] = { 3000, "Achievement Unlocked", 100 };
    isMystery = true;
};
};