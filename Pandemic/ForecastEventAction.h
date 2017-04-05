#pragma once
#include "EventAction.h"
#include "InfectionCard.h"

class ForecastEventAction : public EventAction {

public:
	ForecastEventAction();
	ForecastEventAction(vector<InfectionCard*>, vector<PlayerCard*>*);
	void act(Player *);
	string toString();

private:
	vector<InfectionCard*> infectionCardDeck;
	vector<PlayerCard*>* playerCardDiscard;
	int cardPosition;
};
