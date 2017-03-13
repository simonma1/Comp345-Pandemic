#pragma once
#include "InfectionCard.h"

class CardManager {

private:
	vector<InfectionCard*> infectionCardDeck;
	vector<InfectionCard*> infectionDiscard;

public:
	CardManager();
	CardManager(vector<InfectionCard*> infectionDeck);
	~CardManager();
	void setInfectionCardDeck(vector<InfectionCard*> infectionDeck) { this->infectionCardDeck = infectionDeck; };
	void setInfectionCardDiscard(vector<InfectionCard*> infectionDeck) { this->infectionDiscard = infectionDeck; };



};