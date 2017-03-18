#pragma once
#include "Location.h"
#include "DiseaseCubes.h"
#include <vector>
#include <iostream>
using namespace std;

class Map {

public:
	Map();
	Map(const Map& map);
	~Map();

	map<int, Location> getMapLocation() { return cities; };
	void printConnections();
	string toString();
	Location getLocationAtId(int id);

	void setDiseaseCubes(DiseaseCubes* cubes) { this->diseaseCubes = cubes; };
	DiseaseCubes* getDiseaseCubes() { return diseaseCubes; };

	//Infection Action
	void infectCity(Location loc);

	//Treating Action
	void treat(Location);

	//Setters
	void setMapLocation(map<int, Location>);
	void setLocationNumOfBlack(int id, int numInfection);
	void setLocationNumOfYellow(int id, int numInfection);
	void setLocationNumOfRed(int id, int numInfection);
	void setLocationNumOfBlue(int id, int numInfection);


private:
	map<int,Location> cities;//An int id will serve as the key to every location in the map
	static const int numOfCities = 48;
	DiseaseCubes* diseaseCubes;
};