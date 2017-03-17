#pragma once
#include "MovementNoCardAction.h"

class ShuttleFlightAction : public MovementNoCardAction {
public:
	void act(Player *);
	string toString();
	ShuttleFlightAction();
	ShuttleFlightAction(int);
	int getOtherRSLocationId() { return otherRSLocationId; };

private:
	int otherRSLocationId;
};
