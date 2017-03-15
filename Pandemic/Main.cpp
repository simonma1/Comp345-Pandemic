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
	static const int MOVESPERTURN = 4;
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
		cout << "You entered an invalid value. Please Try Again." << endl;
		cin >> startOrLoad;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	vector<Player *> players;
	//Depending on the input will either load an existing game or start a new one
	if (startOrLoad == 1) {//Starts a new game
		loader = new Loader("newgame.json");//newgame.json is the default file name

		loader->loadBoardInfo(board);

		//Asks the user for the number of player and instantiate them
		int numOfPlayers;
		cout << "How many players will there be?" << endl;
		cin >> numOfPlayers;
		while ((numOfPlayers < 1) || (numOfPlayers > 4)) {
			cout << "You entered an invalid value. Please Try Again." << endl;
			cin >> startOrLoad;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		//Creates the desired number of players. Works only for 2 players for now
		for (int i = 0; i < numOfPlayers; i++) {
			board->initializeNewPlayer();
		}
	
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
		loader->load(players);
		for (int i = 0; i < players.size(); i++)
			board->addPlayer(players[i]);
	}

	//Creates Reference card for the players. To be modified later on
	
	players[0]->lookAtReferenceCard();

	int keepPlaying = 0; // using this to be able to get out of while loop for now (debugging)

	while (!board->isGameOver() && keepPlaying == 0) {
		//Does the 4 actions
		for (int i = MOVESPERTURN; i > 0; i--){
			//print state of the board
			cout << board->toString();

			//Prints the players detail
			for (int i = 0; i < players.size(); i++) {
				cout << (*players[i]).toString() << endl;
					cout << endl;
			}
			cout << "YOU HAVE " << i << "ACTIONS LEFT"<<endl;


			 //players[0]->addPlayerCard(new CityCard(5, 5)); // Used to test the charter flight action

			 
			//Used to test the build research station action and discover cure.
			/*for (int i = 15; i < 20; i++) {
				players[0]->addPlayerCard(new CityCard(i, i));
			}*/

			

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


			// Delete the created actions
			for (int i = 0; i < actions.size(); i++) {
				delete actions[i];
				actions.erase(actions.begin() + i);
			}
		}

		//Draw 2 Player cards

		//Infect Cities
		board->endOfTurnInfection();

		// change the next player's turn
		board->toggleTurn();

		cout << "The turn has been switched. Would you like to keep playing?\nEnter 0 to keep playing or 1 to stop playing" << endl;
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
