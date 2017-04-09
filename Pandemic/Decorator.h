#pragma once
#include "Observer.h"

class Observable;

class Decorator: public Observer {
	Observer* gameStatsObservers;

public:
	Decorator(Observer*);
	virtual void update(Observable*);
};
