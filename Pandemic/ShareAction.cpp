#include "ShareAction.h"

void ShareAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is sharing knowledge" << endl;
}

ShareAction::ShareAction(){}

ShareAction::ShareAction(Player * playerYouCanShareWith) {
	this->playerYouCanShareWith = playerYouCanShareWith;
}

ShareAction::~ShareAction() {
	playerYouCanShareWith = NULL;
}
