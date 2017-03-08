#include "Location.h"
#include <ctime>
#pragma once

class Pawn {

public:
	Location getCurrentLocation();
	string getColor() { return pawnColor; };
	string getName() { return name; };
	Pawn(string, string);
	Pawn(string);
	Pawn();

private:
	string pawnColor;
	string name;
	Location currentLocation;


};