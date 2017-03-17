#pragma once
#include "MovementCardAction.h"

class DirectFlightAction : public MovementCardAction {
public:
	DirectFlightAction();
	DirectFlightAction(int, vector<PlayerCard*>*);
	void act(Player *);
	int getDestination() { return destinationId; };
	string toString();

private:
	int destinationId;
	vector<PlayerCard*>* playerCardDiscard;
};
