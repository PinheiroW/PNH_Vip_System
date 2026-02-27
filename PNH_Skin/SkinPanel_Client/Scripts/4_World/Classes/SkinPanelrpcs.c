class FD_ColorPanelrpcs
{
	void FD_ColorPanelrpcs()
	{
		GetRPCManager().AddRPC("FDColorPanel", "UpdateSkin", this, SingeplayerExecutionType.Both);
		GetRPCManager().AddRPC("FDColorPanel", "InitData", this, SingeplayerExecutionType.Client);
        GetRPCManager().AddRPC("FDColorPanel", "RequestData", this, SingeplayerExecutionType.Server);
	}

    void InitData(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        Param2<array<string>,bool> data;
        if (!ctx.Read(data)) return;

        if (type == CallType.Client)
        {
            MissionBaseWorld.Cast(GetGame().GetMission()).SetGameData(data.param1,data.param2);
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

            if(player.Recived)
               player.OnShowStore(data.param2);

            player.Recived = true;
        }
    }

    void RequestData(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type == CallType.Server)
        {
            PlayerBase player = PlayerBase.Cast(GetSSPlayerByIdentity(sender.GetPlayerId()));
            if(player)
                MissionBaseWorld.Cast(GetGame().GetMission()).ResponseData(player);
        }
    }

	void UpdateSkin(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
        //Print("[DEV FD][FD-COLORPANEL] MudarTextura");
        Param2<string,bool> data;
        Weapon_Base weapHands;
        ItemBase item;
        if (!ctx.Read(data)) return;
		
        PlayerBase player = PlayerBase.Cast(GetSSPlayerByIdentity(sender.GetPlayerId()));
		//PlayerBase player = data.param1;
		string Texture = data.param1;
        bool onlyhands = data.param2;
        array<string> slots = {"Armband","Back","Body","Eyewear","Feet","Gloves","Headgear","Hips","Legs","Mask","Vest"};

        if(!onlyhands)
        {            
            for(int i; i < slots.Count();i++)
            {
                item = ItemBase.Cast(player.FindAttachmentBySlotName(slots[i]));
                if(item)
					item.HandleTexture(Texture);
            }
        }
        else
        {            
            item = ItemBase.Cast(player.GetItemInHands());
            if(item)
                item.HandleTexture(Texture);
        }

	}
};