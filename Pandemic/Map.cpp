#include "Map.h"
#include <iostream>

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


