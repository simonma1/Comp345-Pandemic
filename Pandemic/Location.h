#include <string>
#include <vector>
#include <map>
using namespace std;

#pragma once

class Location
{

public:
	string toString();
	Location();
	Location(int,string, string, vector<int>, int, int, int, int);
	int getId() { return id; };
	string getCity() { return city; };
	string getArea() { return area; };
	vector<int> getConnections() { return connections; }
	int getYellow() { return numOfYellow; };
	int getBlack() { return numOfBlack; };
	int getBlue() { return numOfBlue; };
	int getRed() { return numOfRed; };

private:
	int id;
	string city;
	string area;
	vector<int> connections;
	int numOfYellow;
	int numOfBlack;
	int numOfRed;
	int numOfBlue;
};


