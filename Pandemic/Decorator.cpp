#include "Decorator.h"

Decorator::Decorator(Observer* gameStatsObservers) {
	this->gameStatsObservers = gameStatsObservers;
}

void Decorator::update(Observable* observable) {
	gameStatsObservers->update(observable);
}