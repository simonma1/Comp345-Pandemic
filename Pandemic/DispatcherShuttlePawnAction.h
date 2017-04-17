#pragma once
#include "RoleAction.h"

class DispatcherShuttlePawnAction : public RoleAction {
public:
	DispatcherShuttlePawnAction() {};
	DispatcherShuttlePawnAction(int, Player*);
	void act(Player *);
	string toString();

private:
	int destinationId;
	Player* pawnOwner;
};
