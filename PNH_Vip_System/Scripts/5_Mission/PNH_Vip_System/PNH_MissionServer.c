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
	// SISTEMA DE FILA DE PRIORIDADE
	// ==========================================
	override void OnPreConnect(PlayerIdentity identity, out string uid_to_kick)
	{
		super.OnPreConnect(identity, uid_to_kick);

		// O método OnPreConnect pode ser chamado antes de o jogador ter um identity completo,
		// então capturamos o UID da forma bruta por segurança.
		string uid = identity.GetId();

		if (PNH_VipManager.GetInstance().HasQueuePriority(uid))
		{
			// Isso joga o jogador para o topo da fila (padrão nativo do DayZ Reserved Slots)
			identity.SetReservedSlot(true);
			PNH_Logger.Log("VIP_System", "Jogador usou Fila de Prioridade: " + identity.GetName());
		}
	}

	// ==========================================
	// MENSAGEM PRIVADA AO LOGAR
	// ==========================================
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		if (identity)
		{
			string uid = identity.GetId();
			
			// Se o jogador é VIP de Tier, mandamos o status
			if (PNH_VipManager.GetInstance().IsVip(uid))
			{
				string dataVencimento = PNH_VipManager.GetInstance().GetVipExpirationDate(uid);
				string tier = PNH_VipManager.GetInstance().GetVipTier(uid);
				
				string msg = "Bem-vindo de volta! O seu status [" + tier + "] e valido ate: " + dataVencimento;
				
				// Disparando via Framework (se você configurou o ChatController)
				PNH_ChatController.SendPrivateMessage(identity, msg);
			}
		}
	}
}