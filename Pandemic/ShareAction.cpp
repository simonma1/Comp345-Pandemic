#include "ShareAction.h"

void ShareAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is sharing knowledge" << endl;
}
