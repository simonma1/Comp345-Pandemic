#pragma once
#include "InfectionCard.h"
#include "PlayerCards.h"
#include "Board.h"
#include "Observable.h"
#include "InfectionLogObserver.h"
#include <iostream>
#include <time.h>

class Board;
/*
The card manager class will handle the logic of drawing cards and will contain all
the cards that will be on the board, that is Infection cards and Player cards. 
This class will be implemented as an observable class for the infection Cards, it could easily be done for the Player Cards too 
*/
class CardManager : public Observable {

private:
	vector<InfectionCard*> infectionCardDeck;//The list of infection cards on the board that the player can draw from
	vector<InfectionCard*> infectionDiscard;//The discarded list of infection cards on the board
	
	vector<PlayerCard*> playerCardDeck;//Deck of player cards on the board that the player can draw from
	vector<PlayerCard*> playerCardDiscard;//Cards discarded by the players
	vector<int> IdsOfPlayerCardToDiscard;

	map<int, PlayerCard*> playerCardList;
	map<int,int> numOfCardsPerPlayer = { { 2, 4 },{ 3, 3 },{ 4, 2 }};

public:
	CardManager();
	CardManager(vector<InfectionCard*> infectionDeck, vector<InfectionCard*> infectionDiscardDeck);
	~CardManager();

	//Infection Decks
	void setInfectionCardDeck(vector<InfectionCard*> infectionDeck) { this->infectionCardDeck = infectionDeck; };
	void setInfectionCardDiscard(vector<InfectionCard*> infectionDeck) { this->infectionDiscard = infectionDeck; };
	//Had to make it as a pointer for the ForecastEvent action to do what it is supposed to 
	vector<InfectionCard*>* getInfectionCardDeck() { return &infectionCardDeck; };
	//Had to make it a pointer as with playerCardDiscard for the ResilientPopulationEvent action to actually do what it is supposed to do
	//Adjusted the infectionLogObserver to reflect that this change
	vector<InfectionCard*>* getInfectionCardDiscard() { return &infectionDiscard; };
	vector<int> getInfectionCardDeckId();
	vector<int> getInfectionCardDiscardId();

	//PlayerCards decks
	void setPlayerCardDeck(vector<PlayerCard*> playerCardDeck) { this->playerCardDeck = playerCardDeck; };
	void setPlayerCardDiscard(vector<PlayerCard*> playerCardDeck) { this->playerCardDiscard = playerCardDeck; };
	vector<PlayerCard*> getPlayerCardDeck() { return playerCardDeck; };
	vector<PlayerCard*>* getPlayerCardDiscard() { return &playerCardDiscard; };
	vector<int> getPlayerCardDeckId();
	vector<int> getPlayerCardDiscardId();
	void setIdsOfPlayerCardToDiscard(vector<int> IdsOfPlayerCardToDiscard) {
		this->IdsOfPlayerCardToDiscard = IdsOfPlayerCardToDiscard;
	};
	void setDiscardedPlayerCardsFromLoad();

	//PlayerCardList
	void setPlayerCardList(map<int, PlayerCard*> playerCardList) { this->playerCardList = playerCardList; };

	//Infection Card actions
	Location drawInfectionCard();
	void moveInfectionCardToDiscard(InfectionCard*, int);
	int drawShuffledCard();
	void moveCardToDeck();

	//PlayerCard action
	void distributeCards(Board* board);
	PlayerCard* drawPlayerCard();
	void setPlayerCardsFromLoad(Player* player);

	string toString();


};