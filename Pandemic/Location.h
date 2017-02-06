#include <string>
using namespace std;

#pragma once

class Location
{

public:
	string toString();
	Location();
	Location(int,string, string);

private:
	int id;
	string city;
	string area;
};


