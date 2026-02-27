void EquipmentAssault(PlayerBase player, int Assault) {
    EntityAI Scope;
    Weapon_Base Arma;
    EntityAI LanternaArma;
    EntityAI Laser;
    EntityAI Lanterna;

    switch (Assault) {
    case 0: // PRESET QUE IRÁ SER CARREGADO NO VIP (PARA TROCAR BASTA INSERIR O NUMERO DO CASE(PRESET) NO VIP QUE FOI CRIADO)
        //SCAR-H
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("Snafu_ScarH_OD_GUN"));
        Arma.CF_SpawnMagazine("SNAFU_ScarH_100RND_Mag_Black"); // <----- CARREGAR A ARMA COM O PENTE !
        Arma.GetInventory().CreateAttachment("SNAFUGevar_Suppressor_Green");
        Arma.GetInventory().CreateAttachment("SNAFUScar_AFG_BK");
        Arma.GetInventory().CreateAttachment("SNAFU_ModBipod");
        LanternaArma = Arma.GetInventory().CreateAttachment("UniversalLight");
        LanternaArma.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Tango6T_Wood");
        Scope.GetInventory().CreateAttachment("Battery9V");
        Arma.GetInventory().CreateAttachment("SNAFU_ScarH_100RND_Mag_Black");
        player.GetInventory().CreateInInventory("SNAFU_ScarH_100RND_Mag_Black");
        player.GetInventory().CreateInInventory("SNAFU_ScarH_100RND_Mag_Black");
        break;

    case 1:
        //FNSCAR
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SCAR_Gun"));
        Arma.CF_SpawnMagazine("SNAFU_CMAG60556_Tan");
        Arma.GetInventory().CreateAttachment("Snafu_ScarH_SIL_Tan");
        Arma.GetInventory().CreateAttachment("SNAFUScar_AFG_Tan");
        LanternaArma = Arma.GetInventory().CreateAttachment("UniversalLight");
        LanternaArma.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Tango6T_Wood");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("SNAFU_CMAG60556_Tan");
        player.GetInventory().CreateInInventory("SNAFU_CMAG60556_Tan");
        player.GetInventory().CreateInInventory("SNAFU_CMAG60556_Tan");
        break;

    case 2:
        //SG550
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SG550_Gun"));
        Arma.CF_SpawnMagazine("SG550_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_LStandardized_Suppressor_Green");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Trijicon_Docter");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("SG550_Mag");
        player.GetInventory().CreateInInventory("SG550_Mag");
        player.GetInventory().CreateInInventory("SG550_Mag");
        player.GetInventory().CreateInInventory("SG550_Mag");
        player.GetInventory().CreateInInventory("SG550_Mag");
        break;

    case 3:
        //SG552
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SG552_Gun"));
        Arma.CF_SpawnMagazine("SG550_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_Standardized_Suppressor_Black");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Trijicon_Docter");
        Scope.GetInventory().CreateAttachment("Battery9V");
        LanternaArma = Arma.GetInventory().CreateAttachment("UniversalLight");
        LanternaArma.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("SG550_Mag");
        player.GetInventory().CreateInInventory("SG550_Mag");
        player.GetInventory().CreateInInventory("SG550_Mag");
        player.GetInventory().CreateInInventory("SG550_Mag");
        player.GetInventory().CreateInInventory("SG550_Mag");
        break;

    case 4:
        //REMI
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("ACR_Gun"));
        Arma.CF_SpawnMagazine("SNAFU_BMAG556_Tan");
        Arma.GetInventory().CreateAttachment("SNAFU_Standardized_Suppressor_Green");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Trijicon_Docter");
        Scope.GetInventory().CreateAttachment("Battery9V");
        LanternaArma = Arma.GetInventory().CreateAttachment("UniversalLight");
        LanternaArma.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Tan");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Tan");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Tan");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Tan");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Tan");
        break;

    case 5:
        //M249
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("GCGN_M249"));
        Arma.CF_SpawnMagazine("GCGN_M249_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_M249Grip");
        Arma.GetInventory().CreateAttachment("SNAFU_M249HG");
        Arma.GetInventory().CreateAttachment("SNAFU_M249Bipod");
        Arma.GetInventory().CreateAttachment("SNAFU_M249Stock");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Laser = Arma.GetInventory().CreateAttachment("SNAFU_PEQ1_Laser");
        Laser.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Kobra");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        break;

    case 6:
        //AA12
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("AA12_Gun"));
        Arma.CF_SpawnMagazine("AA12_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_Shotgunchoke_Yellow");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Trijicon_Docter");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("AA12_Mag");
        player.GetInventory().CreateInInventory("AA12_Mag");
        player.GetInventory().CreateInInventory("AA12_Mag");
        player.GetInventory().CreateInInventory("AA12_Mag");
        player.GetInventory().CreateInInventory("AA12_Mag");
        player.GetInventory().CreateInInventory("Ammo_12gaPellets");
        player.GetInventory().CreateInInventory("Ammo_12gaPellets");
        break;

    case 7:
        //HK416
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("HK416_Gun"));
        Arma.CF_SpawnMagazine("GCGN_HK416_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_LStandardized_Suppressor_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_EOTech_EXPS3");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("GCGN_HK416_Mag");
        player.GetInventory().CreateInInventory("GCGN_HK416_Mag");
        player.GetInventory().CreateInInventory("GCGN_HK416_Mag");
        player.GetInventory().CreateInInventory("GCGN_HK416_Mag");
        player.GetInventory().CreateInInventory("GCGN_HK416_Mag");
        break;

    case 8:
        //HK417
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNHK417_Gun"));
        Arma.CF_SpawnMagazine("SNHK417_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_LStandardized_Suppressor_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_EOTech_EXPS3");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("SNHK417_Mag");
        player.GetInventory().CreateInInventory("SNHK417_Mag");
        player.GetInventory().CreateInInventory("SNHK417_Mag");
        player.GetInventory().CreateInInventory("SNHK417_Mag");
        player.GetInventory().CreateInInventory("SNHK417_Mag");
        player.GetInventory().CreateInInventory("SNHK417_Mag");
        break;

    case 9:
        //IA2
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("IA2_Gun"));
        Arma.CF_SpawnMagazine("SNAFU_BMAG556_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_LStandardized_Suppressor_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_EOTech_EXPS3");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        break;

    case 10:
        //MK18
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("MK18_Gun"));
        Arma.CF_SpawnMagazine("SNAFU_BMAG556_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_LStandardized_Suppressor_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Walther");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        break;

    case 11:
        //VR80
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("VR80_Gun"));
        Arma.CF_SpawnMagazine("VR80_Magazine_10rd");
        Arma.GetInventory().CreateAttachment("SNAFU_Shotgunchoke_Tur");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Walther");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("VR80_Magazine_10rd");
        player.GetInventory().CreateInInventory("VR80_Magazine_10rd");
        player.GetInventory().CreateInInventory("VR80_Magazine_10rd");
        player.GetInventory().CreateInInventory("VR80_Magazine_10rd");
        player.GetInventory().CreateInInventory("VR80_Magazine_10rd");
        player.GetInventory().CreateInInventory("Ammo_12gaPellets");
        player.GetInventory().CreateInInventory("Ammo_12gaPellets");
        break;

    case 12:
        //AKM
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("AKM"));
        Arma.CF_SpawnMagazine("Mag_AKM_Drum_TEST");
        Arma.GetInventory().CreateAttachment("TTC_Universal_Suppressor_BLACK");
        Arma.GetInventory().CreateAttachment("AK_WoodBttstck_Camo");
        Arma.GetInventory().CreateAttachment("AK_WoodHndgrd");
        Scope = Arma.GetInventory().CreateAttachment("PSO1Optic");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("Mag_AKM_Drum_TEST");
        player.GetInventory().CreateInInventory("Mag_AKM_Drum_TEST");
        player.GetInventory().CreateInInventory("Mag_AKM_Drum_TEST");
        player.GetInventory().CreateInInventory("Mag_AKM_Drum_TEST");
        break;

    case 13:
        //RPK
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNAFU_RPK16_Black"));
        Arma.CF_SpawnMagazine("SNAFU_RPK16_Black_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_LStandardized_Suppressor_Black");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Walther");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("SNAFU_RPK16_Black_Mag");
        player.GetInventory().CreateInInventory("SNAFU_RPK16_Black_Mag");
        player.GetInventory().CreateInInventory("SNAFU_RPK16_Black_Mag");
        player.GetInventory().CreateInInventory("SNAFU_RPK16_Black_Mag");
        player.GetInventory().CreateInInventory("SNAFU_RPK16_Black_Mag");
        break;

    case 14:
        //AEK545
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNAFU_AEK545_Gun"));
        Arma.CF_SpawnMagazine("SNAFU_RPK16_Black_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_Standardized_Suppressor_Black");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Walther");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("SNAFU_RPK16_Black_Mag");
        player.GetInventory().CreateInInventory("SNAFU_RPK16_Black_Mag");
        player.GetInventory().CreateInInventory("SNAFU_RPK16_Black_Mag");
        player.GetInventory().CreateInInventory("SNAFU_RPK16_Black_Mag");
        break;

    case 15:
        //CZ805
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNAFU_CZ805_Gun"));
        Arma.CF_SpawnMagazine("GCGN_HK416_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Arma.GetInventory().CreateAttachment("SNAFUGevar_Suppressor_Tan");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Trijicon_Docter");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("GCGN_HK416_Mag");
        player.GetInventory().CreateInInventory("GCGN_HK416_Mag");
        player.GetInventory().CreateInInventory("GCGN_HK416_Mag");
        player.GetInventory().CreateInInventory("GCGN_HK416_Mag");
        break;

    case 16:
        //PDW
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNAFU_KAC_Gun"));
        Arma.CF_SpawnMagazine("SNAFU_KAC_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Arma.GetInventory().CreateAttachment("SNAFU_Standardized_Suppressor_Black");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Trijicon_Docter");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("SNAFU_KAC_Mag");
        player.GetInventory().CreateInInventory("SNAFU_KAC_Mag");
        player.GetInventory().CreateInInventory("SNAFU_KAC_Mag");
        player.GetInventory().CreateInInventory("SNAFU_KAC_Mag");
        player.GetInventory().CreateInInventory("SNAFU_KAC_Mag");
        break;

    case 17:
        //RPD
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNAFURPD"));
        Arma.CF_SpawnMagazine("SNAFURPD_100rdMag");
        player.GetInventory().CreateInInventory("SNAFURPD_100rdMag");
        player.GetInventory().CreateInInventory("SNAFURPD_100rdMag");
        player.GetInventory().CreateInInventory("SNAFURPD_100rdMag");
        break;

    case 18:
        //PKP
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("Snafu_PKP_NBlack_Gun"));
        Arma.CF_SpawnMagazine("Snafu_PKP_250RND_Mag");
        player.GetInventory().CreateInInventory("SNAFU_PKPBIPOD");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_AKWalther");
        player.GetInventory().CreateInInventory("Snafu_PKP_250RND_Mag");
        player.GetInventory().CreateInInventory("Snafu_PKP_250RND_Mag");
        player.GetInventory().CreateInInventory("SNAFU_Normalized_Suppressor_Black");
        player.GetInventory().CreateInInventory("Battery9V");
        break;

    case 19:
        //AUGA3
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNAFUAUG_BK"));
        Arma.CF_SpawnMagazine("SNAFU_BMAG556_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Arma.GetInventory().CreateAttachment("SNAFU_Standardized_Suppressor_Black");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Trijicon_Docter");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        break;

    case 20:
        //HONEY
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNAFUHoneyBadger_Black"));
        Arma.CF_SpawnMagazine("SNAFU_BMAG300_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Trijicon_Docter");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("SNAFU_BMAG300_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG300_Black");
        break;

    case 21:
        //TAR21
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNAFUTAR21_Black"));
        Arma.CF_SpawnMagazine("SNAFU_BMAG556_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_SR25_Supp");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_EOTech_EXPS3");
        Scope.GetInventory().CreateAttachment("Battery9V");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        break;

    case 22:
        //Snafu_ScarH_Cannabis
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("Snafu_ScarH_Cannabis"));
        Arma.CF_SpawnMagazine("SNAFU_ScarH_100RND_Mag_Black");
        Arma.GetInventory().CreateAttachment("SNAFUGevar_Suppressor_Green");
        Arma.GetInventory().CreateAttachment("SNAFUScar_AFG_BK");
        Arma.GetInventory().CreateAttachment("SNAFU_ModBipod");
        LanternaArma = Arma.GetInventory().CreateAttachment("UniversalLight");
        LanternaArma.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Tango6T_Wood");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("SNAFU_ScarH_100RND_Mag_Black");
        player.GetInventory().CreateInInventory("SNAFU_ScarH_100RND_Mag_Black");
        break;

    case 23:
        //Snafu_ScarH_Fogo
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("Snafu_ScarH_Fogo"));
        Arma.CF_SpawnMagazine("SNAFU_ScarH_100RND_Mag_Black");
        Arma.GetInventory().CreateAttachment("SNAFUGevar_Suppressor_Green");
        Arma.GetInventory().CreateAttachment("SNAFUScar_AFG_BK");
        Arma.GetInventory().CreateAttachment("SNAFU_ModBipod");
        LanternaArma = Arma.GetInventory().CreateAttachment("UniversalLight");
        LanternaArma.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Tango6T_Wood");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("SNAFU_ScarH_100RND_Mag_Black");
        player.GetInventory().CreateInInventory("SNAFU_ScarH_100RND_Mag_Black");
        break;

    case 24:
        //Snafu_ScarH_Roses_Skull
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("Snafu_ScarH_Roses_Skull"));
        Arma.CF_SpawnMagazine("SNAFU_ScarH_100RND_Mag_Black");
        Arma.GetInventory().CreateAttachment("SNAFUGevar_Suppressor_Green");
        Arma.GetInventory().CreateAttachment("SNAFUScar_AFG_BK");
        Arma.GetInventory().CreateAttachment("SNAFU_ModBipod");
        LanternaArma = Arma.GetInventory().CreateAttachment("UniversalLight");
        LanternaArma.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Tango6T_Wood");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("SNAFU_ScarH_100RND_Mag_Black");
        player.GetInventory().CreateInInventory("SNAFU_ScarH_100RND_Mag_Black");
        break;

    case 25:
        //Snafu_ScarH_Naips
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("Snafu_ScarH_Naips"));
        Arma.CF_SpawnMagazine("SNAFU_ScarH_100RND_Mag_Black");
        Arma.GetInventory().CreateAttachment("SNAFUGevar_Suppressor_Green");
        Arma.GetInventory().CreateAttachment("SNAFUScar_AFG_BK");
        Arma.GetInventory().CreateAttachment("SNAFU_ModBipod");
        LanternaArma = Arma.GetInventory().CreateAttachment("UniversalLight");
        LanternaArma.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Tango6T_Wood");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("SNAFU_ScarH_100RND_Mag_Black");
        player.GetInventory().CreateInInventory("SNAFU_ScarH_100RND_Mag_Black");
        break;

    case 26:
        //SNAFUHoneyBadger_Rainbow
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNAFUHoneyBadger_Rainbow"));
        Arma.CF_SpawnMagazine("SNAFU_BMAG300_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Trijicon_Docter");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("SNAFU_BMAG300_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG300_Black");
        break;

    case 27:
        //SNAFUHoneyBadger_Cannabis
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNAFUHoneyBadger_Cannabis"));
        Arma.CF_SpawnMagazine("SNAFU_BMAG300_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Trijicon_Docter");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("SNAFU_BMAG300_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG300_Black");
        break;

    case 28:
        //SNAFUHoneyBadger_Constelacao
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNAFUHoneyBadger_Constelacao"));
        Arma.CF_SpawnMagazine("SNAFU_BMAG300_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Lanterna = Arma.GetInventory().CreateAttachment("UniversalLight");
        Lanterna.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Trijicon_Docter");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("SNAFU_BMAG300_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG300_Black");
        break;

    case 29:
        //GCGN_M249_Cyber
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("GCGN_M249_Cyber"));
        Arma.CF_SpawnMagazine("GCGN_M249_Mag");

        Arma.GetInventory().CreateAttachment("SNAFU_M249Grip");
        Arma.GetInventory().CreateAttachment("SNAFU_M249HG");
        Arma.GetInventory().CreateAttachment("SNAFU_M249Bipod");
        Arma.GetInventory().CreateAttachment("SNAFU_M249Stock");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Laser = Arma.GetInventory().CreateAttachment("SNAFU_PEQ1_Laser");
        Laser.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Kobra");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        break;

    case 30:
        //GCGN_M249_Star
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("GCGN_M249_Star"));
        Arma.CF_SpawnMagazine("GCGN_M249_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_M249Grip");
        Arma.GetInventory().CreateAttachment("SNAFU_M249HG");
        Arma.GetInventory().CreateAttachment("SNAFU_M249Bipod");
        Arma.GetInventory().CreateAttachment("SNAFU_M249Stock");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Laser = Arma.GetInventory().CreateAttachment("SNAFU_PEQ1_Laser");
        Laser.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Kobra");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        player.GetInventory().CreateInInventory("GCGN_M249_Mag");
        break;

    case 31:
        //M4A1 VERDE
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("M4A1_Green"));
        Arma.CF_SpawnMagazine("Mag_STANAGCoupled_30Rnd");
        Arma.GetInventory().CreateAttachment("M4_CQBBttstck_Green");
        Arma.GetInventory().CreateAttachment("M4_PlasticHndgrd_Green");
        Arma.GetInventory().CreateAttachment("M4_Suppressor");
        Arma.GetInventory().CreateAttachment("AtlasBipod");
        Scope = Arma.GetInventory().CreateAttachment("M4_T3NRDSOptic");
        Scope.GetInventory().CreateAttachment("Battery9V");
        LanternaArma = Arma.GetInventory().CreateAttachment("UniversalLight");
        LanternaArma.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("Mag_STANAGCoupled_30Rnd");
        player.GetInventory().CreateInInventory("Mag_STANAGCoupled_30Rnd");
        player.GetInventory().CreateInInventory("Mag_STANAGCoupled_30Rnd");
        break;

    case 32:
        //SA-80
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("SNAFUSA80"));
        Arma.CF_SpawnMagazine("SNAFU_BMAG556_Black");
        Arma.GetInventory().CreateAttachment("SNAFU_LStandardized_Suppressor_Green");
        Arma.GetInventory().CreateAttachment("SNAFU_FGKAC_Grip");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_Trijicon_Docter");
        Scope.GetInventory().CreateAttachment("Battery9V");
        LanternaArma = Arma.GetInventory().CreateAttachment("UniversalLight");
        LanternaArma.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        player.GetInventory().CreateInInventory("SNAFU_BMAG556_Black");
        break;

    case 33:
        //BIZON				
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("PP19"));
        Arma.CF_SpawnMagazine("Mag_PP19_64Rnd");
        Arma.GetInventory().CreateAttachment("PP19_Bttstck");
        Arma.GetInventory().CreateAttachment("TTC_Universal_Suppressor_BLACK");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_AKWalther");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("Mag_PP19_64Rnd");
        player.GetInventory().CreateInInventory("Mag_PP19_64Rnd");
        player.GetInventory().CreateInInventory("Mag_PP19_64Rnd");
        player.GetInventory().CreateInInventory("Mag_PP19_64Rnd");
        break;

    case 34:
        //Sic MCX				
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("APES_MCXSpear"));
        Arma.CF_SpawnMagazine("APES_MCXSpearMagazine");
        Scope = Arma.GetInventory().CreateAttachment("APES_Shinigamigreen");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("APES_MCXSpearMagazine");
        player.GetInventory().CreateInInventory("APES_MCXSpearMagazine");
        player.GetInventory().CreateInInventory("APES_MCXSpearMagazine");
        player.GetInventory().CreateInInventory("APES_MCXSpearMagazine");
        player.GetInventory().CreateInInventory("APES_MCXSpearMagazine");
        break;

    case 35:
        //AKzenit				
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("APES_AKZenit_Black"));
        Arma.CF_SpawnMagazine("APES_AKZenit_Magazine");
        Arma.GetInventory().CreateAttachment("APES_Universal_Suppressor");
        Scope = Arma.GetInventory().CreateAttachment("APES_Shinigamigreen");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("APES_AKZenit_Magazine");
        player.GetInventory().CreateInInventory("APES_AKZenit_Magazine");
        player.GetInventory().CreateInInventory("APES_AKZenit_Magazine");
        player.GetInventory().CreateInInventory("APES_AKZenit_Magazine");
        break;

    case 36:
        //m56 black				
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("APES_M56"));
        Arma.CF_SpawnMagazine("APES_M56_Magazine");
        Scope = Arma.GetInventory().CreateAttachment("APES_Shinigamigreen");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("APES_M56_Magazine");
        player.GetInventory().CreateInInventory("APES_M56_Magazine");
        break;

    case 37:
        //FN Evoly			
        Arma = Weapon_Base.Cast(player.GetHumanInventory().CreateInHands("APES_FNEvoly"));
        Arma.CF_SpawnMagazine("APES_FNEvoly_Magazine");
        Arma.GetInventory().CreateAttachment("APES_Universal_Suppressor");
        Scope = Arma.GetInventory().CreateAttachment("APES_Shinigamigreen");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("APES_FNEvoly_Magazine");
        player.GetInventory().CreateInInventory("APES_FNEvoly_Magazine");
        break;
    }
    Arma.RandomizeFSMState();
    Arma.Synchronize();
    player.SetQuickBarEntityShortcut(Arma, 0, true);
};

