#include "Location.h"

/*
Every city will be stored in a location object, a map of them all being stored in the Map Object. 
Cities should contained a name, an area color, an id for the key of the object, a list of connections, and status of all infections in that city
*/

string Location::toString()
{
	string result = city + ": " + to_string(numOfYellow) + " yellows, " + to_string(numOfRed) + " reds, " + to_string(numOfBlue) + " blues, " + to_string(numOfBlack) + " blacks, connected to: ";
	return result ;
}

Location::Location()
{
}

//Creates a Location object. This constructor is linked with the json serialization, so any changes here should be reflected in the Loader class
Location::Location(int id, string city, string area, vector<int> connections)
{
	this -> id = id;
	this -> city = city;
	this -> area = area;
	this->connections = connections;
	this->numOfYellow = 0;
	this->numOfBlue = 0;
	this->numOfBlack = 0;
	this->numOfRed = 0;

}

void Location::infect(string infectionColor, DiseaseCubes* diseases)
{
	cout << "INFECTING " << city <<endl;

	if (infectionColor == "Black") {
		cout << "Adding black" << endl;
		numOfBlack++;
		diseases->DecrementNumOfBlackPieces();
	} else if (infectionColor == "Yellow") {
		cout << "Adding yellow" << endl;
		numOfYellow++;
		diseases->DecrementNumOfYellowPieces();
	} else if (infectionColor == "Red") {
		cout << "Adding red" << endl;
		numOfRed++;
		diseases->DecrementNumOfRedPieces();
	} else if (infectionColor == "Blue") {
		cout << "Adding blue" << endl;
		numOfBlue++;
		diseases->DecrementNumOfBluePieces();
	}
}
