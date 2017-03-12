#pragma once
#include "InfectionCard.h"

class CardManager {

private:
	vector<InfectionCard*> infectionCardDeck;
	vector<InfectionCard*> infectionDiscard;

public:
	CardManager();
	void setInfectionCardDeck(InfectionCard* infectionDeck);


};