#include "EventAction.h"

void EventAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is using an event action" << endl;
}
