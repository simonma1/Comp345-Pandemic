#include "Location.h"

string Location::toString()
{
	return to_string(id) + " " + city + ": " + to_string(numOfYellow) + " yellows, " + to_string(numOfRed) + " reds, " + to_string(numOfBlue) + " blues, " + to_string(numOfBlue) + " blacks, connected to: <connected cities>";
}

Location::Location()
{
}

Location::Location(int id, string city, string area, int yellow, int blue, int black, int red)
{
	this -> id = id;
	this -> city = city;
	this -> area = area;
	this->numOfYellow = yellow;
	this->numOfBlue = blue;
	this->numOfBlack = black;
	this->numOfRed = red;

}
