#include "..\..\script_macros.hpp"
/*
    File: fn_adminTpInVehicle.sqf
    Author: Lewis Mackinnon
*/

if ((FETCH_CONST(life_adminlevel) < 2) && admin_duty) exitWith {closeDialog 0; hint "You must be <t color = '#7300e6'>on-duty</t> to use this."};

private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);
_target = call compile format ["%1", _target];

if (isNil "_target" || isNull _target) exitWith {};
if (_target == player) exitWith {hint "You are unable to do this.";};

if (vehicle _target isEqualTo _target) exitWith {hint "You cannot teleport in this player's as they are not inside of a vehicle."};

_vehicle = vehicle _target;
player moveInCargo _vehicle
hint format ["You have teleported in the vehicle of <t color = '#7300e6'>%1</t>.",_target getVariable ["realname",name _target]];
