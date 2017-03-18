#pragma once
#include "Observer.h"

class ResearchStationObserver : public Observer {

public:
	virtual void update(Observable*);

};