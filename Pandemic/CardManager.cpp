#include "CardManager.h"
#include <iostream>

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
