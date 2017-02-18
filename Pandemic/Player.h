#include <vector>
#include "Location.h"
#include "Cards.h"
#include "Pawn.h"
using namespace std;
#pragma once


class Player 
{

/*
	Every Player has: 1 pawn, 1 reference card, 1 role card, up to 7 player cards(starting with 4 for 2 players) 

*/
private:
	//Role role; //Role will later be define as a class, maybe using strategy pattern. 
	//Will be a string for now to be mocked in the common part 
	string role;
	ReferenceCard* referenceCard;
	vector<PlayerCard> playerCards;
	Pawn* playerPawn;//Each Player has a Pawn which will have a Location on the Board

public:
	Location movePawn();
	Pawn setPawn(string);
	void setReferenceCard(ReferenceCard*);
	void setRole(string);
	Player();
	Player(string, ReferenceCard*);
	string toString();
	~Player();
};




