#pragma once
#include "RoleAction.h"

class DispatcherAction : public RoleAction {
public:
	DispatcherAction() {};
	void act(Player *);
	string toString();
	//bool canPerformRoleAction(Player *);
};