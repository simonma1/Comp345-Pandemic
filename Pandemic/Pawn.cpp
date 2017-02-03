#include "Pawn.h"

Pawn::Pawn(string color) {

}

void Pawn::setPosition(Square newPosition) {
	position.setCity(newPosition.getCity());
	position.setArea(newPosition.getArea());
}

Square Pawn::getPosition() {
	return position;
}
