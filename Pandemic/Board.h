#include "Player.h"
#include "Map.h"
#pragma once

/*The board will contain the list of player and allow them to interact with the locations and card,
as well as execute action
*/
class Board 
{

public:
	Board();
	~Board();
	void addPlayer(Player* p);
	void setMap(Map*);
	void initializeNewPlayer(Role*);
	vector<Player*> getListOfPlayer() { return players; };
	string toString();
	void setOutbreakMarker(int i);
	int getoutBreakMarker; 


private: 
	vector<Player*> players;
	Map* boardMap;
	vector<string> colors = { "Pink", "Orange", "Blue", "Green", "Red", "White", "Brown" };
	string getRandomColorFromRemaining();
	int infectionRateMarker;
	int outbreakMarker;
	vector<int> InfectionDeck;


};