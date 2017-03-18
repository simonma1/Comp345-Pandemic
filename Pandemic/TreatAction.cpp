#include "TreatAction.h"

void TreatAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is treating a disease" << endl;
	boardMap->treat(boardMap->getLocationAtId(location));
}

string TreatAction::toString() {
	return "You can treat a disease";
}

TreatAction::TreatAction(){}

TreatAction::TreatAction(string targetColor, Map* boardMap, int location) {
	this->targetColor = targetColor;
	this->boardMap = boardMap;
	this->location = location;
}
