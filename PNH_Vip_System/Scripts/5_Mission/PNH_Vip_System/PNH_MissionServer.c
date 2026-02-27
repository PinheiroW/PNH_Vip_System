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

		// Usamos o Identity direto para garantir que o UID seja lido no respawn
		PlayerIdentity identity = player.GetIdentity();
		if (identity)
		{
			string uid = identity.GetId();
			if (PNH_VipManager.GetInstance().IsVip(uid))
			{
				array<string> items = PNH_VipManager.GetInstance().GetVipClothing(uid);
				if (items && items.Count() > 0)
				{
					player.RemoveAllItems();
					foreach (string itm : items) { player.GetInventory().CreateInInventory(itm); }
					PNH_Logger.Log("VIP_System", "Spawn VIP processado para: " + identity.GetName());
				}
			}
		}
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		if (player && identity)
		{
			// Envia as listas de restrição para o cliente do jogador sincronizar
			auto params = new Param2<array<string>, array<string>>(
				PNH_VipManager.GetInstance().GetGlobalRestrictedList(),
				PNH_VipManager.GetInstance().GetPrivateItems(identity.GetId())
			);
			GetGame().RPCSingleParam(player, 99955, params, true, identity);
		}
	}
}