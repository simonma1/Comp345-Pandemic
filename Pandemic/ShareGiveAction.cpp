#include "ShareGiveAction.h"

void ShareGiveAction::act(Player *player) {
	cout << player->getRole()->getName() + " is performing a share give action" << endl;
}

ShareGiveAction::ShareGiveAction(){}

ShareGiveAction::ShareGiveAction(Player *playerYouCanGiveTo) {
	this->playerYouCanGiveTo = playerYouCanGiveTo;
}
