#include "CardBuilder.h"
#include "CityCard.h"
#include "EpidemicCard.h"
#include "EventCard.h"

CityCardBuilder::CityCardBuilder(int cardId, int cityId)
{
	buildId(cardId);
	buildCityId(cityId);
}

void CityCardBuilder::buildId(int id)
{
	card->setCardId(id);
}


void CityCardBuilder::buildType()
{
	card->setType("city");
}

void CityCardBuilder::buildCityId(int id)
{ 
	dynamic_cast<CityCard*>(card)->setCityId(id);
}

void CityCardBuilder::createNewCard()
{
	this->card = new CityCard;
}
