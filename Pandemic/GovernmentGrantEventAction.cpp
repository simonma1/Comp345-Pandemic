#include "GovernmentGrantEventAction.h"

GovernmentGrantEventAction::GovernmentGrantEventAction() {
}

GovernmentGrantEventAction::GovernmentGrantEventAction(vector<int>* boardResearchStations, vector<PlayerCard*>* playerCardDiscard, int randomCityId) {
	this->boardResearchStations = boardResearchStations;
	this->playerCardDiscard = playerCardDiscard;
	this->randomCityId = randomCityId;

}

void GovernmentGrantEventAction::act(Player *player) {
	//The idea here is to build a research station onto a location that is chosen on the board (randomly and a check will be made in Board.cpp
	//to make sure there isnt a research station already built there).	
	boardResearchStations->push_back(randomCityId);

	for (int i = 0; i < player->getPlayerCards().size(); i++) { // find which card is being discarded
		if (player->getPlayerCards()[i]->getCardName() == "Government Grant") {
			cardPosition = i;
			break;
		}
	}
	playerCardDiscard->push_back(player->getPlayerCards()[cardPosition]);
	player->removePlayerCard(player->getPlayerCards()[cardPosition]->getId());
}

string GovernmentGrantEventAction::toString() {
	return "Add 1 research station to any city (no City Cards needed)";
}
