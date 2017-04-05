#include "OneQuietNightEventAction.h"

OneQuietNightEventAction::OneQuietNightEventAction() {
}

OneQuietNightEventAction::OneQuietNightEventAction(vector<PlayerCard*>* playerCardDiscard) {
	this->playerCardDiscard = playerCardDiscard;
}

void OneQuietNightEventAction::act(Player * player) {
	//The idea is to use the board, check if a player has this event card, and skip the startInfection() that will happen once a player has finished his/her turn
	for (int i = 0; i < player->getPlayerCards().size(); i++) { // find which card is being discarded
		if (player->getPlayerCards()[i]->getCardName() == "One Quiet Night") {
			cardPosition = i;
			break;
		}
	}
	playerCardDiscard->push_back(player->getPlayerCards()[cardPosition]);
	player->removePlayerCard(player->getPlayerCards()[cardPosition]->getId());
}

string OneQuietNightEventAction::toString() {
	return "Skip the next Infect Cities step (Do not flip over any Infection Cards)";
}
