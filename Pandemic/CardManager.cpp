#include "CardManager.h"


CardManager::CardManager() {

}

CardManager::CardManager(vector<InfectionCard*> infectionDeck, vector<InfectionCard*> infectionDiscardDeck) {
	this->infectionCardDeck = infectionDeck;
	this->infectionDiscard = infectionDiscardDeck;
}

//Returns the id associated with every card in the infection deck
vector<int> CardManager::getInfectionCardDeckId() {
	vector<int> ids;

	for (int i = 0; i < infectionCardDeck.size(); i++) {
		ids.push_back(infectionCardDeck[i]->getLocationId());
	}

	return ids;
}

//Returns the id associated with every card in the discard infection deck
vector<int> CardManager::getInfectionCardDiscardId() {
	vector<int> ids;

	for (int i = 0; i < infectionDiscard.size(); i++) {
		ids.push_back(infectionDiscard[i]->getLocationId());
	}

	return ids;
}

CardManager::~CardManager() {
	for (auto it = infectionCardDeck.begin(); it != infectionCardDeck.end(); ++it) {
		delete *it;
	}
	infectionCardDeck.clear();
}

//Returns the next infection card and moves it from the deck to the discard pile
InfectionCard * CardManager::drawInfectionCard()
{
	if (infectionCardDeck.size() != 0) {
		cout << "Drawing Infection Card";
		int nextCard = drawShuffledCard();
		InfectionCard* card = infectionCardDeck[nextCard];
		moveInfectionCardToDiscard(card, nextCard);
		return card;
	}
	return nullptr;
}

//Moves the card between the 2 decks
void CardManager::moveInfectionCardToDiscard(InfectionCard* infection, int cardId)
{
	infectionCardDeck.erase(infectionCardDeck.begin() + cardId);
	infectionDiscard.insert(infectionDiscard.begin(), infection);
}

//Generates the id of the next card to draw
int CardManager::drawShuffledCard()
{
	srand(time(NULL));//Allows for the randomness
	int randomNum = rand() % infectionCardDeck.size();//Normalizes the value by the amount of pawns available
	return randomNum;
}

string CardManager::toString() {
	string value = "";

	value += "The discarded cards are: \n";

	for (int i = 0; i < infectionDiscard.size(); i++) {
	
		value += to_string(infectionDiscard[i]->getLocationId()) + ". " 
			+ infectionDiscard[i]->getCityName() + "\n" ;
	
	}

	return value;
}
