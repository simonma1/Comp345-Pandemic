#include "Map.h"
#include <iostream>
#define NUM_OF_CITIES_IN_AREA 12

Map::Map() 
{
}

Map::Map(const Map& map) {
	cities = map.cities;
	this->diseaseCubes = new DiseaseCubes;
	*diseaseCubes = *map.diseaseCubes;
}

Map::~Map() {
	delete diseaseCubes;
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

void Map::setLocationNumOfBlack(int id, int numInfection){
	cities.at(id).setBlack(numInfection);
}

void Map::setLocationNumOfYellow(int id, int numInfection) {
	cities.at(id).setYellow(numInfection);
}

void Map::setLocationNumOfRed(int id, int numInfection) {
	cities.at(id).setRed(numInfection);
}

void Map::setLocationNumOfBlue(int id, int numInfection) {
	cities.at(id).setBlue(numInfection);
}

string Map::toString() {

	string result = "The Map\n";
	
	string tab = "    ";

	for (int j = 1; j <= numOfCities; j++) {
		
		if (j / 12 == 0 && j % 12 ==1) {//Cities with Ids from 1 to 12. Color will only be printed for the 1st one
			// Blue Area. Assumed to be the first 12 cities
			result += tab + "Blue:\n";
			result += tab + tab + "ID" + tab + "City\n";
		}
		else if (j / 12 == 1 && j % 12 == 1) {
			// Yellow Area. Assumed to be the following 12 cities
			result += tab + "Yellow:\n";
			result += tab + tab + "ID" + tab + "City\n";
		}
		else if (j / 12 == 2 && j % 12 == 1) {
			// Blue Area. Assumed to be the following 12 cities
			result += tab + "Black:\n";
			result += tab + tab + "ID" + tab + "City\n";
		}
		else if (j / 12 == 3 && j % 12 == 1)
		{
			// Black Area. Assumed to be the following 12 cities
			result += tab + "Red:\n";
			result += tab + tab + "ID" + tab + "City\n";
		}
		result += tab + tab + to_string(j) + tab + cities.at(j).toString();

		//The following will print the Id and city name of all cities connected to the current city
		vector<int> cityConnection = cities.at(j).getConnections();
		for (int i = 0; i < cityConnection.size(); i++) {
			result += to_string(cities.at(cityConnection[i]).getId()) + "."
				+ cities.at(cityConnection[i]).getCity();
			
			//Prints a coma to separate the cities except for the last one
			if (i != (cityConnection.size() - 1)) {
				result += ", ";
			}
		}
		result += "\n";
	}
	return result;
}

Location Map::getLocationAtId(int id) {
	return cities.at(id);
}

void Map::infectCity(Location loc)
{
	int cityId = loc.getId();
	string virusColor = loc.getArea();
	cities.at(cityId).infect(virusColor, diseaseCubes);
	notifyObservers();
}

void Map::treat(Location loc) {
	int cityId = loc.getId();
	string virusColor = loc.getArea();
	cities.at(cityId).treatDisease(virusColor, diseaseCubes);
	notifyObservers();
}

