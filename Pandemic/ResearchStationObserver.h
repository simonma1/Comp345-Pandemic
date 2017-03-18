#pragma once
#include "Observer.h"
#include "BuildRSAction.h"
#include "Board.h"

class ResearchStationObserver : public Observer {

public:
	virtual void update(Observable*);

};