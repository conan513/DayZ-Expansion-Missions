#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlus\\BotMissions\\BotGroupMissionTisy.c" 
#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlus\\BotMissions\\BotGroupMissionNWA.c" 
#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlus\\BotMissions\\BotGroupMissionPav.c" 
#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlus\\BotMissions\\BotGroupMissionZel.c" 
#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlus\\BotMissions\\BotGroupMissionKab.c" 
#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlus\\BotMissions\\BotGroupMissionC1.c" 
#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlus\\BotMissions\\BotGroupMissionC2.c" 
#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlus\\BotMissions\\BotGroupMissionC3.c" 
#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlus\\BotMissions\\BotGroupMissionC4.c"
#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlus\\BotMissions\\BotGroupMissionTroick.c"

class initBotMissions
{
	void initBotMissions() {};
	
	void runBotMissions()
	{
		// запуск миссии Тисы--------------------------------------------
		BotGroupMissionTisy onMissionTisy = new BotGroupMissionTisy();
		onMissionTisy.StartMissionAI();	
		//---------------------------------------------------------------
		
		BotGroupMissionNWA onMissionNWA = new BotGroupMissionNWA();
		onMissionNWA.StartMissionAI();	
		
		BotGroupMissionPav onMissionPav = new BotGroupMissionPav();
		onMissionPav.StartMissionAI();	
		
		BotGroupMissionZel onMissionZel = new BotGroupMissionZel();
		onMissionZel.StartMissionAI();	
		
		BotGroupMissionKab onMissionKab = new BotGroupMissionKab();
		onMissionKab.StartMissionAI();
		
		BotGroupMissionTroick onMissionTroick = new BotGroupMissionTroick();
		onMissionTroick.StartMissionAI();
		
		BotGroupMissionC1 onMissionC1 = new BotGroupMissionC1();
		onMissionC1.StartMissionAI();	
		
		BotGroupMissionC2 onMissionC2 = new BotGroupMissionC2();
		onMissionC2.StartMissionAI();	
		
		BotGroupMissionC3 onMissionC3 = new BotGroupMissionC3();
		onMissionC3.StartMissionAI();
		
		BotGroupMissionC4 onMissionC4 = new BotGroupMissionC4();
		onMissionC4.StartMissionAI();
	}
		
}
