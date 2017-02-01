#include "Player.h"
#include "Map.h"
#include "json.hpp"
using json = nlohmann::json;
#pragma once


class Board 
{

public:
	Board();

private: 
	vector<Player> players;
	Map boardMap;


};