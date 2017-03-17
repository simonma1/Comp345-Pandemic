#include "DiscoverCureAction.h"

void DiscoverCureAction::act(Player *player) {
	cout << player->getRole()->getName() << " Is discovering a cure to the " + curableArea + " disease" << endl;

	cout << "------------------------------------------" << endl;
	cout << "Here are the cards you can discard:\n"; // list out the cards for the area.

	vector<int> discardableCards; // vector that will store the id's of the cards that are removable. (don't need the entire card, just their ids)
	vector<int> positionOfDiscardableCards; 
	int counter = 1; // need to count the cards in case card's aren't next to each other in list.
	for (int i = 0; i < player->getPlayerCards().size(); i++) {
		PlayerCard* pc = player->getPlayerCards()[i]; // keep track of the current playercard
		int cardId = pc->getId(); // get the card's id
		string cardArea = locationMap[cardId].getArea(); // get the card's area
		if (curableArea == cardArea) { // if it's the area of the area for which it can discover a cure
			discardableCards.push_back(cardId); // store the card's id to the list of card id's
			cout << to_string(counter) + ". " + pc->toString() << endl; // print out a valid card
			counter++;
			positionOfDiscardableCards.push_back(i);
		}
	}


	string prompt = "Please indicate the card numbers of the 5 cards you would like to discard to discover a cure: \n";
	string error = "You entered an incorrect card number, or you already selected it. Please select another card: \n";

	int chosenCard = 0;
	const int NUM_CARDS_TO_DISCOVER_CURE = 5;
	map<int, bool> chosenCards; // used to keep track of the cards already selected. map is simplest since you won't have to search, you just search by key.
	cout << prompt;
	for (int i = 0; i < NUM_CARDS_TO_DISCOVER_CURE; i++) { // repeat this process for 5 cards
		cout << "Card number " + to_string(i + 1) + ":  ";
		cin >> chosenCard;
		
		while (chosenCard < 1 || chosenCard > discardableCards.size() || chosenCards[chosenCard - 1]) { // check the user's input and make sure that it's within number of cards and the card hasn't already been selected. 
			cout << error;
			cout << "Card number " + to_string(i + 1) + ":  ";
			cin >> chosenCard;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		chosenCards[chosenCard - 1] = true;
		
	}

	for (auto card : chosenCards) {
		playerCardDiscard->push_back(player->getPlayerCards()[positionOfDiscardableCards[card.first]]); // add the card to discard pile. "card.first" returns the key not the value of the map. 
	}

	for (auto card : chosenCards) {
		player->removePlayerCard(discardableCards[card.first]);
	}

	*isAreaCured = true;
}

DiscoverCureAction::DiscoverCureAction(){}

DiscoverCureAction::DiscoverCureAction(string curableArea, bool *isAreaCured, vector<PlayerCard*>* playerCardDiscard, map<int, Location> locationMap) {
	this->curableArea = curableArea;
	this->isAreaCured = isAreaCured;
	this->playerCardDiscard = playerCardDiscard;
	this->locationMap = locationMap;
}

string DiscoverCureAction::toString() {
	return "You can discover a Cure for the " + curableArea + " disease";
}
