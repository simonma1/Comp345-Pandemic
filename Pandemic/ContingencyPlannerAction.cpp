#include "ContingencyPlannerAction.h"
#include <string>
#include <iostream>

using namespace std;

ContingencyPlannerAction::ContingencyPlannerAction(vector<PlayerCard*>*) {
	this->playerCardDiscard = playerCardDiscard;
}

void ContingencyPlannerAction::act(Player *player) {
	//traverse the discard deck and look for an event card that will handed to a contingency planner
	if (playerCardDiscard != NULL) {
		for (int i = 0; i < playerCardDiscard->size(); i++) {
			if (playerCardDiscard->size() == 0) break;
			if (playerCardDiscard->at(i)->getType() == "event") {
				player->addPlayerCard(playerCardDiscard->at(i));
				break;
			}
		}
	}
}

string ContingencyPlannerAction::toString() {
	return "Continency Planner: Take an event card from anywhere in the player discard pile. Only 1 event card can be added onto this role at a time and removed from game once used";
}
