#pragma once
#include "OtherAction.h"

class BuildRSAction : public OtherAction {
public:
	BuildRSAction();
	BuildRSAction(vector<int>*);
	~BuildRSAction();

	void act(Player *);
	string toString();

private:
	vector<int>* boardResearchStations;

};
