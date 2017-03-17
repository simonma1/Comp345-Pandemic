#include "CharterFlightAction.h"

void CharterFlightAction::act(Player *player) {
	cout << player->getRole()->getName() << " has selected a charter flight." << endl;
	
	int destinationId = 0;
	cout << "Please indicate the city id of the city you wish to travel to  ";
	cin >> destinationId;

	while (destinationId < 1 || destinationId > 48) {
		if (destinationId == player->getPlayerPawn()->getCurrentLocation())
			cout << "You're already there!" << endl;
		else 
			cout << "You entered an invalid city id" << endl;

		cout << "Please indicate the city id of the city you wish to travel to  ";
		cin >> destinationId;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} 
	

}

string CharterFlightAction::toString() {
	return "You can perform a Charter Flight to anywhere on the map";
}
