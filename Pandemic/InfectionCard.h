#pragma once
#include "Location.h"

class InfectionCard {

private:
	Location city;

public:
	InfectionCard();
	InfectionCard(Location);
	~InfectionCard();
	void infect(Location*);
	string printInfectionCard();
};