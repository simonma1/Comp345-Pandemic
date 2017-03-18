#pragma once
#include "Observer.h"

class DiseaseObserver : public Observer {

public:
	virtual void update(Observable*);

};