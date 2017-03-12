#pragma once
#include "OtherAction.h"

class ShareAction : public OtherAction {
public:
	virtual void act(Player*) = 0;
	ShareAction();
	ShareAction(Player*);
	~ShareAction();
	Player* getPlayerYouCanShareWith() { return playerYouCanShareWith; };

private:
	Player *playerYouCanShareWith;
};