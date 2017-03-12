#pragma once
#include "MovementCardAction.h"

class DirectFlightAction : public MovementCardAction {
public:
	void act(Player *);
};
