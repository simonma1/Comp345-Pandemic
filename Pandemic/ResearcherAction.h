#pragma once
#include "RoleAction.h"

class ResearcherAction : public RoleAction {
public:
	ResearcherAction() {};
	void act(Player *);
	string toString();
};