class PNH_VipManager
{
	private static ref PNH_VipManager m_Instance;

	// Caminhos declarados de forma absoluta para o compilador do DayZ aceitar
	const string CONFIG_FOLDER = "$profile:PNH/Vips/";
	const string CONFIG_PATH = "$profile:PNH/Vips/PNH_Vip_Config.json";

	ref PNH_VipConfig m_Config;

	// Mapas de acesso rápido na memória (UID -> Valor)
	ref map<string, string> m_ActiveVIPs;
	ref map<string, ref array<string>> m_ActivePrivateItems;
	ref map<string, bool> m_SkinPanelAccess;
	ref map<string, bool> m_QueuePriority;
	ref map<string, string> m_VipExpirationDates;

	void PNH_VipManager()
	{
		m_ActiveVIPs = new map<string, string>;
		m_ActivePrivateItems = new map<string, ref array<string>>;
		m_SkinPanelAccess = new map<string, bool>;
		m_QueuePriority = new map<string, bool>;
		m_VipExpirationDates = new map<string, string>;
		
		LoadConfig();
	}

	static PNH_VipManager GetInstance()
	{
		if (!m_Instance)
		{
			m_Instance = new PNH_VipManager();
		}
		return m_Instance;
	}

	void LoadConfig()
	{
		if (!FileExist(CONFIG_FOLDER))
		{
			MakeDirectory(CONFIG_FOLDER);
		}

		m_Config = new PNH_VipConfig();

		// Se o ficheiro não existir, criamos um de exemplo para o dono do servidor
		if (!FileExist(CONFIG_PATH))
		{
			CreateDefaultConfig();
			JsonFileLoader<PNH_VipConfig>.JsonSaveFile(CONFIG_PATH, m_Config);
			PNH_Logger.Log("VIP_System", "Novo ficheiro PNH_Vip_Config.json gerado!");
		}
		else
		{
			JsonFileLoader<PNH_VipConfig>.JsonLoadFile(CONFIG_PATH, m_Config);
		}

		ProcessConfig();
	}

	void CreateDefaultConfig()
	{
		// Exemplo de Tier
		PNH_VipTierData bronze = new PNH_VipTierData();
		bronze.FilaPrioridade = false;
		bronze.AcessoSkinPanel = false;
		bronze.RoupasEItens.Insert("AP_jacket_swat_3");
		m_Config.Sistema_VIP.Categorias.Insert("VIPBRONZE", bronze);

		PNH_VipTierData gold = new PNH_VipTierData();
		gold.FilaPrioridade = true;
		gold.AcessoSkinPanel = true;
		gold.RoupasEItens.Insert("GhillieSuit_Woodland");
		m_Config.Sistema_VIP.Categorias.Insert("VIPGOLD", gold);

		// Exemplo de Jogador VIP
		PNH_VipPlayerData p1 = new PNH_VipPlayerData();
		p1.Nome = "Pinheiro";
		p1.Steam64ID = "76561198000000000";
		p1.Categoria = "VIPGOLD";
		p1.DataVencimento = "20/06/2026";
		m_Config.Sistema_VIP.JogadoresAtivos.Insert(p1);

		// Exemplo de Pacote Privado
		PNH_VipPackageData pack1 = new PNH_VipPackageData();
		pack1.NomeDoPacote = "PACOTE_ASSAULT";
		pack1.AcessoSkinPanel = true;
		pack1.ItensPermitidos.Insert("M4A1");
		
		PNH_VipDonatorData d1 = new PNH_VipDonatorData();
		d1.Nome = "JogadorExemplo";
		d1.Steam64ID = "76561198111111111";
		d1.DataVencimento = "15/08/2026";
		pack1.DoadoresAtivos.Insert(d1);

		m_Config.Sistema_ItensPrivados.Insert(pack1);
	}

