#pragma once
#include <string>
#include "Area.h"

using namespace std;

class Square {
private:
	string city;
	Area area;

public:
	Square();
	Square(string newCity, Area newArea);
	void setCity(string newCity);
	string getCity();
	void setArea(Area newArea);
	Area getArea();
};
