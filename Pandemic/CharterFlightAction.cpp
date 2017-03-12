#include "CharterFlightAction.h"

void CharterFlightAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is on a charter flight" << endl;
}
