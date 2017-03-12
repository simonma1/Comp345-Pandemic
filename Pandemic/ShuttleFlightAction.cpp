#include "ShuttleFlightAction.h"

void ShuttleFlightAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is taking a shuttle flight" << endl;
}
