#include "CardManager.h"
#include <iostream>

CardManager::CardManager() {

}

CardManager::CardManager(vector<InfectionCard*> infectionDeck) {
	this->infectionCardDeck = infectionDeck;
}

CardManager::~CardManager() {
	for (auto it = infectionCardDeck.begin(); it != infectionCardDeck.end(); ++it) {
		delete *it;
	}
	infectionCardDeck.clear();
}
