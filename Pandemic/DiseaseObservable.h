#pragma once
#include "Observable.h"

class DiseaseObservable : public Observable {
public:
	void addObserver(Observer*);
	void notifyObservers();

private:
	vector<Observer*> observers;
};
