#include "..\..\script_macros.hpp"
/*
    File: fn_virt_sell.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Sell a virtual item to the store / shop
*/
private ["_type","_index","_price","_amount","_name"];
if ((lbCurSel 2402) isEqualTo -1) exitWith {};
_type = lbData[2402,(lbCurSel 2402)];
_price = M_CONFIG(getNumber,"CfgItems",_type,"sellPrice");
if (_price isEqualTo -1) exitWith {};

_amount = ctrlText 2405;
if (!([_amount] call TON_fnc_isnumber)) exitWith {hint "You didn't enter an actual number";};
_amount = parseNumber (_amount);
if (_amount > (ITEM_VALUE(_type))) exitWith {hint "You don't have that many items to sell!"};
if ((time - life_action_delay) < 0.2) exitWith {hint "You're doing it too fast!";};
life_action_delay = time;

_price = (_price * _amount);
_name = M_CONFIG(getText,"CfgItems",_type,"displayName");
if ([false,_type,_amount] call life_fnc_handleInv) then {
    hint format ["You sold %1 %2 for £%3.",_amount,_name,[_price] call life_fnc_numberText];
    CASH = CASH + _price;
    [0] call SOCK_fnc_updatePartial;
    [] call life_fnc_virt_update;
};

if (life_shop_type isEqualTo "drugdealer") then {
    private ["_array","_ind","_val"];
    _array = life_shop_npc getVariable ["sellers",[]];
    _ind = [getPlayerUID player,_array] call TON_fnc_index;
    if (!(_ind isEqualTo -1)) then {
        _val = ((_array select _ind) select 2);
        _val = _val + _price;
        _array set[_ind,[getPlayerUID player,profileName,_val]];
        life_shop_npc setVariable ["sellers",_array,true];
    } else {
        _array pushBack [getPlayerUID player,profileName,_price];
        life_shop_npc setVariable ["sellers",_array,true];
    };
};

if (life_shop_type isEqualTo "gold" && (LIFE_SETTINGS(getNumber,"atm_cooldown")) > 0) then {
    [] spawn {
        life_use_atm = false;
        sleep ((LIFE_SETTINGS(getNumber,"atm_cooldown")) * 60);
        life_use_atm = true;
    };
};

[3] call SOCK_fnc_updatePartial;