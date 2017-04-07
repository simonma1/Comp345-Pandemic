#include "ContingencyPlannerAction.h"
#include <string>
#include <iostream>

using namespace std;

ContingencyPlannerAction::ContingencyPlannerAction(vector<PlayerCard*>* playerCardDiscard) {
	this->playerCardDiscard = playerCardDiscard;
}

void ContingencyPlannerAction::act(Player *player) {
	//traverse the discard deck and look for an event card that will be handed to a contingency planner
	if (playerCardDiscard != NULL) {
		for (int i = 0; i < playerCardDiscard->size(); i++) {
			if (playerCardDiscard->at(i)->getType() == "event") {
				player->addPlayerCard(playerCardDiscard->at(i));
				playerCardDiscard->erase(playerCardDiscard->begin() + i);
				break;
			}
		}
		//If here, there are no event cards in the player discard pile
		cout << "There are no event cards in the player discard pile." << endl;
	}
}

string ContingencyPlannerAction::toString() {
	return "Continency Planner: Take an event card from anywhere in the player discard pile. Note that the act of checking the player discard pile will count against your action total even if there are no event cards in the discard pile. Only 1 event card can be added onto this role at a time and removed from game once used";
}
