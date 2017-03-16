#include "MedicAction.h"
#include <string>
#include <iostream>

using namespace std;

void MedicAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is removing all cubes of one color" << endl;
}

string MedicAction::toString() {
	return "Medic: Remove all cubes of one color when doing Treat Disease and automatically remove cubes of cured diseases from the city you are in (and prevent them rom being placed there)";
}