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

		// Comando para recarregar o JSON sem reiniciar o servidor
		if (input == "!vipsreload")
		{
			PNH_VipManager.GetInstance().LoadConfig();
			SyncAllOnlinePlayers();
			PNH_Logger.Log("VIP_System", "Configuracoes recarregadas por: " + identity.GetName());
		}
	}

	void SyncAllOnlinePlayers()
	{
		array<Man> players = new array<Man>;
		GetGame().GetPlayers(players);

		foreach (Man p : players)
		{
			PlayerBase player = PlayerBase.Cast(p);
			if (player && player.GetIdentity())
			{
				SendSyncRPC(player, player.GetIdentity());
			}
		}
	}

	void SendSyncRPC(PlayerBase player, PlayerIdentity identity)
	{
		string uid = identity.GetId();

		// Sincroniza Bloqueio de Itens
		ref array<string> restricted = PNH_VipManager.GetInstance().GetGlobalRestrictedList();
		ref array<string> allowed = PNH_VipManager.GetInstance().GetPrivateItems(uid);
		Param2<ref array<string>, ref array<string>> syncData = new Param2<ref array<string>, ref array<string>>(restricted, allowed);
		GetGame().RPCSingleParam(player, 99955, syncData, true, identity);

		// Sincroniza Painel de Skins
		bool hasAccess = PNH_VipManager.GetInstance().HasSkinPanelAccess(uid);
		Param1<bool> skinParam = new Param1<bool>(hasAccess);
		PNH_RpcManager.Get().SendRPC(9991, skinParam, true, identity);
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		if (player && identity)
		{
			SendSyncRPC(player, identity);
		}
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