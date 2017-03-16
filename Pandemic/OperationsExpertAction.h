#pragma once
#include "RoleAction.h"

class OperationsExpertAction : public RoleAction {
public:
	OperationsExpertAction() {};
	void act(Player *);
	string toString();
	//bool canPerformRoleAction(Player *);
};