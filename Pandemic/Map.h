#include "Location.h"
#include <vector>
using namespace std;
#pragma once

class Map {

public:
	Map();
	void setMapLocation(vector<Location>);

private:
	vector<Location> cities;
};