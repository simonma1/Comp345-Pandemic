#pragma once
#include "RoleAction.h"

class OperationsExpertAction : public RoleAction {
public:
	virtual void act(Player *) = 0;
	virtual string toString() = 0;
};