#include "OperationsExpertAction.h"
#include <string>
#include <iostream>

using namespace std;

void OperationsExpertAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is building a research station in same city" << endl;
}

string OperationsExpertAction::toString() {
	return "Operations Expert: As an action, build a research station in the city you are in (no City card needed) and move from a research station to an city by discarding any City card once per turn.";
}
