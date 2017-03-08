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

	void setOutbreakMarker(int outbreak) { outbreakMarker = outbreak; };
	void setInfectionMarker(int infection) { infectionRateMarker = infection; };
	void setNumOfBlackPieces(int numOfPieces) { this->numOfBlackPieces = numOfPieces; };
	void setNumOfYellowPieces(int numOfPieces) { this->numOfYellowPieces = numOfPieces; };
	void setNumOfRedPieces(int numOfPieces) { this->numOfRedPieces = numOfPieces; };
	void setNumOfBluePieces(int numOfPieces) { this->numOfBluePieces = numOfPieces; };
	void setBlackCureFound(bool isCured) { this->blackCureFound = isCured; };
	void setYellowCureFound(bool isCured) { this->yellowCureFound = isCured; };
	void setRedCureFound(bool isCured) { this->redCureFound = isCured; };
	void setBlueCureFound(bool isCured) { this->blueCureFound = isCured; };


private: 
	vector<Player*> players;
	Map* boardMap;
	int getRandomNumber();
	int infectionRateMarker;
	int outbreakMarker;
	vector<int> InfectionDeck;
	int numOfBlackPieces, numOfYellowPieces, numOfBluePieces, numOfRedPieces;
	bool yellowCureFound, blackCureFound, blueCureFound, redCureFound;
	void boardSetup();
	vector<Pawn> listOfRoles;

};