	void ProcessConfig()
	{
		// Limpar a memória antes de recarregar
		m_ActiveVIPs.Clear();
		m_ActivePrivateItems.Clear();
		m_SkinPanelAccess.Clear();
		m_QueuePriority.Clear();
		m_VipExpirationDates.Clear();

		int currentYear, currentMonth, currentDay;
		GetYearMonthDayUTC(currentYear, currentMonth, currentDay);

		// 1. PROCESSAR VIPS
		if (m_Config.Sistema_VIP && m_Config.Sistema_VIP.JogadoresAtivos)
		{
			foreach (PNH_VipPlayerData player : m_Config.Sistema_VIP.JogadoresAtivos)
			{
				if (IsDateExpired(player.DataVencimento, currentYear, currentMonth, currentDay))
				{
					PNH_Logger.Log("VIP_System", "VIP Expirado! Jogador: " + player.Nome + " (" + player.Steam64ID + ") Vencimento: " + player.DataVencimento);
					continue;
				}

				// Registra na memória o VIP Válido
				m_ActiveVIPs.Insert(player.Steam64ID, player.Categoria);
				m_VipExpirationDates.Insert(player.Steam64ID, player.DataVencimento);

				PNH_VipTierData tierData = m_Config.Sistema_VIP.Categorias.Get(player.Categoria);
				if (tierData)
				{
					if (tierData.FilaPrioridade) m_QueuePriority.Insert(player.Steam64ID, true);
					if (tierData.AcessoSkinPanel) m_SkinPanelAccess.Insert(player.Steam64ID, true);
				}
			}
		}

		// 2. PROCESSAR ITENS PRIVADOS
		if (m_Config.Sistema_ItensPrivados)
		{
			foreach (PNH_VipPackageData package : m_Config.Sistema_ItensPrivados)
			{
				foreach (PNH_VipDonatorData donator : package.DoadoresAtivos)
				{
					if (IsDateExpired(donator.DataVencimento, currentYear, currentMonth, currentDay))
					{
						PNH_Logger.Log("VIP_System", "Pacote Privado Expirado! Jogador: " + donator.Nome + " (" + donator.Steam64ID + ")");
						continue;
					}

					// Adiciona os itens permitidos à lista pessoal deste jogador
					array<string> currentAllowed;
					if (!m_ActivePrivateItems.Find(donator.Steam64ID, currentAllowed))
					{
						currentAllowed = new array<string>;
						m_ActivePrivateItems.Insert(donator.Steam64ID, currentAllowed);
					}

					foreach (string item : package.ItensPermitidos)
					{
						if (currentAllowed.Find(item) == -1) // Evita itens duplicados na memória
						{
							currentAllowed.Insert(item);
						}
					}

					// Libera o painel de skins se o pacote avulso permitir
					if (package.AcessoSkinPanel)
					{
						m_SkinPanelAccess.Insert(donator.Steam64ID, true);
					}
				}
			}
		}
		
		PNH_Logger.Log("VIP_System", "Ficheiro JSON lido e UIDs validados com sucesso na memoria.");
	}

	bool IsDateExpired(string expDateStr, int curYear, int curMonth, int curDay)
	{
		array<string> dateParts = new array<string>;
		expDateStr.Split("/", dateParts);
		
		if (dateParts.Count() != 3) return true; // Formato inválido é ignorado por segurança
		
		int expDay = dateParts[0].ToInt();
		int expMonth = dateParts[1].ToInt();
		int expYear = dateParts[2].ToInt();

		if (curYear > expYear) return true;
		if (curYear == expYear && curMonth > expMonth) return true;
		if (curYear == expYear && curMonth == expMonth && curDay > expDay) return true;

		return false;
	}

	// ==========================================
	// GETTERS PARA SEREM USADOS NO PLAYERBASE
	// ==========================================

	bool IsVip(string uid)
	{
		return m_ActiveVIPs.Contains(uid);
	}

	bool HasQueuePriority(string uid)
	{
		return m_QueuePriority.Contains(uid);
	}

	bool HasSkinPanelAccess(string uid)
	{
		return m_SkinPanelAccess.Contains(uid);
	}

	string GetVipExpirationDate(string uid)
	{
		string date;
		if (m_VipExpirationDates.Find(uid, date))
		{
			return date;
		}
		return "";
	}

	string GetVipTier(string uid)
	{
		string tier;
		if (m_ActiveVIPs.Find(uid, tier))
		{
			return tier;
		}
		return "";
	}

	array<string> GetVipClothing(string uid)
	{
		string tier = GetVipTier(uid);
		if (tier != "")
		{
			PNH_VipTierData tierData = m_Config.Sistema_VIP.Categorias.Get(tier);
			if (tierData)
			{
				return tierData.RoupasEItens;
			}
		}
		return null;
	}

	array<string> GetPrivateItems(string uid)
	{
		array<string> items;
		if (m_ActivePrivateItems.Find(uid, items))
		{
			return items;
		}
		return new array<string>;
	}

    // Nova função para gerar uma lista mestra de todos os itens restritos
	bool IsItemRestrictedGlobally(string itemName)
	{
		if (m_Config && m_Config.Sistema_ItensPrivados)
		{
			foreach (PNH_VipPackageData package : m_Config.Sistema_ItensPrivados)
			{
				if (package.ItensPermitidos && package.ItensPermitidos.Find(itemName) != -1)
				{
					return true;
				}
			}
		}
		return false;
	}
}