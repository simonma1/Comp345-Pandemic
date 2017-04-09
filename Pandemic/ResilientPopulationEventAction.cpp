#include "ResilientPopulationEventAction.h"

ResilientPopulationEventAction::ResilientPopulationEventAction() {
}

ResilientPopulationEventAction::ResilientPopulationEventAction(vector<InfectionCard*>* infectionCardDiscard, vector<PlayerCard*>* playerCardDiscard) {
	this->infectionCardDiscard = infectionCardDiscard;
	this->playerCardDiscard = playerCardDiscard;
}

void ResilientPopulationEventAction::act(Player * player) {
	//For now, just remove a ramdom infection card in the infection card discard pile from the game (will possibly add a check for the action happening between infect and intensify of an epidemic later
	int choiceInfectionCard;
	for (int i = 0; i < infectionCardDiscard->size(); i++)
		cout << infectionCardDiscard->at(i)->getCityName() + "\n" << endl;

	cout << "Which infection card would you like to remove from the discard pile? Choose a number between 0 and " << infectionCardDiscard->size() - 1 <<  endl;
	cin >> choiceInfectionCard;
	
	//For random removal
	//srand(time(NULL));
	//int randomInfectionCard = rand() % infectionCardDiscard.size() + 1;
	if (choiceInfectionCard >= 0 && choiceInfectionCard <= infectionCardDiscard->size() - 1) {
		cout << "Removing infection card from discard pile (will still be displayed for record but no longer in pile): " << infectionCardDiscard->at(choiceInfectionCard)->getCityName() << endl;
		infectionCardDiscard->erase(infectionCardDiscard->begin() + choiceInfectionCard);
		
		cout << "The infection card discard pile now contains the following: " << endl;
		for (int i = 0; i < infectionCardDiscard->size(); i++)
			cout << infectionCardDiscard->at(i)->getCityName() + "\n" << endl;

		for (int i = 0; i < player->getPlayerCards().size(); i++) { // find which card is being discarded
			if (player->getPlayerCards()[i]->getCardName() == "Resilient Population") {
				cardPosition = i;
				break;
			}
		}
		playerCardDiscard->push_back(player->getPlayerCards()[cardPosition]);
		player->removePlayerCard(player->getPlayerCards()[cardPosition]->getId());
	}
	else
		cout << "You have entered an invalid output. You now will only be able to carry out this action in future turns." << endl;
}

string ResilientPopulationEventAction::toString() {
	return "Remove any 1 card in the Infection Discard Pile from the game. You may play this between the Infect and Intensify steps of an Epidemic";
}
