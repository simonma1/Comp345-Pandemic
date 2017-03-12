#include "DirectFlightAction.h"

void DirectFlightAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is on a direct flight" << endl;
}
