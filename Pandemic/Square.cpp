#include "Square.h"

Square::Square() {
	city = "Alabama";
	area = Area::Blue;
}

Square::Square(string newCity, Area newArea) {
	city = newCity;
	area = newArea;
}

void Square::setCity(string newCity) {
	city = newCity;
}
string Square::getCity() {
	return city;
}

void Square::setArea(Area newArea) {
	area = newArea;
}

Area Square::getArea() {
return area;
}
