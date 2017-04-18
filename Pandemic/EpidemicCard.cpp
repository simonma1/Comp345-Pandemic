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

void EpidemicCard::cardAction(Board boardMap)
{

}

string EpidemicCard::toString() {
	return "Epidemic Card: " + cardName;
}
