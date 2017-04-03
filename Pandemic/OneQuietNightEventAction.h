#pragma once
#include "EventAction.h"

class OneQuietNightEventAction : public EventAction {

public:
	OneQuietNightEventAction();
	void act(Player *);
	string toString();
};

