#include "Location.h"
#include <vector>
using namespace std;
#pragma once

class Map {

public:
	Map();
	void setMapLocation(map<int, Location>);
	map<int, Location> getMapLocation() { return cities; };

private:
	map<int,Location> cities;
};