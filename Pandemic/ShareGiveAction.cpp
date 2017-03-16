#include "ShareGiveAction.h"

void ShareGiveAction::act(Player *player) {
	cout << player->getRole()->getName() + " is giving a card to the " + playerYouCanGiveTo->getRole()->getName() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Here are your cards:\n" + player->playerCardsToString(); // list out the cards.

	string prompt = "Please indicate the card number you would like to give to the " + playerYouCanGiveTo->getRole()->getName() + "  ";
	int chosenCard = 0;
	

	cout << prompt;
	cin >> chosenCard;

	while (chosenCard < 1 || chosenCard > player->getPlayerCards().size()) { // check the user's input and make sure that it's within number of cards. 
		cout << prompt;
		cin >> chosenCard;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int chosenCardId = player->getPlayerCards()[chosenCard - 1]->getId(); // store the information of the card temporarily to display at the end of the action
	string chosenCardType = player->getPlayerCards()[chosenCard - 1]->getType();

	playerYouCanGiveTo->addPlayerCard(player->getPlayerCards()[chosenCard - 1]); // add the card to the other player's list of playercards.
	player->removePlayerCard(chosenCardId); // remove the card from the player's list of playercards.

	cout << "Gave a " + chosenCardType + " card" << endl; 
}

string ShareGiveAction::toString() {
	return "You can share your knowledge with the " + playerYouCanGiveTo->getRole()->getName();
}

ShareGiveAction::ShareGiveAction(){}

ShareGiveAction::ShareGiveAction(Player *playerYouCanGiveTo) {
	this->playerYouCanGiveTo = playerYouCanGiveTo;
}

ShareGiveAction::~ShareGiveAction() {
	playerYouCanGiveTo = NULL;
}
