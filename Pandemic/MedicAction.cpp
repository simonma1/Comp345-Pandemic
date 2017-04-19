#include "MedicAction.h"
#include <string>
#include <iostream>

using namespace std;

MedicAction::MedicAction(Map* boardMap, Location currentLocation, int currentLocationId) {
	this->boardMap = boardMap;
	this->currentLocation = currentLocation;
	this->currentLocationId = currentLocationId;
}

void MedicAction::act(Player *player) {
	cout << "Medic has initiated their role action" << endl;

	if (currentLocation.getBlue() > 0) {
		while (currentLocation.getBlue() > 0) {
			boardMap->treat(boardMap->getLocationAtId(currentLocationId), "blue");
		}
		cout << "Medic has removed all blue disease cubes" << endl;
	}
	if (currentLocation.getBlack() > 0) {
		while (currentLocation.getBlack() > 0) {
			boardMap->treat(boardMap->getLocationAtId(currentLocationId), "black");
		}
		cout << "Medic has removed all black disease cubes" << endl;
	}
	if (currentLocation.getRed() > 0) {
		while (currentLocation.getRed() > 0) {
			boardMap->treat(boardMap->getLocationAtId(currentLocationId), "red");
		}
		cout << "Medic has removed all red disease cubes" << endl;
	}
	if (currentLocation.getYellow() > 0) {
		while (currentLocation.getYellow() > 0) {
			boardMap->treat(boardMap->getLocationAtId(currentLocationId), "yellow");
		}
		cout << "Medic has removed all yellow disease cubes" << endl;
	}
	
}

string MedicAction::toString() {
	return "Medic: Remove all cubes of one color when doing Treat Disease and automatically remove cubes of cured diseases from the city you are in (and prevent them rom being placed there)";
}