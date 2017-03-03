#include "Location.h"

/*
Every city will be stored in a location object, a map of them all being stored in the Map Object. 
Cities should contained a name, an area color, an id for the key of the object, a list of connections, and status of all infections in that city
*/

string Location::toString()
{
	string result = city + ": " + to_string(numOfYellow) + " yellows, " + to_string(numOfRed) + " reds, " + to_string(numOfBlue) + " blues, " + to_string(numOfBlue) + " blacks, connected to: ";
	return result ;
}

Location::Location()
{
}

//Creates a Location object. This constructor is linked with the json serialization, so any changes here should be reflected in the Loader class
Location::Location(int id, string city, string area, vector<int> connections, int yellow, int blue, int black, int red)
{
	this -> id = id;
	this -> city = city;
	this -> area = area;
	this->connections = connections;
	this->numOfYellow = yellow;
	this->numOfBlue = blue;
	this->numOfBlack = black;
	this->numOfRed = red;

}
