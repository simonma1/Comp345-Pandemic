#pragma once
#include "Observer.h"
#include <vector>

using namespace std;

class Observable {
public:
	void addObserver(Observer*);
	void notifyObservers();

private:
	vector<Observer*> observers;
};