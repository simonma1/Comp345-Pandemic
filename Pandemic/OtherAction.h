#pragma once
#include "Action.h"

class OtherAction : public Action {
public:
	virtual void act(Player *) = 0;
	virtual string toString() = 0;
};