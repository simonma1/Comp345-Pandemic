#pragma once
#include "ShareAction.h"

class ShareTakeAction : public ShareAction {
public:
	void act(Player*);
	ShareTakeAction();
	ShareTakeAction(Player*);

private:
	Player *playerYouCanTakeFrom;
};
