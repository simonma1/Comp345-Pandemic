#pragma once
#include "Observer.h"
#include <vector>

using namespace std;

class Observable {
public:
	virtual void addObserver(Observer *) = 0;
	virtual void notifyObservers() = 0;
};