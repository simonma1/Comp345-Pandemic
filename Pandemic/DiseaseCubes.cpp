#include "DiseaseCubes.h"

DiseaseCubes::DiseaseCubes() {

}

DiseaseCubes::DiseaseCubes(int black, int yellow, int red, int blue) {
	this->numOfBlackPieces = black;
	this->numOfYellowPieces = yellow;
	this->numOfRedPieces = red;
	this->numOfBluePieces = blue;
}

string DiseaseCubes::toString() {

	string value = "";
	value += "\tThere are " + to_string(numOfBlackPieces) + " BLACK cubes still available\n";
	value += "\tThere are " + to_string(numOfYellowPieces) + " YELLOW cubes still available\n";
	value += "\tThere are " + to_string(numOfRedPieces) + " RED cubes still available\n";
	value += "\tThere are " + to_string(numOfBluePieces) + " BLUE cubes still available\n\n";


	return value;
}
