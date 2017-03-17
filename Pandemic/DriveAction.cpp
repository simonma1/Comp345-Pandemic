#include "DriveAction.h"

void DriveAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is driving to " + to_string(destinationId) << endl;
	player->movePawn(destinationId);
}

DriveAction::DriveAction(){}

DriveAction::DriveAction(int destinationId) {
	this->destinationId = destinationId;
}

string DriveAction::toString() {
	return "You can drive to " + to_string(destinationId);
}
