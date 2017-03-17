#include "DirectFlightAction.h"

DirectFlightAction::DirectFlightAction() {}

DirectFlightAction::DirectFlightAction(int destinationId, vector<PlayerCard*>* playerCardDiscard) {
	this->destinationId = destinationId;
	this->playerCardDiscard = playerCardDiscard;
}

void DirectFlightAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is on a direct flight to " + to_string(destinationId) << endl;
	player->getPlayerPawn()->setLocation(destinationId);

	int cardPosition = 0; // to find the card being discarded in order to perform the direct flight action
	
	for (int i = 0; i < player->getPlayerCards().size(); i++) { // find which card is being discarded
		if (player->getPlayerCards()[i]->getId() == destinationId) {
			cardPosition = i;
		}
	}

	playerCardDiscard->push_back(player->getPlayerCards()[cardPosition]);
	//playerCardDiscard.push_back(new CityCard());
	
	player->removePlayerCard(destinationId);
}

string DirectFlightAction::toString() {
	return "You can perform a Direct Flight to " + to_string(destinationId);
}
