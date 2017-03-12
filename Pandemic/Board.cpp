#include "Board.h"
#include "Loader.h"

/*
The board class will act as an intermediary between location and player
*/

Board::Board()
{
	outbreakMarker = 0;
	boardMap = new Map;

	boardSetup();
}

Board::Board(int outbreak, int infection, int blackPieces, int yellowPieces,int redPieces, 
	int bluePieces, bool blackCure, bool yellowCure, bool redCure, bool blueCure) {
	
	this->outbreakMarker = outbreak;
	this->infectionRateMarker = infection;

	this->numOfBlackPieces = blackPieces;
	this->numOfYellowPieces = yellowPieces;
	this->numOfRedPieces = redPieces;
	this->numOfBluePieces = bluePieces;

	this->blackCureFound = blackCure;
	this->yellowCureFound = yellowCure;
	this->redCureFound = redCure;
	this->blueCureFound = blueCure;
	boardMap = new Map;
}

//Destructor for the Board object. Will delete every player from the vector of player pointer
Board::~Board()
{
	for (int i = 0; i < players.size(); i++)
	{
		delete players[i];
	}
	if (boardMap != NULL) {
		delete boardMap;
	}
}

void Board::addPlayer(Player * p)
{
	players.push_back(p);
}

void Board::setMap(Map* map)
{
	boardMap = map;
}

/*
Creates a new player to be put in the list of player. The player will be given a pawn of a 
random color. No 2 players will receive the same one. The pawn will be link to the class of 
that color
*/
void Board::initializeNewPlayer()
{
	Player* player = new Player();
	int randNum = getRandomNumber();

	Role* role = new Role(listOfRoles[randNum].getRole());
	Pawn* pawn = new Pawn;
	*pawn = listOfRoles[randNum];
	player->setPawn(pawn);//Sets the pawn with the color for the player
	player->setRole(role);
	addPlayer(player);//adds the player to the list of player
	listOfRoles.erase(listOfRoles.begin() + randNum);//Removes the color from the list
}

string Board::toString()
{
	string value = "";

	value += boardMap->toString() + "\n";
	string line = "-------------------------------------------------------------------------------\n";
	value += line;

	value += "Board Info:\n";
	value += "\tThe Oubreak Level is at: " + to_string(outbreakMarker) + "\n\n";
	value += "\tThe Infection Level is at: " + to_string(infectionRateMarker) + "\n\n";
	value += "\tThere is " + to_string(numOfBlackPieces) + " black pieces still available\n";
	value += "\tThere is " + to_string(numOfYellowPieces) + " yellow pieces still available\n";
	value += "\tThere is " + to_string(numOfRedPieces) + " red pieces still available\n";
	value += "\tThere is " + to_string(numOfBluePieces) + " blue pieces still available\n\n";

	if (blackCureFound && blueCureFound && redCureFound && yellowCureFound) {
		value += "\tAll diseases have been cured!!!\n";
	}
	else if (!blackCureFound && !blueCureFound && !redCureFound && !yellowCureFound) {
		value += "\tNo diseases have been cured yet\n";
	}
	else {
		if (blackCureFound) {
			value += "\tThe black disease has been cured!!\n";
		}else {
			value += "\tThe black disease has not been cured\n";
		}

		if (yellowCureFound) {
			value += "\tThe yellow disease has been cured!!\n";
		}
		else {
			value += "\tThe yellow disease has not been cured\n";
		}

		if (redCureFound) {
			value += "\tThe red disease has been cured!!\n";
		}
		else {
			value += "\tThe red disease has not been cured\n";
		}

		if (blueCureFound) {
			value += "\tThe blue disease has been cured!!\n";
		}
		else {
			value += "\tThe blue disease has not been cured\n";
		}
	}
	value += "\n";

	value += line;

	value += printResearchStationsLocation();

	return value;
}

//Generates a random color from the colors list for a new player
int Board::getRandomNumber()
{
	cout << "A ROLE IS BEING RANDOMLY GENERATED FOR THE PLAYER\n" << endl;
	srand(time(NULL));//Allows for the randomness
	int randomNum = rand() % listOfRoles.size();//Normalizes the value by the amount of pawns available
	return randomNum;
}

//Instantiates the part common for all boards. Mainly the roles and location. Location will have to be refactored here  
void Board::boardSetup()
{
	string setupFileName = "setup.json";	
	Loader loadCommon = Loader(setupFileName);
	Map* map = new Map();

	this->listOfRoles = loadCommon.gameSetup(map);
	*boardMap = *map;
	map = NULL;

}

