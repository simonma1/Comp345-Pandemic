#pragma once
#include "RoleAction.h"

class ContingencyPlannerAction : public RoleAction {
public:
	ContingencyPlannerAction() {};
	void act(Player *);
	string toString();
	//bool canPerformRoleAction(Player *);
};