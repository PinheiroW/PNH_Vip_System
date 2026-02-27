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
		// Delay maior para garantir sincronia do Identity no Spawn
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
				PNH_Logger.Log("VIP_System", "Entrega de itens VIP concluida: " + player.GetIdentity().GetName());
			}
		}
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		
		if (player && identity)
		{
			string uid = identity.GetId();

			// 1. Sincronização do Bloqueio de Itens (ID: 99955)
			ref array<string> restricted = PNH_VipManager.GetInstance().GetGlobalRestrictedList();
			ref array<string> allowed = PNH_VipManager.GetInstance().GetPrivateItems(uid);
			Param2<ref array<string>, ref array<string>> syncData = new Param2<ref array<string>, ref array<string>>(restricted, allowed);
			GetGame().RPCSingleParam(player, 99955, syncData, true, identity);

			// 2. Autorização do Painel de Skins via Framework (ID: 9991)
			// Conforme a sua Framework, o primeiro parâmetro deve ser um INT (ID do RPC).
			bool hasAccess = PNH_VipManager.GetInstance().HasSkinPanelAccess(uid);
			Param1<bool> skinParam = new Param1<bool>(hasAccess);
			PNH_RpcManager.Get().SendRPC(9991, skinParam, true, identity);
			
			PNH_Logger.Log("VIP_System", "Permissoes e Skins sincronizadas: " + identity.GetName());
		}
	}
}