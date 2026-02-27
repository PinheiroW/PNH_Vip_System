modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		// Inicia o Manager no arranque do servidor
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

			// Verifica se o jogador tem um Tier VIP válido no Manager (3_Game)
			if (PNH_VipManager.GetInstance().IsVip(uid))
			{
				array<string> vipItems = PNH_VipManager.GetInstance().GetVipClothing(uid);
				
				if (vipItems && vipItems.Count() > 0)
				{
					// Limpa o inventário inicial
					player.RemoveAllItems();
					
					// Spawna os itens definidos no JSON
					foreach (string itemName : vipItems)
					{
						player.GetInventory().CreateInInventory(itemName);
					}
					
					PNH_Logger.Log("VIP_System", "Equipamento VIP entregue a: " + player.GetIdentity().GetName());
				}
			}
		}
	}

	// ==========================================
	// MENSAGEM PRIVADA AO ENTRAR
	// ==========================================
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		if (identity)
		{
			string uid = identity.GetId();
			
			// Se o jogador for VIP, envia a confirmação e data de validade
			if (PNH_VipManager.GetInstance().IsVip(uid))
			{
				string dataVencimento = PNH_VipManager.GetInstance().GetVipExpirationDate(uid);
				string tier = PNH_VipManager.GetInstance().GetVipTier(uid);
				
				string msg = "PNH VIP: Status [" + tier + "] ativo ate " + dataVencimento;
				
				// Utiliza o ChatController da tua Framework
				PNH_ChatController.SendPrivateMessage(identity, msg);
				
				PNH_Logger.Log("VIP_System", "Jogador VIP conectado: " + identity.GetName() + " (" + tier + ")");
			}
		}
	}
}