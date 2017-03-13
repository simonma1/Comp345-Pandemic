#pragma once
#include "PlayerCards.h"
#include <string>
#include <vector>
using namespace std;


class CityCard : public PlayerCard
{
public:
	CityCard();
	CityCard(int);
	void cardAction();


};