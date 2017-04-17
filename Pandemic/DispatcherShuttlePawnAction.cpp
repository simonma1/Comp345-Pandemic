#include "DispatcherShuttlePawnAction.h"

DispatcherShuttlePawnAction::DispatcherShuttlePawnAction(int destinationId, Player* pawnOwner) {
	this->destinationId = destinationId;
	this->pawnOwner = pawnOwner;
}

void DispatcherShuttlePawnAction::act(Player * player) {
	//This is the first action a dispathcer can conduct - moving another player's pawn to a city that has a pawn without discarding cards
	pawnOwner->getPlayerPawn()->setLocation(destinationId);
	cout << pawnOwner->getRole()->getName() << " is, through a dispatcher, being moved." << endl;
}

string DispatcherShuttlePawnAction::toString() {
	return "Move any pawn, if its owner agrees, to any city containing another pawn ";
}
