#include "ResilientPopulationEventAction.h"

ResilientPopulationEventAction::ResilientPopulationEventAction() {
}

ResilientPopulationEventAction::ResilientPopulationEventAction(vector<InfectionCard*> infectionCardDiscard, vector<PlayerCard*>* playerCardDiscard) {
	this->infectionCardDiscard = infectionCardDiscard;
	this->playerCardDiscard = playerCardDiscard;
}

void ResilientPopulationEventAction::act(Player * player) {
	//For now, just remove a ramdom infection card in the infection card discard pile from the game (will possibly add a check for the action happening between infect and intensify of an epidemic later
	srand(time(NULL));
	int randomInfectionCard = rand() % infectionCardDiscard.size() + 1;
	cout << "Removing infection card from discard pile (will still be displayed for record but no longer in pile): " << infectionCardDiscard.at(randomInfectionCard)->getCityName() << endl;
	infectionCardDiscard.erase(infectionCardDiscard.begin() + randomInfectionCard);

	for (int i = 0; i < player->getPlayerCards().size(); i++) { // find which card is being discarded
		if (player->getPlayerCards()[i]->getCardName() == "Resilient Population") {
			cardPosition = i;
			break;
		}
	}
	playerCardDiscard->push_back(player->getPlayerCards()[cardPosition]);
	player->removePlayerCard(player->getPlayerCards()[cardPosition]->getId());
}

string ResilientPopulationEventAction::toString() {
	return "Remove any 1 card in the Infection Discard Pile from the game. You may play this between the Infect and Intensify steps of an Epidemic";
}
