#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class PlayerCard {

protected:
	int cardId;
	string cardName;
	string type;

public:
	virtual void cardAction() = 0;
	string getCardName() { return cardName; };
	int getId() { return cardId; }
	string getType() { return type; };
	virtual string toString() = 0;
};