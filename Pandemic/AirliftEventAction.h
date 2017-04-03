#pragma once
#include "EventAction.h"

class AirliftEventAction : public EventAction {

public:
	AirliftEventAction();
	AirliftEventAction(int, string);
	void act(Player *);
	string toString();

private:
	int destinationId;
	string permissionFromOther;
};
