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
	Square(string city, Area area);
	void setCity(string city);
	string getCity();
	void setArea(Area area);
	Area getArea();
};
