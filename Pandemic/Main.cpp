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

void saveGame(Loader*, string, Board*, vector<Player*>);

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

		//Creates 2 players
		board->initializeNewPlayer();
		board->initializeNewPlayer();

		board->distributePlayerCards();

		players = board->getListOfPlayer();

		board->startInfection();

	}
	else {
		//Asks the user for the save file name to load
		string filename = "";
		cout << "What is the name of the file you want to load? (No need to put the extension)" << endl;
		cin >> filename;
		filename += ".json";

		loader = new Loader(filename);
		loader->loadBoardInfo(board);
		loader->load(players, board->getMap()->getMapLocation());
	}

	//Creates Reference card for the players. To be modified later on
	
	players[0]->lookAtReferenceCard();

	int keepPlaying = 0; // using this to be able to get out of while loop for now (debugging)

	while (!board->isGameOver() && keepPlaying == 0) {
		//print state of the board
		cout << board->toString();

		//Prints the players detail
		for (int i = 0; i < players.size(); i++) {
			cout << (*players[i]).toString() << endl;
			cout << endl;
		}

		// Display available actions
		vector<Action*> actions = board->getPlayerAvailableActions(players[board->getTurn()]);
		cout << "Here are your available actions:" << endl;
		for (int i = 0; i < actions.size(); i++) {
			cout << to_string(i + 1) + ". " + actions[i]->toString() << endl;
		}
		
		if (actions.size() > 1) {
			int actionChosen = 0;
			do {
				cout << "Please select the action number you would like to perform between 1 and " + to_string(actions.size()) + "  ";
				cin >> actionChosen;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (actionChosen < 1 || actionChosen > actions.size());

			cout << "Selected action " + to_string(actionChosen) << endl;
			actions[actionChosen - 1]->act(players[board->getTurn()]);
		}
		else {
			cout << "I'm sorry, you currently do not have any actions available";
		}
		
		
		// change the next player's turn
		board->toggleTurn();
		
		// Delete the created actions
		for (int i = 0; i < actions.size(); i++) {
			delete actions[i];
			actions[i] = NULL;
		}

		cout << "The turn has be switched. Would you like to keep playing?\nEnter 0 to keep playing or 1 to stop playing" << endl;
		cin >> keepPlaying;
	}
	

	string saveFileName = "save";//save the game state in a file called save.json (for now)
	saveGame(loader, saveFileName, board, players);

		 
	//Deletes the pointer used
	delete loader;
	delete board;
	system("Pause");
}

void saveGame(Loader *loader, string saveFileName, Board *board, vector<Player*> players) {
	loader->save(saveFileName, board);
	loader->save(saveFileName, players);
}
