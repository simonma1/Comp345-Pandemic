#include "Location.h"
#include <ctime>
#pragma once

class Pawn {

public:
	Location getCurrentLocation();
	string getColor() { return pawnColor; };
	Pawn(string);
	Pawn();

private:
	string pawnColor;
	Location currentLocation;


};