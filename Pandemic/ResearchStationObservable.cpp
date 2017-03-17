#include "ResearchStationObservable.h"

void ResearchStationObservable::addObserver(Observer *researchStationObserver) {
	observers.push_back(researchStationObserver);
}

void ResearchStationObservable::notifyObservers() {
	for (int i = 0; i < observers.size(); i++) {
		observers[i]->update(this);
	}
}