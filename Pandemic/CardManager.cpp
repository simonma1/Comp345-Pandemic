#include "CardManager.h"

CardManager::CardManager() {
	addObserver(new InfectionLogObserver);//Adds a new observer when creating the cardManager
}

CardManager::CardManager(vector<InfectionCard*> infectionDeck, vector<InfectionCard*> infectionDiscardDeck) {
	this->infectionCardDeck = infectionDeck;
	this->infectionDiscard = infectionDiscardDeck;
	addObserver(new InfectionLogObserver);//Adds a new observer when creating the cardManager
}

//Returns the id associated with every card in the infection deck
vector<int> CardManager::getInfectionCardDeckId() {
	vector<int> ids;

	for (int i = 0; i < infectionCardDeck.size(); i++) {
		ids.push_back(infectionCardDeck[i]->getLocationId());
	}

	return ids;
}

vector<int> CardManager::getPlayerCardDeckId() {
	vector<int> ids;

	for (int i = 0; i < playerCardDeck.size(); i++) {
		ids.push_back(playerCardDeck[i]->getId());
	}

	return ids;
}

vector<int> CardManager::getPlayerCardDiscardId() {
	vector<int> ids;

	for (int i = 0; i < playerCardDiscard.size(); i++) {
		ids.push_back(playerCardDiscard[i]->getId());
	}

	return ids;
}

//Returns the id associated with every card in the discard infection deck
vector<int> CardManager::getInfectionCardDiscardId() {
	vector<int> ids;

	for (int i = 0; i < infectionDiscard.size(); i++) {
		ids.push_back(infectionDiscard[i]->getLocationId());
	}

	return ids;
}

CardManager::~CardManager() {
	for (auto it = infectionCardDeck.begin(); it != infectionCardDeck.end(); ++it) {
		delete *it;
	}
	infectionCardDeck.clear();

	for (auto it = infectionDiscard.begin(); it != infectionDiscard.end(); ++it) {
		delete *it;
	}
	infectionDiscard.clear();

	
	map<int, PlayerCard*>::iterator it = playerCardList.find(1);
	if (it != playerCardList.end()) {
		delete it->second;
		playerCardList.erase(it);
	}	

	for (auto& observer : observers) {
		delete observer;
	}
}

//Returns the next infection card and moves it from the deck to the discard pile
Location CardManager::drawInfectionCard()
{
	if (infectionCardDeck.size() != 0) {
		cout << "Drawing Infection Card\n\n";
		int nextCard = drawShuffledCard();
		InfectionCard* card = infectionCardDeck[nextCard];
		moveInfectionCardToDiscard(card, nextCard);
		notifyObservers();//Notifies the observers
		return card->getLocation();
	}
	else {
		//Will notify observer
	}
}

//Moves the card between the 2 decks
void CardManager::moveInfectionCardToDiscard(InfectionCard* infection, int cardId)
{
	infectionCardDeck.erase(infectionCardDeck.begin() + cardId);
	infectionDiscard.insert(infectionDiscard.begin(), infection);
}

//Moves the card from the default list of player card to the play deck 
void CardManager::moveCardToDeck() {
	for (auto& iter : playerCardList){//iterates through the map's object so only those remaining are accessed
		playerCardDeck.push_back(iter.second);//Pushes the player card in the deck
	}
		
}

void CardManager::setPlayerCardsFromLoad(Player* player) {
	vector<int> cardIds = player->getPlayerCardId();
	for (int i = 0; i < cardIds.size(); i++) {
		playerCardList.at(cardIds[i])->getId();
		player->addPlayerCard(playerCardList.at(cardIds[i]));
		playerCardList.erase(cardIds[i]);
	}
}

void CardManager::setDiscardedPlayerCardsFromLoad() {
	for (int i = 0; i < IdsOfPlayerCardToDiscard.size(); i++) {
		int id = IdsOfPlayerCardToDiscard[i];
		cout << playerCardList.at(id)->getId();
		playerCardDiscard.push_back(playerCardList.at(id));
		playerCardList.erase(id);
	}
}

//Generates the id of the next card to draw
int CardManager::drawShuffledCard()
{
	srand(time(NULL));//Allows for the randomness
	int randomNum = rand() % infectionCardDeck.size();//Normalizes the value by the amount of pawns available
	return randomNum;
}

void CardManager::distributeCards(Board* board)
{
	//Removes the epidemic cards from the deck
	cout << "Removing the Epidemic cards from the deck\n";
	vector<PlayerCard*> epidemicTempHolder;
	for (int i = 1; i <= playerCardList.size(); i++) {
		if (playerCardList.at(i)->getType() != "epidemic") {
			playerCardDeck.push_back(playerCardList.at(i));
		} else {
			epidemicTempHolder.push_back(playerCardList.at(i));
		}
	}
	cout << "The epidemic Cards have been removed from the deck. Ready to distribute cards!\n";

	int numOfCards = numOfCardsPerPlayer.at(board->getNumOfPlayers());
	
	cout << "Every Player will be handed out " << numOfCards << " cards\n";

	//For every player, give them the number of player card necessary
	for (int i = 0; i < board->getNumOfPlayers(); i++) {
		vector<PlayerCard*> playerHand;

		cout << "GENERATING PLAYER " << to_string(i + 1) << "'S CARDS\n";

		for (int j = 0; j < numOfCards; j++) {
		
			srand(time(NULL));//Allows for the randomness
			int randomNum = rand() % playerCardDeck.size();
			playerHand.push_back(playerCardDeck.at(randomNum));
			playerCardDeck.erase(playerCardDeck.begin() + randomNum);
		}
		board->getListOfPlayer().at(i)->setPlayerCards(playerHand);//Sets the players hand
	}

	//Puts the epidemic cards back in the deck
	cout << "Putting the Epidemic Cards back in the deck" << endl;
	for (int i = 0; i < epidemicTempHolder.size(); i++) {
		playerCardDeck.push_back(epidemicTempHolder[i]);
	}
}

PlayerCard* CardManager::drawPlayerCard() {

	cout << "Drawing a Player Card " << endl;
	srand(time(NULL));//Allows for the randomness
	int randomNum = rand() % playerCardDeck.size();
	PlayerCard* card = playerCardDeck[randomNum];
	playerCardDeck.erase(playerCardDeck.begin() + randomNum);
	return card;
}

string CardManager::toString() {
	string value = "";

	value += "The discarded infection cards are: \n";

	for (int i = 0; i < infectionDiscard.size(); i++) {
	
		value += to_string(infectionDiscard[i]->getLocationId()) + ". " 
			+ infectionDiscard[i]->getCityName() + "\n" ;
	}
	
	value += "\n";

	if (playerCardDiscard.size() > 0) {
		value += "The discarded city and event cards are: \n";
		for (int i = 0; i < playerCardDiscard.size(); i++) {
			value += playerCardDiscard[i]->toString() + "\n";
		}
	}
	else {
		value += "There are no discarded player cards\n";
	}
	
	value += "\n";

	value += "There are " + to_string(playerCardList.size()) + " player cards\n";

	return value;
}

