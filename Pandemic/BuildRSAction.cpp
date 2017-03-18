#include "BuildRSAction.h"

using namespace std;

BuildRSAction::BuildRSAction(){
	addObserver(new ResearchStationObserver);
}

BuildRSAction::BuildRSAction(vector<int>* boardResearchStations) {
	this->boardResearchStations = boardResearchStations;
	addObserver(new ResearchStationObserver);
}

BuildRSAction::~BuildRSAction() {
	boardResearchStations = NULL;
}

void BuildRSAction::act(Player *player) {
	cout << player->getRole()->getName() << " Building a Research Station" << endl;
	boardResearchStations->push_back(player->getPlayerPawn()->getCurrentLocation());
	player->removePlayerCard(player->getPlayerPawn()->getCurrentLocation());
	notifyObservers();
}

string BuildRSAction::toString() {
	return "You can build a Research Station";
}
