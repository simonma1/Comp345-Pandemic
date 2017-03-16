#pragma once
#include "PlayerCards.h"
#include <string>
#include <vector>
using namespace std;


class CityCard : public PlayerCard
{
private:
	int cityId;

public:
	CityCard();
	CityCard(int,int);
	void cardAction();
	string toString();


};