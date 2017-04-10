#include "TreatAction.h"

void TreatAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is treating the " + targetColor + " disease\n" << endl;
	boardMap->treat(boardMap->getLocationAtId(location), targetColor);
}

string TreatAction::toString() {
	return "You can treat the " + targetColor + " disease";
}

TreatAction::TreatAction(){}

TreatAction::TreatAction(string targetColor, Map* boardMap, int location) {
	this->targetColor = targetColor;
	this->boardMap = boardMap;
	this->location = location;
}
