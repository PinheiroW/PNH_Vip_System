// CAMINHO DOS ARQUIVOS DOS VIPS
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\PNH\\Roupas.c"
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\PNH\\Armas.c"

// PARTE VANILLA
void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//EditorLoaderModule.ExportLootData = true; //LINHA DE CÓD PARA GERAÇÃO DE LOOT
	//GetCEApi().ExportProxyData( "7500 0 7500", 18000 );

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 6, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}	
}

// PARTE DO FD-VIPSPAWN
class CustomMission: MissionServer
{
	//PRESET ROUPAS
	protected ref TStringArray VIPS_Roupa0 = new TStringArray;	
	protected ref TStringArray VIPS_Roupa1 = new TStringArray;
	protected ref TStringArray VIPS_Roupa2 = new TStringArray;
	protected ref TStringArray VIPS_Roupa3 = new TStringArray; 
	protected ref TStringArray VIPS_Roupa4 = new TStringArray; //CRIAR MATRIZ
	
	//PRESET ARMAS ASSALTO
	protected ref TStringArray VIPS_Armas0 = new TStringArray;	
	protected ref TStringArray VIPS_Armas1 = new TStringArray;
	protected ref TStringArray VIPS_Armas2 = new TStringArray;
	protected ref TStringArray VIPS_Armas3 = new TStringArray;
	protected ref TStringArray VIPS_Armas4 = new TStringArray;
	protected ref TStringArray VIPS_Armas5 = new TStringArray;
	protected ref TStringArray VIPS_Armas6 = new TStringArray;
	protected ref TStringArray VIPS_Armas7 = new TStringArray;
	protected ref TStringArray VIPS_Armas8 = new TStringArray;
	protected ref TStringArray VIPS_Armas9 = new TStringArray;	
	protected ref TStringArray VIPS_Armas10 = new TStringArray;	
	protected ref TStringArray VIPS_Armas11 = new TStringArray;	
	protected ref TStringArray VIPS_Armas12 = new TStringArray;	
	protected ref TStringArray VIPS_Armas13 = new TStringArray;	
	protected ref TStringArray VIPS_Armas14 = new TStringArray;	
	protected ref TStringArray VIPS_Armas15 = new TStringArray;	
	protected ref TStringArray VIPS_Armas16 = new TStringArray;	
	protected ref TStringArray VIPS_Armas17 = new TStringArray;	
	protected ref TStringArray VIPS_Armas18 = new TStringArray;	
	protected ref TStringArray VIPS_Armas19 = new TStringArray;	
	protected ref TStringArray VIPS_Armas20 = new TStringArray;	
	protected ref TStringArray VIPS_Armas21 = new TStringArray;	
	
	//PRESET ARMAS SNIPER
	protected ref TStringArray VIPS_ArmasS0 = new TStringArray;	
	protected ref TStringArray VIPS_ArmasS1 = new TStringArray;
	protected ref TStringArray VIPS_ArmasS2 = new TStringArray;
	protected ref TStringArray VIPS_ArmasS3 = new TStringArray;
	protected ref TStringArray VIPS_ArmasS4 = new TStringArray;
	protected ref TStringArray VIPS_ArmasS5 = new TStringArray;
	protected ref TStringArray VIPS_ArmasS6 = new TStringArray;
	protected ref TStringArray VIPS_ArmasS7 = new TStringArray;
	protected ref TStringArray VIPS_ArmasS8 = new TStringArray;
	protected ref TStringArray VIPS_ArmasS9 = new TStringArray;
	protected ref TStringArray VIPS_ArmasS10 = new TStringArray;
	protected ref TStringArray VIPS_ArmasS11 = new TStringArray;
	protected ref TStringArray VIPS_ArmasS12 = new TStringArray;
	protected ref TStringArray VIPS_ArmasS13 = new TStringArray;								
		
	override void OnInit()
	{
		super.OnInit();			
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(VipAtualizar, 60000, true); // 30000 = 30seg || 60000 = 1 min || 300000 = 5min || 600000 = 10min			
		VipAtualizar();	
	}	
	
