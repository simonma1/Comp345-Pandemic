#include "Location.h"

string Location::toString()
{
	return "The city is : " + lcity + " The area is: " + larea;
}

Location::Location()
{
}

Location::Location(string city, string area)
{
	lcity = city;
	larea = area;
}
