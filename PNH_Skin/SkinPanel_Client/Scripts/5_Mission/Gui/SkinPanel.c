class FD_ColorPanel: FD_ColorPanelBase
{
	PlayerBase 				m_Player;
	private Widget          m_SkinWrapper;
	private ButtonWidget 	m_BtnClose;
	private ButtonWidget 	m_SetDefault;
	private CheckBoxWidget  m_Onlyhands;
	private bool			m_IsOpened;
	
	private bool m_Acces;
    private ref array<string> allpath;
    private ref map<int, Widget> m_wBox;

	override Widget Init()
	{
		m_Player = PlayerBase.Cast(GetGame().GetPlayer());
        m_wBox = new map<int, Widget>;
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("SkinPanel_Client/GUI/Layouts/DonatorMenu.layout");
        m_SkinWrapper = layoutRoot.FindAnyWidget("ContentWrapper");
		m_BtnClose = layoutRoot.FindAnyWidget("Close");
		m_SetDefault = layoutRoot.FindAnyWidget("Default");
		m_Onlyhands = layoutRoot.FindAnyWidget("OnlyHands");		

        m_Onlyhands.SetChecked(m_Player.m_OnlyHands);

		m_Acces = MissionBaseWorld.Cast(GetGame().GetMission()).isDonator();
        allpath = MissionBaseWorld.Cast(GetGame().GetMission()).GetImages();

		int CountElements = allpath.Count();

		for(int i; i < allpath.Count();i++)
        {
			Widget Skin = GetGame().GetWorkspace().CreateWidgets("SkinPanel_Client/GUI/Layouts/SkinCase.layout" ,m_SkinWrapper);
			m_SkinWrapper.Update();
			m_wBox.Insert( i, Skin );
        }
		OnInit();
		return layoutRoot;
	}
	
    void OnInit()
    {
    	//Print("[DEV FD][FD-COLORPANEL] Carregando");
        for(int i; i < allpath.Count();i++)
        {
        	ImageWidget.Cast(m_wBox[i].FindAnyWidget("Icon_0" )).LoadImageFile(0,allpath[i]);
        }
    }
	
	override void OnShow()
	{
        super.OnShow();
		PPEffects.SetBlurMenu(0.1);
		GetGame().GetInput().ChangeGameFocus(1);
		GetGame().GetMission().GetHud().Show( false );
		SetFocus( layoutRoot );
	}

	override void OnHide()
	{
		super.OnHide();
		PPEffects.SetBlurMenu(0);
		GetGame().GetInput().ResetGameFocus();
		GetGame().GetMission().GetHud().Show( true );
		Close();
	}

	bool IsOpened()
	{
		return m_IsOpened;
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		int key = -1;
		for(int i; i < m_wBox.Count();i++)
		{
			if(m_wBox[i].FindAnyWidget("SkinCase" ) == w)
				key = i;
		}		
		if(key != -1)
		{
			UpdateSkin(allpath[key]);
			return true;
		}
		if(w == m_BtnClose)
		{
			CloseThis();
			return true;
		}
		if(w == m_SetDefault)
		{
			UpdateSkin();
			return true;
		}
		return false;
	}

    override bool OnChange( Widget w, int x, int y, bool finished )
	{
		super.OnChange(w, x, y, finished);
		if (!finished) return false;
        m_Player.m_OnlyHands = m_Onlyhands.IsChecked();
		return false;
	}

	void UpdateSkin(string Texture = "")
	{
		m_Player = PlayerBase.Cast(GetGame().GetPlayer());		
		if (m_Acces && m_Player.TextureIsUpdated())
		{				
			m_Player.SetCurrentSkin(Texture);
			GetRPCManager().SendRPC("FDColorPanel", "UpdateSkin", new Param2<string,bool>(Texture,m_Onlyhands.IsChecked()), true, m_Player.GetIdentity());
		}				
	}	

	override void CloseThis()
	{
		GetGame().GetUIManager().Back();	
	}
}