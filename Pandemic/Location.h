#include <string>
using namespace std;

#pragma once

class Location
{

public:
	string toString();
	Location();
	Location(string, string);

private:
	string lcity;
	string larea;
};


