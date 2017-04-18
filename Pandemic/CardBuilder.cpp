#include "CardBuilder.h"
#include "CityCard.h"
#include "EpidemicCard.h"
#include "EventCard.h"


void CardBuilder::buildId()
{
	card->setCardId(this->cardId);
}

//City Card Part

CityCardBuilder::CityCardBuilder()
{
}


void CityCardBuilder::buildType()
{
	card->setType("city");
}

void CityCardBuilder::buildSpecificPart()
{
	buildCityId();
}

void CityCardBuilder::buildCityId()
{ 
	dynamic_cast<CityCard*>(card)->setCityId(this->cityId);
}

void CityCardBuilder::createNewCard()
{
	this->card = new CityCard;
}

//Event Card Part

EventCardBuilder::EventCardBuilder()
{
}

void EventCardBuilder::buildType()
{
	card->setType("event");
}

void EventCardBuilder::buildCardName()
{
	card->setCardName(this->cardName);
}

void EventCardBuilder::buildSpecificPart()
{
	buildCardName();
}


void EventCardBuilder::createNewCard()
{
	this->card = new EventCard;
}

//Epidemic Card Part

EpidemicCardBuilder::EpidemicCardBuilder()
{
}

void EpidemicCardBuilder::buildType()
{
	card->setType("epidemic");
}

void EpidemicCardBuilder::buildCardName()
{
	card->setCardName(this->cardName);
}

void EpidemicCardBuilder::buildSpecificPart()
{
	buildCardName();
}


void EpidemicCardBuilder::createNewCard()
{
	this->card = new EventCard;
}
