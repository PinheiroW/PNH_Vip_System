class configItemsVIP
{
	private const static string CONFIG_PAST = "$profile:PNH/Settings";
	private const static string CONFIG_FILE = CONFIG_PAST + "\\PNH_Private.json";	
	int RefreshConfig = 30;	
	ref array < ref PlayerSVIP > PlayersVIP = new ref array < ref PlayerSVIP > ;	
	
	void configItemsVIP(){	
		if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
			SetConfig();		
	}
	
	void SetConfig(){		
		if(!FileExist(CONFIG_PAST))
			MakeDirectory(CONFIG_PAST);
		
		if(!FileExist(CONFIG_FILE)){			
			ref PlayerSVIP Temp1 = new PlayerSVIP;				
			Temp1.m_TypeVIP = "GOLD";
			Temp1.m_Players.Insert(new PlayerActiveVIP("DEV","76561198966041256","20/12/2024"));		
			Temp1.m_ItemsPrivate.Insert("AKM");	
			Temp1.m_ItemsPrivate.Insert("M4A1");	

			ref PlayerSVIP Temp2 = new PlayerSVIP;		
			Temp2.m_TypeVIP = "SILVER";
			Temp2.m_Players.Insert(new PlayerActiveVIP("DEV","76561198966041255","20/12/2023"));
			Temp2.m_ItemsPrivate.Insert("SVD");		
			Temp2.m_ItemsPrivate.Insert("VSS");	
			
			PlayersVIP.Insert(Temp1);		
			PlayersVIP.Insert(Temp2);			
			JsonFileLoader<configItemsVIP>.JsonSaveFile(CONFIG_FILE, this);
		}			
		JsonFileLoader<configItemsVIP>.JsonLoadFile(CONFIG_FILE, this);
	}
}

ref configItemsVIP N_configItemsVIP;
static ref configItemsVIP GetconfigItemsVIP(){
	if (!N_configItemsVIP){
		N_configItemsVIP = new ref configItemsVIP;
	}
	return N_configItemsVIP;
}

