class BotGroupMissionKab: CustomMission
{
	
	void BotGroupMissionKab() {}
	
	
	// Конфиги ботов
	vector BotSpawnPoint = "4541.687500 317.593628 8324.727539";				// задаем точку спавна бота	
	
	protected int m_botAcuracy = 10;											// Настройка меткости бота (чем выше число, тем чаще бот промазывает)
	
	protected int BotSolderCountMin = 2;  										// назначаем минимальное количесство ботов
	protected int BotSolderCountMax = 4;										// назначаем максимальное количесство ботов
	
	protected int botLootCountMin = 5; 											// назначаем минимальное количество лута у бота
	protected int botLootCountMax = 15; 										// назначаем максимальное количество лута у бота
	
	protected float Zone_Radius = 150;											// Радиус триггера на игрока для появления ботов
	
	protected bool isUseCheckPoints = false;										// задаем используются ли чекпонинты true - используются, fslse - не используются
	protected bool isBotKaratist = false;										// Задаем будут ли боты с оружием или будут дратся кулаками, по умолчанию они с оружием, если нужны без огнестрела пропиши true
	protected bool onRespawnBot = true;											// Включение или отключение респавна бота (true - включено, fslse - выключено)
	protected bool canUseTrigger = true;										// Использовать триггер (true - включено, fslse - выключено), если не используется триггер боты спавнятся сразу после запуска сервера
	protected int m_respawnTime = 30;											// Время респавна бота (выставлено 30 минут)
	
	protected bool canBotSpawned = true;										// Не изменять!!!!!!!
	
