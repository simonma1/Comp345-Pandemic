#pragma once
#include "PlayerCards.h"

class EpidemicCard : public PlayerCard {

public:
	EpidemicCard();
	EpidemicCard(int, string);
	void cardAction();
	string toString();

};