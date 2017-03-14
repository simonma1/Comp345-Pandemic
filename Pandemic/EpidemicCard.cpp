#include "EpidemicCard.h"

EpidemicCard::EpidemicCard()
{
}

EpidemicCard::EpidemicCard(int cardId, string cardName)
{
	this->cardId = cardId;
	this->cardName = cardName;
	this->type = "epidemic";
}

void EpidemicCard::cardAction()
{
}
