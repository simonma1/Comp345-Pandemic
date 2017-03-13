#include "ShuttleFlightAction.h"

void ShuttleFlightAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is taking a shuttle flight" << endl;
}

string ShuttleFlightAction::toString() {
	return "You can perform a shuttle flight";
}

ShuttleFlightAction::ShuttleFlightAction(){}

ShuttleFlightAction::ShuttleFlightAction(int otherRSLocationId) {
	this->otherRSLocationId = otherRSLocationId;
}
