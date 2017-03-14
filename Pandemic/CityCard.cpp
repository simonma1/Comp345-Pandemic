#include "CityCard.h"

CityCard::CityCard()
{
}

CityCard::CityCard(int cardId, int cityId) {
	this->cardId = cardId;
	this->cityId = cityId;
	this->type = "city";
}

void CityCard::cardAction() {

}
