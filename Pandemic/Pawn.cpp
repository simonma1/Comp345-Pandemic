#include "Pawn.h"
#include <iostream>


Pawn::Pawn(string color)
{
	this->pawnColor = color;
}

Pawn::Pawn(string color, string name) {
	this->pawnColor = color;
	this->role = name;
}

Pawn::Pawn()
{
}

