#include "Location.h"
#include <vector>
#include <iostream>
using namespace std;
#pragma once

class Map {

public:
	Map();
	void setMapLocation(map<int, Location>);
	map<int, Location> getMapLocation() { return cities; };
	void printConnections();

private:
	map<int,Location> cities;//An int id will serve as the key to every location in the map
	const int numOfCities = 48;
};