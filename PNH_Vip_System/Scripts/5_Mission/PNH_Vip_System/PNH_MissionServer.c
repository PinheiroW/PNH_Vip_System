modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		PNH_VipManager.GetInstance();
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		super.StartingEquipSetup(player, clothesChosen);

		// Damos um pequeno delay para garantir que a Identity do jogador está pronta
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.ProcessVipSpawn, 100, false, player);
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
				PNH_Logger.Log("VIP_System", "Spawn VIP processado: " + player.GetIdentity().GetName());
			}
		}
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		
		if (player && identity)
		{
			string uid = identity.GetId();

			// 1. Sincronização do Bloqueio de Itens (RPC 99955)
			ref array<string> restricted = PNH_VipManager.GetInstance().GetGlobalRestrictedList();
			ref array<string> allowed = PNH_VipManager.GetInstance().GetPrivateItems(uid);
			
			// Declaração simplificada para evitar erro de sintaxe
			Param2<ref array<string>, ref array<string>> syncData;
			syncData = new Param2<ref array<string>, ref array<string>>(restricted, allowed);
			GetGame().RPCSingleParam(player, 99955, syncData, true, identity);

			// 2. Autorização do Painel de Skins (RPC do teu mod de Skin)
			string skinMod = "PNH_Skin";
			string skinMethod = "InitData";
			bool hasAccess = PNH_VipManager.GetInstance().HasSkinPanelAccess(uid);
			
			Param1<bool> skinParam = new Param1<bool>(hasAccess);
			PNH_RpcManager.Get().SendRPC(skinMod, skinMethod, skinParam, true, identity);
			
			PNH_Logger.Log("VIP_System", "Permissoes sincronizadas para: " + identity.GetName());
		}
	}
}