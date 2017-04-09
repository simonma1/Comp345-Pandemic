#include "ForecastEventAction.h"
#include <algorithm>

ForecastEventAction::ForecastEventAction() {
}

ForecastEventAction::ForecastEventAction(vector<InfectionCard*>* infectionCardDeck, vector<PlayerCard*>* playerCardDiscard) {
	this->infectionCardDeck = infectionCardDeck;
	this->playerCardDiscard = playerCardDiscard;
}

void ForecastEventAction::act(Player * player) {
	//The idea is to randomly shuffle the first six card of the infection card deck. For simplicity, the action of drawing, looking at, rearranging
	//and then placing these cards back onto the deck will be simulated by simply shuffling these 6 cards in place, checking what they are before and after the shuffle. 
	if (infectionCardDeck->size() >= 6) {
		//Show the top 6 cards of the infection card deck
		cout << "The top six infection cards were: " << endl;
		for (int i = 0; i < 6; i++)
			cout << infectionCardDeck->at(i)->getCityName() << endl;

		std::random_shuffle(infectionCardDeck->begin(), infectionCardDeck->begin() + 5);
		cout << "\nUpon using the forecast event, the top six infection cards are now: \n" << endl;

		for (int i = 0; i < 6; i++)
			cout << infectionCardDeck->at(i)->getCityName() + "\n" << endl;
	}

	for (int i = 0; i < player->getPlayerCards().size(); i++) { // find which card is being discarded
		if (player->getPlayerCards()[i]->getCardName() == "Forecast") {
			cardPosition = i;
			break;
		}
	}
	playerCardDiscard->push_back(player->getPlayerCards()[cardPosition]);
	player->removePlayerCard(player->getPlayerCards()[cardPosition]->getId());
}

string ForecastEventAction::toString() {
	return "Draw, look at, and rearrange the top 6 cards of the Infection card. Put them back on top";
}
