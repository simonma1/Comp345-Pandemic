#include "DiscoverCureAction.h"

void DiscoverCureAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is discovering a cure" << endl;
}

DiscoverCureAction::DiscoverCureAction(){}

DiscoverCureAction::DiscoverCureAction(string curableArea) {
	this->curableArea = curableArea;
}