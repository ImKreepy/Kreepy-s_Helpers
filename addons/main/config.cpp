#include "script_component.hpp"

class CfgPatches {
    class MAIN_ADDON {
        author = AUTHOR;
        authors[] = {"Im Kreepy"};
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"cba_main","cba_xeh"};
        units[] = {
            "IK_Modules_RescaleObjects",
            "IK_Modules_MakeAceArsenal",
            "IK_Modules_FullHealArea",
            "IK_Modules_RRR"
        };
        weapons[] = {};
        VERSION_CONFIG;

         
    };
};

class CfgAddons
{
    class PreloadAddons 
    {
        class KreepyHelper_Preload
        {
            list[] = {
            "cba_main",
            "cba_xeh",
            QUOTE(MAIN_ADDON)
            };
        };
    };
};

class CfgMods
{
    class Mod_Base;
	class UNSC_Infirmary: Mod_Base
	{
		dir="@Kreepy's Helpers";
		name = "Kreepy's Helpers";
        author = "Im Kreepy";
        description = "This mod is just a few things I created to make the lives of my Zeuses a little easier.";

        //action = "https://discord.gg/FqY9cNzB5n";
        //actionName = "Join Jaeger Company";

        tooltip = "Kreepy's Helpers";
        tooltipOwned = "Kreepy's Helpers Owned";

        picture = "\ik\kh\addons\main\logos\kh_logotitle_512_ca.paa"; // Logo displayed in expansions menu
        logo = "\ik\kh\addons\main\logos\kh_logo_ca.paa"; // Image displayed on the main menu (128x)
        logoOver = "\ik\kh\addons\main\logos\kh_logoover_ca.paa"; // Image displayed when the mouse hovers over the image on the main menu (128x)
        logoSmall = "\ik\kh\addons\main\logos\kh_logo_small_ca.paa"; // Image displayed in Arsenal or 3DEN (32x)

        overview = "This mod is just a few things I created to make the lives of my Zeuses a little easier.";
        overviewText = "Kreepy's Helpers";
        overviewPicture = "\ik\kh\addons\main\logos\kh_logo_ca.paa";
        overviewFootnote = "\ik\kh\addons\main\logos\kh_logo_ca.paa";
	};
};

class CfgFactionClasses {
    class IK_Modules {
        displayName="Kreepy's Helpers";
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
