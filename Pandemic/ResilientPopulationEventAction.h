#pragma once
#include "EventAction.h"
#include "InfectionCard.h"

class ResilientPopulationEventAction : public EventAction {

public:
	ResilientPopulationEventAction();
	ResilientPopulationEventAction(vector<InfectionCard*>*);
	void act(Player *);
	string toString();

private:
	vector<InfectionCard*>* infectionCardDiscard;
};
