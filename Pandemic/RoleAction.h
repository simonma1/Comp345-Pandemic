#pragma once
#include "Action.h"

class RoleAction : public Action {
public:
	virtual void act(Player *) = 0;
	virtual string toString() = 0;
};