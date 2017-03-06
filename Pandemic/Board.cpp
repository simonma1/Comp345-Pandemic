#include "Board.h"

/*
The board class will act as an intermediary between location and player
*/

Board::Board()
{
	outbreakMarker = 0;
	boardMap = new Map;
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
void Board::initializeNewPlayer(Role* role)
{
	Player* player = new Player();
	string color = getRandomColorFromRemaining();//Returns the color of the pawn
	player->setPawn(color);//Sets the pawn with the color for the player
	player->setRole(role);
	addPlayer(player);//adds the player to the list of player

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

	return value;
}

//Generates a random color from the colors list for a new player
string Board::getRandomColorFromRemaining()
{
	srand(time(NULL));//Allows for the randomness
	int randomNum = rand() % colors.size();//Normalizes the value by the amount of colors available
	string color = colors[randomNum];//Gets the color at the index randomly chosen
	colors.erase(colors.begin() + randomNum);//Removes the color from the list
	return color;
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
