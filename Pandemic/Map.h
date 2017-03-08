#include "Location.h"
#include <vector>
#include <iostream>
using namespace std;
#pragma once

class Map {

public:
	Map();
	Map(const Map& map);
	void setMapLocation(map<int, Location>);
	map<int, Location> getMapLocation() { return cities; };
	void printConnections();
	string toString();

private:
	map<int,Location> cities;//An int id will serve as the key to every location in the map
	static const int numOfCities = 48;
};