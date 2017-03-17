#include "ShareTakeAction.h"

void ShareTakeAction::act(Player *player) {
	cout << player->getRole()->getName() + " is performing a share take action" << endl;

	cout << "------------------------------------------" << endl;
	cout << "Here are the other player's cards:\n" + playerYouCanTakeFrom->playerCardsToString(); // list out the cards.

	string prompt = "Please indicate the card number you would like to give to the " + player->getRole()->getName() + "  ";
	int chosenCard = 0;


	cout << prompt;
	cin >> chosenCard;

	while (chosenCard < 1 || chosenCard > playerYouCanTakeFrom->getPlayerCards().size()) { // check the user's input and make sure that it's within number of cards. 
		cout << prompt;
		cin >> chosenCard;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int chosenCardId = playerYouCanTakeFrom->getPlayerCards()[chosenCard - 1]->getId(); // store the information of the card temporarily to display at the end of the action
	string chosenCardType = playerYouCanTakeFrom->getPlayerCards()[chosenCard - 1]->getType();

	player->addPlayerCard(playerYouCanTakeFrom->getPlayerCards()[chosenCard - 1]); // add the card to the other player's list of playercards.
	playerYouCanTakeFrom->removePlayerCard(chosenCardId); // remove the card from the player's list of playercards.

	cout << "Received a " + chosenCardType + " card" << endl;
}

string ShareTakeAction::toString() {
	return "You can receive knowledge from the " + playerYouCanTakeFrom->getRole()->getName();
}

ShareTakeAction::ShareTakeAction(){}

ShareTakeAction::ShareTakeAction(Player *playerYouCanTakeFrom) {
	this->playerYouCanTakeFrom = playerYouCanTakeFrom;
}

ShareTakeAction::~ShareTakeAction() {
	playerYouCanTakeFrom = NULL;
}
