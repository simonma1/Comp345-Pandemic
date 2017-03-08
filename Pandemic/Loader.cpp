#include "Loader.h"

/*
	The loader class will act as the class that will either load a game, existing or new, as well as save the game
*/

//Creates a new Loader with the will name to load when starting the game
Loader::Loader(string filename) {
	try {
		ifstream i(filename);
		i >> this->j;
	}
	catch (const std::invalid_argument& ia) {
		//Catches exception where the file entered does not exist and starts a new game
		ifstream i("map.json");
		i >> this->j;
		std::cerr << "Invalid argument: " << ia.what() << '\n';
		cerr << "Starting a New Game";
	}
}


//Given the filename, will save the state of the board to a json file of that name
//The order will not be as the original file since it is stored alphabetically in the json
void Loader::save(string filename, Board board) {

	map<int, Location> cities = board.getMap()->getMapLocation();

	for (int i = 1; i < (cities.size() + 1); i++) {
	
		//i-1 because the keys in the map start at 1, but in an array, indexing starts at 0
		out["location"][i-1]["id"] = cities.at(i).getId();
		out["location"][i - 1]["yellow"] = cities.at(i).getYellow();
		out["location"][i - 1]["blue"] = cities.at(i).getBlue();
		out["location"][i - 1]["black"] = cities.at(i).getBlack();
		out["location"][i - 1]["red"] = cities.at(i).getRed();
	
	}

	out["Board"]["outbreakLevel"] = board.getOutBreakMarker();
	out["Board"]["infectionLevel"] = board.getInfectionRateMarker();
	out["Board"]["pieces"]["blackPiecesAv"] = board.getNumOfBlackPieces();
	out["Board"]["pieces"]["yellowPiecesAv"] = board.getNumOfYellowPieces();
	out["Board"]["pieces"]["redPiecesAv"] = board.getNumOfRedPieces();
	out["Board"]["pieces"]["bluePiecesAv"] = board.getNumOfBluePieces();
	out["Board"]["diseaseEradicated"]["black"] = board.isBlackCured();
	out["Board"]["diseaseEradicated"]["yellow"] = board.isYellowCured();
	out["Board"]["diseaseEradicated"]["red"] = board.isRedCured();
	out["Board"]["diseaseEradicated"]["blue"] = board.isBlueCured();


	//Saves the game information to a new or existing file of the specified name
	std::ofstream o(filename + ".json");
	o << std::setw(4) << this->out << std::endl;
}

vector<Player *> Loader::loadPlayers() {
	Player *player1;
	Player *player2;
	vector<Player *> players;

	players.push_back(player1);
	players.push_back(player2);

	int i = 0;
	for (auto &player : players) {

		Role *r = new Role (j["Players"][i]["role"].get<string>());

		vector<string> playerCardNames = j["Players"][i]["playercards"].get<vector<string>>();
		vector<PlayerCard *> pcards;

		for (auto &cardName : playerCardNames) { // for each playerCardName, create a new player card and store it in a vector. 
			PlayerCard *pc = new CityCard(cardName);
			pcards.push_back(pc);
		}

		Pawn *pawn = new Pawn(j["Players"][i]["pawn"]["color"].get<string>()); // The color int is read from the json (since enum stored as int) 
																  //and dynamically created and allocated
		

		//int playerLocation = j["Players"][i]["pawn"]["location"].get<int>();

		//pawn->setPawnLocation(playerLocation);

		Player* p = new Player( // Create the player with the role, and the pawn
			r,
			pawn
		);

		player = p;
		player->setPlayerCards(pcards);

		i++;
	}


	return players;
}

//Save the state of the players in the json.
void Loader::save(string filename, vector<Player *> players) {
	for (int i = 0; i < 2; i++) {
		// Save player's role
		out["Players"][i]["role"] = players[i]->getRole()->getName();


		// Save player's cards 
		for (int j = 0; j < players[i]->getPlayerCards().size(); j++) {
			out["Players"][i]["playercards"][j] = players[i]->getPlayerCards()[j]->getCardName();
		}


		// Save player's pawn color, and location.
		out["Players"][i]["pawn"]["color"] = players[i]->getPlayerPawn()->getColor();
		//out["Players"][i]["pawn"]["location"] = players[i]->getPlayerPawn()->getCurrentLocation().getId();
	}
	

	//Saves the game information to a new or existing file of the specified name
	std::ofstream o(filename + ".json");
	o << std::setw(4) << this->out << std::endl;
}

void Loader::load(vector<Player*> & players)
{
	players = loadPlayers();

}

//Loads the board data that is related to a game
void Loader::loadBoardInfo(Board * board)
{
	board->setOutbreakMarker(j["Board"]["outbreakLevel"].get<int>());
	board->setInfectionMarker(j["Board"]["infectionLevel"].get<int>());

	board->setNumOfBlackPieces(j["Board"]["pieces"]["blackPiecesAv"].get<int>());
	board->setNumOfYellowPieces(j["Board"]["pieces"]["yellowPiecesAv"].get<int>());
	board->setNumOfRedPieces(j["Board"]["pieces"]["redPiecesAv"].get<int>());
	board->setNumOfBluePieces(j["Board"]["pieces"]["bluePiecesAv"].get<int>());

	board->setBlackCureFound(j["Board"]["diseaseEradicated"]["black"].get<bool>());
	board->setYellowCureFound(j["Board"]["diseaseEradicated"]["yellow"].get<bool>());
	board->setRedCureFound(j["Board"]["diseaseEradicated"]["red"].get<bool>());
	board->setBlueCureFound(j["Board"]["diseaseEradicated"]["blue"].get<bool>());
}

vector<Pawn> Loader::gameSetup(Map* initMap) {
	map<int, Location> cityMap;
	//j[location] is the array with all the different cities. Thus each object can be accessed like a regular array
	for (int i = 0; i < j["location"].size(); i++) {
		//Loops through all cities in the JSON and puts them in a list that will be given to the map
		int cityId = j["location"][i]["id"].get<int>();
		Location l{//Calls the constructor of Location object, thus order is important to be the same
			cityId,
			j["location"][i]["city"].get<std::string>(),
			j["location"][i]["area"].get<std::string>(),
			j["location"][i]["adjacent"].get<std::vector<int>>(),
			j["location"][i]["yellow"].get<int>(),
			j["location"][i]["blue"].get<int>(),
			j["location"][i]["black"].get<int>(),
			j["location"][i]["red"].get<int>()
		};

		cityMap[cityId] = l;
	}

	initMap->setMapLocation(cityMap);

	vector<Pawn> listOfRoles;
	for (int k = 0; k < j["GameSetup"]["roles"].size(); k++) {

		Pawn p{
			j["GameSetup"]["roles"][k]["color"],
			j["GameSetup"]["roles"][k]["role"]
		};

		listOfRoles.push_back(p);
	}

	return listOfRoles;
}
