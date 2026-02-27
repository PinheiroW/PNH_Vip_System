modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();

		// Inicia o PNH_VipManager no arranque do servidor.
		// Isto vai forçar a leitura e a criação da pasta e do JSON.
		PNH_VipManager.GetInstance();
	}
}