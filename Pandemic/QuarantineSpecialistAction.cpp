#include "QuarantineSpecialistAction.h"
#include <string>
#include <iostream>

using namespace std;

void QuarantineSpecialistAction::act(Player *player) {
	cout << player->getRole()->getName() << " Preventing disease and outbreaks within current city" << endl;
}

string QuarantineSpecialistAction::toString() {
	return "Quarantine Specialist: Prevent disease cube placements (and outbreaks) in the city you are in and all cities conneced to it";
}

/*
bool QuarantineSpecialist::canPerformRoleAction(Player *player) {
	if (player->getRole()->getName == "Quarantine Specialist") {
		return true;
	}
	else
		return false;
}
*/