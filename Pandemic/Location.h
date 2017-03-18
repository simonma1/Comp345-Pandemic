#pragma once
#include "DiseaseCubes.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Location
{

public:
	string toString();
	Location();
	Location(int,string, string, vector<int>);
	int getId() { return id; };
	string getCity() { return city; };
	string getArea() { return area; };
	vector<int> getConnections() { return connections; }

	//Setters And Getters
	void setBlack(int numInfection) { this->numOfBlack = numInfection; };
	void setYellow(int numInfection) { this->numOfYellow = numInfection; };
	void setRed(int numInfection) { this->numOfRed = numInfection; };
	void setBlue(int numInfection) { this->numOfBlue = numInfection; };
	int getYellow() { return numOfYellow; };
	int getBlack() { return numOfBlack; };
	int getBlue() { return numOfBlue; };
	int getRed() { return numOfRed; };

	//Infection Actions
	void infect(string infectionColor, DiseaseCubes* diseases);

	//Treating Actions
	void treatDisease(string, DiseaseCubes* diseases);

private:
	int id;
	string city;
	string area;
	vector<int> connections;
	int numOfYellow;
	int numOfBlack;
	int numOfRed;
	int numOfBlue;

	void treatBlue();
	void treatBlack();
	void treatYellow();
	void treatRed();
};


