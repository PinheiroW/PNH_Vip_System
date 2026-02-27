const int SKINSTORE_NEMESIS = 987512;

modded class MissionGameplay
{
    ref FD_ColorPanel m_FD_ColorPanel;
	
	void MissionGameplay()
    {
        m_FD_ColorPanelrpcs = new ref FD_ColorPanelrpcs();
    }
	
    void ~MissionGameplay()
    {
        if (m_FD_ColorPanelrpcs) delete m_FD_ColorPanelrpcs;
    }

    override FD_ColorPanelBase GetFDColorPanelGUI()
    {
        return m_FD_ColorPanel;
    }
	
    FD_ColorPanelBase CreateFDColorPanelGUI()
    {
    	m_FD_ColorPanel = new FD_ColorPanel();
    	return m_FD_ColorPanel;
    }

	override void OnKeyPress(int key)
	{
		super.OnKeyPress(key);
		UIManager UIMgr = GetGame().GetUIManager();
		if (key == KeyCode.KC_ESCAPE)
		{
			if (GetFDColorPanelGUI())
            {
                GetFDColorPanelGUI().CloseThis();
            }
		}
	}
};