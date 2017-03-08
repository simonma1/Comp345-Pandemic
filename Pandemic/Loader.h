#include "Location.h"
#include "Player.h"
#include "json.hpp"
#include "Board.h"
#include <fstream>
using namespace std;
using json = nlohmann::json;
#pragma once

class Loader {
private:
	json j;
	json out;

public:
	Loader(string filename);
	vector<Player *> loadPlayers();
	Board loadBoard();
	void save(string filename, Board* board);
	void save(string filename, vector<Player *> players);
	void load(vector<Player*> &);
	void loadBoardInfo(Board* board);
	vector<Pawn> gameSetup(Map* initMap);
};