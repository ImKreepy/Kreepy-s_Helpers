#include "..\script_component.hpp"
/*
 * Authors: Im Kreepy
 * Rescales object to a specified amount.
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
 * [_logic,_units,_activated] call kh_fnc_rescaleObjects
 *
 * Public: No
 */

params [
	["_logic", objNull, [objNull]],
	["_units", [], [[]]],
	["_activated", true, [true]]
];

private _scale = _logic getVariable ["RescaleFactor", 1];
private _objectPosition = getPosATL (_units select 0);
private _attachObject = "IK_Stand_In" createVehicle _objectPosition;
hideObjectGlobal _attachObject;
{
	_x attachTo [_attachObject];
	waitUntil { attachedTo _x == _attachObject; };
	if (!simulationEnabled _x) then {
		_x enableSimulationGlobal true;
	};
	if (!isSimpleObject _x) then {
		private _pos = getPosWorld _x;
		private _dir = getDir _x;
		sleep 0.1;
		deleteVehicle _x;
		sleep 0.1;
		private _simpleObject = createSimpleObject [typeOf _x, _pos];
		_simpleObject setObjectScale _scale;
		_simpleObject setDir _dir;
	};
	_x setObjectScale _scale
} forEach _units;
true;
