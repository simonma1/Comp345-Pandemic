#include "DriveAction.h"

void DriveAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is driving" << endl;
}
