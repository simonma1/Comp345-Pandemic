#include "OperationsExpertBuildAction.h"
#include <string>
#include <iostream>

using namespace std;

OperationsExpertBuildAction::OperationsExpertBuildAction(vector<int>* boardResearchStations) {
	this->boardResearchStations = boardResearchStations;
}

void OperationsExpertBuildAction::act(Player *player) {
	cout << player->getRole()->getName() << " Building a Research Station" << endl;
	boardResearchStations->push_back(player->getPlayerPawn()->getCurrentLocation());
}

string OperationsExpertBuildAction::toString() {
	return "Operations Expert: As an action, build a research station in the city you are in (no City card needed and without discarding it).";
}
