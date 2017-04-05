#pragma once
#include "PlayerCards.h"


class CardBuilder {

public:
	virtual void buildId() = 0;
	virtual void buildType() = 0;
	virtual void createNewCard() = 0;
	void setCardId(int cardId) { this->cardId = cardId; };
	PlayerCard* getCard() { return card; };

protected:
	PlayerCard* card;
	int cardId;
};

class CityCardBuilder : public CardBuilder{

public:
	CityCardBuilder();
	virtual void buildId();
	virtual void buildType();
	void buildCityId();
	virtual void createNewCard();
	void setCityId(int cityId) { this->cityId = cityId; };

private:
	int cityId;
};