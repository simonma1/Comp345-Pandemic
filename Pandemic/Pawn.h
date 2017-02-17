#include "Location.h"
#include <ctime>
#pragma once

//Each player will be represented by a pawn of a different color, which is an enum type. It is linked with the Role Card
enum color { Pink, Orange, Blue, Green, Red, White, Brown };

class Pawn {

public:
	Location getCurrentLocation();
	string assignColor();
	string getColor() { return pawnColor; };
	Pawn();

private:
	string pawnColor;
	Location currentLocation;


};