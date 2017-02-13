#include "Location.h"

string Location::toString()
{
	return "The city at id: " + std::to_string(id) + " is : " + city + " The area is: " + area;
}

Location::Location()
{
}

Location::Location(int id, string city, string area)
{
	this -> id = id;
	this -> city = city;
	this -> area = area;
}
