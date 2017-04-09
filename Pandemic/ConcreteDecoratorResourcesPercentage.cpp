#include "ConcreteDecoratorResourcesPercentage.h"

void ConcreteDecoratorResourcesPercentage::update(Observable *observable) {
	Decorator::update(observable);
	int sizeSupply = 60;
	//Will print the percentage of resources that a player possesses
	//Will print the number of resources of each player based on the number of player cards they have
	int numResources = (static_cast<Board*>(observable)->getListOfPlayer()[static_cast<Board*>(observable)->getTurn()]->getPlayerCards().size());
	//cout << " The number of resources (player cards) the current player has is: " << numResources << endl;
	//Will print the total number of remaining resources of each player based on the number of player cards they have
	if (static_cast<Board*>(observable)->getCardManager()->getPlayerCardDeck().size() > 0) {
		sizeSupply = (static_cast<Board*>(observable)->getCardManager()->getPlayerCardDeck().size());
		//cout << " The number of remaining resources as a supply available is: " << sizeSupply << endl;
	}
	cout << " ADDITION OF NEW STATISTIC: The fraction of resources a player has as compared to the remaining supply is: " << (numResources) << "/" << (sizeSupply) << endl;
}