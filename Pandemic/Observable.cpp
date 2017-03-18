#include "Observable.h"

//Adds observer objects to the the observable's list of observers
void Observable::addObserver(Observer * observer)
{
	observers.push_back(observer);
}

//Loops through the object's observer and notifies them to call their update function
void Observable::notifyObservers()
{
	for (const auto& observer : observers) {
		observer->update(this);//passes itself so the observer will have access to the observable object's data
	}
}
