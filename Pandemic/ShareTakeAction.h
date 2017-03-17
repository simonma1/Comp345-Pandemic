#pragma once
#include "ShareAction.h"

class ShareTakeAction : public ShareAction {
public:
	void act(Player*);
	string toString();
	ShareTakeAction();
	ShareTakeAction(Player*);
	~ShareTakeAction();

private:
	Player *playerYouCanTakeFrom;
};
