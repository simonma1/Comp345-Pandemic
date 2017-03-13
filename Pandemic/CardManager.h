#pragma once
#include "InfectionCard.h"

/*
The card manager class will handle the logic of drawing cards and will contain all
the cards that will be on the board, that is Infection cards and Player cards. 
*/
class CardManager {

private:
	vector<InfectionCard*> infectionCardDeck;//The list of infection cards on the board that the player can draw from
	vector<InfectionCard*> infectionDiscard;//The discarded list of infection cards on the board

public:
	CardManager();
	CardManager(vector<InfectionCard*> infectionDeck, vector<InfectionCard*> infectionDiscardDeck);
	~CardManager();

	//Infection Decks
	void setInfectionCardDeck(vector<InfectionCard*> infectionDeck) { this->infectionCardDeck = infectionDeck; };
	void setInfectionCardDiscard(vector<InfectionCard*> infectionDeck) { this->infectionDiscard = infectionDeck; };
	vector<InfectionCard*> getInfectionCardDeck() { return infectionCardDeck; };
	vector<InfectionCard*> getInfectionCardDiscard() { return infectionDiscard; };
	vector<int> getInfectionCardDeckId();
	vector<int> getInfectionCardDiscardId();


};