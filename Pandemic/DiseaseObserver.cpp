#include "DiseaseObserver.h"
#include "DiseaseCubes.h"
#include <iostream>

void DiseaseObserver::update(Observable *observable) {
	cout << "---------------------------------------------------------------------------------------" << endl;
	cout << "The list of disease cubes: \n";
	static_cast<DiseaseCubes*>(observable)->toString();
	cout << "END \n---------------------------------------------------------------------------------------" << endl;
}
