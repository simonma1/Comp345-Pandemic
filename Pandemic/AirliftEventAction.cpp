#include "AirliftEventAction.h"

AirliftEventAction::AirliftEventAction() {
}

AirliftEventAction::AirliftEventAction(int destinationId, vector<PlayerCard*>* playerCardDiscard) {
	this->destinationId = destinationId;
	this->playerCardDiscard = playerCardDiscard;
}

void AirliftEventAction::act(Player * player) {
	//The idea is to move a pawn to any city (this will be decided and checked on the board) as long as the permission is received from owner of the pawn
	//(again a player will be prompted on the console).
	cout << player->getRole()->getName() << " Is, due to an airlift event action, being moved to " + to_string(destinationId) << endl;
	player->getPlayerPawn()->setLocation(destinationId);

	bool cardFound = false;
	for (int i = 0; i < player->getPlayerCards().size(); i++) { // find which card is being discarded
		if (player->getPlayerCards()[i]->getCardName() == "Airlift" && cardFound == false) {
			cardPosition = i;
			cardFound = true;
		}
	}
	playerCardDiscard->push_back(player->getPlayerCards()[cardPosition]);
	player->removePlayerCard(player->getPlayerCards()[cardPosition]->getId());
}


string AirliftEventAction::toString() {
	return "Move any 1 pawn to any city. Get permission before moving another player's pawn";
}
