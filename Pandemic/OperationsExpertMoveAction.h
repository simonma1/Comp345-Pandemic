#pragma once
#include "OperationsExpertAction.h"

class OperationsExpertMoveAction : public OperationsExpertAction {
public:
	OperationsExpertMoveAction() {};
	OperationsExpertMoveAction(int, vector<PlayerCard*>*, vector<PlayerCard*>);
	void act(Player *);
	string toString();
	int getDestination() { return destinationId; };
	/*
	static void setActionCalled(const bool isCalled) {
		actionCalled = isCalled;
	};
	*/

private:
	int destinationId;
	vector<PlayerCard*>* playerCardDiscard;
	vector<PlayerCard*> playerCardDeck;
	//static const bool actionCalled = false;
};
