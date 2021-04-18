class CfgInteractions {
	/* GENERAL INTERACTIONS */
	// Show ID	
	// Show Licenses	
	// Give Cash
	// Give Keys

	/* RESTRAINED INTERACTIONS */
	// Put In Vehicle
	// Feed/Hydrate
	// Blindfold/Remove Blindfold
	// Gag/Remove Gag
	// Check Inventory
	// Check vItems
	// Check ID
	// Check Licenses

	/* POLICE INTERACTIONS */
	// Issue Ticket
	// Send to Prison

	/* MEDIC INTERACTIONS */
	// Revive

	class Person {
		class GiveKeys {
			title = "Give Keys";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_giveVehicleKeys";
			condition = "true";
		};

		class Unrestrain {
			title = "Unrestrain";
			factions[] = { "Police" };
			onClick = "[_this select 0, player, false] call ULP_fnc_restrain; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained";
		};
		class Escort : Unrestrain {
			title = "Escort";
			onClick = "[_this select 0, player, true] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { !([_this] call ULP_fnc_isEscorted) }";
		};
		class StopEscort : Unrestrain {
			title = "Stop Escorting";
			onClick = "[_this select 0, player, false] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [_this] call ULP_fnc_isEscorted }";
		};

		class Imprision : Unrestrain {
			title = "Send to Prison";
			onClick = "_this call ULP_fnc_setPrisonTime; closeDialog 0;";
			condition = "[player] call ULP_fnc_canImprison && { [_this] call ULP_fnc_canImprisoned }";
		};

		// Admin Commands...
		class AdminHeal {
			title = "Admin Heal";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "(_this select 0) setDamage 0; [format[""You've healed this player using admin powers...""]] call ULP_fnc_hint; [getPlayerUID player, ""Admin"", [""AdminHeal"", serverTime, [name (_this select 0)]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2]; closeDialog 0;";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { (damage _this) > 0 } && { [""Heal"", false] call ULP_fnc_checkPower }";
		};
	};

	class PersonMedical {
		class AdministerBlood {
			title = "Administer Blood";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_administerBlood";
			condition = "(0 max ([""BloodBag""] call ULP_fnc_hasItem)) > 0";
		};
	};

	class PersonEscortOnly {
		class StopEscort {
			title = "Stop Escorting";
			factions[] = { "Police" };
			onClick = "[_this select 0, player, false] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [_this] call ULP_fnc_isEscorted }";
		};
	};

	class House {
		class BuyHouse {
			title = "Buy House";
			factions[] = { "Civilian" };
			onClick = "_this call ULP_fnc_buyHouse;";
			condition = "isClass (missionConfigFile >> ""CfgFactions"" >> [player] call ULP_fnc_getFaction >> ""Housing"") && { !([_this] call ULP_fnc_isHouseOwned) }";
		};
	};

	class HouseOwner {
		class SellHouse {
			title = "Sell House";
			factions[] = { "Civilian" };
			onClick = "_this call ULP_fnc_sellHouse;";
			condition = "[_this, player, false] call ULP_fnc_isHouseOwner";
		};
	};

	class EquipmentBox {
		class ClearBox {
			title = "Clear Box";
			factions[] = { "Police" };
			onClick = "_this call ULP_fnc_clearCargo;";
			condition = "true";
		};
		
		class ResetLoadout {
			title = "Reset Loadout";
			factions[] = { "Police", "Medic", "Hato" };
			onClick = "[] call ULP_fnc_setLoadout;";
			condition = "[[player] call ULP_fnc_getFaction] call ULP_fnc_canResetLoadout;";
		};
	};

	class Vault {
		class Repair {
			title = "Repair Vault";
			factions[] = { "Police" };
			onClick = "[""Repairing Vault"", 60, _this, { (player distance (_this select 0)) <= 5 }, { private _object = _this select 0; [""You have successfully reapired the lock!""] call ULP_fnc_hint; _object setVariable [""drilled"", false, true]; }, {}, [""GRAB"", ""CROUCH""]] call ULP_UI_fnc_startProgress;";
			condition = "_this getVariable [""drilled"", true]";
		};
	};

	class Vehicle {

		class Repair {
			title = "Repair";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_repairVehicle";
			condition = "true";
		};

		class Lockpick : Repair {
			title = "Lockpick";
			onClick = "_this call ULP_fnc_lockpickVehicle";
			condition = "!([player, _this] call ULP_fnc_isVehicleOwner) && { [""Lockpick""] call ULP_fnc_hasItem > 0 }";
		};

		class Registration : Repair {
			title = "Registration";
			onClick = "closeDialog 0; [(_this select 0)] call ULP_fnc_vehicleRegistration";
			factions[] = { "Police", "Hato" };
		};

		class Clamp : Repair {
			title = "Clamp";
			onClick = "_this call ULP_fnc_clampVehicle";
			factions[] = { "Police", "Hato" };
		};

		// TODONOW
		class Search : Repair {
			title = "Search";
			onClick = "hint ""Hello"";";
			factions[] = { "Police" };
		};

		class Garage : Repair {
			title = "Garage";
			onClick = "_this call ULP_fnc_garageVehicle";
			factions[] = { "Police", "Hato" };
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess || { [""Medic_Main"", 2] call ULP_fnc_hasAccess }";
		};

		class Impound : Repair {
			title = "Impound";
			onClick = "_this call ULP_fnc_impoundVehicle";
			factions[] = { "Police", "Hato" };
			condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess";
		};

		class Scrap : Repair {
			title = "Scrap";
			onClick = "_this call ULP_fnc_crushVehicle";
			factions[] = { "Police" };
			condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess";
		};

		class PulloutOccupants : Repair {
			title = "Pullout Occupants";
			onClick = "if (_this call ULP_fnc_ejectVehicleCrew) then { closeDialog 0; };";
			// TODONOW : Condition Keys or (Police or License) & canMove ! on veh
		};

		// TODONOW
		class Push : Repair {
			title = "Push";
			onClick = "hint ""Hello"";";
		};

		// Admin Commands...
		class AdminRepair {
			title = "Admin Repair";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "(_this select 0) setDamage 0; [format[""You've repaired this vehicle using admin powers.""]] call ULP_fnc_hint; [getPlayerUID player, ""Admin"", [""AdminRepair"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Vehicle"", false] call ULP_fnc_checkPower }";
		};
		class AdminRefuel {
			title = "Admin Refuel";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "if ((count (units (_this select 0))) > 0) exitWith { [""No one can be in the vehicle while its refueled!""] call ULP_fnc_hint; }; [(_this select 0), 1] remoteExecCall [""ULP_fnc_setFuel"", (_this select 0)]; hint format[""You've refueled this vehicle using admin powers...""]; [getPlayerUID player, ""Admin"", [""AdminFuel"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Vehicle"", false] call ULP_fnc_checkPower }";
		};
	};
};