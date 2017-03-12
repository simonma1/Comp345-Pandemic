#pragma once
#include "MovementCardAction.h"

class DirectFlightAction : public MovementCardAction {
public:
	DirectFlightAction();
	DirectFlightAction(int);
	void act(Player *);
	int getDestination() { return destination; };

private:
	int destination;
};
