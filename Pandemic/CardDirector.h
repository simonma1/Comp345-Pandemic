#pragma once
#include "CardBuilder.h"

class CardDirector {

public:
	void setBuilder(CardBuilder* builder) { this->cardBuilder = builder; };
	PlayerCard* getPlayerCard() { return cardBuilder->getCard(); };
	void constructCard();

private:
	CardBuilder* cardBuilder;
};