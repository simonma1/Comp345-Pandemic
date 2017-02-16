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
	map<int,Location> cities;
	const int numOfCities = 48;
};