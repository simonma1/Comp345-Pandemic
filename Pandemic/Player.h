#include <vector>
#include "Location.h";
#include "Cards.h";
using namespace std;
#pragma once


class Player 
{

/*
	Every Player has: 1 pawn, 1 reference card, 1 role card, up to 7 player cards(starting with 4 for 2 players) 

*/
private:
	Role role; //Role will later be define as a class
	ReferenceCard referenceCard;
	vector<PlayerCard> playerCards;
	Pawn playerPawn;//Each Player has a Pawn which will have a Location on the Board

public:
	Player generatePlayer();//Used to handle the logic of player creation
	Role getRole();
	City movePawn();
	Player();
};




