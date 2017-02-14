#pragma once
#include "Square.h";
#include <string>;

using std::string;

class Pawn {
private:
	Square position;
	string color;

public:
	Pawn(string newColor);
	void setPosition(Square newPosition);
	Square getPosition();
	void setColor(string newColor);
	string getColor();
};