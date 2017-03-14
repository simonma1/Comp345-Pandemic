#include "EventCard.h"

EventCard::EventCard()
{
}

EventCard::EventCard(int cardId, string cardName)
{
	this->cardId = cardId;
	this->cardName = cardName;
	this->type = "event";
}

void EventCard::cardAction()
{
}
