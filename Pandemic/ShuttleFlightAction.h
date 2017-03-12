#pragma once
#include "MovementNoCardAction.h"

class ShuttleFlightAction : public MovementNoCardAction {
public:
	void act(Player *);
};
