#include "Cards.h"
#include "ReferenceCard.h"





std::string PlayerCard::getCardName() {
	return cardName;
}



Role::Role(std::string name) {
	this->name = name;
}

PlayerCard::PlayerCard(std::string cardName) {
	this->cardName = cardName;
}