#include "ShuttleFlightAction.h"

void ShuttleFlightAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is taking a shuttle flight" << endl;
}

ShuttleFlightAction::ShuttleFlightAction(){}

ShuttleFlightAction::ShuttleFlightAction(int otherRSLocationId) {
	this->otherRSLocationId = otherRSLocationId;
}
