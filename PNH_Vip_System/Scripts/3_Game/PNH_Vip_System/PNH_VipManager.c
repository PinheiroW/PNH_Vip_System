class PNH_VipManager
{
	private static ref PNH_VipManager m_Instance;
	const string CONFIG_FOLDER = "$profile:PNH/Vips/";
	const string CONFIG_PATH = "$profile:PNH/Vips/PNH_Vip_Config.json";

	ref PNH_VipConfig m_Config;
	ref map<string, string> m_ActiveVIPs;
	ref map<string, ref array<string>> m_ActivePrivateItems;
	ref map<string, bool> m_SkinPanelAccess;
	ref map<string, bool> m_QueuePriority;
	ref map<string, string> m_VipExpirationDates;
	ref array<string> m_GlobalRestrictedItems;

	void PNH_VipManager()
	{
		m_ActiveVIPs = new map<string, string>;
		m_ActivePrivateItems = new map<string, ref array<string>>;
		m_SkinPanelAccess = new map<string, bool>;
		m_QueuePriority = new map<string, bool>;
		m_VipExpirationDates = new map<string, string>;
		m_GlobalRestrictedItems = new array<string>;
		LoadConfig();
	}

	static PNH_VipManager GetInstance()
	{
		if (!m_Instance) m_Instance = new PNH_VipManager();
		return m_Instance;
	}

	void LoadConfig()
	{
		if (!FileExist(CONFIG_FOLDER)) MakeDirectory(CONFIG_FOLDER);
		m_Config = new PNH_VipConfig();
		if (!FileExist(CONFIG_PATH))
		{
			CreateDefaultConfig();
			JsonFileLoader<PNH_VipConfig>.JsonSaveFile(CONFIG_PATH, m_Config);
		}
		else
		{
			JsonFileLoader<PNH_VipConfig>.JsonLoadFile(CONFIG_PATH, m_Config);
		}
		ProcessConfig();
	}

	void CreateDefaultConfig()
	{
		PNH_VipTierData gold = new PNH_VipTierData();
		gold.FilaPrioridade = true;
		gold.AcessoSkinPanel = true;
		gold.RoupasEItens.Insert("GhillieSuit_Woodland");
		m_Config.Sistema_VIP.Categorias.Insert("VIPGOLD", gold);

		PNH_VipPlayerData p1 = new PNH_VipPlayerData();
		p1.Nome = "Pinheiro";
		p1.Steam64ID = "76561198000000000";
		p1.Categoria = "VIPGOLD";
		p1.DataVencimento = "20/06/2026";
		m_Config.Sistema_VIP.JogadoresAtivos.Insert(p1);

		PNH_VipPackageData pack1 = new PNH_VipPackageData();
		pack1.NomeDoPacote = "PACOTE_ASSAULT";
		pack1.AcessoSkinPanel = true;
		pack1.ItensPermitidos.Insert("M4A1");
		
		PNH_VipDonatorData d1 = new PNH_VipDonatorData();
		d1.Nome = "Pinheiro";
		d1.Steam64ID = "76561198000000000";
		d1.DataVencimento = "20/06/2026";
		pack1.DoadoresAtivos.Insert(d1);
		m_Config.Sistema_ItensPrivados.Insert(pack1);
	}

	void ProcessConfig()
	{
		m_ActiveVIPs.Clear();
		m_ActivePrivateItems.Clear();
		m_SkinPanelAccess.Clear();
		m_QueuePriority.Clear();
		m_VipExpirationDates.Clear();
		m_GlobalRestrictedItems.Clear();

		int cY, cM, cD;
		GetYearMonthDayUTC(cY, cM, cD);

		if (m_Config.Sistema_VIP && m_Config.Sistema_VIP.JogadoresAtivos)
		{
			foreach (PNH_VipPlayerData player : m_Config.Sistema_VIP.JogadoresAtivos)
			{
				string uid = player.Steam64ID;
				uid.Trim();

				if (IsDateExpired(player.DataVencimento, cY, cM, cD)) continue;
				
				m_ActiveVIPs.Insert(uid, player.Categoria);
				m_VipExpirationDates.Insert(uid, player.DataVencimento);
				
				PNH_VipTierData tier = m_Config.Sistema_VIP.Categorias.Get(player.Categoria);
				if (tier)
				{
					if (tier.FilaPrioridade) m_QueuePriority.Insert(uid, true);
					if (tier.AcessoSkinPanel) m_SkinPanelAccess.Insert(uid, true);
				}
			}
		}

		if (m_Config.Sistema_ItensPrivados)
		{
			foreach (PNH_VipPackageData package : m_Config.Sistema_ItensPrivados)
			{
				foreach (string restricted : package.ItensPermitidos)
				{
					string lowItem = restricted;
					lowItem.ToLower();
					if (m_GlobalRestrictedItems.Find(lowItem) == -1) m_GlobalRestrictedItems.Insert(lowItem);
				}

				foreach (PNH_VipDonatorData donator : package.DoadoresAtivos)
				{
					string dUID = donator.Steam64ID;
					dUID.Trim();

					if (IsDateExpired(donator.DataVencimento, cY, cM, cD)) continue;
					
					array<string> allowed;
					if (!m_ActivePrivateItems.Find(dUID, allowed))
					{
						allowed = new array<string>;
						m_ActivePrivateItems.Insert(dUID, allowed);
					}
					foreach (string item : package.ItensPermitidos)
					{
						string lowAllowed = item;
						lowAllowed.ToLower();
						if (allowed.Find(lowAllowed) == -1) allowed.Insert(lowAllowed);
					}
					if (package.AcessoSkinPanel) m_SkinPanelAccess.Insert(dUID, true);
				}
			}
		}
	}

	bool IsDateExpired(string dateStr, int cY, int cM, int cD)
	{
		array<string> p = new array<string>;
		dateStr.Split("/", p);
		if (p.Count() != 3) return true;
		int eD = p[0].ToInt(); int eM = p[1].ToInt(); int eY = p[2].ToInt();
		
		if (cY > eY) return true;
		if (cY == eY && cM > eM) return true;
		if (cY == eY && cM == eM && cD > eD) return true;
		return false;
	}

	bool IsVip(string uid) { return m_ActiveVIPs.Contains(uid); }
	bool HasSkinPanelAccess(string uid) { return m_SkinPanelAccess.Contains(uid); }
	string GetVipExpirationDate(string uid) { string d; m_VipExpirationDates.Find(uid, d); return d; }
	string GetVipTier(string uid) { string t; m_ActiveVIPs.Find(uid, t); return t; }
	
	array<string> GetVipClothing(string uid) {
		string t = GetVipTier(uid);
		if (t != "") {
			PNH_VipTierData td = m_Config.Sistema_VIP.Categorias.Get(t);
			if (td) return td.RoupasEItens;
		}
		return null;
	}

	array<string> GetPrivateItems(string uid) {
		array<string> items;
		if (m_ActivePrivateItems.Find(uid, items)) return items;
		return new array<string>;
	}

	array<string> GetGlobalRestrictedList() { return m_GlobalRestrictedItems; }
}