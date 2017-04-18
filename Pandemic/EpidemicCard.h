#pragma once
#include "PlayerCards.h"
#include "Board.h"
#include "CardManager.h"
#include <vector>

class EpidemicCard : public PlayerCard {

public:
	EpidemicCard();
	EpidemicCard(int, string);
	void cardAction();
	string toString();

private:
	Board* board;
	CardManager* cardManager;
	vector<CardManager> infectionDeck;
};