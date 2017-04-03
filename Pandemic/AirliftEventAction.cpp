#include "AirliftEventAction.h"

AirliftEventAction::AirliftEventAction() {
}

AirliftEventAction::AirliftEventAction(int destinationId, string permissionFromOther) {
	this->destinationId = destinationId;
	this->permissionFromOther = permissionFromOther;
}

void AirliftEventAction::act(Player * player) {
	//The idea is to move a pawn to any city (this will be decided and checked on the board) as long as the permission is received from owner of the pawn
	//(again a player will be prompted on the console).
	if (permissionFromOther == "Y" || permissionFromOther == "y") {
		cout << player->getRole()->getName() << " Is, due to an airlift event action, is being moved to " + to_string(destinationId) << endl;
		player->getPlayerPawn()->setLocation(destinationId);
	}
	else cout << "Cannot move pawn as did not get permisson from player" << endl;
}

string AirliftEventAction::toString() {
	return "Move any 1 pawn to any city. Get permission before moving another player's pawn";
}
