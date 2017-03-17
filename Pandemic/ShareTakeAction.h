#pragma once
#include "ShareAction.h"

class ShareTakeAction : public ShareAction {
public:
	void act(Player*);
	string toString();
	ShareTakeAction();
	ShareTakeAction(Player*, int);
	~ShareTakeAction();

private:
	Player *playerYouCanTakeFrom;
	int cardPosition;
};
