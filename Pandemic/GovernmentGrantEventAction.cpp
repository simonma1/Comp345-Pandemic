#include "GovernmentGrantEventAction.h"

GovernmentGrantEventAction::GovernmentGrantEventAction() {
}

GovernmentGrantEventAction::GovernmentGrantEventAction(vector<int>* boardResearchStations, Map* boardMap, int location) {
	this->boardResearchStations = boardResearchStations;
	this->boardMap = boardMap;
	this->location = location;
}

void GovernmentGrantEventAction::act(Player *player) {
	//The idea here is to build a research station onto a location that is chosen on the board (randomly and a check will be made in Board.cpp
	//to make sure there isnt a research station already built there).
	cout << player->getRole()->getName() << " Building a Research Station" << endl;
	boardResearchStations->push_back(boardMap->getLocationAtId(location).getId());
}

string GovernmentGrantEventAction::toString() {
	return "Add 1 research station to any city (no City Cards needed)";
}
