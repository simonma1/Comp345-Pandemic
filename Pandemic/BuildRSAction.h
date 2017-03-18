#pragma once
#include "OtherAction.h"
#include "Observable.h"
#include "ResearchStationObserver.h"
#include <iostream>

class BuildRSAction : public OtherAction, public Observable {
public:
	BuildRSAction();
	BuildRSAction(vector<int>*);
	~BuildRSAction();

	void act(Player *);
	string toString();

protected:
	vector<int>* boardResearchStations;

};
