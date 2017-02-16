#include "Location.h"

string Location::toString()
{
	string result = to_string(id) + " " + city + ": " + to_string(numOfYellow) + " yellows, " + to_string(numOfRed) + " reds, " + to_string(numOfBlue) + " blues, " + to_string(numOfBlue) + " blacks, connected to:";
	string connectionResult = "";
	for (auto &connection : connections) {
		connectionResult += " " + to_string(connection);
	}
	result += connectionResult + ".";
	return result ;
}

Location::Location()
{
}

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
