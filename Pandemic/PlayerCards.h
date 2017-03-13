#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class PlayerCard {

protected:
	int id;
	string cardName;

public:
	virtual void cardAction() = 0;
	string getCardName() { return cardName; };
	int getId() { return id; }
};