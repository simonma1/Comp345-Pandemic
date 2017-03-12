#pragma once
#include "OtherAction.h"

class DiscoverCureAction : public OtherAction {
public:
	void act(Player *);
	DiscoverCureAction();
	DiscoverCureAction(string);
	string getCurableArea() { return curableArea; };

private:
	string curableArea;
};