#include "Cards.h"


ReferenceCard::ReferenceCard(std::string cardName)
{
	name = cardName;
}


std::string PlayerCard::getCardName() {
	return cardName;
}



Role::Role(std::string name) {
	this->name = name;
}

PlayerCard::PlayerCard(std::string cardName) {
	this->cardName = cardName;
}