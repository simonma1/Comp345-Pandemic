#pragma once
#include "RoleAction.h"

class QuarantineSpecialistAction : public RoleAction {
public:
	QuarantineSpecialistAction() {};
	void act(Player *);
	string toString();
	//bool canPerformRoleAction(Player *);
};