#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Location.h"
#include "Loader.h"
#include "Cards.h"
#include "PlayerCards.h"
#include "CityCard.h"
#include "ReferenceCard.h"
#include "BuildRSAction.h"
#include "CharterFlightAction.h"
#include "DirectFlightAction.h"
#include "DiscoverCureAction.h"
#include "DriveAction.h"
#include "RoleAction.h"
#include "ShareAction.h"
#include "ShuttleFlightAction.h"
#include "TreatAction.h"
#include <vector>
using namespace std;

int main()
{
	Loader* loader;
	Board* board = new Board;
	int startOrLoad=0;

	
	//Welcome message
	std::cout << "Welcome to Pandemic!!!!" << endl;
	std::cout << "Do you want to:" << endl;
	std::cout << "1. Start New Game" << endl;
	std::cout << "2. Load a Game" << endl;

	cin >> startOrLoad;//User's choice of starting a new game or loading an existing one
	cin.clear();//New line for input
	cin.ignore(numeric_limits<streamsize>::max(), '\n');//Ignores data that is not an integer

	//Will keep asking the user until a valid response has been given
	while ((startOrLoad != 1) && (startOrLoad != 2)) {
		std::cout << "You entered an invalid value. Please Try Again." << endl;
		cin >> startOrLoad;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	vector<Player *> players;
	//Depending on the input will either load an existing game or start a new one
	if (startOrLoad == 1) {//Starts a new game
		loader = new Loader("newgame.json");//newgame.json is the default file name

		loader->loadBoardInfo(board);

		board->distributePlayerCards();
		//Creates 2 players
		board->initializeNewPlayer();
		board->initializeNewPlayer();

		players = board->getListOfPlayer();

	}
	else {
		//Asks the user for the save file name to load
		string filename = "";
		cout << "What is the name of the file you want to load? (No need to put the extension)" << endl;
		cin >> filename;
		filename += ".json";

		loader = new Loader(filename);
		loader->loadBoardInfo(board);
		loader->load(players);
	}

	//Creates Reference card for the players. To be modified later on
	
	players[0]->lookAtReferenceCard();
	

	cout << board->toString();

	//Prints the players detail
	for (int i = 0; i < players.size(); i++) {
		cout << (*players[i]).toString() << endl;
		cout << endl;
	}
	
	board->drawInfectionCard();

	string saveFileName = "save";//save the game state in a file called save.json (for now)
	loader->save(saveFileName, board);
	loader->save(saveFileName, players);

	// Begin actions test
	//vector<Action*> actions = board->getPlayerAvailableActions(players[0]);
	// End actions test
		 
	//Deletes the pointer used
	delete loader;
	delete board;
	system("Pause");
}