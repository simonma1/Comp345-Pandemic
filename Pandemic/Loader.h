#include "Location.h"
#include "Player.h"
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;
#pragma once

class Loader {
private:
	json j;

public:
	Loader(string filename);
	std::vector<Location> loadMap();
	Player loadPlayers();
};