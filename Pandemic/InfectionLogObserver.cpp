#include "InfectionLogObserver.h"

void InfectionLogObserver::update(Observable* observable) {
	cout << "In Infection Log: \n ";
	static_cast<CardManager*>(observable);
}

