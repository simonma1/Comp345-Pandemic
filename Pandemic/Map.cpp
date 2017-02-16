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

	string result = "";

	// Yellow Area. Assumed to be the first 12 cities
	for (int i = 0; i < NUM_OF_CITIES_IN_AREA; i++) {
		int j = i + 1;
		result += cities.at(j).toString();
	}

	// Red Area. Assumed to be the following 12 cities

	// Blue Area. Assumed to be the following 12 cities

	// Black Area. Assumed to be the following 12 cities
}

