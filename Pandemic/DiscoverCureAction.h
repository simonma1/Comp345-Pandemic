#pragma once
#include "OtherAction.h"

class DiscoverCureAction : public OtherAction {
public:
	void act(Player *);
	DiscoverCureAction();
	DiscoverCureAction(string, bool*);
	string getCurableArea() { return curableArea; };
	string toString();

private:
	string curableArea;
	bool *isAreaCured;
};