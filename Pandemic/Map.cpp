#include "Map.h"
#include <iostream>

Map::Map() 
{
	//Initializes the matrix so that all member of the matrix are false;d
	connectionVector.resize(this->numOfCities);
	for (int i = 0; i < this->numOfCities; i++) {
		connectionVector[i].resize(this->numOfCities);
		for (int j = 0; j < numOfCities; j++) {
			this->connectionVector[i][j] = false;
		}
	}
}

void Map::setMapLocation(map<int, Location> map)
{
	cities = map;
}

void Map::setConnections(vector<vector <bool>> connections)
{
	this->connectionVector = connections;
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

//Mostly for testing that the data in the matrix is actually correct
//Will print all the connections between the city 
void Map::printConnectionMatrix()
{
	for (int i = 0; i < this->connectionVector.size(); i++) {
		string lineOfMatrix = "";
		for (int j = 0; j < this->connectionVector[i].size(); j++) {
			if (this->connectionVector[i][j] == true) {
				lineOfMatrix += " T";
			}
			else {
				lineOfMatrix += " F";
			}
		}
		//cout << lineOfMatrix << endl;
	}
}

