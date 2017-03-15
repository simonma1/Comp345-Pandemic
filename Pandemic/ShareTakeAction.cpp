#include "ShareTakeAction.h"

void ShareTakeAction::act(Player *player) {
	cout << player->getRole()->getName() + " is performing a share take action" << endl;
}

string ShareTakeAction::toString() {
	return "You can receive knowledge from the " + playerYouCanTakeFrom->getRole()->getName();
}

ShareTakeAction::ShareTakeAction(){}

ShareTakeAction::ShareTakeAction(Player *playerYouCanTakeFrom) {
	this->playerYouCanTakeFrom = playerYouCanTakeFrom;
}

ShareTakeAction::~ShareTakeAction() {
	playerYouCanTakeFrom = NULL;
}
