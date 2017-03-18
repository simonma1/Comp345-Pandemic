#include "Observable.h"

void Observable::addObserver(Observer *o) {
	observers.push_back(o);
}

void Observable::notifyObservers() {
	for (int i = 0; i < observers.size(); i++) {
		observers[i]->update(this);
	}
}
