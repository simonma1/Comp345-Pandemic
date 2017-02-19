#include "Cards.h"


int Pawn::getCurrentLocation()
{
	return currentLocation;
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

void Pawn::setPawnLocation(int location) {
	this->currentLocation = location;
}

Role::Role(string name) {
	this->name = name;
}

PlayerCard::PlayerCard(string cardName) {
	this->cardName = cardName;
}