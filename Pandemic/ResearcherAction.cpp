#include "ResearcherAction.h"
#include <string>
#include <iostream>

using namespace std;

void ResearcherAction::act(Player *player) {
	cout << player->getRole()->getName() << " Give/take any city card from the same city" << endl;
}

string ResearcherAction::toString() {
	return "Researcher: As an action, you may give (or a player can take) any City card from your hand. You must both be in the same city.The card does not have to match the city you are in.";
}

/*
bool Researcher::canPerformRoleAction(Player *player) {
	if (player->getRole()->getName == "Researcher") {
		return true;
	}
	else
		return false;
}
*/