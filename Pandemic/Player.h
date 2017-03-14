#pragma once
#include <vector>
#include "Location.h"
#include "Cards.h"
#include "PlayerCards.h"
#include "CityCard.h"
#include "Pawn.h"
#include "ReferenceCard.h"

using namespace std;

class Player 
{

/*
	Every Player has: 1 pawn, 1 reference card, 1 role card, up to 7 player cards(starting with 4 for 2 players) 

*/
private:
	Role* role; //Role will later be define as a class
	ReferenceCard *referenceCard; 
	vector<PlayerCard*> playerCards;
	Pawn* playerPawn;//Each Player has a Pawn which will have a Location on the Board

public:
	Role* getRole() { return role; };
	Location* movePawn();
	~Player();
	Player(Role* role, Pawn* playerPawn);
	Player();
	vector<PlayerCard*> getPlayerCards();
	Pawn* getPlayerPawn();
	void setPlayerCards(vector<PlayerCard*> playerCards);
	void setReferenceCard(ReferenceCard*);
	void setRole(Role*);
	string toString();
	void setPawn(Pawn* p) { playerPawn = p; };
	void lookAtReferenceCard();
	void addPlayerCard(PlayerCard* card);

};




