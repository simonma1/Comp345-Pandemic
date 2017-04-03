#include "ResilientPopulationEventAction.h"

ResilientPopulationEventAction::ResilientPopulationEventAction() {
}

ResilientPopulationEventAction::ResilientPopulationEventAction(vector<InfectionCard*>* infectionCardDiscard) {
	this->infectionCardDiscard = infectionCardDiscard;
}

void ResilientPopulationEventAction::act(Player *) {
	//For now, just remove a ramdom infection card in the infection card discard pile from the game (will add possibly a check for the action happening between infect and intensify of an epidemic later
	srand(time(0));
	int randomInfectionCard;
	if (infectionCardDiscard != NULL) {
		for (int i = 1; i <= infectionCardDiscard->size(); i++) {
			randomInfectionCard = rand() % infectionCardDiscard->size() + 1;
			infectionCardDiscard->erase(infectionCardDiscard->begin() + randomInfectionCard);
			break; 
		}
	}
}

string ResilientPopulationEventAction::toString() {
	return "Remove any 1 card in the Infection Discard Pile from the game. You may play this between the Infect and Intensify steps of an Epidemic";
}
