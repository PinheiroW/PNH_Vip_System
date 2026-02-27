// ==========================================
// CLASSES DE DADOS PARA O JSON - SISTEMA VIP
// ==========================================

class PNH_VipTierData
{
	bool FilaPrioridade;
	bool AcessoSkinPanel;
	ref array<string> RoupasEItens;

	void PNH_VipTierData()
	{
		RoupasEItens = new array<string>;
	}
}

class PNH_VipPlayerData
{
	string Nome;
	string Steam64ID;
	string Categoria;
	string DataVencimento;
}

class PNH_VipSystemData
{
	ref map<string, ref PNH_VipTierData> Categorias;
	ref array<ref PNH_VipPlayerData> JogadoresAtivos;

	void PNH_VipSystemData()
	{
		Categorias = new map<string, ref PNH_VipTierData>;
		JogadoresAtivos = new array<ref PNH_VipPlayerData>;
	}
}

// ===================================================
// CLASSES DE DADOS PARA O JSON - SISTEMA ITENS PRIVADOS
// ===================================================

class PNH_VipDonatorData
{
	string Nome;
	string Steam64ID;
	string DataVencimento;
}

class PNH_VipPackageData
{
	string NomeDoPacote;
	bool AcessoSkinPanel;
	ref array<string> ItensPermitidos;
	ref array<ref PNH_VipDonatorData> DoadoresAtivos;

	void PNH_VipPackageData()
	{
		ItensPermitidos = new array<string>;
		DoadoresAtivos = new array<ref PNH_VipDonatorData>;
	}
}

// ==========================================
// ARQUIVO JSON PRINCIPAL (ALL-IN-ONE)
// ==========================================

class PNH_VipConfig
{
	ref PNH_VipSystemData Sistema_VIP;
	ref array<ref PNH_VipPackageData> Sistema_ItensPrivados;

	void PNH_VipConfig()
	{
		Sistema_VIP = new PNH_VipSystemData;
		Sistema_ItensPrivados = new array<ref PNH_VipPackageData>;
	}
}