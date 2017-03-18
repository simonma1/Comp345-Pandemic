#pragma once
#include "Observer.h"
#include <vector>

using namespace std;

class Observer;

class Observable {
public:
	void addObserver(Observer*);
	void notifyObservers();

protected:
	vector<Observer*> observers;
};