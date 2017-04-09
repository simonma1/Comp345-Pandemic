#pragma once
#include "Decorator.h"
#include "GameStatsObserver.h"

class ConcreteDecoratorResourcesPercentage : public Decorator {

public:
	ConcreteDecoratorResourcesPercentage(Observer* gameStatsObservers) : Decorator::Decorator(gameStatsObservers) {};
	virtual void update(Observable*);
};
