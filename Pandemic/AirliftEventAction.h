#pragma once
#include "EventAction.h"

class AirliftEventAction : public EventAction {

public:
	AirliftEventAction();
	AirliftEventAction(int, vector<PlayerCard*>*);
	void act(Player *);
	string toString();

private:
	int destinationId;
	vector<PlayerCard*>* playerCardDiscard;
	int cardPosition;
};
