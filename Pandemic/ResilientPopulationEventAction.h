#pragma once
#include "EventAction.h"
#include "InfectionCard.h"

class ResilientPopulationEventAction : public EventAction {

public:
	ResilientPopulationEventAction();
	ResilientPopulationEventAction(vector<InfectionCard*>, vector<PlayerCard*>*);
	void act(Player *);
	string toString();

private:
	vector<InfectionCard*> infectionCardDiscard;
	vector<PlayerCard*>* playerCardDiscard;
	int cardPosition;
};
