#pragma once
#include "Location.h";

//Each player will be represented by a pawn of a different color, which is an enum type. It is linked with the Role Card
enum Color { Pink, Orange, Blue, Green, Red, White, Brown };

class Pawn {

private:
	Color pawnColor;
	City currentLocation;

public:
	City getCurrentLocation();
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