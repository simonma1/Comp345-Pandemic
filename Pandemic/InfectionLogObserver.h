#pragma once
#include "Observer.h"
#include "CardManager.h"

class InfectionLogObserver : public Observer{

public:
	virtual void update(Observable*);

};
