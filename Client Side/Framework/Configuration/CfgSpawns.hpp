class CfgSpawns {
    class BaseSpawn {
        factions[] = { "Civilian" };
        buildings[] = {};
        radius = 300;
        conditions = "true";
    };
    class Police : BaseSpawn { factions[] = { "Police" }; };
    class HATO : BaseSpawn { factions[] = { "Hato" }; };
    class Medic : BaseSpawn { factions[] = { "Medic" }; };
    class Civilian : BaseSpawn {
        buildings[] = {};
    };

    class Altis {
        // Altis Police Constabulary
        class KavalaStation : Police {
            displayName = "Kavala Headquarters";
            marker = "apc_spawn_kavala";
            icon = "";
        };
        class AthiraStation : Police {
            displayName = "Athira Station";
            marker = "apc_spawn_athira";
            icon = "";
        };
        class PyrgosStation : Police {
            displayName = "Pyrgos Station";
            marker = "apc_spawn_pyrgos";
            icon = "";
        };
        class AgiosStation : Police {
            displayName = "Agios Station";
            marker = "apc_spawn_agios";
            icon = "";
        };

        // National Health Service
        class KavalaHospital : Medic {
            displayName = "Kavala Hospital";
            marker = "nhs_spawn_kavala";
            icon = "";
        };
        class AthiraClinic : Medic {
            displayName = "Athira Clinic";
            marker = "nhs_spawn_athira";
            icon = "";
        };
        class PyrgosHClinic : Medic {
            displayName = "Pyrgos Clinic";
            marker = "nhs_spawn_pyrgos";
            icon = "";
        };
        class SofiaHClinic : Medic {
            displayName = "Sofia Clinic";
            marker = "nhs_spawn_sofia";
            icon = "";
        };
        class AgiosHClinic : Medic {
            displayName = "Agios Clinic";
            marker = "nhs_spawn_agioss";
            icon = "";
        };

        // Altis Police Constabulary / National Health Service
        class MarineStation {
            displayName = "Marine Base";
            factions[] = { "Police", "Medic" };
            marker = "joint_spawn_marine";
            icon = "";
        };

        // HATO
        class HatoKavala : HATO {
            displayName = "Highways Agency";
            marker = "hato_spawn_kavala";
            icon = "";
        };

        // Civilian
        class Kavala : Civilian {
            displayName = "Kavala";
            marker = "civ_spawn_kavala";
            icon = "";
        };
        class Athira : Civilian {
            displayName = "Athira";
            marker = "civ_spawn_athira";
            icon = "";
        };
        class Pyrgos : Civilian {
            displayName = "Pyrgos";
            marker = "civ_spawn_pyrgos";
            icon = "";
        };
        class Sofia : Civilian {
            displayName = "Sofia";
            marker = "civ_spawn_sofia";
            icon = "";
        };
        class Agios : Civilian {
            displayName = "Agios";
            marker = "civ_spawn_agios";
            icon = "";
        };
        class Neochori : Civilian {
            displayName = "Neochori";
            marker = "civ_spawn_neochori";
            icon = "";
        };
    };

    class Malden {
        class LaTriniteConstabulary : Police {
            displayName = "La Trinité Constabulary";
            marker = "cop_spawn_1";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };

        class test : Police {
            displayName = "Another Option";
            marker = "cop_spawn_2";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };

        class LaTriniteHospital : Medic {
            displayName = "La Trinité HQ";
            marker = "medic_spawn";
            icon = "\a3\ui_f\data\map\VehicleIcons\pictureLogic_ca.paa";
        };

        class LaTrinite : BaseSpawn {
            displayName = "La Trinité";
            marker = "civ_spawn_1";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };
    };
};