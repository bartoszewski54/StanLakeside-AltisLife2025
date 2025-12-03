class CfgReputation {
	Lowest = -1000;
	Highest = 1000;

	class Types {
		// Harming Others
		// Harming Others
        class ExecuteHigh { reason = "zabiłeś kogoś o wysokiej reputacji"; change = -50; };
        class ExecuteNorm { reason = "zabiłeś kogoś o normalnej reputacji"; change = -30; };
        class ExecuteLow { reason = "zabiłeś kogoś o niskiej reputacji"; change = -20; };
        class IncapHigh { reason = "obezwładniłeś kogoś o wysokiej reputacji"; change = -30; };
        class IncapNorm { reason = "obezwładniłeś kogoś o neutralnej reputacji"; change = -15; };
        class IncapLow { reason = "zabiłeś kogoś o niskiej reputacji"; change = 25; };
        class AssaultHigh { reason = "zaatakowałeś kogoś o wysokiej reputacji"; change = -10; };
        class AssaultNorm { reason = "zaatakowałeś kogoś o normalnej reputacji"; change = -5; };

        class RobHigh { reason = "obrabowałeś kogoś o wysokiej reputacji"; change = -25; };
        class RobNorm { reason = "obrabowałeś kogoś o normalnej reputacji"; change = -20; };
        class RobLow { reason = "obrabowałeś kogoś o niskiej reputacji"; change = -10; };
        class RobStore { reason = "obrabowałeś sklep"; change = -10; };
        class SeizeComms { reason = "zniszczyłeś czyjąś komunikację"; change = -5; };
        // Reviving
        class ReviveHigh { reason = "reanimowałeś kogoś o wysokiej reputacji"; change = 50; };
        class ReviveNorm { reason = "reanimowałeś kogoś o normalnej reputacji"; change = 30; };
        class ReviveLow { reason = "reanimowałeś kogoś o niskiej reputacji"; change = 20; };
        class BloodHigh { reason = "przekazałeś komuś o wysokiej reputacji krew"; change = 5; };
        // Policing
        class ArrestHigh { reason = "aresztowałeś kogoś o wysokiej reputacji"; change = 10; };
        class ArrestNorm { reason = "aresztowałeś kogoś o normalnej reputacji"; change = 20; };
        class ArrestLow { reason = "aresztowałeś kogoś o niskiej reputacji"; change = 30; };
        class IssueTicket { reason = "wystawiłeś komuś mandat"; change = 10; };
        class SeizeLicense { reason = "odebrałeś komuś licencję"; change = 10; };
        // Removing Vehicles
        class ImpoundVehicle { reason = "odholowałeś pojazd"; change = 5; };
        class CrushVehicle { reason = "zniszczyłeś pojazd"; change = 5; };
        class ChopVehicle { reason = "pociąłeś pojazd"; change = -50; };
        // Government
        class Vote { reason = "wspierałeś demokrację przez głosowanie"; change = 50; };
        class Rig { reason = "próbowałeś sabotować demokrację"; change = -100; };
	};
};