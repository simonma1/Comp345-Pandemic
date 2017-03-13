#pragma once
#include "OtherAction.h"

class ShareAction : public OtherAction {
public:
	virtual void act(Player*) = 0;
	virtual string toString() = 0;
	Player* getPlayerYouCanShareWith() { return playerYouCanShareWith; };

private:
	Player *playerYouCanShareWith;
};