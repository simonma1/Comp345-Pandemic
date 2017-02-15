#include <string>
#include <map>
using namespace std;

#pragma once

class Location
{

public:
	string toString();
	Location();
	Location(int,string, string, int, int, int, int);
	int getId() { return id; };
	string getCity() { return city; };
	string getArea() { return area; };
	int getYellow() { return numOfYellow; };
	int getBlack() { return numOfBlack; };
	int getBlue() { return numOfBlue; };
	int getRed() { return numOfRed; };

private:
	int id;
	string city;
	string area;
	int numOfYellow;
	int numOfBlack;
	int numOfRed;
	int numOfBlue;
};


