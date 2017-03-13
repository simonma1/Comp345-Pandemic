#pragma once
#include "OtherAction.h"

class BuildRSAction : public OtherAction {
public:
	void act(Player *);
	string toString();
};
