#include "Location.h"
#include <ctime>
#pragma once

class Pawn {

public:
	Location getCurrentLocation();
	string getColor() { return pawnColor; };
	string getRole() { return role; };
	Pawn(string, string);
	Pawn(string);
	Pawn();

private:
	string pawnColor;
	string role;
	Location currentLocation;


};