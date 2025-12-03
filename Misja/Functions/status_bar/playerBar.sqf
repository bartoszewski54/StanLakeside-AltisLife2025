waitUntil {!(isNull (findDisplay 46))};
disableSerialization;

	4 cutRsc["statusBar","PLAIN"];
	[] spawn
	{
		sleep 5;

	while {true} do
	{
		sleep 1;

		if(isNull ((uiNamespace getVariable "statusBar")displayCtrl 1000)) then
		{
			diag_log "statusbar is null create";
			disableSerialization;

			4 cutRsc["statusBar","PLAIN"];
		};

		_sivil = (civilian countSide playableUnits);
		_polis = (west countSide playableUnits);
		_doktor = (independent countSide playableUnits);
		_time = (round(360-(serverTime)/60));  //edit the '240' value (60*4=240) to change the countdown timer if your server restarts are shorter or longer than 4 hour intervals
		_hours = (floor(_time/60));
		_minutes = (_time - (_hours * 60));


		switch(_minutes) do	{
			case 9: {_minutes = "09"};
			case 8: {_minutes = "08"};
			case 7: {_minutes = "07"};
			case 6: {_minutes = "06"};
			case 5: {_minutes = "05"};
			case 4: {_minutes = "04"};
			case 3: {_minutes = "03"};
			case 2: {_minutes = "02"};
			case 1: {_minutes = "01"};
			case 0: {_minutes = "00"};
		};

		((uiNamespace getVariable "statusBar")displayCtrl 1000)ctrlSetStructuredText parseText
			format["<t %7 size='1' font='PuristaSemibold'><img size='1.0' image='Data\icons\cywile.paa' color='FFF'/> %1</t> | <t color='#FFF' size='1' font='PuristaSemibold'><img size='1.0' image='Data\icons\policja.paa' color='FFF'/> %2</t> | <t color='#FFF' size='1' font='PuristaSemibold'><img size='1.0' image='Data\icons\medycy.paa' color='FFF'/> %3</t>",
					_sivil,
					_polis,
					_doktor

				];




	};
};
