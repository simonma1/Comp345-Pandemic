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
		ifstream i("newgame.json");
		i >> this->j;
		std::cerr << "Invalid argument: " << ia.what() << '\n';
		cerr << "Starting a New Game";
	}
}


//Given the filename, will save the state of the board to a json file of that name
//The order will not be as the original file since it is stored alphabetically in the json
void Loader::save(string filename, Board* board) {

	Map* cityList = board->getMap();
	map<int, Location> cities = cityList->getMapLocation();
	int outIndex = 0;//Keeps track of the size of all cities that have infections

	//Saves the infection for the cities, only if that number is bigger than 0
	for (int i = 1; i < (cities.size() + 1); i++) {

		int yellow = cities.at(i).getYellow();
		int black = cities.at(i).getBlack();
		int red = cities.at(i).getRed();
		int blue = cities.at(i).getBlue();

		//Checks to see if the current city as an infection of note, that is not 0
		if (yellow != 0 || black != 0 || red != 0 || blue != 0) {
			//i-1 because the keys in the map start at 1, but in an array, indexing starts at 0
			out["location"][outIndex]["id"] = cities.at(i).getId();

			//Only prints the infection number for that infection's color
			if (yellow != 0) {
				out["location"][outIndex]["yellow"] = yellow;
			}

			if (black != 0) {
				out["location"][outIndex]["black"] = black;
			}

			if (red != 0) {
				out["location"][outIndex]["red"] = red;
			}

			if (blue != 0) {
				out["location"][outIndex]["blue"] = blue;
			}
			outIndex++; // incremented only if a city has an infection
		} 
	}

	//Prints out an empty array if there is no infection to prevent parsing problems when loading
	if (outIndex == 0) {
		vector<int> empty;
		out["location"] = empty;
	}

	DiseaseCubes* diseases = board->getDiseaseCubes();

	//Saves the board data
	out["Board"]["outbreakLevel"] = board->getOutBreakMarker();
	out["Board"]["infectionLevel"] = board->getInfectionRateMarker();
	out["Board"]["diseaseEradicated"]["black"] = board->isBlackCured();
	out["Board"]["diseaseEradicated"]["yellow"] = board->isYellowCured();
	out["Board"]["diseaseEradicated"]["red"] = board->isRedCured();
	out["Board"]["diseaseEradicated"]["blue"] = board->isBlueCured();
	out["Board"]["researchStations"] = board->getResearchStations();

	out["Board"]["pieces"]["blackPiecesAv"] = diseases->getNumOfBlackPieces();
	out["Board"]["pieces"]["yellowPiecesAv"] = diseases->getNumOfYellowPieces();
	out["Board"]["pieces"]["redPiecesAv"] = diseases->getNumOfRedPieces();
	out["Board"]["pieces"]["bluePiecesAv"] = diseases->getNumOfBluePieces();

	out["Board"]["turn"] = board->getTurn();

	CardManager* cardManager = board->getCardManager();

	//Save the Infection Cards
	out["cards"]["infection"]["deck"] = cardManager->getInfectionCardDeckId();
	out["cards"]["infection"]["discard"] = cardManager->getInfectionCardDiscardId();

	//Saves the game information to a new or existing file of the specified name
	std::ofstream o(filename + ".json");
	o << std::setw(4) << this->out << std::endl;
}

vector<Player *> Loader::loadPlayers(map<int, Location> map) {
	Player *player1;
	Player *player2;
	vector<Player *> players;

	players.push_back(player1);
	players.push_back(player2);

	int i = 0;
	for (auto &player : players) {

		Role *r = new Role (j["Players"][i]["role"].get<string>());
		
		//TODO: add event cards.
		//vector<int> playerCardCityIds = j["Players"][i]["playercards"]["citycards"].get<vector<int>>(); 
		

		Pawn *pawn = new Pawn(j["Players"][i]["pawn"]["color"].get<string>()); // The color int is read from the json (since enum stored as int) 
																  //and dynamically created and allocated
		

		int playerLocation = j["Players"][i]["pawn"]["location"].get<int>();

		pawn->setLocation(map[playerLocation]);

		Player* p = new Player( // Create the player with the role, and the pawn
			r,
			pawn
		);

		player = p;

		i++;
	}


	return players;
}

//Save the state of the players in the json.
void Loader::save(string filename, vector<Player *> players) {
	for (int i = 0; i < 2; i++) {
		// Save player's role
		out["Players"][i]["role"] = players[i]->getRole()->getName();

		//TODO: add event cards.
		// Save player's cards 
		for (int j = 0; j < players[i]->getPlayerCards().size(); j++) {
			out["Players"][i]["playercards"]["citycards"][j] = players[i]->getPlayerCards()[j]->getId();
		}


		// Save player's pawn color, and location.
		out["Players"][i]["pawn"]["color"] = players[i]->getPlayerPawn()->getColor();
		out["Players"][i]["pawn"]["location"] = players[i]->getPlayerPawn()->getCurrentLocation().getId();

		
	}
	

	//Saves the game information to a new or existing file of the specified name
	std::ofstream o(filename + ".json");
	o << std::setw(4) << this->out << std::endl;
}

void Loader::load(vector<Player*> & players, map<int, Location> map)
{
	players = loadPlayers(map);

}

