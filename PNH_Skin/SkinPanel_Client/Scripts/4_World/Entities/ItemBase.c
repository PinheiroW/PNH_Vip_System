modded class ItemBase
{
    private string m_CurrentTexture = "";
    ref array<string> hiddenTextures;
	bool m_IsDefaultSkin = false;

	override void EOnInit(IEntity other, int extra)
	{
		super.EOnInit(other, extra);
		string config;
		string classname = this.GetType();
		hiddenTextures = new array<string>;

		if(this.IsInherited(Weapon_Base))
			config = "CfgWeapons " +  classname + " hiddenSelectionsTextures";
		else if(this.IsInherited(Magazine))
			config = "CfgMagazines " +  classname  + " hiddenSelectionsTextures";
		else if(this.IsInherited(ItemBase))
			config = "CfgVehicles " +  classname + " hiddenSelectionsTextures";

		GetGame().ConfigGetTextArray(config, hiddenTextures);
	}

	void HandleTexture(string Skin = "")
	{
        string path;
		bool flag;
		if(!hiddenTextures)
        	return;

        //Print("[DEV FD][FD-COLORPANEL] Lidar com Textura");
        //Print(hiddenTextures.Count());
        //Print(hiddenTextures[0]);
		
		for (int i; i < hiddenTextures.Count(); i++)
		{
			if(Skin == "")
			{
                path = hiddenTextures[i];
                flag = true;
			}
			else
			{
               path = Skin
               flag = false;
			}

			SetObjectTexture(i, path);
			SetAttachmentsTexture(Skin);
            OnSkinUpdate(flag);
		}
	}

    string GetCurrentTexture()
    {
    	return m_CurrentTexture;
    }

    void SetAttachmentsTexture(string Skin)
    {
    	if (GetInventory().AttachmentCount() > 0)
        {
            for (int i; i < GetInventory().AttachmentCount(); i++)
			{
				ItemBase Attachment = ItemBase.Cast(GetInventory().GetAttachmentFromIndex(i));
				Attachment.HandleTexture(Skin);
				//Print(Attachment);
				//Print(Attachment.ClassName());
			}
        }
    }

	void OnSkinUpdate(bool flag)
	{
        m_IsDefaultSkin = flag;
	}

	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
	{
		if (old_owner)
		{
			if (new_owner != old_owner)
			{
				if (!m_IsDefaultSkin)
					HandleTexture();
			}
		}
		super.OnItemLocationChanged(old_owner, new_owner);
	}
}

