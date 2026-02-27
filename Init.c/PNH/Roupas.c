void EquipmentRoupas(PlayerBase player, int Roupas)
{	
	player.ClearInventory();
	
	EntityAI Capacete; //CAPACETE
	EntityAI Blusa; //BLUSA
	EntityAI Calca; //CALÇA
	EntityAI Bota; //BOTA
	EntityAI Mochila; //MOCHILA
	EntityAI MochilaColete; //MOCHILA
	EntityAI Colete; //COLETE		
	EntityAI Cinto; //CINTO		
	EntityAI Lanterna; //LANTERNA 
	EntityAI Coldre; //COLDRE
	EntityAI Visor; //VISOR
	EntityAI Range; //TELEMETRO	
	EntityAI Walktalk; //RADIO
	EntityAI Melee; //ARMA BRANCA
	EntityAI NVG; //ARMA BRANCA
	EntityAI Chapeu;	
	
	switch(Roupas)
	{
		case 0 :
			//VIPBRONZE
			player.GetInventory().CreateInInventory("AP_jacket_swat_3");
			player.GetInventory().CreateInInventory("HuntingBag_VIP_Bronze_InfernalZ");
			player.GetInventory().CreateInInventory("AP_pants_swat_3");
			player.GetInventory().CreateInInventory("AP_mask_azrael");
			player.GetInventory().CreateInInventory("AP_gloves_leather");
			player.GetInventory().CreateInInventory("AP_boots_lowa_black");
			player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
			player.GetInventory().CreateInInventory("WaterBottle");
			player.GetInventory().CreateInInventory("BandageDressing");
			player.GetInventory().CreateInInventory("Battery9V");
			player.GetInventory().CreateInInventory("FangeKnife");
			player.GetInventory().CreateInInventory("LeatherSewingKit");
			player.GetInventory().CreateInInventory("SewingKit");
			Cinto = player.GetInventory().CreateInInventory("AP_belt_swat");
			Colete = player.GetInventory().CreateInInventory("AP_vest_swat_para");
			Capacete = player.GetInventory().CreateInInventory("AP_helm_mich_T1_black");	
			break;
	
		case 1 :
			//VIPPRATA	
			player.GetInventory().CreateInInventory("AP_jacket_swat_3");
			player.GetInventory().CreateInInventory("HuntingBag_VIP_Prata_InfernalZ");
			player.GetInventory().CreateInInventory("AP_pants_swat_3");
			player.GetInventory().CreateInInventory("AP_mask_azrael");
			player.GetInventory().CreateInInventory("AP_gloves_leather");
			player.GetInventory().CreateInInventory("AP_boots_lowa_black");
			player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
			player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
			player.GetInventory().CreateInInventory("WaterBottle");
			player.GetInventory().CreateInInventory("BandageDressing");
			player.GetInventory().CreateInInventory("BandageDressing");
			player.GetInventory().CreateInInventory("Battery9V");
			player.GetInventory().CreateInInventory("FangeKnife");
			player.GetInventory().CreateInInventory("LeatherSewingKit");
			player.GetInventory().CreateInInventory("SewingKit");
			Cinto = player.GetInventory().CreateInInventory("AP_belt_swat");
			Colete = player.GetInventory().CreateInInventory("AP_vest_swat_para");
			Capacete = player.GetInventory().CreateInInventory("AP_helm_mich_T1_black");
			break;

		case 2 :
			//VIPGOLD	
			player.GetInventory().CreateInInventory("MMG_operatorshirt_black");
			player.GetInventory().CreateInInventory("HuntingBag_VIP_Gold_InfernalZ");
			player.GetInventory().CreateInInventory("mmg_tactical_pants_black");
			player.GetInventory().CreateInInventory("MMG_facemask_skull");
			player.GetInventory().CreateInInventory("mmg_tac_goggles_red_black");
			player.GetInventory().CreateInInventory("mmg_tactical_gloves_black");
			player.GetInventory().CreateInInventory("MMG_boots_black");
			player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
			player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
			player.GetInventory().CreateInInventory("WaterBottle");
			player.GetInventory().CreateInInventory("BandageDressing");
			player.GetInventory().CreateInInventory("BandageDressing");
			player.GetInventory().CreateInInventory("Battery9V");
			player.GetInventory().CreateInInventory("LeatherSewingKit");
			player.GetInventory().CreateInInventory("SewingKit");
			player.GetInventory().CreateInInventory("Morphine");
			player.GetInventory().CreateInInventory("VitaminBottle");
			player.GetInventory().CreateInInventory("TetracyclineAntibiotics");
			player.GetInventory().CreateInInventory("PainkillerTablets");
			player.GetInventory().CreateInInventory("SalineBagIV");
			player.GetInventory().CreateInInventory("FangeKnife");
			player.GetInventory().CreateInInventory("AP_hood_azrael");
			player.GetInventory().CreateInInventory("GhillieSuit_Woodland");
			player.GetInventory().CreateInInventory("GhillieHood_Woodland");
			Cinto = player.GetInventory().CreateInInventory("mmg_cargobelt_black");
			Capacete = player.GetInventory().CreateInInventory("MMG_tactical_helmet_black");	
			NVG = Capacete.GetInventory().CreateAttachment("mmg_gp_nvg_black");
			NVG.GetInventory().CreateAttachment("Battery9V");	
			break;
			
		case 3 :	
			//VIPPLATINA
			player.GetInventory().CreateInInventory("MMG_operatorshirt_black");
			player.GetInventory().CreateInInventory("HuntingBag_VIP_Gold_InfernalZ");
			player.GetInventory().CreateInInventory("mmg_tactical_pants_black");
			player.GetInventory().CreateInInventory("MMG_facemask_skull");
			player.GetInventory().CreateInInventory("mmg_tac_goggles_red_black");
			player.GetInventory().CreateInInventory("mmg_tactical_gloves_black");
			player.GetInventory().CreateInInventory("MMG_boots_black");
			player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
			player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
			player.GetInventory().CreateInInventory("WaterBottle");
			player.GetInventory().CreateInInventory("BandageDressing");
			player.GetInventory().CreateInInventory("BandageDressing");
			player.GetInventory().CreateInInventory("Battery9V");
			player.GetInventory().CreateInInventory("LeatherSewingKit");
			player.GetInventory().CreateInInventory("SewingKit");
			player.GetInventory().CreateInInventory("Morphine");
			player.GetInventory().CreateInInventory("VitaminBottle");
			player.GetInventory().CreateInInventory("TetracyclineAntibiotics");
			player.GetInventory().CreateInInventory("PainkillerTablets");
			player.GetInventory().CreateInInventory("SalineBagIV");
			player.GetInventory().CreateInInventory("FangeKnife");
			player.GetInventory().CreateInInventory("AP_hood_azrael");
			player.GetInventory().CreateInInventory("GhillieSuit_Woodland");
			player.GetInventory().CreateInInventory("GhillieHood_Woodland");
			Cinto = player.GetInventory().CreateInInventory("mmg_cargobelt_black");
			Capacete = player.GetInventory().CreateInInventory("MMG_tactical_helmet_black");	
			NVG = Capacete.GetInventory().CreateAttachment("mmg_gp_nvg_black");
			NVG.GetInventory().CreateAttachment("Battery9V");	
			break;
			
		case 4 :	
			//VIPESMERALDA		
			player.GetInventory().CreateInInventory("AP_jacket_swat_3");
			player.GetInventory().CreateInInventory("HuntingBag_VIP_Gold_InfernalZ");
			player.GetInventory().CreateInInventory("AP_pants_swat_3");
			player.GetInventory().CreateInInventory("AP_mask_azrael");
			player.GetInventory().CreateInInventory("TacticalGoggles");
			player.GetInventory().CreateInInventory("AP_gloves_leather");
			player.GetInventory().CreateInInventory("AP_boots_lowa_black");
			player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
			player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
			player.GetInventory().CreateInInventory("WaterBottle");
			player.GetInventory().CreateInInventory("BandageDressing");
			player.GetInventory().CreateInInventory("BandageDressing");
			player.GetInventory().CreateInInventory("Battery9V");
			player.GetInventory().CreateInInventory("LeatherSewingKit");
			player.GetInventory().CreateInInventory("SewingKit");
			player.GetInventory().CreateInInventory("Morphine");
			player.GetInventory().CreateInInventory("VitaminBottle");
			player.GetInventory().CreateInInventory("TetracyclineAntibiotics");
			player.GetInventory().CreateInInventory("PainkillerTablets");
			player.GetInventory().CreateInInventory("SalineBagIV");
			player.GetInventory().CreateInInventory("FangeKnife");
			player.GetInventory().CreateInInventory("GhillieSuit_Woodland");
			player.GetInventory().CreateInInventory("GhillieHood_Woodland");
			Cinto = player.GetInventory().CreateInInventory("AP_belt_swat");
			Colete = player.GetInventory().CreateInInventory("AP_vest_swat_para");
			Capacete = player.GetInventory().CreateInInventory("NVGHeadstrap");	
			NVG = Capacete.GetInventory().CreateAttachment("NVGoggles");
			NVG.GetInventory().CreateAttachment("Battery9V");	
			break;
	}
		
	//ITENS PARA TODOS OS PRESETS (CASO QUEIRA ITENS EXPECIFICO PARA CADA PRESET BASTA COMENTAR TODA A PARTE DO CÓDIGO DE ITENS)
/*player.GetInventory().CreateAttachment("CombatKnife");	
	Range = player.GetInventory().CreateInInventory("Rangefinder");		
	Range.GetInventory().CreateAttachment("Battery9V");	
	player.GetInventory().CreateInInventory("Morphine");			
	player.GetInventory().CreateInInventory("Morphine");
	player.GetInventory().CreateInInventory("SalineBagIV");
	player.GetInventory().CreateInInventory("SalineBagIV");	
	player.GetInventory().CreateInInventory("ChernarusMap");		
	player.GetInventory().CreateInInventory("BandageDressing");
	player.GetInventory().CreateInInventory("BandageDressing");
	player.GetInventory().CreateInInventory("BandageDressing");	
	player.GetInventory().CreateInInventory("LockPick");	
	player.GetInventory().CreateInInventory("Epinephrine");
	player.GetInventory().CreateInInventory("Epinephrine");	
	player.GetInventory().CreateInInventory("CanOpener");	
	player.GetInventory().CreateInInventory("TacticalBaconCan");	
	player.GetInventory().CreateInInventory("SpaghettiCan");
	player.GetInventory().CreateInInventory("Canteen");				
	player.GetInventory().CreateInInventory("Canteen");	
	player.SetQuickBarEntityShortcut( Melee, 2, true );	*/
};