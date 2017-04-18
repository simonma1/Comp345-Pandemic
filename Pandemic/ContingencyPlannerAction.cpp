#include "ContingencyPlannerAction.h"
#include <string>
#include <iostream>

using namespace std;

ContingencyPlannerAction::ContingencyPlannerAction(vector<PlayerCard*>* playerCardDiscard) {
	this->playerCardDiscard = playerCardDiscard;
}

void ContingencyPlannerAction::act(Player *player) {
	//traverse the discard deck and look for an event card that will be handed to a contingency planner
	bool cardFound = false;
	if (playerCardDiscard != NULL) {
		for (int i = 0; i < playerCardDiscard->size(); i++) {
			if (playerCardDiscard->at(i)->getType() == "event" && cardFound == false) {
				player->addPlayerCard(playerCardDiscard->at(i));
				playerCardDiscard->erase(playerCardDiscard->begin() + i);
				cardFound = true;
			}
		}
		//If here, there are no event cards in the player discard pile
		cout << "There are no event cards in the player discard pile." << endl;
	}
}

string ContingencyPlannerAction::toString() {
	return "Contingency Planner: take an event card from anywhere in the player discard pile.";
}
