#pragma once
#include "Board.h"
#include "Location.h"
#include "Player.h"
#include "json.hpp"
#include "EventCard.h"
#include "EpidemicCard.h"
#include <fstream>
using namespace std;
using json = nlohmann::json;

class Board;// Forward declaration for the loader who has a board object 
class CardManager;

class Loader {
private:
	json j;
	json out;

public:
	Loader(string filename);
	vector<Player *> loadPlayers(map<int, Location>);
	Board loadBoard();
	void save(string filename, Board* board);
	void save(string filename, vector<Player *> players);
	void load(vector<Player*> &, map<int, Location>);
	void loadBoardInfo(Board* board);
	vector<Pawn> gameSetup(Map* initMap, CardManager* cardManager);
};