//Loads the board data that is related to a game
void Loader::loadBoardInfo(Board * board)
{
	//Loads the miscellaneous data of the board
	board->setOutbreakMarker(j["Board"]["outbreakLevel"].get<int>());
	board->setInfectionMarker(j["Board"]["infectionLevel"].get<int>());

	board->setBlackCureFound(j["Board"]["diseaseEradicated"]["black"].get<bool>());
	board->setYellowCureFound(j["Board"]["diseaseEradicated"]["yellow"].get<bool>());
	board->setRedCureFound(j["Board"]["diseaseEradicated"]["red"].get<bool>());
	board->setBlueCureFound(j["Board"]["diseaseEradicated"]["blue"].get<bool>());

	board->setResearchStations(j["Board"]["researchStations"].get<std::vector<int>>());

	board->setTurn(j["Board"]["turn"].get<int>());

	DiseaseCubes* diseases = new DiseaseCubes(
		j["Board"]["pieces"]["blackPiecesAv"].get<int>(),
		j["Board"]["pieces"]["yellowPiecesAv"].get<int>(),
		j["Board"]["pieces"]["redPiecesAv"].get<int>(),
		j["Board"]["pieces"]["bluePiecesAv"].get<int>()
	);

	board->setDiseaseCubes(diseases);

	//Loads the infection level for every cities
	Map* map = board->getMap();
	for (int idx = 0; idx < j["location"].size(); idx++) {

		int locationId = j["location"][idx]["id"];
		if (!(j["location"][idx]["black"].is_null())) {
			map->setLocationNumOfBlack(locationId, j["location"][idx]["black"].get<int>());
		}

		if (!(j["location"][idx]["yellow"].is_null())) {
			map->setLocationNumOfYellow(locationId, j["location"][idx]["yellow"].get<int>());
		}

		if (!(j["location"][idx]["red"].is_null())) {
			map->setLocationNumOfRed(locationId, j["location"][idx]["red"].get<int>());
		}

		if (!(j["location"][idx]["blue"].is_null())) {
			map->setLocationNumOfBlue(locationId, j["location"][idx]["blue"].get<int>());
		}
	}

	//Loads the card Manager

	//The infection cards will be stored according to the id of the location that they correspond to
	vector<int> infectionCardIds = j["cards"]["infection"]["deck"].get<vector<int>>();
	vector<int> infectionCardDiscardIds = j["cards"]["infection"]["discard"].get<vector<int>>();

	vector<InfectionCard*> infectionCards;//Will contain the infection deck
	vector<InfectionCard*> infectionDiscardCards;//Will contain the discarded infection cards

	//Loads the infection deck
	for (int i = 0; i < infectionCardIds.size(); i++) {//Loops through the deck card in the json 
		Location city = map->getLocationAtId(infectionCardIds[i]);//Gets the location corresponding to the id
		InfectionCard* infectionCard = new InfectionCard(city);//Creates the infection card using the location object
		infectionCards.push_back(infectionCard);//Adds all the location to the list that will be returned to the card manager
	}

	//Loads the discard deck
	for (int i = 0; i < infectionCardDiscardIds.size(); i++) {
		Location city = map->getLocationAtId(infectionCardDiscardIds[i]);
		InfectionCard* infectionCard = new InfectionCard(city);
		infectionDiscardCards.push_back(infectionCard);
	}

	//Sets the board's card Manager with the card being instantiated according to the JSON
	//CardManager* cardManager = new CardManager(infectionCards, infectionDiscardCards);
	//board->setCardManager(cardManager);
	CardManager* cardManager = board->getCardManager();
	cardManager->setInfectionCardDeck(infectionCards);
	cardManager->setInfectionCardDiscard(infectionDiscardCards);

	map = NULL;//deletes the dangling map pointer
	cardManager = NULL;
}

vector<Pawn> Loader::gameSetup(Map* initMap, CardManager* cardManager) {
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
		};

		cityMap[cityId] = l;
	}

	initMap->setMapLocation(cityMap);

	//Instantiates the list of Player Cards

	map<int, PlayerCard*> playerCards;

	//Loops through the city cards
	for (int i = 0; i < j["GameSetup"]["playerCards"]["cityCards"].size(); i++) {
		int cardId = j["GameSetup"]["playerCards"]["cityCards"][i]["cardId"].get<int>();
		int cityId = j["GameSetup"]["playerCards"]["cityCards"][i]["cityId"].get<int>();
		PlayerCard* cityCard = new CityCard(cardId, cityId);
		playerCards[cardId] = cityCard;
	}

	//Loops through the event Cards
	for (int i = 0; i < j["GameSetup"]["playerCards"]["eventCards"].size(); i++) {
		int cardId = j["GameSetup"]["playerCards"]["eventCards"][i]["cardId"].get<int>();
		string cardName = j["GameSetup"]["playerCards"]["eventCards"][i]["cardName"].get<string>();
		PlayerCard* eventCard = new EventCard(cardId, cardName);
		playerCards[cardId] = eventCard;
	}

	//Loops through all the epidemic Cards
	for (int i = 0; i < j["GameSetup"]["playerCards"]["epidemicCards"].size(); i++) {
		int cardId = j["GameSetup"]["playerCards"]["epidemicCards"][i]["cardId"].get<int>();
		string description = j["GameSetup"]["playerCards"]["epidemicCards"][i]["description"].get<string>();
		PlayerCard* epidemicCard = new EpidemicCard(cardId, description);
		playerCards[cardId] = epidemicCard;
	}

	cardManager->setPlayerCardList(playerCards);

	//Instantiates the list of roles that a player can have
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
