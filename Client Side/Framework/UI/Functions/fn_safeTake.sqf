#include "..\..\script_macros.hpp"
/*
    File: fn_safeTake.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Gateway to fn_vehTakeItem.sqf but for safe(s).
*/
private ["_ctrl","_num","_safeInfo"];
disableSerialization;

if ((lbCurSel 3502) isEqualTo -1) exitWith {hint "You need to select an item!";};
_ctrl = CONTROL_DATA(3502);
_num = ctrlText 3505;
_safeInfo = life_safeObj getVariable ["safe",0];

//Error checks
if (!([_num] call TON_fnc_isnumber)) exitWith {hint "Invalid number format";};
_num = parseNumber(_num);
if (_num < 1) exitWith {hint "You can't enter anything below 1!";};
if (!(_ctrl isEqualTo "goldBar")) exitWith {hint "You can't store anything but gold bars in the safe."};
if (_num > _safeInfo) exitWith {hint format ["There isn't %1 gold bar(s) in the safe!",_num];};

//Secondary checks
_num = [_ctrl,_num,life_carryWeight,life_maxWeight] call life_fnc_calWeightDiff;
if (_num isEqualTo 0) exitWith {hint localize "STR_NOTF_InvFull"};


//Take it
if (!([true,_ctrl,_num] call life_fnc_handleInv)) exitWith {hint localize "STR_NOTF_CouldntAdd";};
life_safeObj setVariable ["safe",_safeInfo - _num,true];
[life_safeObj] call life_fnc_safeInventory;
