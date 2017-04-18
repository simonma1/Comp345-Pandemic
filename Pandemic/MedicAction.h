#pragma once
#include "RoleAction.h"
#include "Location.h"
#include "Map.h"
#include <iostream>

class MedicAction : public RoleAction {
public:
	MedicAction(Map* boardMap, Location currentLocation, int currentLocationId);
	void act(Player *);
	string toString();

private:
	Location currentLocation;
	int currentLocationId;
	Map* boardMap;
};