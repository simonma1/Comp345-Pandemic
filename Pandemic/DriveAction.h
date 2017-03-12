#pragma once
#include "MovementNoCardAction.h"

class DriveAction : public MovementNoCardAction {
public:
	void act(Player *);
};