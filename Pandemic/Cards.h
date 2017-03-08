#include <string>
#include <vector>
#include <iostream>
using namespace std;
#pragma once

class PlayerCard {

protected:
	int id;
	string cardName;

public:
	virtual void cardEffect() = 0;
	string getCardName() { return cardName; };

};



class CityCard: public PlayerCard
{
public:
	CityCard();
	CityCard(string);
	void cardEffect();


};

class Role
{
private:
	string name;

public:
	string getName() { return name; };
	Role(string name);
	Role();
};