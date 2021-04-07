/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_spawnMenu";

if (ULP_Imprisioned && { [player, ULP_Prison_Time, objNull, false] call ULP_fnc_imprison }) exitWith {
	cutText [ "", "BLACK IN" ];
};

disableSerialization;

if !(createDialog "DialogSpawn") exitWith {
	["Abort", true, false] call BIS_fnc_endMission;
};

private _display = findDisplay 3000;
if (isNull _display) exitWith {};

_display displaySetEventHandler ["keyDown","_this call ULP_UI_fnc_blockEsc"];

private _map = _display displayCtrl 3001;
_map ctrlEnable false;

private _list = _display displayCtrl 3002;
lbClear _list;

private _item = -1;
private _icon = "";

{
	if (call compile getText(_x >> "conditions") && { [player, getArray(_x >> "factions")] call ULP_fnc_isFaction }) then {
		_item = _list lbAdd getText(_x >> "displayName");
		_icon = getText(_x >> "icon");

		if !(_icon isEqualTo "") then {
			_list lbSetPicture [_item, _icon];
		};
		
		_list lbSetValue [_item, 0];
		_list lbSetData [_item, configName _x];
	};
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgSpawns" >> worldName));

if (isClass (missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction >> "Housing")) then {
	{
		private _cfg = [typeOf _x] call ULP_fnc_vehicleCfg;

		if ([getNumber (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _x) >> "canSpawn")] call ULP_fnc_bool) then {
			_item = _list lbAdd (_x getVariable ["building_name", (_cfg param [3, "House"])]);;
			_list lbSetValue [_item, 1];
			_list lbSetData [_item, _x call BIS_fnc_netId];
		};
	} forEach ULP_Houses;
};

{
	if ([configName _x, player] call ULP_fnc_ownsBase) then {
		_item = _list lbAdd getText (_x >> "displayName");
		_list lbSetValue [_item, 2];
		_list lbSetData [_item, getText (_x >> "Spawn" >> "marker")];
	};
} forEach ("isClass (_x >> ""Spawn"")" configClasses (missionConfigFile >> "CfgBases"));

_list lbSetCurSel 0;
[_list, 0, 0] call ULP_fnc_changeSpawn;
_list ctrlSetEventHandler ["LBSelChanged", "_this call ULP_fnc_changeSpawn;"];