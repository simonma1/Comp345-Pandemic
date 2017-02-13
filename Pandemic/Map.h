#include "Location.h"
#include <vector>
using namespace std;
#pragma once

class Map {

public:
	Map();
	void setMapLocation(map<int,Location>);

private:
	map<int,Location> cities;
};