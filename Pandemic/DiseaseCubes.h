#pragma once
#include <string>
#include "DiseaseObserver.h"
#include "Observable.h"

using namespace std;

class DiseaseCubes:public Observable {

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

	void setNumOfBlackPieces(int numOfPieces) { this->numOfBlackPieces = numOfPieces; notifyObservers(); };
	void setNumOfYellowPieces(int numOfPieces) { this->numOfYellowPieces = numOfPieces;notifyObservers(); };
	void setNumOfRedPieces(int numOfPieces) { this->numOfRedPieces = numOfPieces; notifyObservers(); };
	void setNumOfBluePieces(int numOfPieces) { this->numOfBluePieces = numOfPieces; notifyObservers();};

	void DecrementNumOfBlackPieces() { numOfBlackPieces--; notifyObservers();};
	void DecrementNumOfYellowPieces() { numOfYellowPieces--; notifyObservers();};
	void DecrementNumOfRedPieces() { numOfRedPieces--; notifyObservers();};
	void DecrementNumOfBluePieces() { numOfBluePieces--; notifyObservers();};

	void IncrementNumOfBluePieces() { numOfBluePieces++; notifyObservers();};
	void IncrementNumOfYellowPieces() { numOfBluePieces++; notifyObservers();};
	void IncrementNumOfBlackPieces() { numOfBluePieces++; notifyObservers();};
	void IncrementNumOfRedPieces() { numOfBluePieces++; notifyObservers();};

};