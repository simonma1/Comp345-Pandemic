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
	Board(int, int, int, int, int ,int, bool, bool, bool, bool);
	~Board();
	void addPlayer(Player* p);
	void setMap(Map*);
	void initializeNewPlayer();
	vector<Player*> getListOfPlayer() { return players; };
	string toString();
	void setOutbreakMarker(int i);
	Map* getMap() { return boardMap; };
	Board(const Board&);

	int getOutBreakMarker() { return outbreakMarker; };
	int getInfectionRateMarker() { return infectionRateMarker; };
	int getNumOfBlackPieces() { return numOfBlackPieces; };
	int getNumOfBluePieces() { return numOfBluePieces; };
	int getNumOfRedPieces() { return numOfRedPieces; };
	int getNumOfYellowPieces() { return numOfYellowPieces; };
	bool isYellowCured() { return yellowCureFound; };
	bool isBlackCured() { return blackCureFound; };
	bool isRedCured() { return redCureFound; };
	bool isBlueCured() { return blueCureFound; };


private: 
	vector<Player*> players;
	Map* boardMap;
	vector<string> colors = { "Pink", "Orange", "Blue", "Green", "Red", "White", "Brown" };
	int getRandomNumber();
	int infectionRateMarker;
	int outbreakMarker;
	vector<int> InfectionDeck;
	int numOfBlackPieces, numOfYellowPieces, numOfBluePieces, numOfRedPieces;
	bool yellowCureFound, blackCureFound, blueCureFound, redCureFound;
	void boardSetup();
	vector<Pawn> listOfRoles;

};