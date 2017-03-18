#include "Observable.h"

void Observable::addObserver(Observer * observer)
{
	observers.push_back(observer);
}

void Observable::notifyObservers()
{
	for (const auto& observer : observers) {
		observer->update(this);
	}
}