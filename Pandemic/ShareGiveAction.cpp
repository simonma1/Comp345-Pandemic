#include "ShareGiveAction.h"

void ShareGiveAction::act(Player *player) {
	cout << player->getRole()->getName() + " is giving a card to the " + playerYouCanGiveTo->getRole()->getName() << endl;

	int cardId = player->getPlayerCards()[cardPosition]->getId();
	string chosenCardType = player->getPlayerCards()[cardPosition]->getType();
	
	playerYouCanGiveTo->addPlayerCard(player->getPlayerCards()[cardPosition]); // add the card to the other player's list of playercards.
	player->removePlayerCard(cardId); // remove the card from the player's list of playercards.

	cout << "Gave a " + chosenCardType + " card" << endl; 
}

string ShareGiveAction::toString() {
	return "You can share your knowledge with the " + playerYouCanGiveTo->getRole()->getName();
}

ShareGiveAction::ShareGiveAction(){}

ShareGiveAction::ShareGiveAction(Player *playerYouCanGiveTo, int cardPosition) {
	this->playerYouCanGiveTo = playerYouCanGiveTo;
	this->cardPosition = cardPosition;
}

ShareGiveAction::~ShareGiveAction() {
	playerYouCanGiveTo = NULL;
}
