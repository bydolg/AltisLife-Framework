/*
	@File: CfgPerks.hpp
	@Author: Jack "Scarso" Farhall & Lewis Mackinnon
	@Description: Configures the settings behind the professions system.
*/

class CfgProfessions {
    class Prof_Fishing {
        displayName = "Fishing";
        variable = "Prof_Fishing";
        description = "Fishing is a profession that is defined around the catching and trade of various types of fish from the different fishing grounds marked on the map.";
        side = "Civilian";
        maxLevel = 500;
        levels[] = {
            {50, "Novice"}, {100, "Intermediate"}, {250, "Advanced"}, {500, "Expert"}
        };
    };

    class Prof_Gathering {
        displayName = "Gathering";
        variable = "Prof_Gathering";
        description = "Gathering is a profession that is defined around the recovery of resources from various fields / plantations that are marked on the map.";
        side = "Civilian";
        maxLevel = 500;
        levels[] = {
            {50, "Novice"}, {100, "Intermediate"}, {250, "Advanced"}, {500, "Expert"}
        };
    };

    class Prof_Mining {
        displayName = "Mining";
        variable = "Prof_Mining";
        description = "Mining is a profession that is defined around the excavation of resources from various mines that are marked on the map.";
        side = "Civilian";
        maxLevel = 500;
        levels[] = {
            {50, "Novice"}, {100, "Intermediate"}, {250, "Advanced"}, {500, "Expert"}
        };
    };

    class Prof_Processing {
        displayName = "Processing";
        variable = "Prof_Processing";
        description = "Processing is a profession that is defined around the processing of various raw materials into useable materials at various processing sites around the map..";
        side = "Civilian";
        maxLevel = 500;
        levels[] = {
            {50, "Novice"}, {100, "Intermediate"}, {250, "Advanced"}, {500, "Expert"}
        };
    };

    class Prof_Cooking {
        displayName = "Cooking";
        variable = "Prof_Cooking";
        description = "Cooking is a profession that is defined around the cooking of different types of food gathered from around the map in various different ways.";
        side = "Civilian";
        maxLevel = 500;
        levels[] = {
            {50, "Novice"}, {100, "Intermediate"}, {250, "Advanced"}, {500, "Expert"}
        };
    };

    class Prof_Crafting {
        displayName = "Crafting";
        variable = "Prof_Crafting";
        description = "Crafting is a profession that is defined around the crafting of various items using materials gathered and collected from around the map.";
        side = "Civilian";
        maxLevel = 500;
        levels[] = {
            {50, "Novice"}, {100, "Intermediate"}, {250, "Advanced"}, {500, "Expert"}
        };
    };
};