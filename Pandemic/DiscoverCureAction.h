#pragma once
#include "OtherAction.h"

class DiscoverCureAction : public OtherAction {
public:
	void act(Player *);
	DiscoverCureAction();
	DiscoverCureAction(string, bool*, vector<PlayerCard*>* playerCardDiscard, map<int, Location> locationMap);
	string getCurableArea() { return curableArea; };
	string toString();

private:
	string curableArea;
	bool *isAreaCured;
	vector<PlayerCard*>* playerCardDiscard;
	map<int, Location> locationMap;
};