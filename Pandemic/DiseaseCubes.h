#pragma once
#include <string>
using namespace std;

class DiseaseCubes {

private:
	int numOfBlackPieces, numOfYellowPieces, numOfBluePieces, numOfRedPieces;

public:
	DiseaseCubes();
	DiseaseCubes(int,int, int, int);
	string toString();

	int getNumOfBlackPieces() { return numOfBlackPieces; };
	int getNumOfBluePieces() { return numOfBluePieces; };
	int getNumOfRedPieces() { return numOfRedPieces; };
	int getNumOfYellowPieces() { return numOfYellowPieces; };

	void setNumOfBlackPieces(int numOfPieces) { this->numOfBlackPieces = numOfPieces; };
	void setNumOfYellowPieces(int numOfPieces) { this->numOfYellowPieces = numOfPieces; };
	void setNumOfRedPieces(int numOfPieces) { this->numOfRedPieces = numOfPieces; };
	void setNumOfBluePieces(int numOfPieces) { this->numOfBluePieces = numOfPieces; };

	void DecrementNumOfBlackPieces() { numOfBlackPieces--; };
	void DecrementNumOfYellowPieces() { numOfYellowPieces--; };
	void DecrementNumOfRedPieces() { numOfRedPieces--; };
	void DecrementNumOfBluePieces() { numOfBluePieces--; };

	void IncrementNumOfBluePieces() { numOfBluePieces++; };
	void IncrementNumOfYellowPieces() { numOfBluePieces++; };
	void IncrementNumOfBlackPieces() { numOfBluePieces++; };
	void IncrementNumOfRedPieces() { numOfBluePieces++; };

};