#pragma once
#include "Action.h"

class OtherAction : public Action {
public:
	virtual void act(Player *) = 0;
};