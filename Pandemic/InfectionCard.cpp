#include "InfectionCard.h"

InfectionCard::InfectionCard() {

}

InfectionCard::InfectionCard(Location city) {
	this->city = city;
}

void InfectionCard::infect(Location* city)
{
	
}

string InfectionCard::printInfectionCard() {

	return city.toString();
	
}

int InfectionCard::getLocationId() {
	return city.getId();
}

string InfectionCard::getCityName() {
	return city.getCity();
}

InfectionCard::~InfectionCard() {

}