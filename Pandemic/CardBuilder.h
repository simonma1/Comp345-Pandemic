#pragma once
#include "PlayerCards.h"

//Abstract class for player card creation
class CardBuilder {

public:
	virtual void buildId();
	virtual void buildType() = 0;//sets the type of the card, e.g. event, epidemic, or city
	virtual void buildSpecificPart() = 0 ;//sets the part of the card that may not be common to all parts
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
	virtual void buildType();
	virtual void buildSpecificPart();
	void buildCityId();
	virtual void createNewCard();
	void setCityId(int cityId) { this->cityId = cityId; };

private:
	int cityId;
};

class EventCardBuilder : public CardBuilder {

public:
	EventCardBuilder();
	virtual void buildType();
	void buildCardName();
	virtual void buildSpecificPart();
	void setCardName(string name) { this->cardName = name; };
	virtual void createNewCard();

private:
	string cardName;
};


class EpidemicCardBuilder : public CardBuilder {

public:
	EpidemicCardBuilder();
	virtual void buildType();
	void buildCardName();
	virtual void buildSpecificPart();
	void setCardName(string name) { this->cardName = name; };
	virtual void createNewCard();

private:
	string cardName;
};