Board::Board(const Board& board) {

	this->outbreakMarker = board.outbreakMarker;
	this->infectionRateMarker = board.infectionRateMarker;

	this->numOfBlackPieces = board.numOfBlackPieces;
	this->numOfYellowPieces = board.numOfYellowPieces;
	this->numOfRedPieces = board.numOfRedPieces;
	this->numOfBluePieces = board.numOfBluePieces;

	this->blackCureFound = board.blackCureFound;
	this->yellowCureFound = board.yellowCureFound;
	this->redCureFound = board.redCureFound;
	this->blueCureFound = board.blueCureFound;

	this->boardMap = new Map;
	*boardMap = *board.boardMap;
}

string Board::printResearchStationsLocation() {
	string value = "The Research Stations are located in the following cities: \n";

	for (int i = 0; i < researchStations.size(); i++) {
		string cityName = boardMap->getMapLocation().at(researchStations[i]).getCity();
		value += "\t" + to_string(researchStations[i]) + ". " + cityName + "\n";
	}

	value += "\n";
	return value;
}
vector<Action*> Board::getPlayerAvailableActions(Player *player) {
	vector<Action*> availableActions;
	
	if (player->getPlayerCards().size() > 0) {
		for (auto &card : player->getPlayerCards()) {
			// check for build RS action and charterflight action
			if (player->getPlayerPawn()->getCurrentLocation()->getCity() == card->getCardName()) {
				availableActions.push_back(new BuildRSAction());
				availableActions.push_back(new CharterFlightAction());
			}
			// check for directflight action
			else
				availableActions.push_back(new DirectFlightAction(card->getId()));
		}
	}
	
	// check for discover cure action
	for (int i = 0; i < researchStations.size(); i++) {
		if (player->getPlayerPawn()->getCurrentLocation()->getId() == researchStations[i]) { // is the player on a research station
			int blueAreaCardCounter = 0; // keep track of number of player's blue cards
			int blackAreaCardCounter = 0; // keep track of number of player's black cards
			int redAreaCardCounter = 0; // keep track of number of player's red cards
			int yellowAreaCardCounter = 0; // keep track of number of player's yellow cards

			string blueArea = "Blue";
			string blackArea = "Black";
			string redArea = "Red";
			string yellowArea = "Yellow";


			if (player->getPlayerCards().size() > 0) { // does the player have any cards
				for (auto &card : player->getPlayerCards()) { // count the number of cards with the same area as the reasearch station's area
					string cardArea = boardMap->getMapLocation().at(card->getId()).getArea();

					// count the number of each area card
					if (cardArea  == blueArea) blueAreaCardCounter++;
					else if (cardArea == blackArea) blackAreaCardCounter++;
					else if (cardArea == redArea) redAreaCardCounter++;
					else if (cardArea == yellowArea) yellowAreaCardCounter++;

				}
			}
			
			// if the player has any number of area cards greater than or equal to 5, he can discover a cure for that area
			if (blueAreaCardCounter >= 5)
				availableActions.push_back(new DiscoverCureAction(blueArea));
			if (blackAreaCardCounter >= 5)
				availableActions.push_back(new DiscoverCureAction(blackArea));
			if (redAreaCardCounter >= 5)
				availableActions.push_back(new DiscoverCureAction(redArea));
			if (yellowAreaCardCounter >= 5)
				availableActions.push_back(new DiscoverCureAction(yellowArea));


			// check for shuttleflight action
			for (int j = 0; j < researchStations.size(); j++) { // add every other research station player can move to.
				availableActions.push_back(new ShuttleFlightAction(researchStations[j]));
			}
		}
	}

	// check for drive action
	for (auto connection : player->getPlayerPawn()->getCurrentLocation()->getConnections()) {
		availableActions.push_back(new DriveAction(connection));
	}

	// check for role action
	//TODO

	// check for share action
	for (auto &otherPlayer : players) {
		if (otherPlayer != player) {
			if (otherPlayer->getPlayerPawn()->getCurrentLocation()->getId() == player->getPlayerPawn()->getCurrentLocation()->getId()) {
				if (otherPlayer->getPlayerCards().size() > 0) // if other player has cards, player can take from him
					availableActions.push_back(new ShareTakeAction(otherPlayer));
				if (player->getPlayerCards().size() > 0) // if player has cards, he can give to other player
					availableActions.push_back(new ShareGiveAction(otherPlayer));
			}
		}
	}

	// check for treat action


	return vector<Action*>();
}
;
