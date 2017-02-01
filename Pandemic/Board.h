#include "Player.h"
#include "Map.h"
#pragma once


class Board 
{

public:
	Board();

private: 
	vector<Player> players;
	Map boardMap;


};