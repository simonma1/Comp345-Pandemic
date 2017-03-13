#pragma once
#include "OtherAction.h"

class TreatAction : public OtherAction {
public:
	void act(Player *);
	string toString();
	TreatAction();
	TreatAction(string);
	string getTargetColor() { return targetColor; };

private:
	string targetColor;
};
