#pragma once
#include "Player.h"
#include "Map.h"
#include "Action.h"
#include "BuildRSAction.h"
#include "CharterFlightAction.h"
#include "DirectFlightAction.h"
#include "DiscoverCureAction.h"
#include "DriveAction.h"
#include "RoleAction.h"
#include "ShareAction.h"
#include "ShareGiveAction.h"
#include "ShareTakeAction.h"
#include "ShuttleFlightAction.h"
#include "TreatAction.h"
#include "CardManager.h"
#include "Loader.h"
#include "DiseaseCubes.h"
#define BLUE "Blue"
#define BLACK "Black"
#define RED "Red"
#define YELLOW "Yellow"
#define MIN_NUM_CARDS_FOR_CURE 5
#define NUM_PLAYERS 2
#define ATLANTA_ID 5

class CardManager;

/*The board will contain the list of player and allow them to interact with the locations and card,
as well as execute action
*/
class Board 
{

public:
	Board();
	Board(int,int, bool, bool, bool, bool);
	~Board();
	void addPlayer(Player* p);
	void setMap(Map*);
	void initializeNewPlayer();
	vector<Player*> getListOfPlayer() { return players; };
	string toString();
	Map* getMap() { return boardMap; };
	Board(const Board&);
	vector<int> getResearchStations() { return researchStations; };
	void setResearchStations(vector<int> researchStations) { this->researchStations = researchStations; };
	string printResearchStationsLocation();
	vector<Action *> getPlayerAvailableActions(Player *);
	void requestAction();
	void setCardManager(CardManager* cardManager) { this->cardManager = cardManager; };
	CardManager* getCardManager() { return this->cardManager; };
	Location drawInfectionCard();
	void distributePlayerCards();
	int getTurn() { return turn; };

	void startInfection();

	int getOutBreakMarker() { return outbreakMarker; };
	int getInfectionRateMarker() { return infectionRateMarker; };
	bool isYellowCured() { return yellowCureFound; };
	bool isBlackCured() { return blackCureFound; };
	bool isRedCured() { return redCureFound; };
	bool isBlueCured() { return blueCureFound; };

	void setOutbreakMarker(int outbreak) { outbreakMarker = outbreak; };
	void setInfectionMarker(int infection) { infectionRateMarker = infection; };
	void setBlackCureFound(bool isCured) { this->blackCureFound = isCured; };
	void setYellowCureFound(bool isCured) { this->yellowCureFound = isCured; };
	void setRedCureFound(bool isCured) { this->redCureFound = isCured; };
	void setBlueCureFound(bool isCured) { this->blueCureFound = isCured; };
	void toggleTurn() { this->turn = (turn + 1) % NUM_PLAYERS; };
	void setTurn(int turn) { this->turn = turn; };
	int getNumOfPlayers() { return players.size(); };

	void setDiseaseCubes(DiseaseCubes* cubes) { this->diseaseCubes = cubes; };
	DiseaseCubes* getDiseaseCubes() { return diseaseCubes; };

	static const int CITIESTOINFECTINBEGINNING = 9;
	
private: 
	vector<Player*> players;
	Map* boardMap;
	int getRandomNumber();
	int infectionRateMarker;
	int outbreakMarker;
	vector<int> InfectionDeck;
	bool yellowCureFound, blackCureFound, blueCureFound, redCureFound;
	void boardSetup();
	vector<Pawn> listOfRoles;
	vector<int> researchStations; // vector of location ids
	CardManager* cardManager;
	int turn;
	DiseaseCubes* diseaseCubes;
};