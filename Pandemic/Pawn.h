#pragma once
#include "Location.h"
#include <ctime>

class Pawn {

public:
	int getCurrentLocation() { return location; };
	string getColor() { return pawnColor; };
	string getRole() { return role; };
	Pawn(string, string);
	Pawn(string);
	Pawn();
	void setLocation(int location) { this->location = location; };

private:
	string pawnColor;
	string role;
	int location;


};