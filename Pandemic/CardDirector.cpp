#include "CardDirector.h"

void CardDirector::constructCard()
{
	cardBuilder->createNewCard();
	cardBuilder->buildType();
}
