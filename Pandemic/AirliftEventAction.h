#pragma once
#include "EventAction.h"
#include "Player.h"

class AirliftEventAction : public EventAction {

public:
	AirliftEventAction();
	AirliftEventAction(int, Player*, vector<PlayerCard*>*);
	void act(Player *);
	string toString();

private:
	int destinationId;
	Player* pawnOwner;
	vector<PlayerCard*>* playerCardDiscard;
	int cardPosition;
};
