#pragma once
#include "PlayerCards.h"

class EventCard : public PlayerCard {

private:
	string type;

public:
	EventCard();
	EventCard(int, string);
	void cardAction();

};