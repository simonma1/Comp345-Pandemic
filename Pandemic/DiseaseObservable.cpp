#pragma once
#include "DiseaseObservable.h"

void DiseaseObservable::addObserver(Observer *diseaseObserver) {
	observers.push_back(diseaseObserver);
}

void DiseaseObservable::notifyObservers() {
	for (int i = 0; i < observers.size(); i++) {
		observers[i]->update(this);
	}
}
