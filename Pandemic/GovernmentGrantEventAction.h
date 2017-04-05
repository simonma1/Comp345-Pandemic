#pragma once
#include "EventAction.h"

class GovernmentGrantEventAction : public EventAction {

public:
	GovernmentGrantEventAction();
	GovernmentGrantEventAction(vector<int>*, vector<PlayerCard*>*, int);
	void act(Player *);
	string toString();

private:
	vector<int>* boardResearchStations;
	vector<PlayerCard*>* playerCardDiscard;
	int cardPosition, randomCityId;
};
