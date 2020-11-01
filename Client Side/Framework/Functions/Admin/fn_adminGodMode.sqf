#include "..\..\script_macros.hpp"
/*
    File: fn_adminGodMode.sqf
    Author: Tobias 'Xetoxyc' Sittenauer

    Description: Enables God mode for Admin
*/

if (FETCH_CONST(life_adminlevel) < 4) exitWith {closeDialog 0; hint "Your Staff Level is not high enough.";};

closeDialog 0;

if (life_god) then {
    life_god = false;
    titleText ["Godmode disabled","PLAIN"]; titleFadeOut 2;
    player allowDamage true;
} else {
    life_god = true;
    titleText ["Godmode enabled","PLAIN"]; titleFadeOut 2;
    player allowDamage false;
};