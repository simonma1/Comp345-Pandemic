#include "ConcreteDecoratorPercentageCities.h"

void ConcreteDecoratorPercentageCities::update(Observable *observable) {
	Decorator::update(observable);
	//Will print the percentage of cities infected by the players
	float percentage;
	vector<InfectionCard*> infectionDiscard = (static_cast<Board*>(observable)->getCardManager()->getInfectionCardDiscard());
	percentage = ((infectionDiscard.size() / 48.0) * 100.0);
	cout << " ADDITION OF NEW STATISTIC: The percentage of cities infected by the players is around: " << percentage << "%" << endl;
}