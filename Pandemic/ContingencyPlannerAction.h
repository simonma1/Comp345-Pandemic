#pragma once
#include "RoleAction.h"

class ContingencyPlannerAction : public RoleAction {
public:
	ContingencyPlannerAction() {};
	ContingencyPlannerAction(vector<PlayerCard*>*);
	void act(Player *);
	string toString();

private:
	vector<PlayerCard*>* playerCardDiscard;
};