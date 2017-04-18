#pragma once
#include "Action.h"

class EventAction : public Action {
public:
	virtual void act(Player *) = 0;
	virtual string toString() = 0;
};