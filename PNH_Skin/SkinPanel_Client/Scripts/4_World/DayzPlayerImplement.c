modded class DayZPlayerImplement 
{
    override void CommandHandler(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
    {
        super.CommandHandler(pDt,pCurrentCommandID,pCurrentCommandFinished);
        FDColorPanelKeyHandler();
    }
	
    void FDColorPanelKeyHandler()
    {
    	UAInput m_BindStat = GetUApi().GetInputByName("UAToggleSkinStore");
        MissionBaseWorld mission = MissionBaseWorld.Cast(GetGame().GetMission());
        if(m_BindStat.LocalPress() && PlayerBase.Cast(GetGame().GetPlayer()).HasKeyHold()) 
		{
			PlayerBase.Cast(GetGame().GetPlayer()).HoldOpenMenu();
			UIScriptedMenu menu = GetGame().GetUIManager().GetMenu();
			if(!mission.GetFDColorPanelGUI() && !menu)
			{
				bool access = mission.isDonator();
				if(access)
					OnShowStore(access);
				else
					GetRPCManager().SendRPC("FDColorPanel", "RequestData",null, true, GetGame().GetPlayer().GetIdentity());
			}
			else if(mission.GetFDColorPanelGUI())
			{
			   mission.GetFDColorPanelGUI().CloseThis();
			}

        }

    }
    void OnShowStore(bool access)
    {
		if(!access)
			return;

        MissionBaseWorld mission = MissionBaseWorld.Cast(GetGame().GetMission());
        GetGame().GetUIManager().ShowScriptedMenu(mission.CreateFDColorPanelGUI(), null);
    }

    bool HasKeyHold()
    {
        return false;
    }
    void HoldOpenMenu(){};
}

modded class PlayerBase
{
	private bool m_TextureUdateDelay = true;
    private bool m_KeyHolder = true;
	bool m_OnlyHands = false;
	bool Recived = false;
	private string m_CurrentSkin;
	string m_uid;

	bool TextureIsUpdated()
	{
		return m_TextureUdateDelay;
	}

    override bool HasKeyHold()
    {
        return m_KeyHolder
    }

    override void HoldOpenMenu()
    {
        m_KeyHolder = false;
        RefreshKey();
    }

	void OnKeyRefresh()
	{
		m_TextureUdateDelay = true;
        m_KeyHolder = true;
	}

	string GetSkin()
	{
		return m_CurrentSkin;
	}

    void RefreshKey()
    {
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(OnKeyRefresh, 1 * 1000, false);
    }

	void SetCurrentSkin(string skin)
	{
        m_CurrentSkin =  skin;
        m_TextureUdateDelay = false;
		RefreshKey();
	}
}