#include "Observer.h"
#pragma once

using namespace std;

class ResearchStationObserver : public Observer {
public: 
	void update(Observable *);
};