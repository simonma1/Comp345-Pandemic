#include "Location.h"

string Location::toString()
{
	return "The city at id: " + std::to_string(id) + " is : " + city + " The area is: " + area + " The blue infection level is: " + to_string(numOfBlue);
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
