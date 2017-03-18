#include "InfectionLogObserver.h"

void InfectionLogObserver::update(Observable* observable) {

	cout << "-------------------------------------------------------------------------------" "\n" << endl;
	cout << "In Infection Log: \n ";

	vector<InfectionCard*> infectionDeck = (static_cast<CardManager*>(observable)->getInfectionCardDeck());
	cout << "There are now " << infectionDeck.size() << " cards to draw from" << endl;

	cout << "Here is the list of cards still in the deck:\n";
	for (int i = 0; i < infectionDeck.size(); i++) {
		cout << "\t" << infectionDeck[i]->getLocationId() << ". " << infectionDeck[i]->getCityName() << endl;
	}

	vector<InfectionCard*> infectionDiscard = (static_cast<CardManager*>(observable)->getInfectionCardDiscard());
	cout << "There are now " << infectionDiscard.size() << " discarded cards" << endl;

	cout << "Here is the list of discarded cards:\n";
	for (int i = 0; i < infectionDiscard.size(); i++) {
		cout << "\t" << infectionDiscard[i]->getLocationId() << ". " << infectionDiscard[i]->getCityName() << endl;
	}

	cout << "The last discarded infection card was: \n";
	cout << infectionDiscard.front()->getLocationId() << ". " << infectionDiscard.front()->getCityName()<<endl;
	cout << "-------------------------------------------------------------------------------" "\n" << endl;
}