void EquipmentSniper(PlayerBase player, int Sniper) {
    EntityAI Scope;
    Weapon_Base Arma;

    switch (Sniper) {
    case 0:
        //AX50
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUAX50_GUN"));
        Arma.CF_SpawnMagazine("SNAFUAX50_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_W");
        Arma.GetInventory().CreateAttachment("SNAFU_Bipod");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        break;

    case 1:
        //BARRET		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("GCGN_M82_Barret"));
        Arma.CF_SpawnMagazine("GCGN_M82_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_M");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        break;

    case 2:
        //VSSK		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUVSSK"));
        Arma.CF_SpawnMagazine("SNAFUVSSK_5rdMag");
        Arma.GetInventory().CreateAttachment("SNAFU_VSSKbipod");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUVSSK_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUVSSK_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUVSSK_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUVSSK_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUVSSK_5rdMag");
        break;

    case 3:
        //M200S		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFU_M200SNOW"));
        Arma.CF_SpawnMagazine("GCGN_M200_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_M200S_Snow");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_U");
        Arma.GetInventory().CreateAttachment("SNAFU_M200B_BK");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        break;

    case 4:
        //M200	
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFU_M200Green"));
        Arma.CF_SpawnMagazine("GCGN_M200_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_M200S_Green");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_W");
        Arma.GetInventory().CreateAttachment("SNAFU_M200B_BK");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        break;

    case 5:
        //KIVAARI		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUKivaari_Black_Gun"));
        Arma.CF_SpawnMagazine("SNAFUKivaari_25rdMag");
        Arma.GetInventory().CreateAttachment("SNAFU_AtlasBipod");
        Arma.GetInventory().CreateAttachment("SNAFUKivaari_338_Supp");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        break;

    case 6:
        //M300		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFU_M300BK"));
        Arma.CF_SpawnMagazine("SNAFU_M300Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_Bipod");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_B");
        Arma.GetInventory().CreateAttachment("SNAFU_AFG_02_Black");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFU_M300Mag");
        player.GetInventory().CreateInInventory("SNAFU_M300Mag");
        player.GetInventory().CreateInInventory("SNAFU_M300Mag");
        player.GetInventory().CreateInInventory("SNAFU_M300Mag");
        player.GetInventory().CreateInInventory("SNAFU_M300Mag");
        break;

    case 7:
        //AWM		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFU_AWM_Gun"));
        Arma.CF_SpawnMagazine("SNAFU_AWM_Mag");
        Arma.GetInventory().CreateAttachment("SNAFUKivaari_338_Supp");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFU_AWM_Mag");
        player.GetInventory().CreateInInventory("SNAFU_AWM_Mag");
        player.GetInventory().CreateInInventory("SNAFU_AWM_Mag");
        player.GetInventory().CreateInInventory("SNAFU_AWM_Mag");
        player.GetInventory().CreateInInventory("SNAFU_AWM_Mag");
        break;

    case 8:
        //DVL		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUDVL10M2"));
        Arma.CF_SpawnMagazine("SNAFUDVL10M2_5rdMag");
        Arma.GetInventory().CreateAttachment("SNAFUKivaari_338_Supp");
        Arma.GetInventory().CreateAttachment("SNAFU_Bipod");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUDVL10M2_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUDVL10M2_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUDVL10M2_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUDVL10M2_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUDVL10M2_5rdMag");
        break;

    case 9:
        //TAC21		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUTac21"));
        Arma.CF_SpawnMagazine("SNAFUTac21_5rdMag");
        Arma.GetInventory().CreateAttachment("SNAFU_Bipod");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUTac21_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUTac21_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUTac21_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUTac21_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUTac21_5rdMag");
        break;

    case 10:
        //ALLIGATOR		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUAlligator"));
        Arma.CF_SpawnMagazine("SNAFUAlligator_5rdMag");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        break;

    case 11:
        //T5000		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUT5000_Wood_Gun"));
        Arma.CF_SpawnMagazine("SNAFUT5000_Mag");
        Arma.GetInventory().CreateAttachment("SNAFUKivaari_338_Supp");
        Arma.GetInventory().CreateAttachment("SNAFU_AtlasBipod");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUT5000_Mag");
        player.GetInventory().CreateInInventory("SNAFUT5000_Mag");
        player.GetInventory().CreateInInventory("SNAFUT5000_Mag");
        player.GetInventory().CreateInInventory("SNAFUT5000_Mag");
        player.GetInventory().CreateInInventory("SNAFUT5000_Mag");
        break;

    case 12:
        //M98B		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUM98B_Atac_Gun"));
        Arma.CF_SpawnMagazine("SNAFUM98B_Mag");
        Arma.GetInventory().CreateAttachment("SNAFUKivaari_338_Supp");
        Arma.GetInventory().CreateAttachment("SNAFU_AtlasBipod");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUM98B_Mag");
        player.GetInventory().CreateInInventory("SNAFUM98B_Mag");
        player.GetInventory().CreateInInventory("SNAFUM98B_Mag");
        player.GetInventory().CreateInInventory("SNAFUM98B_Mag");
        player.GetInventory().CreateInInventory("SNAFUM98B_Mag");
        break;

    case 13:
        //AS50		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFU_AS50_Gun"));
        Arma.CF_SpawnMagazine("SNAFU_AS50_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_M");
        Arma.GetInventory().CreateAttachment("SNAFU_Bipod");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFU_AS50_Mag");
        player.GetInventory().CreateInInventory("SNAFU_AS50_Mag");
        player.GetInventory().CreateInInventory("SNAFU_AS50_Mag");
        player.GetInventory().CreateInInventory("SNAFU_AS50_Mag");
        player.GetInventory().CreateInInventory("SNAFU_AS50_Mag");
        break;

    case 14:
        //gcgn_m82barret_co_hello_kitty		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("gcgn_m82barret_co_hello_kitty"));
        Arma.CF_SpawnMagazine("GCGN_M82_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_M");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        break;

    case 15:
        //SNAFUAlligator_Frozen		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUAlligator_Frozen"));
        Arma.CF_SpawnMagazine("SNAFUAlligator_5rdMag");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        break;

    case 16:
        //SNAFUAlligator_Sangue		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUAlligator_Sangue"));
        Arma.CF_SpawnMagazine("SNAFUAlligator_5rdMag");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        break;

    case 17:
        //SNAFUAlligator_Skul_Blue		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUAlligator_Skul_Blue"));
        Arma.CF_SpawnMagazine("SNAFUAlligator_5rdMag");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUAlligator_5rdMag");
        break;

    case 18:
        //SNAFUTac21_Love		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUTac21_Love"));
        Arma.CF_SpawnMagazine("SNAFUTac21_5rdMag");
        Arma.GetInventory().CreateAttachment("SNAFU_Bipod");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUTac21_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUTac21_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUTac21_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUTac21_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUTac21_5rdMag");
        break;

    case 19:
        //DdouBle11_Marvel_AX50		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("DdouBle11_Marvel_AX50"));
        Arma.CF_SpawnMagazine("SNAFUAX50_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_W");
        Arma.GetInventory().CreateAttachment("SNAFU_Bipod");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        break;

    case 20:
        //Sneaky_Snek_AX50		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("Sneaky_Snek_AX50"));
        Arma.CF_SpawnMagazine("SNAFUAX50_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_W");
        Arma.GetInventory().CreateAttachment("SNAFU_Bipod");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        break;

    case 21:
        //Jasper_Sunset_AX50		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("Jasper_Sunset_AX50"));
        Arma.CF_SpawnMagazine("SNAFUAX50_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_W");
        Arma.GetInventory().CreateAttachment("SNAFU_Bipod");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        break;

    case 22:
        //Golden_AX50		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("Maple_GoldenEngraved_AX50"));
        Arma.CF_SpawnMagazine("SNAFUAX50_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_W");
        Arma.GetInventory().CreateAttachment("SNAFU_Bipod");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        player.GetInventory().CreateInInventory("SNAFUAX50_Mag");
        break;

    case 23:
        //cheytec fogo	
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("Cheytaclarvafogo"));
        Arma.CF_SpawnMagazine("GCGN_M200_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_M200S_Green");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_W");
        Arma.GetInventory().CreateAttachment("SNAFU_M200B_BK");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        break;

    case 24:
        //M82gold		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("barretouro"));
        Arma.CF_SpawnMagazine("GCGN_M82_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_M");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        break;

    case 25:
        //Cheytateia teia	
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("Cheytateia"));
        Arma.CF_SpawnMagazine("GCGN_M200_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_M200S_Green");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_W");
        Arma.GetInventory().CreateAttachment("SNAFU_M200B_BK");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        break;

    case 26:
        //Cheyt colorida
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("Cheytaccolor1"));
        Arma.CF_SpawnMagazine("GCGN_M200_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_M200S_Green");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_W");
        Arma.GetInventory().CreateAttachment("SNAFU_M200B_BK");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        break;

    case 27:
        //Beowulfkryp
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("PNC_W_Beowulf50_kryp"));
        Arma.CF_SpawnMagazine("PNC_Mag_Beowulf50_20Rnd");
        Arma.GetInventory().CreateAttachment("PNC_KIVAARI_Bttstck_kryp");
        Arma.GetInventory().CreateAttachment("PNC_BarretM82A1_Suppressor_black");
        Arma.GetInventory().CreateAttachment("UniversalLight");
        Arma.GetInventory().CreateAttachment("Battery9V");
        Scope = Arma.GetInventory().CreateAttachment("AD_DHF5");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("PNC_Mag_Beowulf50_20Rnd");
        player.GetInventory().CreateInInventory("PNC_Mag_Beowulf50_20Rnd");
        player.GetInventory().CreateInInventory("PNC_Mag_Beowulf50_20Rnd");
        break;

    case 28:
        //Aurora
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("PNC_W_Aurora"));
        Arma.CF_SpawnMagazine("PNC_Mag_Aurora_5Rnd");
        Arma.GetInventory().CreateAttachment("PNC_Aurora_Suppressor");
        Scope = Arma.GetInventory().CreateAttachment("AD_DHF5");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("PNC_Mag_Aurora_5Rnd");
        player.GetInventory().CreateInInventory("PNC_Mag_Aurora_5Rnd");
        player.GetInventory().CreateInInventory("PNC_Mag_Aurora_5Rnd");
        player.GetInventory().CreateInInventory("PNC_Mag_Aurora_5Rnd");
        break;

    case 29:
        //lynix
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("SNAFUGM6Lynx"));
        Arma.CF_SpawnMagazine("SNAFUGM6Lynx_5rdMag");
        Arma.GetInventory().CreateAttachment("SNAFU_Bipod");
        Scope = Arma.GetInventory().CreateAttachment("AD_DHF5");
        Scope.GetInventory().CreateAttachment("Battery9V");

        player.GetInventory().CreateInInventory("SNAFUGM6Lynx_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUGM6Lynx_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUGM6Lynx_5rdMag");
        player.GetInventory().CreateInInventory("SNAFUGM6Lynx_5rdMag");
        break;

    case 30:
        //CHEYTAC CINZA
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("GCGN_M200"));
        Arma.CF_SpawnMagazine("GCGN_M200_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_M200S_BK");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_W");
        Arma.GetInventory().CreateAttachment("SNAFU_M200B_BK");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        player.GetInventory().CreateInInventory("GCGN_M200_Mag");
        break;

    case 31:
        //KIVAARI		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("Kivaariloka"));
        Arma.CF_SpawnMagazine("SNAFUKivaari_25rdMag");
        Arma.GetInventory().CreateAttachment("SNAFU_AtlasBipod");
        Arma.GetInventory().CreateAttachment("SNAFUKivaari_338_Supp");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");

        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        break;

    case 32:
        //KIVAARI		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("Kivaariraio"));
        Arma.CF_SpawnMagazine("SNAFUKivaari_25rdMag");
        Arma.GetInventory().CreateAttachment("SNAFU_AtlasBipod");
        Arma.GetInventory().CreateAttachment("SNAFUKivaari_338_Supp");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        player.GetInventory().CreateInInventory("SNAFUKivaari_25rdMag");
        break;

    case 33:
        //barretdiferente		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("barretdiferente"));
        Arma.CF_SpawnMagazine("GCGN_M82_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_M");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        break;

    case 34:
        //M82barretcobra1		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("M82barretcobra1"));
        Arma.CF_SpawnMagazine("GCGN_M82_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_M");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        break;

    case 35:
        //Anzio red		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("APES_AnzioRed"));
        Arma.CF_SpawnMagazine("APES_Anzio_Magazine");
        Scope = Arma.GetInventory().CreateAttachment("APES_Hunting_Blue");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("APES_Anzio_Magazine");
        player.GetInventory().CreateInInventory("APES_Anzio_Magazine");
        player.GetInventory().CreateInInventory("APES_Anzio_Magazine");
        player.GetInventory().CreateInInventory("APES_Anzio_Magazine");
        break;

    case 36:
        //Anzio black		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("APES_Anzio"));
        Arma.CF_SpawnMagazine("APES_Anzio_Magazine");
        Scope = Arma.GetInventory().CreateAttachment("APES_Hunting_Blue");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("APES_Anzio_Magazine");
        player.GetInventory().CreateInInventory("APES_Anzio_Magazine");
        player.GetInventory().CreateInInventory("APES_Anzio_Magazine");
        player.GetInventory().CreateInInventory("APES_Anzio_Magazine");
        break;

    case 37:
        //barret branca			
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("APES_Barrett_White"));
        Arma.CF_SpawnMagazine("APES_Barrett_Magazine");
        Scope = Arma.GetInventory().CreateAttachment("APES_Shortdotgreen");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("APES_Barrett_Magazine");
        player.GetInventory().CreateInInventory("APES_Barrett_Magazine");
        player.GetInventory().CreateInInventory("APES_Barrett_Magazine");
        player.GetInventory().CreateInInventory("APES_Barrett_Magazine");
        break;

    case 38:
        //Snipex		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("APES_Snipex"));
        Arma.CF_SpawnMagazine("APES_Snipex_Magazine");
        Scope = Arma.GetInventory().CreateAttachment("APES_Shortdotgreen");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("APES_Snipex_Magazine");
        player.GetInventory().CreateInInventory("APES_Snipex_Magazine");
        player.GetInventory().CreateInInventory("APES_Snipex_Magazine");
        player.GetInventory().CreateInInventory("APES_Snipex_Magazine");
        break;

    case 39:
        //APES PGM		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("APES_PGM"));
        Arma.CF_SpawnMagazine("APES_PGM_Magazine");
        Scope = Arma.GetInventory().CreateAttachment("APES_Hunting_Green");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("APES_PGM_Magazine");
        player.GetInventory().CreateInInventory("APES_PGM_Magazine");
        player.GetInventory().CreateInInventory("APES_PGM_Magazine");
        player.GetInventory().CreateInInventory("APES_PGM_Magazine");
        break;

    case 40:
        //BEOWULFVERD		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("APES_Beowulf_green"));
        Arma.CF_SpawnMagazine("APES_BeowulfMagazine");
        Scope = Arma.GetInventory().CreateAttachment("APES_Hunting_Green");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("APES_BeowulfMagazine");
        player.GetInventory().CreateInInventory("APES_BeowulfMagazine");
        player.GetInventory().CreateInInventory("APES_BeowulfMagazine");
        player.GetInventory().CreateInInventory("APES_BeowulfMagazine");
        break;

    case 41:
        //M200 Void colorida		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("APES_M200_Void"));
        Arma.CF_SpawnMagazine("APES_m200_mag");
        Arma.GetInventory().CreateAttachment("APES_408suppressor");
        Scope = Arma.GetInventory().CreateAttachment("APES_Hunting_Green");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("APES_m200_mag");
        player.GetInventory().CreateInInventory("APES_m200_mag");
        player.GetInventory().CreateInInventory("APES_m200_mag");
        player.GetInventory().CreateInInventory("APES_m200_mag");
        break;

    case 42:
        //delta5-pro			
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("APES_Delta_WhiteCaro"));
        Arma.CF_SpawnMagazine("APES_Delta_Magazine");
        Arma.GetInventory().CreateAttachment("APES_408Suppressor");
        Scope = Arma.GetInventory().CreateAttachment("APES_Hunting_Green");
        Scope.GetInventory().CreateAttachment("Battery9V");
        player.GetInventory().CreateInInventory("APES_Delta_Magazine");
        player.GetInventory().CreateInInventory("APES_Delta_Magazine");
        player.GetInventory().CreateInInventory("APES_Delta_Magazine");
        player.GetInventory().CreateInInventory("APES_Delta_Magazine");
        break;

    case 43:
        //M82barretcobra1		
        Arma = Weapon_Base.Cast(player.GetInventory().CreateInInventory("barretfogo"));
        Arma.CF_SpawnMagazine("GCGN_M82_Mag");
        Arma.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_M");
        Scope = Arma.GetInventory().CreateAttachment("SNAFU_HuntingOptic");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        player.GetInventory().CreateInInventory("GCGN_M82_Mag");
        break;
    }
    player.SetQuickBarEntityShortcut(Arma, 1, true);
};