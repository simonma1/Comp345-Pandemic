#include "Pawn.h"
#include <iostream>



Location Pawn::getCurrentLocation()
{
	return Location();
}


Pawn::Pawn(string color)
{
	this->pawnColor = color;
}

Pawn::Pawn(string color, string name) {
	this->pawnColor = color;
	this->name = name;
}

Pawn::Pawn()
{
}

