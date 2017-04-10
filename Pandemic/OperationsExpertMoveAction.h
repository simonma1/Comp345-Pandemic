#pragma once
#include "OperationsExpertAction.h"

class OperationsExpertMoveAction : public OperationsExpertAction {

public:
	OperationsExpertMoveAction() {};
	OperationsExpertMoveAction(int, vector<PlayerCard*>*, vector<PlayerCard*>*);
	void act(Player *);
	string toString();
	int getDestination() { return destinationId; };
	/*
	static void setActionCalled(bool isCalled) {
		actionCalled = isCalled;
	}
	*/

private:
	//static bool actionCalled;
	int destinationId;
	vector<PlayerCard*>* playerCardDiscard;
	vector<PlayerCard*>* playerCardDeck;
};
