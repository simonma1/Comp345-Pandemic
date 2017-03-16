#pragma once
#include "RoleAction.h"

class ScientistAction : public RoleAction {
public:
	ScientistAction();
	void act(Player *);
	string toString();
};
