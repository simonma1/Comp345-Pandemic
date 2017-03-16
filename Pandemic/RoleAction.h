#pragma once
#include "Action.h"

class RoleAction : public Action {
public:
	virtual void act(Player *) = 0;
	virtual string toString() = 0;
	//virtual bool canPerformRoleAction(Player *) = 0;
};