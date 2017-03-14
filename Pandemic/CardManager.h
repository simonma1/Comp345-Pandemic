#pragma once
#include "InfectionCard.h"
#include "PlayerCards.h"
#include <iostream>
#include <time.h>

/*
The card manager class will handle the logic of drawing cards and will contain all
the cards that will be on the board, that is Infection cards and Player cards. 
*/
class CardManager {

private:
	vector<InfectionCard*> infectionCardDeck;//The list of infection cards on the board that the player can draw from
	vector<InfectionCard*> infectionDiscard;//The discarded list of infection cards on the board
	
	vector<PlayerCard*> playerCardDeck;//Deck of player cards on the board that the player can draw from
	vector<PlayerCard*> playerCardDiscard;//Cards discarded by the players

	map<int, PlayerCard*> playerCardList;

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

	//PlayerCards decks
	void setPlayerCardDeck(vector<PlayerCard*> playerCardDeck) { this->playerCardDeck = playerCardDeck; };
	void setPlayerCardDiscard(vector<PlayerCard*> playerCardDeck) { this->playerCardDiscard = playerCardDeck; };
	vector<PlayerCard*> getPlayerCardDeck() { return playerCardDeck; };
	vector<PlayerCard*> getPlayerCardDiscard() { return playerCardDiscard; };

	//PlayerCardList
	void setPlayerCardList(map<int, PlayerCard*> playerCardList) { this->playerCardList = playerCardList; };

	//CardManager actions
	InfectionCard* drawInfectionCard();
	void moveInfectionCardToDiscard(InfectionCard*, int);
	int drawShuffledCard();
	string toString();


};