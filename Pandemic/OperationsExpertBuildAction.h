#pragma once
#include "OperationsExpertAction.h"

class OperationsExpertBuildAction : public OperationsExpertAction {
public:
	OperationsExpertBuildAction(vector<int>*);
	void act(Player *);
	string toString();

private:
	vector<int>* boardResearchStations;
};
