#include "DirectFlightAction.h"

DirectFlightAction::DirectFlightAction() {}

DirectFlightAction::DirectFlightAction(int destinationId) {
	this->destinationId = destinationId;
}

void DirectFlightAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is on a direct flight" << endl;
}
