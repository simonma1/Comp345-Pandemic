#pragma once
#include "Action.h"

class MovementAction : public Action {
public:
	virtual void act(Player *) = 0;
	virtual string toString() = 0;
};