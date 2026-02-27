modded class MissionServer 
{		
	ref array <ref PlayerSVIP> PlayersVIP;
	
    void MissionServer() {				
		PlayersVIP = new ref array <ref PlayerSVIP>;		
        GetconfigItemsVIP();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.SendConfigItemPermission, GetconfigItemsVIP().RefreshConfig * 1000, true);		
    }   		
	
	void ~MissionServer()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(this.SendConfigItemPermission);
	}	
	
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity){		
		if (player)		
			GetConfigList(player, identity);
		
		super.InvokeOnConnect(player, identity);
	}	
	
	void SendConfigItemPermission()
	{
		GetconfigItemsVIP().SetConfig();		
		array<Man> players = new array<Man>();
		GetGame().GetPlayers(players);			
		foreach (Man man : players){
			PlayerBase player;
			if (Class.CastTo(player, man)){
				GetConfigList(player, player.GetIdentity());
			}
		}		
	}
		
	void GetConfigList(PlayerBase player, PlayerIdentity identity)
	{		
		PlayersVIP = GetconfigItemsVIP().PlayersVIP;
		ref array<string> ListItems = new array<string>;
		ref array<string> ListPrivado = new array<string>;
		
		for (int i = 0; i < PlayersVIP.Count(); i++){				
			ListItems.InsertAll(PlayersVIP[i].m_ItemsPrivate);			
			for (int h = 0; h < PlayersVIP[i].m_Players.Count(); h++){					
				string Type = PlayersVIP[i].m_TypeVIP;
				string ID64 = PlayersVIP[i].m_Players[h].m_SteamID;					
				if( identity.GetPlainId() == ID64 )
				{
					string Nick = PlayersVIP[i].m_Players[h].m_Nickname;
					string DataEx = PlayersVIP[i].m_Players[h].m_DateExpired;
					
					array < string > DataLinha = new array < string > ;		
					DataEx.Split("/", DataLinha);
					
					if(!isExpiredVIP(DataLinha[0].ToInt(), DataLinha[1].ToInt(), DataLinha[2].ToInt()))	
						ListPrivado.InsertAll(PlayersVIP[i].m_ItemsPrivate);
				}
			}				
		}	
		SetListPlayerItem(player, ListItems);
		SetCfgPlayer(player, Type, Nick, DataEx, ListPrivado);		
	}
	
	void SetListPlayerItem(PlayerBase player, ref array<string> List)
	{
		player.SetListItemsPrivate(List, GetconfigItemsVIP().RefreshConfig);
		player.RPCSingleParam(-25656465589, new Param2<ref array<string>, int>( List, GetconfigItemsVIP().RefreshConfig), true, player.GetIdentity());			
	}	
	
	void SetCfgPlayer(PlayerBase player, string Type, string Name, string Data, ref array<string> Itens)
	{			
		player.SetPermissionItemPrivate(Itens);
		player.RPCSingleParam(-23654665568, new Param1<ref array<string>>( Itens ), true, player.GetIdentity());			
		GetGame().AdminLog("Item VIP " + Type + " - Jogador [" + Name + "] com SteamID [" + player.GetIdentity().GetPlainId()+"] está ativo até a data " + Data + " com os itens " + Itens);				
	}
	
	bool isExpiredVIP(int Dia, int Mes, int Ano) {
        int AnoAtual, MesAtual, DiaAtual;
        GetYearMonthDayUTC(AnoAtual, MesAtual, DiaAtual);
        if (AnoAtual > Ano || (AnoAtual == Ano && MesAtual > Mes) || (AnoAtual == Ano && MesAtual == Mes && DiaAtual > Dia)) {
            return true;
        } else {
            return false;
        }
        return false;
    }
};