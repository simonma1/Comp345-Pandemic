#pragma once
#include "ShareAction.h"

class ShareGiveAction : public ShareAction {
public:
	void act(Player*);
	ShareGiveAction();
	ShareGiveAction(Player*);

private:
	Player *playerYouCanGiveTo;
};
