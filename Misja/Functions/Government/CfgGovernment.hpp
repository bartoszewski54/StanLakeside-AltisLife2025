class CfgGovernment {
	electionInternal = 14;

	class Rigging {
		timeToRig = 30;
		alreadyRiggedMultiplier = 1.5;
	};
	
	class Legislation {
		class Tax {
			displayName = "Podatek na Wyspie Altis";
			tooltip = "Zmienia to stawkę podatkową stosowaną do niektórych cen na całej wyspie.";
			type = "NUMBER";
			format = "format [""%2%1"", ""%"", [_this] call ULP_fnc_numberText]";
			values[] = { { 1, 10 }, 5 };
		};
		class Paychecks {
			displayName = "Dopłaty do Zasiłków";
			tooltip = "Zmienia to ilość pieniędzy dodawanych do wypłat obywateli altis.";
			type = "NUMBER";
			format = "format [""%1%2"", ""$"", [_this] call ULP_fnc_numberText]";
			values[] = { { 2500, 7500 }, 5000 };
		};
		class Mission {
			displayName = "Pokrycie wynagrodzenia za pracę";
			tooltip = "Zmienia to kwotę dodatkowych pieniędzy przyznawanych przez rząd za wykonanie zadań.";
			type = "NUMBER";
			format = "format [""%1%2"", ""$"", [_this] call ULP_fnc_numberText]";
			values[] = { { 0, 5 }, 0 };
		};
		class Service {
			displayName = "Ceny serwisu pojazdów lotniczych";
			tooltip = "Zmienia to cenę jednostki paliwa na lotniczej stacji paliw.";
			type = "NUMBER";
			format = "format [""%1%2"", ""$"", [_this] call ULP_fnc_numberText]";
			values[] = { { 500, 1500 }, 1000 };
		};
		class Revival {
			displayName = "Podatek od reanimacji";
			tooltip = "Zmienia to ilość pieniędzy wypłacanych medykom podczas wskrzeszania.";
			type = "NUMBER";
			format = "format [""%1%2"", ""$"", [_this] call ULP_fnc_numberText]";
			values[] = { { 10000, 25000 }, 17500 };
		};
	};
};