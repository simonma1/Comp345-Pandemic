#include "QuarantineSpecialistAction.h"
#include <string>
#include <iostream>

using namespace std;

QuarantineSpecialistAction::QuarantineSpecialistAction(string targetColor, Map* boardMap, int location) {
	this->targetColor = targetColor;
	this->boardMap = boardMap;
	this->location = location;
}


void QuarantineSpecialistAction::act(Player *player) {
	cout << player->getRole()->getName() << " Preventing disease and outbreaks within current city and its connecting cities" << endl;
	//The idea is to treat any infection that will occur at a city location that the player is in as well the cities connected to said city.
	//Once the outbreak mechanism is implemented, this role ability should enable a player to also prevent outbreaks 
	boardMap->treat(boardMap->getLocationAtId(location), targetColor);
	cityConnections = boardMap->getLocationAtId(location).getConnections();
	for (int i = 0; i < cityConnections.size(); i++) 
		boardMap->treat(boardMap->getLocationAtId(cityConnections[i]), targetColor);

}

string QuarantineSpecialistAction::toString() {
	return "Quarantine Specialist: Prevent disease cube placements (and outbreaks) in the city you are in and all cities conneced to it";
}
