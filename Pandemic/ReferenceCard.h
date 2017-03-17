#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class ReferenceCard
{
private:
	vector<string> actions;

public:
	vector<string> getReferenceCard() { return actions; };
	ReferenceCard(string);
	ReferenceCard();
	void displayPossibleActions();//Shows all the actions that player can do throughout the game. 

};