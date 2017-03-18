#include "ResearchStationObserver.h"

void ResearchStationObserver::update(Observable *observable) {
	cout << "--------------------------------------------------------------------------------------" << endl;
	cout << "The following are the Research station locations: \n";
	static_cast<Board*>(observable)->printResearchStationsLocation();
	cout << "--------------------------------------------------------------------------------------" << endl;
}