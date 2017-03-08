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
	map<int,Location> loadMap();
	vector<Player *> loadPlayers();
	Board loadBoard();
	void save(string filename, map<int,Location>, Board board);
	void save(string filename, vector<Player *> players);
	void load(vector<Player*> &);
	void gameSetup(Map* initMap);
};