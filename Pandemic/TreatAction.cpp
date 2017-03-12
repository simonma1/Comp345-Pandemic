#include "TreatAction.h"

void TreatAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is treating a disease" << endl;
}

TreatAction::TreatAction(){}

TreatAction::TreatAction(string targetColor) {
	this->targetColor = targetColor;
}
