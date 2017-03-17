#include "RoleAction.h"

void RoleAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is using his role's action" << endl;
}
