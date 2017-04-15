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

	void setCardId(int id) { this->cardId = id; };
	void setCardName(string name) { this->cardName = name; };
	void setType(string type) { this->type = type; };
};