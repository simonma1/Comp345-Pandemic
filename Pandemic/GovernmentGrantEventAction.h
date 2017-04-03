#pragma once
#include "EventAction.h"
#include "Map.h"

class GovernmentGrantEventAction : public EventAction {

public:
	GovernmentGrantEventAction();
	GovernmentGrantEventAction(vector<int>*, Map* boardMap, int location);
	void act(Player *);
	string toString();

private:
	vector<int>* boardResearchStations;
	Map* boardMap;
	int location;
};
