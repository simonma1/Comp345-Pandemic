#include "ForecastEventAction.h"
#include <algorithm>

ForecastEventAction::ForecastEventAction() {
}

ForecastEventAction::ForecastEventAction(vector<InfectionCard*>* infectionCardDeck) {
	this->infectionCardDeck = infectionCardDeck;
}

void ForecastEventAction::act(Player *) {
	//The idea is to randomly shuffle the first six card of the infection card deck. For simplicity, the action of drawing, looking at, rearranging
	//and then placing these cards back onto the deck will be simulated by simply shuffling them in place. 
	if (infectionCardDeck != NULL) {
		for (int i = 0; i < infectionCardDeck->size(); i++) 
			random_shuffle(infectionCardDeck->at(0), infectionCardDeck->at(5));
	}
}

string ForecastEventAction::toString() {
	return "Draw, look at, and rearrange the top 6 cards of the Infection card. Put them back on top";
}
