/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#define CFG missionConfigFile >> "CfgFactions"
scopeName "fn_calcPaycheck";

private _faction = CFG >> [player] call ULP_fnc_getFaction;

private _pay = getNumber ([
	CFG >> "fallbackPay",
	_faction >> "pay"
] select (isClass (_faction)));

if (isClass (_faction >> "Whitelisting")) then {
	{
		_pay = _pay + ((_pay * getNumber (_x >> "payMulti")) * (call (missionNamespace getVariable format["%1_%2", configName _faction, configName _x])));
	} forEach ("isNumber(_x >> 'payMulti')" configClasses (_faction >> "Whitelisting"));
};

if (["GovernmentBonus"] call ULP_fnc_hasPerk) then { _pay = _pay * 1.3 };
if (["ULP_SRV_Setting_DonationGoal"] call ULP_fnc_constant) then { _pay = _pay * getNumber(missionConfigFile >> "CfgSettings" >> "DonationRewards" >> "payIncrease"); };

(round _pay)