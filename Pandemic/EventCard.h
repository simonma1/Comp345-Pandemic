#pragma once
#include "PlayerCards.h"

class EventCard : public PlayerCard {


public:
	EventCard();
	EventCard(int, string);
	void cardAction();
	string toString();
};