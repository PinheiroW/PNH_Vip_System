modded class PlayerBase extends ManBase
{	
	// ==========================================
	// SISTEMA DE BLOQUEIO DE ITENS PRIVADOS
	// ==========================================

	// Função auxiliar centralizada para validar permissão
	bool CanLootPrivateItem(EntityAI item)
	{
		// O bloqueio é sempre validado com autoridade do servidor
		if (!GetGame().IsServer() || !item || !GetIdentity()) return true;

		string itemName = item.GetType();
		string uid = GetIdentity().GetId();

		// Verifica se o item clicado está na lista global de itens bloqueados
		if (PNH_VipManager.GetInstance().IsItemRestrictedGlobally(itemName))
		{
			// Se estiver bloqueado, verifica se ESTE jogador tem permissão
			array<string> allowedItems = PNH_VipManager.GetInstance().GetPrivateItems(uid);
			
			if (allowedItems && allowedItems.Find(itemName) != -1)
			{
				return true; // Tem permissão!
			}
			
			// Se chegou aqui, é porque o item é restrito e o cara não tem permissão
			return false; 
		}

		// Se o item não está na lista global de restrições, qualquer um pode pegar
		return true; 
	}

	override void PredictiveTakeEntityToHands(EntityAI item)
	{		
		if (!CanLootPrivateItem(item)) return; // BLOQUEIA
		super.PredictiveTakeEntityToHands(item);
	}	
	
	override bool PredictiveTakeEntityToTargetAttachmentEx(notnull EntityAI target, notnull EntityAI item, int slot)
	{				
		if (!CanLootPrivateItem(item)) return false; // BLOQUEIA
		return super.PredictiveTakeEntityToTargetAttachmentEx(target, item, slot);
	}
	
	override bool PredictiveTakeToDst(notnull InventoryLocation src, notnull InventoryLocation dst)
	{
		EntityAI item = src.GetItem();
		if (item && !CanLootPrivateItem(item)) return false; // BLOQUEIA
		
		return super.PredictiveTakeToDst(src, dst);
	}
	
	override protected bool TakeToDstImpl(InventoryMode mode, notnull InventoryLocation src, notnull InventoryLocation dst)
	{				
		if (dst.GetItem() && !CanLootPrivateItem(dst.GetItem())) return false; // BLOQUEIA
		return super.TakeToDstImpl(mode, src, dst);
	}	
	
	override protected bool TakeEntityAsAttachmentImpl(InventoryMode mode, notnull EntityAI item)
	{			
		if (!CanLootPrivateItem(item)) return false; // BLOQUEIA
		return super.TakeEntityAsAttachmentImpl(mode, item);
	}	
	
	override bool PredictiveSwapEntities(notnull EntityAI item1, notnull EntityAI item2)
	{
		if (!CanLootPrivateItem(item1) || !CanLootPrivateItem(item2)) return false; // BLOQUEIA
		return super.PredictiveSwapEntities(item1, item2);
	}
		
	override bool PredictiveForceSwapEntities(notnull EntityAI item1, notnull EntityAI item2, notnull InventoryLocation item2_dst)
	{
		if (!CanLootPrivateItem(item1)) return false; // BLOQUEIA
		return super.PredictiveForceSwapEntities(item1, item2, item2_dst);
	}		
}