#pragma once
#include "RoleAction.h"
#include "Map.h"

class QuarantineSpecialistAction : public RoleAction {
public:
	QuarantineSpecialistAction() {};
	QuarantineSpecialistAction(string targetColor, Map* boardMap, int location);
	void act(Player *);
	string toString();

private:
	string targetColor;
	Map* boardMap;
	int location;
	vector<int> cityConnections;
};