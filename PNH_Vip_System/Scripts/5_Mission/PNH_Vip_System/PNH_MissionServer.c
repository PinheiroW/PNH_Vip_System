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

		PlayerIdentity identity = player.GetIdentity();
		if (identity)
		{
			string uid = identity.GetId();
			PNH_Logger.Log("VIP_System", "Verificando VIP para UID: " + uid);

			if (PNH_VipManager.GetInstance().IsVip(uid))
			{
				array<string> items = PNH_VipManager.GetInstance().GetVipClothing(uid);
				if (items && items.Count() > 0)
				{
					player.RemoveAllItems();
					foreach (string itm : items) 
					{ 
						player.GetInventory().CreateInInventory(itm); 
					}
					PNH_Logger.Log("VIP_System", "Roupas VIP entregues para: " + identity.GetName());
				}
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
			array<string> restrictedList = PNH_VipManager.GetInstance().GetGlobalRestrictedList();
			array<string> allowedList = PNH_VipManager.GetInstance().GetPrivateItems(uid);
			
			auto syncParams = new Param2<array<string>, array<string>>(restrictedList, allowedList);
			GetGame().RPCSingleParam(player, 99955, syncParams, true, identity);

			// 2. Autorização do Painel de Skins (RPC 9991)
			bool hasSkinAccess = PNH_VipManager.GetInstance().HasSkinPanelAccess(uid);
			auto skinParams = new Param1<bool>(hasSkinAccess);
			
			// Usando o RPCManager da tua framework conforme o mod PNH_Skin original
			PNH_RpcManager.Get().SendRPC("PNH_Skin", "InitData", skinParams, true, identity);
			
			PNH_Logger.Log("VIP_System", "Sincronizacao de permissões enviada para: " + identity.GetName());
		}
	}
}