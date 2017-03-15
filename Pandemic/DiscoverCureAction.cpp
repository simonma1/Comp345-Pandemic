#include "DiscoverCureAction.h"

void DiscoverCureAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is discovering a cure" << endl;
	*isAreaCured = true;
}

DiscoverCureAction::DiscoverCureAction(){}

DiscoverCureAction::DiscoverCureAction(string curableArea, bool *isAreaCured) {
	this->curableArea = curableArea;
	this->isAreaCured = isAreaCured;
}

string DiscoverCureAction::toString() {
	return "You can discover a Cure for the " + curableArea + " area";
}
