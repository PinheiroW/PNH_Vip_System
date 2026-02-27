static PlayerBase GetSSPlayerByIdentity (int plyId) 
{
    array<Man> players = new array<Man>;
    PlayerBase result = NULL;

    if (GetGame().IsMultiplayer()) 
	{
        GetGame().GetPlayers(players);
        for (int i = 0; i < players.Count(); i++) {
            if (players.Get(i).GetIdentity().GetPlayerId() == plyId) 
			{
                result = PlayerBase.Cast(players.Get(i));
            }
        }
    }
    else
    {
        //Print("[DEV FD][FD-COLORPANEL] Cliente Obter Jogador");
        result = PlayerBase.Cast(GetGame().GetPlayer());
    }

    return result;
}
class FD_ColorPanelBase extends UIScriptedMenu
{
    void CloseThis(){};
}

modded class MissionBaseWorld
{
	bool m_IsDonator;
    bool m_Cooldown = false;
    ref array<string> m_images;
	ref FD_ColorPanelrpcs m_FD_ColorPanelrpcs;
	ref array<string> GetImages()
    {
    	return m_images;
    }
    FD_ColorPanelBase GetFDColorPanelGUI()
    {
        return null;
    }
    FD_ColorPanelBase CreateFDColorPanelGUI()
    {
        return null;
    }
    bool isDonator()
    {
    	return m_IsDonator;
    }
    void ResponseData(PlayerBase player){};
    void SetGameData(array<string> p1,bool p2)
    {
        m_images = p1;
        m_IsDonator = p2;
    }
}

