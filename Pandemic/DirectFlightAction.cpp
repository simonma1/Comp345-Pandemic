#include "DirectFlightAction.h"

DirectFlightAction::DirectFlightAction() {}

DirectFlightAction::DirectFlightAction(int destination) {
	this->destination = destination;
}

void DirectFlightAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is on a direct flight" << endl;
}
