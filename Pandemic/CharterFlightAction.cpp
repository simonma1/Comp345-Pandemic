#include "CharterFlightAction.h"

void CharterFlightAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is on a charter flight" << endl;
}

string CharterFlightAction::toString() {
	return "You can perform a Charter Flight";
}
