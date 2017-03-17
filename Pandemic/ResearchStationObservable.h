#pragma once
#include "Observable.h"

class ResearchStationObservable : public Observable {
public:
	void addObserver(Observer*);
	void notifyObservers();

private:
	vector<Observer*> observers;
};