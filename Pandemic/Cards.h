#include "Location.h"
#pragma once


//Each player will be represented by a pawn of a different color, which is an enum type. It is linked with the Role Card
enum Color { Pink, Orange, Blue, Green, Red, White, Brown };

class Pawn {

public:
	Location getCurrentLocation();

private:
	Color pawnColor;
	Location currentLocation;


};



class ReferenceCard
{


};

class PlayerCard
{


};

class Role
{


};