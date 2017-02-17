#include "Cards.h"


Location Pawn::getCurrentLocation()
{
	return Location();
}

string Role::getName() {
	return name;
}

string PlayerCard::getCardName() {
	return cardName;
}

Color Pawn::getPawnColor() {
	return pawnColor;
}

Pawn::Pawn(Color pawnColor) {
	this->pawnColor = pawnColor;
}

void Pawn::setPawnLocation(Location location) {
	this->currentLocation = location;
}

Role::Role(string name) {
	this->name = name;
}

PlayerCard::PlayerCard(string cardName) {
	this->cardName = cardName;
}