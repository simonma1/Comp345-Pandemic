#include "Square.h"

Square::Square() {
	city = "Alabama";
	area = Area::Blue;
}

Square::Square(string newCity, Area newArea) {
	city = newCity;
	area = newArea;
}