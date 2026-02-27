modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		PNH_VipManager.GetInstance();
	}

	override void OnChatMessage(int chatChannel, PlayerIdentity identity, string input)
	{
		super.OnChatMessage(chatChannel, identity, input);

		if (input == "!vipsreload")
		{
			PNH_VipManager.GetInstance().LoadConfig();
			
			array<Man> players = new array<Man>;
			GetGame().GetPlayers(players);
			foreach (Man p : players)
			{
				PlayerBase pb = PlayerBase.Cast(p);
				if (pb && pb.GetIdentity()) SyncVipData(pb, pb.GetIdentity());
			}
			PNH_Logger.Log("VIP_System", "Reload efetuado por: " + identity.GetName());
		}
	}

	void SyncVipData(PlayerBase player, PlayerIdentity identity)
	{
		string uid = identity.GetId();

		// Sincronização do Bloqueio (RPC 99955)
		ref array<string> restricted = PNH_VipManager.GetInstance().GetGlobalRestrictedList();
		ref array<string> allowed = PNH_VipManager.GetInstance().GetPrivateItems(uid);
		Param2<ref array<string>, ref array<string>> syncData = new Param2<ref array<string>, ref array<string>>(restricted, allowed);
		GetGame().RPCSingleParam(player, 99955, syncData, true, identity);

		// Sincronização SkinPanel (RPC ID: 9991)
		bool hasAccess = PNH_VipManager.GetInstance().HasSkinPanelAccess(uid);
		Param1<bool> skinParam = new Param1<bool>(hasAccess);
		PNH_RpcManager.Get().SendRPC(9991, skinParam, true, identity);
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		if (player && identity) SyncVipData(player, identity);
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		super.StartingEquipSetup(player, clothesChosen);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.ProcessVipSpawn, 250, false, player);
	}

	void ProcessVipSpawn(PlayerBase player)
	{
		if (!player || !player.GetIdentity()) return;
		string uid = player.GetIdentity().GetId();
		if (PNH_VipManager.GetInstance().IsVip(uid))
		{
			array<string> items = PNH_VipManager.GetInstance().GetVipClothing(uid);
			if (items && items.Count() > 0)
			{
				player.RemoveAllItems();
				foreach (string itm : items) { player.GetInventory().CreateInInventory(itm); }
			}
		}
	}
}