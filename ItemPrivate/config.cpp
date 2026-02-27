class CfgPatches
{
	class ItemPrivate
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Scripts",
			"DZ_Data",
			"JM_CF_Scripts"
		};
	};
};
class CfgMods
{
	class ItemPrivate
	{
		name="ItemPrivate";
		credits="";
		author="";
		authorID="";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Mission",
			"World",
			"Game"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"ItemPrivate/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"ItemPrivate/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"ItemPrivate/Scripts/5_Mission"
				};
			};
		};
	};
};
