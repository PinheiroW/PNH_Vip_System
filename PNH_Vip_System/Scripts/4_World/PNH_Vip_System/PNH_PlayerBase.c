modded class PlayerBase
{	
	ref array<string> m_LocalRestrictedList; // Itens bloqueados no server
	ref array<string> m_LocalAllowedItems;    // Itens que EU posso pegar

	void PlayerBase()
	{
		m_LocalRestrictedList = new array<string>;
		m_LocalAllowedItems = new array<string>;
	}

	// Recebe as listas do servidor via RPC (Sincronização)
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (GetGame().IsClient())
		{
			if (rpc_type == 99955) // ID Único para nosso mod
			{
				Param2<array<string>, array<string>> data;
				if (!ctx.Read(data)) return;
				m_LocalRestrictedList = data.param1;
				m_LocalAllowedItems = data.param2;
			}
		}
	}

	bool CanLootPrivateItem(EntityAI item)
	{
		if (!item) return true;
		string itemName = item.GetType();
		itemName.ToLower();

		// Se o item é restrito globalmente
		if (m_LocalRestrictedList.Find(itemName) != -1)
		{
			// Só deixa pegar se estiver na minha lista de permitidos
			if (m_LocalAllowedItems.Find(itemName) != -1) return true;
			return false; 
		}
		return true;
	}

	// Overrides para bloquear todas as formas de interação
	override void PredictiveTakeEntityToHands(EntityAI item) { if (!CanLootPrivateItem(item)) return; super.PredictiveTakeEntityToHands(item); }
	override bool PredictiveTakeEntityToTargetAttachmentEx(notnull EntityAI target, notnull EntityAI item, int slot) { if (!CanLootPrivateItem(item)) return false; return super.PredictiveTakeEntityToTargetAttachmentEx(target, item, slot); }
	override bool PredictiveTakeToDst(notnull InventoryLocation src, notnull InventoryLocation dst) { if (src.GetItem() && !CanLootPrivateItem(src.GetItem())) return false; return super.PredictiveTakeToDst(src, dst); }
	override protected bool TakeToDstImpl(InventoryMode mode, notnull InventoryLocation src, notnull InventoryLocation dst) { if (dst.GetItem() && !CanLootPrivateItem(dst.GetItem())) return false; return super.TakeToDstImpl(mode, src, dst); }
	override protected bool TakeEntityAsAttachmentImpl(InventoryMode mode, notnull EntityAI item) { if (!CanLootPrivateItem(item)) return false; return super.TakeEntityAsAttachmentImpl(mode, item); }
}