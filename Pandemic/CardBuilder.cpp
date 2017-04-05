#include "CardBuilder.h"
#include "CityCard.h"
#include "EpidemicCard.h"
#include "EventCard.h"

CityCardBuilder::CityCardBuilder()
{
}

void CityCardBuilder::buildId()
{
	card->setCardId(this->cardId);
}


void CityCardBuilder::buildType()
{
	card->setType("city");
}

void CityCardBuilder::buildCityId()
{ 
	dynamic_cast<CityCard*>(card)->setCityId(this->cityId);
}

void CityCardBuilder::createNewCard()
{
	this->card = new CityCard;
	buildCityId();
}
