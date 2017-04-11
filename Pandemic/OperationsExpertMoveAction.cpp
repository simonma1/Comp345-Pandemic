#include "OperationsExpertMoveAction.h"
#include <string>
#include <iostream>

using namespace std;

OperationsExpertMoveAction::OperationsExpertMoveAction(int destinationId, vector<PlayerCard*>* playerCardDiscard, vector<PlayerCard*>* playerCardDeck) {
	this->destinationId = destinationId;
	this->playerCardDiscard = playerCardDiscard;
	this->playerCardDeck = playerCardDeck;
}

void OperationsExpertMoveAction::act(Player *player) {
	OperationsExpertMoveAction::setActionCalled(true);
	cout << player->getRole()->getName() << " Is on a direct flight to " + to_string(destinationId) << endl;
	player->getPlayerPawn()->setLocation(destinationId);

	int cardPosition = 0; // to find the card being discarded in order to perform the action
	bool cardFound = false;

	for (int i = 0; i < player->getPlayerCards().size(); i++) { // find which card is being discarded
		if (player->getPlayerCards()[i]->getId() == destinationId) {
			cardPosition = i;
			playerCardDiscard->push_back(player->getPlayerCards()[cardPosition]);
			player->removePlayerCard(destinationId);
			cardFound = true;
			break;
		}
	}
	//if player does not have the city card for the city that he/she wants to move to, check the player card deck
	if (cardFound == false) {
		for (int i = 0; i < playerCardDeck->size(); i++) { // traverse the player card deck looking for the city that an operations expert wants to move to 
			if (playerCardDeck->at(i)->getId() == destinationId) {
				cardPosition = i;
				playerCardDiscard->push_back(playerCardDeck->at(cardPosition));
				playerCardDeck->erase(playerCardDeck->begin() + cardPosition);
				break;
			}
		}
	}
}

string OperationsExpertMoveAction::toString() {
	return "Operations Expert: As an action, move from a research station to any city through a direct flight by discarding any City card once per turn.";
}
