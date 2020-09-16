class BotGroupMissionNWA: CustomMission
{
	
	void BotGroupMissionNWA() {}
	
	
	// ������� �����
	vector BotSpawnPoint = "4271.261719 338.812531 10975.101563";				// ������ ����� ������ ����	
	
	protected int m_botAcuracy = 10;											// ��������� �������� ���� (��� ���� �����, ��� ���� ��� �����������)
	
	protected int BotSolderCountMin = 2;  										// ��������� ����������� ����������� �����
	protected int BotSolderCountMax = 4;										// ��������� ������������ ����������� �����
	
	protected int botLootCountMin = 5; 											// ��������� ����������� ���������� ���� � ����
	protected int botLootCountMax = 15; 										// ��������� ������������ ���������� ���� � ����
	
	protected float Zone_Radius = 1100;											// ������ �������� �� ������ ��� ��������� �����
	
	protected bool isUseCheckPoints = true;									// ������ ������������ �� ���������� true - ������������, fslse - �� ������������
	protected bool isBotKaratist = false;										// ������ ����� �� ���� � ������� ��� ����� ������ ��������, �� ��������� ��� � �������, ���� ����� ��� ���������� ������� true
	protected bool onRespawnBot = true;											// ��������� ��� ���������� �������� ���� (true - ��������, fslse - ���������)
	protected bool canUseTrigger = true;										// ������������ ������� (true - ��������, fslse - ���������), ���� �� ������������ ������� ���� ��������� ����� ����� ������� �������
	protected int m_respawnTime = 30;											// ����� �������� ���� (���������� 30 �����)
	
	protected bool canBotSpawned = true;										// �� ��������!!!!!!!
	
	// ------------------------------- ����� �������  ------------------------------------------ //
	
	
	// ������� � ����� � �������
	// ���� ������� ��� �� ����� ������ ��������� ������ ������� ������ ---> TStringArray OtherEquip = {""}; 
	ref TStringArray Shirt = {"GorkaEJacket_Autumn", "GorkaEJacket_Flat", "GorkaEJacket_PautRev", "GorkaEJacket_Summer"}; 					//��������� ���� ������
	ref TStringArray Jeans = {"GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "GorkaPants_Summer"}; 							//��������� �����
	ref TStringArray Shoes = {"TTSKOBoots", "WorkingBoots_Beige", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown"};			//��������� �������
	ref TStringArray BackPack = {"CoyoteBag_Brown", "CoyoteBag_Green", "HuntingBag", "TortillaBag", "WaterproofBag_Green"};					//��������� ������
	ref TStringArray Vest = {"HighCapacityVest_Black", "HighCapacityVest_Olive", "HuntingVest", "PlateCarrierVest", "UKAssVest_Camo"};		//��������� ���������
	ref TStringArray Helm = {"GorkaHelmet", "Mich2001Helmet", "MotoHelmet_Black", "PumpkinHelmet", "SkateHelmet_Black"};					//��������� ���� ��� �������� ����
	ref TStringArray Gloves = {"WorkingGloves_Beige", "WorkingGloves_Black", "NBCGlovesGray", "OMNOGloves_Brown", "SurgicalGloves_Blue"};	//��������� ��������
	ref TStringArray OtherEquip = {"CivilianBelt", "MilitaryBelt"};																			//��������� �������������� ������� ������, ��� ����� ���� �� ��� ������ :)	
	
	ref TStringArray RandomLoot = {"SardinesCan", "SodaCan_Cola", "SodaCan_Kvass", "Rice", "Rope", "Screwdriver", "AmmoBox_545x39_20Rnd"};  //��������� � ����� ����� ���, ���������� �� ����������
	ref TStringArray MeleeWeap = {"WoodAxe", "FirefighterAxe", "Shovel", "Pickaxe"}; 														//��������� �������� ������
	
	// -------------------------------- ����� �������� ����  -------------------------------------------------------//

	protected EntityAI itemEnt;				// �� ��������!!!!

	// ������� �������� ���������� (����������� ��������� ���)
	void AddCeckPoint(SurvivorBotBase m_BotSolder)
	{
		m_BotSolder.SetUseCheckpoint(); // ��� ������ �� �������!
		
		m_BotSolder.AddCheckpoint("4269.994629 339.012421 10917.826172");
		m_BotSolder.AddCheckpoint("4474.135254 339.012421 10557.146484");
		m_BotSolder.AddCheckpoint("4321.004883 339.012390 10459.886719");
		m_BotSolder.AddCheckpoint("4113.722656 339.012451 10837.003906");
		m_BotSolder.AddCheckpoint("4081.802979 339.012451 10801.938477");
		m_BotSolder.AddCheckpoint("4775.959961 338.970398 9591.289063");
		m_BotSolder.AddCheckpoint("5074.371582 339.012421 9760.172852");
		m_BotSolder.AddCheckpoint("5042.200195 339.012390 9880.341797");	
	}
	// ---------------------------------- ����� ������� �������� ����������  -------------------------------------- /	
	

	
	
	// ������� �������� ������ ��� ���� (��� ����� �������� 7 ����� ������, ��������� �� ������ ����������)
	void createWeapFromBot(SurvivorBotBase m_BotSolder)
	{
		int randomWeapon = Math.RandomInt(1, 7);
			
		switch( randomWeapon )
		{	
			case 1: 
			{
				m_BotSolder.AddWeapon("M4A1"); 				//������
				m_BotSolder.AddWeaponAtt("M4_RISHndgrd");	//�����1
				m_BotSolder.AddWeaponAtt("M4_MPBttstck");	//�����2
				m_BotSolder.AddWeaponAtt("ACOGOptic");		//�����3
				break;
				//������ ��������� �� �������������, �������� ��� ������ �������� ������������� �� ��������� �� ���������
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
	// ----------------------------- ����� ������� �������� ������ ------------------------------------- //
	
	// ������� ������ ���� (��� ������ �� ������!!!)
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
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(respawnBotUnitNWA, m_respawnTime * 60000, true, m_BotSolder);
	}
	// ----------------------------- ����� ������� ������ ���� ------------------------------------- //
	
	// ----------------------------- ������� �������� ����� ----------------------------------------//
	private void respawnBotUnitNWA(SurvivorBotBase m_Bot)
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
	// ----------------------------- ����� ������� ----------------------------------------//
	

	
	
	// ������� ������ ������ �����
	void spawnBotGroup()
	{
		int rndBotGrpCnt = Math.RandomInt(BotSolderCountMin, BotSolderCountMax);
		Print("Bots spawned! Count " + rndBotGrpCnt);
		for (int a = 0; a < rndBotGrpCnt; a++)
		{
			createBotUnit();
		}	
	}
	// --------------------------------------- ����� ������� ������ ������  --------------------------------------- //
	
	// ������� �������� �� ������
	void TriggerPlayersNWA()
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
					GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(TriggerPlayersNWA);			
				} 
			}
		}
	} 
	// --------------------------------------- ����� ������� ��������  --------------------------------------- //
	
	// ��� ������� �������� � initBotMissions.c	
	void StartMissionAI()
	{
		Print("Start mission bot");
		if (canUseTrigger)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(TriggerPlayersNWA, 5000, true);			
		}
		else
		{
			spawnBotGroup();
		}
	}
	
}