	void VipAtualizar()
	{		
		//ROUPAS
		VIPS_Roupa0.Clear();		
		VIPS_Roupa1.Clear();	 
		VIPS_Roupa2.Clear();	
		VIPS_Roupa3.Clear();
		VIPS_Roupa4.Clear();//LIMPAR MATRIZ
		//ASSALTO
		VIPS_Armas0.Clear(); 
		VIPS_Armas1.Clear(); 
		VIPS_Armas2.Clear(); 
		VIPS_Armas3.Clear(); 
		VIPS_Armas4.Clear(); 
		VIPS_Armas5.Clear(); 
		VIPS_Armas6.Clear(); 
		VIPS_Armas7.Clear(); 
		VIPS_Armas8.Clear(); 
		VIPS_Armas9.Clear(); 
		VIPS_Armas10.Clear();
		VIPS_Armas11.Clear();
		VIPS_Armas12.Clear();
		VIPS_Armas13.Clear();
		VIPS_Armas14.Clear();
		VIPS_Armas15.Clear();
		VIPS_Armas16.Clear();
		VIPS_Armas17.Clear();
		VIPS_Armas18.Clear();
		VIPS_Armas19.Clear();
		VIPS_Armas20.Clear();
		VIPS_Armas21.Clear();		
		//SNIPER
		VIPS_ArmasS0.Clear();
		VIPS_ArmasS1.Clear();
		VIPS_ArmasS2.Clear();
		VIPS_ArmasS3.Clear();
		VIPS_ArmasS4.Clear();
		VIPS_ArmasS5.Clear();
		VIPS_ArmasS6.Clear();
		VIPS_ArmasS7.Clear();
		VIPS_ArmasS8.Clear();
		VIPS_ArmasS9.Clear();	
		VIPS_ArmasS10.Clear();
		VIPS_ArmasS11.Clear();
		VIPS_ArmasS12.Clear();
		VIPS_ArmasS13.Clear();
		
		string UID_DATA;	
		int AnoAtual, MesAtual, DiaAtual, Dia, Mes, Ano;
		GetYearMonthDayUTC(AnoAtual, MesAtual, DiaAtual);
		array<string> VipLinha = new array<string>;	
		array<string> DataLinha = new array<string>;		
		FileHandle VIPS_LISTA = OpenFile("$profile:DEV FD/Settings/FD-VipSpawn.txt", FileMode.READ); // CAMINHO PARA FAZER O CHECK NO STEAM ID64 DO PLAYER
		
		if (VIPS_LISTA != 0)
		{
			string linha_Vips;					
			while (FGets(VIPS_LISTA,linha_Vips) > 0)
			{
				VipLinha.Clear();
				DataLinha.Clear();
				bool Expirado = false;
				linha_Vips.Split ("|",VipLinha);
				string NOME_VIP = VipLinha[0];
				string NOME_ASSAULT = VipLinha[1];
				string NOME_SNIPER = VipLinha[2];
				string UID_VIP = VipLinha[3];
				string NICK_PLAYER = VipLinha[5];
				UID_DATA = VipLinha[4];	
				UID_DATA.Split ("/",DataLinha);				
				Dia = DataLinha[0].ToInt();
				Mes = DataLinha[1].ToInt();
				Ano = DataLinha[2].ToInt();				

				if (AnoAtual > Ano || (AnoAtual == Ano && MesAtual > Mes) || (AnoAtual == Ano && MesAtual == Mes && DiaAtual > Dia))			
					Expirado = true;				
				else				
					Expirado = false;	
				
				if (Expirado)										
					GetGame().AdminLog("** VIP " + NOME_VIP + " DO "+ NICK_PLAYER +" COM UID "+ UID_VIP +" EXPIROU NA DATA " +Dia+"/"+Mes+"/"+Ano+ " ! FOI IGNORADO PELO SERVER ! **");			
				else
				{	// PRESETS DE ROUPAS				
					if (NOME_VIP == "VIPBRONZE")
						VIPS_Roupa0.Insert(UID_VIP);  			
					else if (NOME_VIP == "VIPPRATA")		
						VIPS_Roupa1.Insert(UID_VIP);  						
					else if (NOME_VIP == "VIPGOLD")		
						VIPS_Roupa2.Insert(UID_VIP); 
					else if (NOME_VIP == "VIPPLATINA")		
						VIPS_Roupa3.Insert(UID_VIP); 
					else if (NOME_VIP == "VIPESMERALDA")	
						VIPS_Roupa4.Insert(UID_VIP); 
					
					// PRESETS DE ARMAS ASSAULT                          
					if (NOME_ASSAULT == "SCARH")
						VIPS_Armas0.Insert(UID_VIP); 
					else if (NOME_ASSAULT == "FNSCAR")
						VIPS_Armas1.Insert(UID_VIP); 
					else if (NOME_ASSAULT == "SG550")
						VIPS_Armas2.Insert(UID_VIP); 							
					else if (NOME_ASSAULT == "SG552")
						VIPS_Armas3.Insert(UID_VIP); 
					else if (NOME_ASSAULT == "REMI")
						VIPS_Armas4.Insert(UID_VIP); 
					else if (NOME_ASSAULT == "M249")
						VIPS_Armas5.Insert(UID_VIP);
					else if (NOME_ASSAULT == "AA12")
						VIPS_Armas6.Insert(UID_VIP); 
					else if (NOME_ASSAULT == "HK416")
						VIPS_Armas7.Insert(UID_VIP);				
					else if (NOME_ASSAULT == "HK417")
						VIPS_Armas8.Insert(UID_VIP); 
					else if (NOME_ASSAULT == "IA2")
						VIPS_Armas9.Insert(UID_VIP);
					else if (NOME_ASSAULT == "MK18")
						VIPS_Armas10.Insert(UID_VIP);	
					else if (NOME_ASSAULT == "VR80")
						VIPS_Armas11.Insert(UID_VIP);
					else if (NOME_ASSAULT == "AKM")
						VIPS_Armas12.Insert(UID_VIP);
					else if (NOME_ASSAULT == "RPK")
						VIPS_Armas13.Insert(UID_VIP);
					else if (NOME_ASSAULT == "AEK545")
						VIPS_Armas14.Insert(UID_VIP);
					else if (NOME_ASSAULT == "CZ805")
						VIPS_Armas15.Insert(UID_VIP);
					else if (NOME_ASSAULT == "PDW")
						VIPS_Armas16.Insert(UID_VIP);
					else if (NOME_ASSAULT == "RPD")
						VIPS_Armas17.Insert(UID_VIP);
					else if (NOME_ASSAULT == "PKP")
						VIPS_Armas18.Insert(UID_VIP);
					else if (NOME_ASSAULT == "AUGA3")
						VIPS_Armas19.Insert(UID_VIP);
					else if (NOME_ASSAULT == "HONEY")
						VIPS_Armas20.Insert(UID_VIP);
					else if (NOME_ASSAULT == "TAR21")
						VIPS_Armas21.Insert(UID_VIP);
					
					// PRESETS DE ARMAS SNIPER						
					if (NOME_SNIPER == "AX50")
						VIPS_ArmasS0.Insert(UID_VIP); 
					else if (NOME_SNIPER == "BARRET")
						VIPS_ArmasS1.Insert(UID_VIP); 
					else if (NOME_SNIPER == "VSSK")
						VIPS_ArmasS2.Insert(UID_VIP); 							
					else if (NOME_SNIPER == "M200S")
						VIPS_ArmasS3.Insert(UID_VIP); 
					else if (NOME_SNIPER == "M200")
						VIPS_ArmasS4.Insert(UID_VIP); 
					else if (NOME_SNIPER == "KIVAARI")
						VIPS_ArmasS5.Insert(UID_VIP);
					else if (NOME_SNIPER == "M300")
						VIPS_ArmasS6.Insert(UID_VIP); 
					else if (NOME_SNIPER == "AWM")
						VIPS_ArmasS7.Insert(UID_VIP);					
					else if (NOME_SNIPER == "DVL")
						VIPS_ArmasS8.Insert(UID_VIP);
					else if (NOME_SNIPER == "TAC21")
						VIPS_ArmasS9.Insert(UID_VIP);
					else if (NOME_SNIPER == "ALLIGATOR")
						VIPS_ArmasS10.Insert(UID_VIP);
					else if (NOME_SNIPER == "T5000")
						VIPS_ArmasS11.Insert(UID_VIP);
					else if (NOME_SNIPER == "M98B")
						VIPS_ArmasS12.Insert(UID_VIP);
					else if (NOME_SNIPER == "AS50")
						VIPS_ArmasS13.Insert(UID_VIP);
				}				
			}			
			CloseFile(VIPS_LISTA);
		}
		GetGame().AdminLog("[DEV FD][FD-VIPSPAWN] ATUALIZADO !");		
	}	
	
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );
		GetGame().SelectPlayer( identity, m_player );
		return m_player;
	}	

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		PlayerIdentity PlayerIdent = player.GetIdentity();
		string PlayerBISID = PlayerIdent.GetId(); 
		string PlayerUID = PlayerIdent.GetPlainId(); 		
		player.GetStatEnergy().Set(5000); //FOME INICIAL 5000 CHEIO
		player.GetStatWater().Set(2500);  //SEDE INICIAL 2500 CHEIO	
		
		if (VIPS_Roupa0.Find(PlayerUID) >= 0)			
			EquipmentRoupas(player, 0);
		else if ( VIPS_Roupa1.Find(PlayerUID) >= 0) // DEFINIR SE ELE TIVER NA MATRIZ
			EquipmentRoupas(player, 1);
		else if ( VIPS_Roupa2.Find(PlayerUID) >= 0) // DEFINIR SE ELE TIVER NA MATRIZ
			EquipmentRoupas(player, 2);	
		else if ( VIPS_Roupa3.Find(PlayerUID) >= 0) // DEFINIR SE ELE TIVER NA MATRIZ
			EquipmentRoupas(player, 3);
		else if ( VIPS_Roupa4.Find(PlayerUID) >= 0) // DEFINIR SE ELE TIVER NA MATRIZ
			EquipmentRoupas(player, 4);
		else

        // SET PARA O EVERYONE (TODOS QUE NÃO FOREM VIP)	
		{
			player.ClearInventory(); // LIMPAR ROUPA DO EVERYONE VANILLA ANTES DE APLICAR A NOVA
			string ChemlightArray[] = {"Chemlight_White","Chemlight_Yellow","Chemlight_Green","Chemlight_Red"};
			string FoodArray[] = {"Apple","Pear","Plum","Banana","Orange"};
			player.GetInventory().CreateInInventory("AthleticShoes_Black");
			player.GetInventory().CreateInInventory("InfernalZVIPS_Jaqueta_Player");	
			player.GetInventory().CreateInInventory("InfernalZVIPS_Calca_Player");			
			player.GetInventory().CreateInInventory("InfernalZVIPS_Gorro_Player");
			player.GetInventory().CreateInInventory("BandageDressing");
			player.GetInventory().CreateInInventory("KitchenKnife");		
			player.GetInventory().CreateInInventory("Flashlight");		
			player.GetInventory().CreateInInventory("Battery9V");					
			player.GetInventory().CreateInInventory(ChemlightArray[Math.RandomInt(0,4)]);
			player.GetInventory().CreateInInventory(FoodArray[Math.RandomInt(0,5)]);
		}
		
		// PRESETS DE ARMAS ASSAULT
		if ( VIPS_Armas0.Find(PlayerUID) >= 0)								
			EquipmentAssault(player, 0);		
		else if ( VIPS_Armas1.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 1);
		else if ( VIPS_Armas2.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 2);
		else if ( VIPS_Armas3.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 3);
		else if ( VIPS_Armas4.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 4);
		else if ( VIPS_Armas5.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 5);
		else if ( VIPS_Armas6.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 6);
		else if ( VIPS_Armas7.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 7);
		else if ( VIPS_Armas8.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 8);
		else if ( VIPS_Armas9.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 9);
		else if ( VIPS_Armas10.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 10);
		else if ( VIPS_Armas11.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 11);
		else if ( VIPS_Armas12.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 12);
		else if ( VIPS_Armas13.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 13);
		else if ( VIPS_Armas14.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 14);
		else if ( VIPS_Armas15.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 15);
		else if ( VIPS_Armas16.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 16);
		else if ( VIPS_Armas17.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 17);
		else if ( VIPS_Armas18.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 18);
		else if ( VIPS_Armas19.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 19);
		else if ( VIPS_Armas20.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 20);
		else if ( VIPS_Armas21.Find(PlayerUID) >= 0)
			EquipmentAssault(player, 21);
		
		// PRESETS DE ARMAS SNIPER
		if ( VIPS_ArmasS0.Find(PlayerUID) >= 0)								
			EquipmentSniper(player, 0);
		else if ( VIPS_ArmasS1.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 1);
		else if ( VIPS_ArmasS2.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 2);
		else if ( VIPS_ArmasS3.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 3);
		else if ( VIPS_ArmasS4.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 4);
		else if ( VIPS_ArmasS5.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 5);
		else if ( VIPS_ArmasS6.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 6);
		else if ( VIPS_ArmasS7.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 7);
		else if ( VIPS_ArmasS8.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 8);
		else if ( VIPS_ArmasS9.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 9);
		else if ( VIPS_ArmasS10.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 10);
		else if ( VIPS_ArmasS11.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 11);
		else if ( VIPS_ArmasS12.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 12);
		else if ( VIPS_ArmasS13.Find(PlayerUID) >= 0)
			EquipmentSniper(player, 13);
	}	
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}