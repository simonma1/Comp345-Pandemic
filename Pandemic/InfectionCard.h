#pragma once
#include "Location.h"

/*
Infection cards are the cards drawn every turn to infect cities, they contain a
location which will be infected when drawn.
*/
class InfectionCard {

private:
	Location city;

public:
	InfectionCard();
	InfectionCard(Location);
	~InfectionCard();
	void infect(Location*);
	string printInfectionCard();
	int getLocationId();
};