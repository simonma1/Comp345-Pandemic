#include <string>
#include <vector>
#include <iostream>
using namespace std;
#pragma once

class Card {

protected:
	 

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