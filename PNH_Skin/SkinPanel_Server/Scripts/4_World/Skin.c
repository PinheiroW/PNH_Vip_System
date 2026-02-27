class FDColorPanelData{
	ref array<string> Players = new array<string>;
	ref array<string> Skins = new array<string>;
}
class DataHandler extends DataHandlerBase
{
	const static string path = "$profile:PNH/Settings";	
	const static string pathFile = path + "//PNH-ColorPanel.json"
	
    ref FDColorPanelData m_DataBox;
	
    ref Timer m_Timer;

	void DataHandler()
	{
		//Print("[DEV FD][FD-COLORPANEL] Manipulador de dados");
		m_Timer = new Timer();
	}

	override void OnUpdate()
	{		
		if (GetGame().IsServer())
		{
			if(!FileExist(path)) 
			{
				MakeDirectory(path);
			}			
			
			if (FileExist(pathFile))
			{
				JsonFileLoader<FDColorPanelData>.JsonLoadFile(pathFile, m_DataBox);					
			}
			else
			{				
				Save();				
			}
		}
	}
		
	void Save()
	{			
		Fill()
		JsonFileLoader<FDColorPanelData>.JsonSaveFile(pathFile, m_DataBox);
		OnUpdate();
	}
	
	void Fill()
	{
		m_DataBox = new FDColorPanelData;		
		m_DataBox.Players.Insert("76561199469401978");		
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_1.paa");
	    m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_2.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_3.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_4.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_5.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_6.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_7.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_8.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_9.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_10.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_11.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_12.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_13.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_14.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_15.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_16.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_17.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_18.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_19.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_20.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_21.paa");
	    m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_22.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_23.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_24.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_25.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_26.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_27.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_28.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_29.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_30.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_31.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_32.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_33.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_34.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_35.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_36.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_37.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_38.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_39.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_40.paa");	
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_41.paa");
	    m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_42.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_43.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_44.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_45.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_46.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_47.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_48.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_49.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_50.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_51.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_52.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_53.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_54.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_55.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_56.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_57.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_58.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_59.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_60.paa");
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_61.paa");	
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_62.paa");	
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_63.paa");	
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_64.paa");	
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_65.paa");	
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_66.paa");	
		m_DataBox.Skins.Insert("SkinPanel_Client\\Data\\Color_67.paa");
				
	}

    override void OnInit()
    {
		//Print("[DEV FD][FD-COLORPANEL] A Iniciar");     
		m_Timer.Run(300, this,"OnUpdate", NULL, true);
    }

	ref array<string> GetImages()
	{
		return m_DataBox.Skins;
	}

	bool IsOnList(string id)
	{
		array<string> buf = m_DataBox.Players;
		if (buf.Find(id) != -1)
			return true;

		return false;
	}
}