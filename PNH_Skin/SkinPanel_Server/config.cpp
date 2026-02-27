class CfgPatches
{
	class SkinPanel_Server
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Characters_Vests",
			"DZ_Weapons_Firearms"
		};
	};
};
class CfgMods
{
	class SkinPanel_Server
	{
		name="SkinPanel_Server";
		credits="DEV FD";
		author="byFD";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"SkinPanel_Server/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"SkinPanel_Server/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"SkinPanel_Server/Scripts/5_Mission"
				};
			};
		};
	};
};
