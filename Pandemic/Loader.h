#include "Location.h"
#include "Player.h"
#include "json.hpp"
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
	Player loadPlayers();
	void save(string filename, map<int,Location>);
};