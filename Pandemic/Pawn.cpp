#include "Pawn.h"

Pawn::Pawn(string newColor) {
	color = newColor;
}

void Pawn::setPosition(Square newPosition) {
	position.setCity(newPosition.getCity());
	position.setArea(newPosition.getArea());
}

Square Pawn::getPosition() {
	return position;
}

void Pawn::setColor(string newColor) {
	color = newColor;
}

string Pawn::getColor() {
	return color;
}