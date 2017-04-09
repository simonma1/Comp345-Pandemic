#include "GameStatsObserver.h"

/*
Concrete description of the Observer for the board as an observable which will print
changes in the the 1) number of cities infected by the players, 2) total number of resources at each player possession, 3) the number of disease cubes on the map, and 4) the remaining resources as a supply available during the game.
*/
void GameStatsObserver::update(Observable* observable) {

	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Game Statistics:\n ";

	//Will print the number of infected cities based on information about the  infection discard pile
	vector<InfectionCard*> infectionDiscard = (static_cast<Board*>(observable)->getCardManager()->getInfectionCardDiscard());
	cout << "The number of cities infected by the players: " << infectionDiscard.size() << endl;

	//Will print the number of resources of each player based on the number of player cards they have
	int numResources = (static_cast<Board*>(observable)->getListOfPlayer()[static_cast<Board*>(observable)->getTurn()]->getPlayerCards().size());
	cout << " The number of resources (player cards) the current player has is: " << numResources << endl;
	
	//Will print the number of disease cubes on the map
	int numDiseaseCubes = (static_cast<Board*>(observable)->getMap()->getDiseaseCubes()->getNumOfBlackPieces() +
		static_cast<Board*>(observable)->getMap()->getDiseaseCubes()->getNumOfRedPieces() + 
		static_cast<Board*>(observable)->getMap()->getDiseaseCubes()->getNumOfBluePieces() +
		static_cast<Board*>(observable)->getMap()->getDiseaseCubes()->getNumOfYellowPieces());
	cout << " The number of disease cubes on the map is: " << numDiseaseCubes << endl;
	
	//Will print the total number of remaining resources of each player based on the number of player cards they have
	int sizeSupply = (static_cast<Board*>(observable)->getCardManager()->getPlayerCardDeck().size());
	cout << " The number of remaining resources as a supply available is: " << sizeSupply << endl;


}


