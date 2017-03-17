#pragma once
#include "Observer.h"

class DiseaseObserver : public Observer {
public:
	void update(Observable *);
};
