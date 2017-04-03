#include "OneQuietNightEventAction.h"

OneQuietNightEventAction::OneQuietNightEventAction() {
}

void OneQuietNightEventAction::act(Player * player) {
	//The idea is to use the board, check if a player has this event card, and skip the startInfection() that will happen once a player has finished his/her turn
	
}

string OneQuietNightEventAction::toString() {
	return "Skip the next Infect Cities step (Do not flip over any Infection Cards)";
}
