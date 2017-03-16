#include "ScientistAction.h"
#include <string>
#include <iostream>

using namespace std;

ScientistAction::ScientistAction() {

}

void ScientistAction::act(Player *player) {
	cout << player->getRole()->getName() << " Discovering a cure!" << endl;
}

string ScientistAction::toString() {
	return "Scientist: You need only 4 cards of the same color to do the Discover a Cure action";
}

/*
bool Scientist::canPerformRoleAction(Player *player) {
	if (player->getRole()->getName == "Scientist") {
		return true;
	}
	else
		return false;
}
*/