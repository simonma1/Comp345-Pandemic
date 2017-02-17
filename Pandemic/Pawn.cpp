#include "Pawn.h"
#include <iostream>



Location Pawn::getCurrentLocation()
{
	return Location();
}

string Pawn::assignColor()
{
	vector<string> colors = { "Pink", "Orange", "Blue", "Green", "Red", "White", "Brown" };
	srand(time(NULL));
	int randomNum = rand() % 7;
	string pawnCol = colors[randomNum];
	this->pawnColor = pawnCol;
	return pawnCol;
}

Pawn::Pawn()
{
	assignColor();
}
