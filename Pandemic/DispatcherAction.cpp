#include "DispatcherAction.h"
#include <string>
#include <iostream>

using namespace std;

void DispatcherAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is moving another's pawn" << endl;
}

string DispatcherAction::toString() {
	return "Dispatcher: Move another player's pawn as if it were yours and, as an action, move any pawn to a city with another pawn(must get permission before moving another player's pawn)";
}

/*
bool Dispatcher::canPerformRoleAction(Player *player) {
	if (player->getRole()->getName == "Dispatcher") {
		return true;
	}
	else
		return false;
}
*/