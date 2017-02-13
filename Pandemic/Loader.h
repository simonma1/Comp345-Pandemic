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

public:
	Loader(string filename);
	std::map<int,Location> loadMap();
	Player loadPlayers();
};