#pragma once
#include "Player.h"
#include <iostream>

class Action {
public:
	virtual void act(Player *) = 0;
	virtual string toString() = 0;
};
