#pragma once
#include "Square.h";
#include <string>;

using std::string;

class Pawn {
private:
	Square position;
	string color;
	ReferenceCard reference;
	RoleCard role;

public:
	Pawn(string color);
	void setPosition(Square newPosition);
	Square getPosition();
};