modded class MissionServer
{
	static ref DataHandler m_DataHandler;
    ref array<string> m_ReceivedPlayers;

	override void OnInit()
	{
		super.OnInit();
		m_ReceivedPlayers = new array<string>;
        m_DataHandler = new DataHandler();
        m_DataHandler.OnUpdate();
        m_DataHandler.OnInit();
        GetFD_ColorPanelrpcs();
	}

    private ref FD_ColorPanelrpcs GetFD_ColorPanelrpcs()
    {
        if (!m_FD_ColorPanelrpcs)
			m_FD_ColorPanelrpcs = new ref FD_ColorPanelrpcs;

        return m_FD_ColorPanelrpcs;
    }

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
    {
        Entity playerEnt;

        playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
        Class.CastTo(m_player, playerEnt);
        GetGame().SelectPlayer(identity, m_player);
        ResponseData(m_player);
        return m_player;
    }

    override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	{
        super.OnClientReadyEvent(identity, player);
		GetGame().SelectPlayer(identity, player);
        ResponseData(player);
	};
	
    override void ResponseData(PlayerBase player)
    {
        string uid = player.GetIdentity().GetPlainId();
        //Print(m_ReceivedPlayers);          
        player.m_uid = uid;
        bool isdonator = GetDataHandler().IsOnList(uid);
        array<string> Images = GetDataHandler().GetImages();
        GetRPCManager().SendRPC( "FDColorPanel", "InitData", new Param2<array<string>,bool>(Images,isdonator), true, player.GetIdentity());
    }

    override void PlayerDisconnected(PlayerBase player, PlayerIdentity identity, string uid)
    {
        if (!player)
            return;
       
        string m_uid = player.m_uid;
        int key = m_ReceivedPlayers.Find(m_uid);
        m_ReceivedPlayers.Remove(key);
        super.PlayerDisconnected( player,  identity,  uid )
    }

    DataHandler GetDataHandler()
	{ 
		return m_DataHandler;
	}
};