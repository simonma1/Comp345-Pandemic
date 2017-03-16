#include "ContingencyPlannerAction.h"
#include <string>
#include <iostream>

using namespace std;

void ContingencyPlannerAction::act(Player *player) {
	cout << player->getRole()->getName() << "Select a discarded Event card and remove from the game" << endl;
}

string ContingencyPlannerAction::toString() {
	return "Dispatcher: As an action, take any discarded Event card and store it on this card and to remove a played stored Event card from the game(Limit: 1 event card on this card at a time, which is not part of your hand.";
}

/*
bool ContingencyPlanner::canPerformRoleAction(Player *player) {
	if (player->getRole()->getName == "Contingency Planner") {
		return true;
	}
	else
		return false;
}
*/