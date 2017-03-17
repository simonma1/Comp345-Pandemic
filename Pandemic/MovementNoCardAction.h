#pragma once
#include "MovementAction.h"

class MovementNoCardAction : public MovementAction {
public:
	virtual void act(Player *) = 0;
	virtual string toString() = 0;
};