#include "DirectFlightAction.h"

DirectFlightAction::DirectFlightAction() {}

DirectFlightAction::DirectFlightAction(int destinationId) {
	this->destinationId = destinationId;
}

void DirectFlightAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is on a direct flight to " + to_string(destinationId) << endl;
}

string DirectFlightAction::toString() {
	return "You can perform a Direct Flight to " + to_string(destinationId);
}
