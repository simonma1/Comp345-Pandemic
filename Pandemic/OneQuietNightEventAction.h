#pragma once
#include "EventAction.h"

class OneQuietNightEventAction : public EventAction {

public:
	OneQuietNightEventAction();
	OneQuietNightEventAction(vector<PlayerCard*>*);
	void act(Player *);
	string toString();

private:
	vector<PlayerCard*>* playerCardDiscard;
	int cardPosition;
};

