#include "ShareTakeAction.h"

void ShareTakeAction::act(Player *player) {
	cout << player->getRole()->getName() + " is performing a share take action" << endl;
}

ShareTakeAction::ShareTakeAction(){}

ShareTakeAction::ShareTakeAction(Player *playerYouCanTakeFrom) {
	this->playerYouCanTakeFrom = playerYouCanTakeFrom;
}
