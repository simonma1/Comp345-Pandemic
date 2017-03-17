#include "ShareTakeAction.h"

void ShareTakeAction::act(Player *player) {
	cout << player->getRole()->getName() + " is performing a share take action" << endl;

	int cardId = playerYouCanTakeFrom->getPlayerCards()[cardPosition]->getId();
	string chosenCardType = playerYouCanTakeFrom->getPlayerCards()[cardPosition]->getType();

	player->addPlayerCard(playerYouCanTakeFrom->getPlayerCards()[cardPosition]); // add the card to the other player's list of playercards.
	playerYouCanTakeFrom->removePlayerCard(cardId); // remove the card from the player's list of playercards.

	cout << "Received a " + chosenCardType + " card" << endl;
}

string ShareTakeAction::toString() {
	return "You can receive knowledge from the " + playerYouCanTakeFrom->getRole()->getName();
}

ShareTakeAction::ShareTakeAction(){}

ShareTakeAction::ShareTakeAction(Player *playerYouCanTakeFrom, int cardPosition) {
	this->playerYouCanTakeFrom = playerYouCanTakeFrom;
	this->cardPosition = cardPosition;
}

ShareTakeAction::~ShareTakeAction() {
	playerYouCanTakeFrom = NULL;
}
