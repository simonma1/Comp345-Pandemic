#include <string>
#include <vector>
#include <iostream>
using namespace std;
#pragma once

class ReferenceCard
{
private:
	vector<string> actions;

public:
	vector<string> getReferenceCard(){ return actions; };
	ReferenceCard(string);
	ReferenceCard();
	void displayPossibleActions();//Shows all the actions that player can do throughout the game. 

};

class PlayerCard
{
private:
	string cardName;

public:
	string getCardName();
	PlayerCard(string cardName);

};

class Role
{
private:
	string name;

public:
	string getName() { return name; };
	Role(string name);
};