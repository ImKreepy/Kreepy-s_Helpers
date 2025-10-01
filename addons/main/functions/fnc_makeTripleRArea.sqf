#include "..\script_component.hpp"
/*
 * Authors: Im Kreepy
 * Turns synced triggers into tripple R areas.
 *
 * Arguments:
 * 0: _logic (optional, default: objNull) <OBJECT>
 * 1: _units (optional, default: []) <ARRAY>
 * 2: _activated (optional, default: true) <BOOL>
 *
 * Return Value:
 * Module Activated <BOOL>
 *
 * Example:
 * [_logic,_units,_activated] call kh_fnc_makeTripleRArea
 *
 * Public: No
 */

params [
	["_logic", objNull, [objNull]],
	["_units", [], [[]]],
	["_activated", true, [true]]
];

{
    _x setTriggerActivation ["ANYPLAYER", "PRESENT", true];
    _x setTriggerStatements [
        "this",
        QUOTE({_x setdammage 0; _x setfuel 1; _x setVehicleAmmo 1} forEach thislist;),
        ""
    ];
} forEach _units;
true;
