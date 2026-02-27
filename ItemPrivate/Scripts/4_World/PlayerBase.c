modded class PlayerBase extends ManBase
{	
	ref array<string> ItemsList;
	ref array<string> ItemsPrivate;		
	int m_RefreshPrivateItem;
	
	void PlayerBase()
	{		
		ItemsList = new array<string>;	
		ItemsPrivate = new array<string>;	
	}	
	
	override void Init()
	{
		super.Init();			
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckItemPrivateInventory, m_RefreshPrivateItem * 1000, true);
	}
	
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx){
		super.OnRPC(sender, rpc_type, ctx);			
		if(GetGame().IsClient()){			
			if (rpc_type == -25656465589){				
				Param2<ref array<string>, int> LItem;
				if (!ctx.Read(LItem)) return;				
				SetListItemsPrivate(LItem.param1, LItem.param2);										
			}			
			if (rpc_type == -23654665568){				
				Param1<ref array<string>> data;
				if (!ctx.Read(data)) return;				
				SetPermissionItemPrivate(data.param1);						
			}		
		}
	}
		
	void SetPermissionItemPrivate(ref array<string> List)
	{
		ItemsPrivate = List;		
		SetSynchDirty();
	}		
	
	void SetListItemsPrivate(ref array<string> Items, int TimeRefresh)
	{
		ItemsList = Items;
		m_RefreshPrivateItem = TimeRefresh;
		SetSynchDirty();
	}
	
	override void PredictiveTakeEntityToHands(EntityAI item){		
		if( ItemsList.Find(item.GetType()) >= 0 )	
		{
			if(ItemsPrivate.Find(item.GetType()) >= 0)				
				super.PredictiveTakeEntityToHands(item);
			
			return;
		}		
		super.PredictiveTakeEntityToHands(item); //ADD MAO
	}	
	
	override bool PredictiveTakeEntityToTargetAttachmentEx (notnull EntityAI target, notnull EntityAI item, int slot){				
		if( ItemsList.Find(item.GetType()) >= 0 )
		{
			if(ItemsPrivate.Find(item.GetType()) >= 0)				
				return super.PredictiveTakeEntityToTargetAttachmentEx(target, item,slot);

			return false;
		}		
		return super.PredictiveTakeEntityToTargetAttachmentEx(target, item,slot); //ADD SLOT
	}
	
	override bool PredictiveTakeToDst(notnull InventoryLocation src, notnull InventoryLocation dst)
{
    EntityAI item = src.GetItem();
    
    if (ItemsList.Find(item.GetType()) >= 0)
    {
        if (ItemsPrivate.Find(item.GetType()) >= 0)
        {
            // Verifica se o jogador está incapacitado (amarrado ou desmaiado)
            if (IsIncapacitated())
            {
                // Impede o jogador de usar o item se estiver incapacitado
                return false;
            }
            
            return super.PredictiveTakeToDst(src, dst);
        }

        return false;
    }
    
    return super.PredictiveTakeToDst(src, dst);
}

// Verifica se o jogador está incapacitado (amarrado ou desmaiado)
bool IsIncapacitated()
{
    return IsRestrained() || IsUnconscious();
}

	
	override protected bool TakeToDstImpl(InventoryMode mode, notnull InventoryLocation src, notnull InventoryLocation dst){				
		if( ItemsList.Find(dst.GetItem().GetType()) >= 0 )
		{
			if(ItemsPrivate.Find(dst.GetItem().GetType()) >= 0)			
				return super.TakeToDstImpl(mode, src, dst);
			
			return false;
		}
		return super.TakeToDstImpl(mode, src, dst); //ADD INVENTARIO
	}	
	
	override protected bool TakeEntityAsAttachmentImpl(InventoryMode mode, notnull EntityAI item)
	{			
		if( ItemsList.Find(item.GetType()) >= 0 )	
		{
			if(ItemsPrivate.Find(item.GetType()) >= 0)			
				return super.TakeEntityAsAttachmentImpl(mode, item);
			
			return false;
		}
		return super.TakeEntityAsAttachmentImpl(mode, item);//ADD PROCURA SLOT		
	}	
	
	override bool PredictiveSwapEntities (notnull EntityAI item1, notnull EntityAI item2)
	{
		if( ItemsList.Find(item1.GetType()) >= 0 || ItemsList.Find(item2.GetType()) >= 0 )	
		{
			if(ItemsPrivate.Find(item1.GetType()) < 0) return false;
			if(ItemsPrivate.Find(item2.GetType()) < 0) return false;
			return super.PredictiveSwapEntities(item1, item2);
		}
		return super.PredictiveSwapEntities(item1, item2); //TROCAR ITEM DE LUGAR INVENTARIO
	}
		
	
	override bool PredictiveForceSwapEntities (notnull EntityAI item1, notnull EntityAI item2, notnull InventoryLocation item2_dst)
	{
		if( ItemsList.Find(item1.GetType()) >= 0 )	
		{
			if(ItemsPrivate.Find(item1.GetType()) >= 0)			
				return super.PredictiveForceSwapEntities(item1, item2, item2_dst);
			
			return false;
		}
		return super.PredictiveForceSwapEntities(item1, item2, item2_dst);//TROCAR ITEM DE LUGAR MAO
	}		
		
	void CheckItemPrivateInventory() // FUNÇÃO PARA DROPAR O ITEM DO INVENTÁRIO OU EM MÃOS CASO O PLAYER NÃO TENHA PERMISSÃO ATIVA (OBS: DESATIVADO POIS ESTAVA COM BUG TODA VEZ QUE O PLAYER LOGAVA DROPAVA OS ITEM NO CHÃO)
	{				
		/*GameInventory inv = PlayerBase.Cast(this).GetInventory();
		array<EntityAI> items = new array<EntityAI>;
		inv.EnumerateInventory(InventoryTraversalType.INORDER, items);
		inv.EnumerateInventory(InventoryTraversalType.LEVELORDER, items);
		for (int i = 0; i < items.Count(); i++){
			ItemBase item = ItemBase.Cast(items.Get(i));			
			if (item){
				if( ItemsList.Find(item.GetType()) >= 0 ){				
					if(ItemsPrivate.Find(item.GetType()) >= 0)							
						return;
					
					DropItem(item);
				}	
			}
		}
		ItemBase item_in_hands = ItemBase.Cast(GetHumanInventory().GetEntityInHands());		
		if (item_in_hands)
		{
			if( ItemsList.Find(item_in_hands.GetType()) >= 0 )	
			{				
				if(ItemsPrivate.Find(item_in_hands.GetType()) >= 0)				
					return;
				
				DropItem(item_in_hands);
			}	
		}*/
	}	
}