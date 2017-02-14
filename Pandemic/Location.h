#include <string>
#include <map>
using namespace std;

#pragma once

class Location
{

public:
	string toString();
	Location();
	Location(int,string, string);
	int getId() { return id; };
	string getCity() { return city; };
	string getArea() { return area; };
	

private:
	int id;
	string city;
	string area;
};


