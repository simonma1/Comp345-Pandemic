#include "ShareGiveAction.h"

void ShareGiveAction::act(Player *player) {
	cout << player->getRole()->getName() + " is performing a share give action" << endl;
}

string ShareGiveAction::toString() {
	return "You can share your knowledge with the " + playerYouCanGiveTo->getRole()->getName();
}

ShareGiveAction::ShareGiveAction(){}

ShareGiveAction::ShareGiveAction(Player *playerYouCanGiveTo) {
	this->playerYouCanGiveTo = playerYouCanGiveTo;
}

ShareGiveAction::~ShareGiveAction() {
	playerYouCanGiveTo = NULL;
}
