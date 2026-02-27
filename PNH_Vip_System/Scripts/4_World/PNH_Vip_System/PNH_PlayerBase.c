modded class PlayerBase
{	
	ref array<string> m_LocalRestrictedList;
	ref array<string> m_LocalAllowedItems;

	void PlayerBase()
	{
		m_LocalRestrictedList = new array<string>;
		m_LocalAllowedItems = new array<string>;
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (GetGame().IsClient() && rpc_type == 99955)
		{
			Param2<ref array<string>, ref array<string>> data = new Param2<ref array<string>, ref array<string>>(null, null);
			if (!ctx.Read(data)) return;
			m_LocalRestrictedList.Clear();
			m_LocalAllowedItems.Clear();
			m_LocalRestrictedList = data.param1;
			m_LocalAllowedItems = data.param2;
		}
	}

	bool CanLootPrivateItem(EntityAI item)
	{
		if (!item) return true;
		string itemName = item.GetType();
		itemName.ToLower();
		if (m_LocalRestrictedList && m_LocalRestrictedList.Find(itemName) != -1)
		{
			if (m_LocalAllowedItems && m_LocalAllowedItems.Find(itemName) != -1) return true;
			return false; 
		}
		return true;
	}

	override void PredictiveTakeEntityToHands(EntityAI item) 
	{ 
		if (!CanLootPrivateItem(item)) return; 
		super.PredictiveTakeEntityToHands(item); 
	}
	
	override bool PredictiveTakeEntityToTargetAttachmentEx(notnull EntityAI target, notnull EntityAI item, int slot) 
	{ 
		if (!CanLootPrivateItem(item)) return false; 
		return super.PredictiveTakeEntityToTargetAttachmentEx(target, item, slot); 
	}
	
	override bool PredictiveTakeToDst(notnull InventoryLocation src, notnull InventoryLocation dst) 
	{ 
		if (src.GetItem() && !CanLootPrivateItem(src.GetItem())) return false; 
		return super.PredictiveTakeToDst(src, dst); 
	}
	
	override protected bool TakeToDstImpl(InventoryMode mode, notnull InventoryLocation src, notnull InventoryLocation dst) 
	{ 
		if (dst.GetItem() && !CanLootPrivateItem(dst.GetItem())) return false; 
		return super.TakeToDstImpl(mode, src, dst); 
	}
	
	override protected bool TakeEntityAsAttachmentImpl(InventoryMode mode, notnull EntityAI item) 
	{ 
		if (!CanLootPrivateItem(item)) return false; 
		return super.TakeEntityAsAttachmentImpl(mode, item); 
	}
}