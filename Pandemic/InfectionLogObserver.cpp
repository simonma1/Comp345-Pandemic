#include "InfectionLogObserver.h"

/*
Concrete description of the Observer for the card Manager objects which will print
changes in the the infection cards, such as when a card is drawn from the deck to the 
discard pile
*/
void InfectionLogObserver::update(Observable* observable) {

	cout << "-------------------------------------------------------------------------------" "\n" << endl;
	cout << "In Infection Log: \n ";

	//Will print the info regarding the infection card deck
	//casts to be able to use method of the observable object which will be a CardManager
	vector<InfectionCard*>* infectionDeck = (static_cast<CardManager*>(observable)->getInfectionCardDeck());
	cout << "There are now " << infectionDeck->size() << " cards to draw from" << endl;

	cout << "Here is the list of cards still in the deck:\n";
	for (int i = 0; i < infectionDeck->size(); i++) {
		cout << "\t" << infectionDeck->at(i)->getLocationId() << ". " << infectionDeck->at(i)->getCityName() << endl;
	}

	//Prints the info regarding the infection discard pile
	vector<InfectionCard*>* infectionDiscard = (static_cast<CardManager*>(observable)->getInfectionCardDiscard());
	cout << "There are now " << infectionDiscard->size() << " discarded cards" << endl;

	cout << "Here is the list of discarded cards:\n";
	for (int i = 0; i < infectionDiscard->size(); i++) {
		cout << "\t" << infectionDiscard->at(i)->getLocationId() << ". " << infectionDiscard->at(i)->getCityName() << endl;
	}

	//Prints the last infection card that was drawn from the pile
	cout << "The last discarded infection card was: \n";
	cout << infectionDiscard->front()->getLocationId() << ". " << infectionDiscard->front()->getCityName()<<endl;
	cout << "-------------------------------------------------------------------------------" "\n" << endl;
}

