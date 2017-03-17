#pragma once
#include "RoleAction.h"

class MedicAction : public RoleAction {
public:
	MedicAction() {};
	void act(Player *);
	string toString();
};