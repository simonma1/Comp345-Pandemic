#pragma once
#include "ShareAction.h"

class ShareGiveAction : public ShareAction {
public:
	void act(Player*);
	string toString();
	ShareGiveAction();
	ShareGiveAction(Player*);
	~ShareGiveAction();

private:
	Player *playerYouCanGiveTo;
};
