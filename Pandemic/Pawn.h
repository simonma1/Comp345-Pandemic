#pragma once
#include "Location.h"
#include <ctime>

class Pawn {

public:
	Location getCurrentLocation() { return location; };
	string getColor() { return pawnColor; };
	string getRole() { return role; };
	Pawn(string, string);
	Pawn(string);
	Pawn();
	void setLocation(Location location) { this->location = location; };

private:
	string pawnColor;
	string role;
	Location location;


};