	// ------------------------------- конец конфига  ------------------------------------------ //
	
	
	// Массивы с лутом и одеждой
	// Если какойто тип не нужен просто оставляем пустые ковычки пример ---> TStringArray OtherEquip = {""}; 
	ref TStringArray Shirt = {"GorkaEJacket_Autumn", "GorkaEJacket_Flat", "GorkaEJacket_PautRev", "GorkaEJacket_Summer"}; 					//Добавляем верх одежды
	ref TStringArray Jeans = {"GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "GorkaPants_Summer"}; 							//Добавляем штаны
	ref TStringArray Shoes = {"TTSKOBoots", "WorkingBoots_Beige", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown"};			//Добавляем ботинки
	ref TStringArray BackPack = {"CoyoteBag_Brown", "CoyoteBag_Green", "HuntingBag", "TortillaBag", "WaterproofBag_Green"};					//Добавляем Рюкзак
	ref TStringArray Vest = {"HighCapacityVest_Black", "HighCapacityVest_Olive", "HuntingVest", "PlateCarrierVest", "UKAssVest_Camo"};		//Добавляем разгрузку
	ref TStringArray Helm = {"GorkaHelmet", "Mich2001Helmet", "MotoHelmet_Black", "PumpkinHelmet", "SkateHelmet_Black"};					//Добавляем шлем или головной убор
	ref TStringArray Gloves = {"WorkingGloves_Beige", "WorkingGloves_Black", "NBCGlovesGray", "OMNOGloves_Brown", "SurgicalGloves_Blue"};	//Добавляем перчатки
	ref TStringArray OtherEquip = {"CivilianBelt", "MilitaryBelt"};																			//Добавляем дополнительный элемент одежды, это может быть всё что угодно :)	
	
	ref TStringArray RandomLoot = {"SardinesCan", "SodaCan_Cola", "SodaCan_Kvass", "Rice", "Rope", "Screwdriver", "AmmoBox_545x39_20Rnd"};  //Добавляем в масив любой лут, количество не ограничено
	ref TStringArray MeleeWeap = {"WoodAxe", "FirefighterAxe", "Shovel", "Pickaxe"}; 														//Добавляем холодное оружие
	
	// -------------------------------- конец массивов лута  -------------------------------------------------------//

	protected EntityAI itemEnt;				// Не изменять!!!!

	// Функция создания чекпоинтов (прописываем чекпоинты тут)
	void AddCeckPoint(SurvivorBotBase m_BotSolder)
	{
		m_BotSolder.SetUseCheckpoint(); // Эту строку не трогаем!
		
		m_BotSolder.AddCheckpoint("1724.632080 451.730408 14298.412109");
		m_BotSolder.AddCheckpoint("1681.035522 451.784302 14278.791016");
		m_BotSolder.AddCheckpoint("1668.385742 451.730408 14268.739258");
		m_BotSolder.AddCheckpoint("1653.012695 451.784302 14245.443359");
		m_BotSolder.AddCheckpoint("1662.009521 451.784302 14220.044922");
		m_BotSolder.AddCheckpoint("1668.885010 451.730408 14177.100586");
		m_BotSolder.AddCheckpoint("1678.905029 451.784302 14134.460938");
		m_BotSolder.AddCheckpoint("1687.656250 451.784302 14097.293945");
		m_BotSolder.AddCheckpoint("1691.055054 451.728760 14072.710938");
		m_BotSolder.AddCheckpoint("1697.563721 450.094635 14019.088867");
		m_BotSolder.AddCheckpoint("1701.266235 448.636108 13981.079102");
		m_BotSolder.AddCheckpoint("1709.151733 448.368225 13969.950195");
		m_BotSolder.AddCheckpoint("1726.191772 447.882568 13954.740234");
		m_BotSolder.AddCheckpoint("1734.303101 447.342072 13945.562500");
		m_BotSolder.AddCheckpoint("1736.849487 447.158569 13939.061523");
		m_BotSolder.AddCheckpoint("1803.257568 436.318970 13812.399414");
		m_BotSolder.AddCheckpoint("1802.478149 435.682281 13794.238281");
		m_BotSolder.AddCheckpoint("1764.742676 434.271759 13667.715820");
		m_BotSolder.AddCheckpoint("1753.983521 434.111572 13660.847656");
		m_BotSolder.AddCheckpoint("1697.765381 433.031982 13621.431641");
		m_BotSolder.AddCheckpoint("1625.751953 437.192169 13583.775391");
		m_BotSolder.AddCheckpoint("1615.443726 437.193420 13582.367188");
		m_BotSolder.AddCheckpoint("1586.155762 439.010864 13609.286133");
		m_BotSolder.AddCheckpoint("1566.816040 441.081787 13643.261719");
		m_BotSolder.AddCheckpoint("1554.550049 441.587372 13645.919922");
		m_BotSolder.AddCheckpoint("1533.254028 440.683624 13646.856445");
		m_BotSolder.AddCheckpoint("1470.583130 444.685120 13679.353516");
		m_BotSolder.AddCheckpoint("1448.422729 446.229736 13681.502930");
		m_BotSolder.AddCheckpoint("1397.534424 448.255707 13663.409180");
		m_BotSolder.AddCheckpoint("1377.747681 448.799530 13661.333984");
		m_BotSolder.AddCheckpoint("1356.402222 451.658264 13669.961914");
		m_BotSolder.AddCheckpoint("1339.632813 454.855988 13690.362305");
		m_BotSolder.AddCheckpoint("1311.232178 457.548615 13730.733398");
		m_BotSolder.AddCheckpoint("1368.332275 455.560181 13762.721680");
		m_BotSolder.AddCheckpoint("1389.098022 453.795563 13785.572266");
		m_BotSolder.AddCheckpoint("1394.411499 451.237183 13801.572266");
		m_BotSolder.AddCheckpoint("1398.934204 451.644989 13828.162109");
		m_BotSolder.AddCheckpoint("1419.962524 456.061951 13891.482422");
		m_BotSolder.AddCheckpoint("1409.579224 458.430359 13947.408203");
		m_BotSolder.AddCheckpoint("1421.006104 459.254517 13993.981445");
		m_BotSolder.AddCheckpoint("1422.121094 459.807831 14022.114258");
		m_BotSolder.AddCheckpoint("1388.509277 462.222443 14044.217773");
		m_BotSolder.AddCheckpoint("1388.548340 462.354797 14044.183594");
		m_BotSolder.AddCheckpoint("1333.772217 463.948151 14062.096680");
		m_BotSolder.AddCheckpoint("1350.346069 465.658081 14107.701172");
		m_BotSolder.AddCheckpoint("1461.509521 459.874268 14133.793945");
		m_BotSolder.AddCheckpoint("1503.123291 455.995056 14137.425781");
		m_BotSolder.AddCheckpoint("1554.196045 452.867004 14107.243164");
		m_BotSolder.AddCheckpoint("1574.911743 452.540283 14100.198242");
		m_BotSolder.AddCheckpoint("1629.664673 451.792175 14197.793945");
		m_BotSolder.AddCheckpoint("1636.238647 451.792175 14221.260742");
		m_BotSolder.AddCheckpoint("1671.278564 451.792175 14275.020508");
		m_BotSolder.AddCheckpoint("1645.910522 451.807617 14315.247070");
		m_BotSolder.AddCheckpoint("1669.397339 451.792175 14331.668945");
		m_BotSolder.AddCheckpoint("1685.370361 451.792175 14341.243164");	
	}
	// ---------------------------------- Конец функции создания чекпоинтов  -------------------------------------- /	
	

	
	
	// Функция создания оружия для бота (тут можно добавить 7 вмдов оружия, вписываем по своему усмотрению)
	void createWeapFromBot(SurvivorBotBase m_BotSolder)
	{
		int randomWeapon = Math.RandomInt(1, 7);
			
		switch( randomWeapon )
		{	
			case 1: 
			{
				m_BotSolder.AddWeapon("M4A1"); 				//оружие
				m_BotSolder.AddWeaponAtt("M4_RISHndgrd");	//Обвес1
				m_BotSolder.AddWeaponAtt("M4_MPBttstck");	//Обвес2
				m_BotSolder.AddWeaponAtt("ACOGOptic");		//Обвес3
				break;
				//Обвесы добовляем по необходимости, магазины для оружия выдаются автоматически их добовлять не требуется
			}
				
			case 2: 
			{
				m_BotSolder.AddWeapon("AKM");
				m_BotSolder.AddWeaponAtt("AK_WoodBttstck");
				m_BotSolder.AddWeaponAtt("AK_WoodHndgrd");
				break;
			}
				
			case 3: 
			{
				m_BotSolder.AddWeapon("AKM");
				m_BotSolder.AddWeaponAtt("AK_WoodBttstck");
				m_BotSolder.AddWeaponAtt("AK_WoodHndgrd");
				break;
			}
				
			case 4: 
			{
				m_BotSolder.AddWeapon("SVD");
				break;
			}
				
			case 5: 
			{
				m_BotSolder.AddWeapon("M4A1"); 	
				m_BotSolder.AddWeaponAtt("M4_RISHndgrd");	
				m_BotSolder.AddWeaponAtt("M4_MPBttstck");	
				m_BotSolder.AddWeaponAtt("ACOGOptic");		
				break;
			}
				
			case 6: 
			{
				m_BotSolder.AddWeapon("AKM");
				m_BotSolder.AddWeaponAtt("AK_WoodBttstck");
				m_BotSolder.AddWeaponAtt("AK_WoodHndgrd");
				break;
			}
				
			case 7: 
			{
				m_BotSolder.AddWeapon("AKM");
				m_BotSolder.AddWeaponAtt("AK_WoodBttstck");
				m_BotSolder.AddWeaponAtt("AK_WoodHndgrd");
				break;
			}
		}		
	}
	// ----------------------------- Конец функции создания оружия ------------------------------------- //
	
	// Функция спавна бота (тут ничего не меняем!!!)
	void createBotUnit()
	{
		private SurvivorBotBase m_BotSolder;
		
		float bspX = BotSpawnPoint[0];
		float bspY = BotSpawnPoint[2];
		
		vector botSpPos = Vector(bspX + Math.RandomInt(1, 5), BotSpawnPoint[1], bspY + Math.RandomInt(1, 5));
				
		m_BotSolder = SurvivorBotBase.Cast(GetGame().CreateObject("BotM_Mirek", botSpPos));
		
		
		if (isBotKaratist)
		{
			m_BotSolder.GetHumanInventory().CreateInHands(MeleeWeap.GetRandomElement());
		}
		else
		{
			createWeapFromBot(m_BotSolder);
		}
		
		m_BotSolder.GetInventory().CreateInInventory(Shirt.GetRandomElement());
		m_BotSolder.GetInventory().CreateInInventory(Jeans.GetRandomElement());
		m_BotSolder.GetInventory().CreateInInventory(Shoes.GetRandomElement());
		m_BotSolder.GetInventory().CreateInInventory(BackPack.GetRandomElement());
		m_BotSolder.GetInventory().CreateInInventory(Vest.GetRandomElement());
		m_BotSolder.GetInventory().CreateInInventory(Helm.GetRandomElement());
		m_BotSolder.GetInventory().CreateInInventory(Gloves.GetRandomElement());			
		m_BotSolder.GetInventory().CreateInInventory(OtherEquip.GetRandomElement());
			
		int rndLootCnt = Math.RandomInt(botLootCountMin, botLootCountMax);
			
		for (int i = 0; i < rndLootCnt; i++)
		{
			itemEnt = m_BotSolder.GetInventory().CreateInInventory(RandomLoot.GetRandomElement());
			if (itemEnt)
			{
				int rndHlt = Math.RandomInt(55,100);
				itemEnt.SetHealth("","",rndHlt);
			}
		}

		m_BotSolder.SetAcuracy(m_botAcuracy);
		
		if (isUseCheckPoints) 
			AddCeckPoint(m_BotSolder);
	
		
		if (m_BotSolder.IsAlive() && m_BotSolder && onRespawnBot)
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(respawnBotUnitKab, m_respawnTime * 60000, true, m_BotSolder);
	}
	// ----------------------------- Конец функции спавна бота ------------------------------------- //
	
	// ----------------------------- Функция респавна ботов ----------------------------------------//
	private void respawnBotUnitKab(SurvivorBotBase m_Bot)
	{
		if (onRespawnBot && m_Bot.IsRespawned())
		{
			if (!m_Bot.IsAlive())
			{
				Print("Respawn killed bot start!" + m_Bot);
				createBotUnit();
				m_Bot.SetRespawned( false );
			}		
		}		
	}
	// ----------------------------- Конец функции ----------------------------------------//
	

	
	
	// Функция спавна группы ботов
	void spawnBotGroup()
	{
		int rndBotGrpCnt = Math.RandomInt(BotSolderCountMin, BotSolderCountMax);
		Print("Bots spawned! Count " + rndBotGrpCnt);
		for (int a = 0; a < rndBotGrpCnt; a++)
		{
			createBotUnit();
		}	
	}
	// --------------------------------------- Конец функции спавна группы  --------------------------------------- //
	
	// Функция триггера на игрока
	void TriggerPlayersKab()
	{  
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
				
		if (canBotSpawned)
		{	
			for ( int u = 0; u < players.Count(); u++ )
			{
					
				PlayerBase player;
				Class.CastTo(player, players.Get(u));
				vector pos = player.GetPosition();
				float dist = vector.Distance( pos, BotSpawnPoint );
				
				if ( dist < Zone_Radius ) 
				{
					spawnBotGroup();
					GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(TriggerPlayersKab);			
				} 
			}
		}
	} 
	// --------------------------------------- Конец функции триггера  --------------------------------------- //
	
	// Эту функцию вызываем в initBotMissions.c	
	void StartMissionAI()
	{
		Print("Start mission bot");
		if (canUseTrigger)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(TriggerPlayersKab, 5000, true);			
		}
		else
		{
			spawnBotGroup();
		}
	}
	
}