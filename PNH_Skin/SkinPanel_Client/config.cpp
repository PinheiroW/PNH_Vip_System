class CfgPatches
{
	class SkinPanel_Client
	{
		units[]={};
		weapons[]=
		{
			"fal"
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Characters_Vests",
			"DZ_Weapons_Firearms",
			"SkinPanel_Server"
		};
	};
};
class CfgMods
{
	class SkinPanel_Client
	{
		name = "SkinPanel_Client";
        credits = "byPNH";
        author = "DEV PNH";
        authorID = "0";
        version = "1.0";
        extra = 0;
        type = "mod";
		inputs = "SkinPanel_Client/Inputs/inputs.xml";
		dependencies[]={"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"SkinPanel_Client/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"SkinPanel_Client/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"SkinPanel_Client/Scripts/5_Mission"
				};
			};
		};
	};
};
class CfgVehicles
{
	class Clothing;
	class ItemOptics;
	class PlateCarrierVest: Clothing
	{
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa",
			"\DZ\characters\vests\data\ballisticvest_co.paa"
		};
	};
};
class cfgWeapons
{
	class Weapon_Base;
	class fal_base;
	class fal: fal_base
	{
		scope=2;
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"DZ\weapons\firearms\fal\Data\fal_co.paa"
		};
	};
};
