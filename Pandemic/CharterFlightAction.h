#pragma once
#include "MovementCardAction.h"

class CharterFlightAction : public MovementCardAction {
public:
	void act(Player *);
	string toString();
};
