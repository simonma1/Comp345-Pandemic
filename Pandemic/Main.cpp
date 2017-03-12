#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Location.h"
#include "Loader.h"
#include "Cards.h"
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

		//Creates some value to be passed to the player object. This is for demo purpose
		Role* role = new Role("Scientist");
		Role* role2 = new Role("Medic");

		PlayerCard* card1 = new CityCard(1);
		PlayerCard* card2 = new CityCard(2);

		vector<PlayerCard* > cards1;
		cards1.push_back(card1);

		vector<PlayerCard* > cards2;
		cards2.push_back(card2);

		//Creates 2 players
		board->initializeNewPlayer();
		board->initializeNewPlayer();

		players = board->getListOfPlayer();
		players[0]->setPlayerCards(cards1);
		players[1]->setPlayerCards(cards2);

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
	
	string saveFileName = "save";//save the game state in a file called save.json (for now)
	loader->save(saveFileName, board);
	loader->save(saveFileName, players);

	// Begin actions test
	cout << "====================================" << endl;
	cout << "Actions section" << endl;
	cout << "====================================" << endl;

	vector<Action *> actions;
	actions.push_back(new BuildRSAction());
	actions.push_back(new ShuttleFlightAction());
	actions.push_back(new TreatAction());
	actions.push_back(new CharterFlightAction());
	actions.push_back(new DirectFlightAction());
	actions.push_back(new DiscoverCureAction());
	actions.push_back(new RoleAction());
	//actions.push_back(new ShareAction());
	actions.push_back(new DriveAction());

	for (auto &action : actions) {
		action->act(players[0]);
	}

	for (auto &action : actions) {
		delete action;
	}// End actions test
		 
	//Deletes the pointer used
	delete loader;
	delete board;
	system("Pause");
}