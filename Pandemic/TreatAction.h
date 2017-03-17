#pragma once
#include "OtherAction.h"
#include "Map.h"

class TreatAction : public OtherAction {
public:
	void act(Player *);
	string toString();
	TreatAction();
	TreatAction(string, Map*, int);
	string getTargetColor() { return targetColor; };

private:
	string targetColor;
	Map* boardMap;
	int location;
};
