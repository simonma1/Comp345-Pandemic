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
	vector<vector <bool>> getConnections() { return connectionVector; };
	void setConnections(vector<vector <bool>> connections);
	void printConnectionMatrix();

private:
	map<int,Location> cities;
	vector<vector <bool>> connectionVector;//A 2d array that will act as an adjacency matrix representing whether there is a link between the 2 cities
	const int numOfCities = 48;
};