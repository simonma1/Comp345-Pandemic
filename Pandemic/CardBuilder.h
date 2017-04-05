#pragma once
#include "PlayerCards.h"


class CardBuilder {

public:
	virtual void buildId(int id) = 0;
	virtual void buildType() = 0;
	virtual void createNewCard() = 0;
	PlayerCard* getCard() { return card; };

protected:
	PlayerCard* card;
};

class CityCardBuilder : public CardBuilder{

public:
	CityCardBuilder(int,int);
	virtual void buildId(int id);
	virtual void buildType();
	void buildCityId(int id);
	virtual void createNewCard();
};