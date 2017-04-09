#pragma once
#include "Decorator.h"
#include "GameStatsObserver.h"

class ConcreteDecoratorPercentageCities: public Decorator {

public:
	ConcreteDecoratorPercentageCities(Observer* gameStatsObservers): Decorator::Decorator(gameStatsObservers) {};
	virtual void update(Observable*);
};
