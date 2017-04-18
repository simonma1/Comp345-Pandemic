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
	board->incrementInfectionRate();
	InfectionCard* bottomInfectionCard = cardManager->getInfectionCardDeck()->at(cardManager->getInfectionCardDeck()->size() - 1);
	if (board->isBlackCured() || board->isBlueCured() || board->isRedCured() || board->isYellowCured()) {
		if (board->isBlackCured()) {

		}
		if (board->isBlueCured()) {

		}
		if (board->isRedCured()) {

		}
		if (board->isYellowCured()) {

		}
	}
	else {

	}



}

string EpidemicCard::toString() {
	return "Epidemic Card: " + cardName;
}
