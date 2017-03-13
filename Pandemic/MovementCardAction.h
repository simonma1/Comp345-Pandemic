#pragma once
#include "MovementAction.h"

class MovementCardAction : public MovementAction {
public:
	virtual void act(Player *) = 0;
	virtual string toString() = 0;
};