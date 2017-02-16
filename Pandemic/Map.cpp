#include "Map.h"
#include <iostream>
#define NUM_OF_CITIES_IN_AREA 12

Map::Map() 
{
}

void Map::setMapLocation(map<int, Location> map)
{
	cities = map;
}

void Map::printConnections()
{
	for (int i = 1; i <= cities.size(); i++) {
		cout << cities.at(i).getCity() << " has the following connection: ";
		vector<int> cityConnection = cities.at(i).getConnections();
		for (int j = 0; j < cityConnection.size(); j++) {
			cout << cities.at(cityConnection[j]).getCity()<< ", ";
		}
		cout << endl;
	}
}


string Map::toString() {

	string result = "The Map\n";
	
	string tab = "    ";

	int j = 0;


	// Yellow Area. Assumed to be the first 12 cities
	result += tab + "Yellow:\n";
	result += tab + tab + "ID" + tab + "City\n";
	for (int i = 0; i < NUM_OF_CITIES_IN_AREA; i++) {
		j = i + 1;
		result += tab + tab + to_string(j) + tab + cities.at(j).toString() + "\n";
	}

	// Red Area. Assumed to be the following 12 cities
	result += tab + "Red:\n";
	result += tab + tab + "ID" + tab + "City\n";
	for (int i = 0; i < NUM_OF_CITIES_IN_AREA; i++) {
		j = i + 1;
		result += tab + tab + to_string(j) + tab + cities.at(j).toString() + "\n";
	}

	// Blue Area. Assumed to be the following 12 cities
	result += tab + "Blue:\n";
	result += tab + tab + "ID" + tab + "City\n";
	for (int i = 0; i < NUM_OF_CITIES_IN_AREA; i++) {
		j = i + 1;
		result += tab + tab + to_string(j) + tab + cities.at(j).toString() + "\n";
	}

	// Black Area. Assumed to be the following 12 cities
	result += tab + "Black:\n";
	result += tab + tab + "ID" + tab + "City\n";
	for (int i = 0; i < NUM_OF_CITIES_IN_AREA; i++) {
		j = i + 1;
		result += tab + tab + to_string(j) + tab + cities.at(j).toString() + "\n";
	}
	return result;
}

