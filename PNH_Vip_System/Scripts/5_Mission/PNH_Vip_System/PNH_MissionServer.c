modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		// Inicia o Manager silenciosamente no arranque
		PNH_VipManager.GetInstance();
	}

	// ==========================================
	// SISTEMA DE ROUPAS (SPAWN VIP)
	// ==========================================
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		super.StartingEquipSetup(player, clothesChosen);

		if (player && player.GetIdentity())
		{
			string uid = player.GetIdentity().GetId();

			// Verifica se o jogador tem um Tier VIP válido
			if (PNH_VipManager.GetInstance().IsVip(uid))
			{
				array<string> vipItems = PNH_VipManager.GetInstance().GetVipClothing(uid);
				
				if (vipItems && vipItems.Count() > 0)
				{
					// Remove as roupas vanilla (fresh spawn) para não encavalar
					player.RemoveAllItems();
					
					// Entrega os itens listados no JSON
					foreach (string itemName : vipItems)
					{
						player.GetInventory().CreateInInventory(itemName);
					}
					
					PNH_Logger.Log("VIP_System", "Roupas VIP entregues para: " + player.GetIdentity().GetName());
				}
			}
		}
	}

	// ==========================================
	// MENSAGEM PRIVADA & FILA DE PRIORIDADE
	// ==========================================
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		if (identity)
		{
			string uid = identity.GetId();
			
			// 1. SISTEMA DE FILA DE PRIORIDADE
			// Ao setar aqui, o motor do jogo reconhece a prioridade deste UID
			if (PNH_VipManager.GetInstance().HasQueuePriority(uid))
			{
				identity.SetReservedSlot(true);
				PNH_Logger.Log("VIP_System", "Jogador usou Fila de Prioridade: " + identity.GetName());
			}

			// 2. MENSAGEM DE BOAS VINDAS VIP
			if (PNH_VipManager.GetInstance().IsVip(uid))
			{
				string dataVencimento = PNH_VipManager.GetInstance().GetVipExpirationDate(uid);
				string tier = PNH_VipManager.GetInstance().GetVipTier(uid);
				
				string msg = "Bem-vindo de volta! O seu status [" + tier + "] e valido ate: " + dataVencimento;
				
				// Disparando via Framework
				PNH_ChatController.SendPrivateMessage(identity, msg);
			}
		}
	}
}