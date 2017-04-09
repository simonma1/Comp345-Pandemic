#pragma once
#include "Observer.h"
#include "Board.h"

class GameStatsObserver : public Observer {

public: 
	GameStatsObserver() {};
	virtual void update(Observable*);
};