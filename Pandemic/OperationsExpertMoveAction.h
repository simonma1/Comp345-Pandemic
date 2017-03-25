#pragma once
#include "OperationsExpertAction.h"

class OperationsExpertMoveAction : public OperationsExpertAction {
public:
	OperationsExpertMoveAction() {};
	OperationsExpertMoveAction(int, vector<PlayerCard*>*, vector<PlayerCard*>*);
	void act(Player *);
	string toString();
	int getDestination() { return destinationId; };

private:
	int destinationId;
	vector<PlayerCard*>* playerCardDiscard;
	vector<PlayerCard*>* playerCardDeck;
};
