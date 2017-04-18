#include "Board.h"

/*
The board class will act as an intermediary between location and player
*/

Board::Board()
{
	outbreakMarker = 0;
	boardMap = new Map;
	boardSetup();
}

Board::Board(int outbreak, int infection, bool blackCure, bool yellowCure, bool redCure, bool blueCure) {
	
	this->outbreakMarker = outbreak;
	this->infectionRateMarker = infection;

	this->blackCureFound = blackCure;
	this->yellowCureFound = yellowCure;
	this->redCureFound = redCure;
	this->blueCureFound = blueCure;
	this->gameLost = false;
	this->gameWon = false;
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
	delete cardManager;
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
	pawn->setLocation(ATLANTA_ID);
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
	value += "\tThe Infection Level is at: " + to_string(getCurrentInfectionRate()) + "\n\n";
	

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

	value += boardMap->getDiseaseCubes()->toString();

	value +=  cardManager->toString();

	value += line;

	value += printResearchStationsLocation();

	value += "\n";

	value += "It is currently the " + players[turn]->getRole()->getName() + "\'s turn\n";

	value += "\n";

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

    loadCommon.gameSetup(this);
}

bool Board::wasVisited(Location loc, vector<Location> visited) {
	bool wasVisited = false;
	for (int i = 0; i < visited.size(); i++) {
		if (loc.getId() == visited[i].getId())
			return true;
	}

	return wasVisited;
}

bool Board::hasOutbreak(Location loc, string virusColor) {
	bool hasOutbreak = false;
	if (virusColor == BLUE && loc.getBlue() == 3)
		hasOutbreak = true;
	else if (virusColor == BLACK && loc.getBlack() == 3)
		hasOutbreak = true;
	else if (virusColor == YELLOW && loc.getYellow() == 3)
		hasOutbreak = true;
	else if (virusColor == RED && loc.getRed() == 3)
		hasOutbreak = true;

	return hasOutbreak;
}

void Board::drawPlayerCards() {
	for (int i = 0; i < 2; i++) {
		PlayerCard* card = cardManager->drawPlayerCard();
		if (card->getType() == "epidemic") {
			epidemicCardAction();
			cardManager->discardPlayerCard(card);
		}
		else {
			players[turn]->addPlayerCard(card);
		}
	}

	int numOfCards = players[turn]->getPlayerCards().size();


	if(numOfCards > MAXNUMBEROFPLAYERCARDS) {
		cout << "You must discard a card " << endl;

		for (int i = 0; i < numOfCards; i++) {
			cout << players[turn]->getPlayerCards().at(i)->getId() << ". ";
			cout << players[turn]->getPlayerCards().at(i)->getType()<<endl;			
		}

		cout << "Which card do you want to discard: " << endl;
		int cardToDiscardId;
		cin >> cardToDiscardId;
		players[turn]->removePlayerCard(cardToDiscardId);
	}
}

void Board::setPlayerCardsFromLoad() {
	for (auto &player : players) {
		cardManager->setPlayerCardsFromLoad(player);
	}
	cardManager->setDiscardedPlayerCardsFromLoad();
	cardManager->moveCardToDeck();
}

void Board::epidemicCardAction() {
	incrementInfectionRate();
	bottomInfectionCard = cardManager->getInfectionCardDeck()->at(cardManager->getInfectionCardDeck()->size() - 1);
	string areaColor = bottomInfectionCard->getLocation().getArea();
	int diseaseCubeCounter;

	cout << "=============================================================================================================" << endl;
	cout << "                                        EPIDEMIC STARTED IN " + boardMap->getLocationAtId(bottomInfectionCard->getLocationId()).getCity() + "!!!" << endl;
	cout << "=============================================================================================================" << endl;

	if (areaColor == BLACK && !isBlackCured() || areaColor == BLUE && !isBlueCured() || areaColor == YELLOW && !isYellowCured() || areaColor == RED && !isRedCured()) {
		if (areaColor == BLACK) 
			diseaseCubeCounter = boardMap->getLocationAtId(bottomInfectionCard->getLocationId()).getBlack();
		else if (areaColor == BLUE)
			diseaseCubeCounter = boardMap->getLocationAtId(bottomInfectionCard->getLocationId()).getBlue();
		else if (areaColor == YELLOW)
			diseaseCubeCounter = boardMap->getLocationAtId(bottomInfectionCard->getLocationId()).getYellow();
		else if (areaColor == RED)
			diseaseCubeCounter = boardMap->getLocationAtId(bottomInfectionCard->getLocationId()).getRed();
		
		if (diseaseCubeCounter == 0) {
			int i = 0;
			while (i < MAX_NUM_INFECTIONS) {
				infectCity(boardMap->getLocationAtId(bottomInfectionCard->getLocationId()), areaColor);
				i++;
			}
			cout << "EPIDEMIC COMPLETE!" << endl;
			cout << bottomInfectionCard->getCityName() << " now has 3 disease cubes in it" << endl;
		}
		else if (diseaseCubeCounter > 0 && diseaseCubeCounter <= MAX_NUM_INFECTIONS) {
			int numInfections = (MAX_NUM_INFECTIONS + 1) - diseaseCubeCounter;
			int i = 0;
			while (i < numInfections) {
				infectCity(boardMap->getLocationAtId(bottomInfectionCard->getLocationId()), areaColor); // in this case, the outbreak will be called at the final infection
				i++;
			}
			cout << "EPIDEMIC COMPLETE!" << endl;
			cout << bottomInfectionCard->getCityName() << " now has 3 disease cubes in it" << endl;
		}
		cardManager->moveInfectionDiscardtoDeck(); // adds the cards back to the deck, but does not account for the "top of deck" criteria
	}
}

void Board::outbreak(Location loc, string virusColor) {
	if (isAQuarantineSpecialist == false) {
		cout << "=============================================================================================================" << endl;
		cout << "                                        STARTING AN OUTBREAK IN " + loc.getCity() + "!!!" << endl;
		cout << "=============================================================================================================" << endl;

		queue<Location> outbreakQueue; // keeps track of the number of outbreaks remaining to handle
		stack<Location> infectionStack; // keeps track of the cities that have to be infected for a particular outbreak (not counting the chained ones)
		vector<Location> visited; // keeps track of the visited outbreak locations.

		outbreakQueue.push(loc); // first push the current location to the outbreak queue
		while (!outbreakQueue.empty()) { // while there are outbreaks remaining to be handled
			outbreakMarker++;
			visited.push_back(outbreakQueue.front()); // this outbreak location has been visited
			for (int neighbour : outbreakQueue.front().getConnections()) { // for every neighbour
				Location neighbourLocation = boardMap->getLocationAtId(neighbour); // get the neighbour as a location.
				if (!wasVisited(neighbourLocation, visited)) { // if the neighbour has already been visited
					if (hasOutbreak(neighbourLocation, virusColor)) // if the neighbour is in an outbreak situation
						outbreakQueue.push(neighbourLocation); // then push to outbreak queue as an outbreak that needs handling.
					else
						infectionStack.push(neighbourLocation); // otherwise push it to the infection stack.
				}
			}
			while (!infectionStack.empty()) { // infect all the cities in the infection stack.
				infectCity(infectionStack.top(), virusColor);
				infectionStack.pop();
			}
			outbreakQueue.pop(); // this outbreak is now handled. back to the top to check the rest (if more exist).
		}
		// End of outbreak handling
		cout << "Outbreak complete!" << endl;
	}
	isAQuarantineSpecialist = false;
}

void Board::infectCity(Location loc, string virusColor) {
	// first if the city is in an outbreak scenario, perform an outbreak, otherwise, just infect it.
	if (hasOutbreak(loc, virusColor))
		outbreak(loc, virusColor);
	else 
		boardMap->infectCity(loc, virusColor);
}

Location Board::drawInfectionCard()
{
	Location locationToInfect = cardManager->drawInfectionCard();
		
	infectCity(locationToInfect, locationToInfect.getArea());

	return locationToInfect;
}

//At the end of every turn, the number of infection cards drawn will be equal to the infection level
void Board::endOfTurnInfection() {
  int infectionLevel = getCurrentInfectionRate();
  if (hasOneQuietNightEventCard == false) {
	  cout << "\nThe Infection Level is at: " << infectionLevel << ". Therefore " << infectionLevel << " Infection Cards will be drawn\n" << endl;
	  for (int i = 0; i < infectionLevel; i++) {
	  	drawInfectionCard();
	  }
  }
hasOneQuietNightEventCard = false;
}

void Board::distributePlayerCards()
{
	cardManager->distributeCards(this);
}

Board::Board(const Board& board) {

	this->outbreakMarker = board.outbreakMarker;
	this->infectionRateMarker = board.infectionRateMarker;

	this->blackCureFound = board.blackCureFound;
	this->yellowCureFound = board.yellowCureFound;
	this->redCureFound = board.redCureFound;
	this->blueCureFound = board.blueCureFound;

	this->boardMap = new Map;
	*boardMap = *board.boardMap;

	this->cardManager = board.cardManager;
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

void Board::startInfection() {
	
	for (int i = 0; i < CITIESTOINFECTINBEGINNING; i++) {
	
			drawInfectionCard();
	
	}

}

//Returns the infection level which is the value at the index of the infection rate vector
int Board::getCurrentInfectionRate() {
	return infectionRates[infectionRateMarker];
}

//When there is an epidemic, increments the infection rate, unless the limit has been reached
void Board::incrementInfectionRate() {
	if (infectionRateMarker >= infectionRates.size()) {
		cout << "THE GAME IS LOST. THE INFECTION RATE HAS REACHED ITS END"<<endl;
	}
	else {
		infectionRateMarker++;
	}
}

bool Board::isGameLost() {
	return cardManager->getPlayerCardDeck()->size() < 1 || outbreakMarker == 8;
}

bool Board::isGameWon()
{
	return (yellowCureFound && blackCureFound && redCureFound && blueCureFound);
}

vector<Action*> Board::getPlayerAvailableActions(Player *player) {
	vector<Action*> availableActions;
	
	//Checks if player can perform a specific role action
	bool canPerformRoleAction = false;

	//Check for Medic Role Action
	if ((player->getRole()->getName() == "Medic")) {
		Location currentLocation = boardMap->getLocationAtId(player->getPlayerPawn()->getCurrentLocation());
		int currentLocationId = currentLocation.getId();

		if (blackCureFound || redCureFound || yellowCureFound || blueCureFound) {
			if (blackCureFound) {
				while (currentLocation.getBlack() > 0) {
					boardMap->treat(boardMap->getLocationAtId(currentLocationId), "black");
				}
			}
			if (redCureFound) {
				while (currentLocation.getRed() > 0) {
					boardMap->treat(boardMap->getLocationAtId(currentLocationId), "red");
				}
			}
			if (yellowCureFound) {
				while (currentLocation.getYellow() > 0) {
					boardMap->treat(boardMap->getLocationAtId(currentLocationId), "yellow");
				}
			}
			if (blueCureFound) {
				while (currentLocation.getBlue() > 0) {
					boardMap->treat(boardMap->getLocationAtId(currentLocationId), "blue");
				}
			}
		}
		if (player->dispatchMove()) {
			if (blackCureFound) {
				while (currentLocation.getBlack() > 0) {
					boardMap->treat(boardMap->getLocationAtId(currentLocationId), "black");
				}
			}
			if (redCureFound) {
				while (currentLocation.getRed() > 0) {
					boardMap->treat(boardMap->getLocationAtId(currentLocationId), "red");
				}
			}
			if (yellowCureFound) {
				while (currentLocation.getYellow() > 0) {
					boardMap->treat(boardMap->getLocationAtId(currentLocationId), "yellow");
				}
			}
			if (blueCureFound) {
				while (currentLocation.getBlue() > 0) {
					boardMap->treat(boardMap->getLocationAtId(currentLocationId), "blue");
				}
			}
		}
		else {
			availableActions.push_back(new MedicAction(boardMap, currentLocation, currentLocationId));
		}
		
	}
	if ((player->getRole()->getName()  == "Researcher")) {
		availableActions.push_back(new ResearcherAction());
		canPerformRoleAction = true;
	}

	if ((player->getRole()->getName() == "Dispatcher")) {
		availableActions.push_back(new DispatcherAction());
		canPerformRoleAction = true;
	}

	//Quarantine Specialist Role Check (simulation)
	Location currentLocation2 = boardMap->getLocationAtId(player->getPlayerPawn()->getCurrentLocation());
	int currentLocationId2 = currentLocation2.getId();
	if ((player->getRole()->getName().compare("Quarantine Specialist") == 0) ) {
		isAQuarantineSpecialist = true;
		if (currentLocation2.getBlue() > 0)
			availableActions.push_back(new QuarantineSpecialistAction(BLUE, boardMap, currentLocationId2));
		else if (currentLocation2.getBlack() > 0)
			availableActions.push_back(new QuarantineSpecialistAction(BLACK, boardMap, currentLocationId2));
		else if (currentLocation2.getRed() > 0)
			availableActions.push_back(new QuarantineSpecialistAction(RED, boardMap, currentLocationId2));
		else if (currentLocation2.getYellow() > 0)
			availableActions.push_back(new QuarantineSpecialistAction(YELLOW, boardMap, currentLocationId2));
		canPerformRoleAction = true;
	}

	//Contingency Planner Role Check 
	bool eventAlreadyOnRole = false;
	if ( (player->getRole()->getName().compare("Contingency Planner") == 0) && eventAlreadyOnRole == false ) {
		availableActions.push_back(new ContingencyPlannerAction(cardManager->getPlayerCardDiscard()));
		canPerformRoleAction = true;
		eventAlreadyOnRole = true;
		//Last card in the discard once used will be an event card if this action is executed and should thus be deleted
		//The card will be shown as being discarded twice but the second output indicates its being erased from the game
		
		if (getCardManager()->getPlayerCardDiscard() != NULL && getCardManager()->getPlayerCardDiscard()->size() > 0) {
			if (getCardManager()->getPlayerCardDiscard()->at(getCardManager()->getPlayerCardDiscard()->size() - 1)->getType() == "event") {
				cout << "The event card that was just picked up by way of the contingency planner action is to be deleted upon a second discarding." << endl;
				getCardManager()->getPlayerCardDiscard()->erase(getCardManager()->getPlayerCardDiscard()->begin() + getCardManager()->getPlayerCardDiscard()->size() - 1);
			}
		}
		
	}

	bool onARsearchStation = false;
	for (int i = 0; i < researchStations.size(); i++) {
		if (player->getPlayerPawn()->getCurrentLocation() == researchStations[i]) { // is the player on a research station
			onARsearchStation = true;
		}
	}

	//Operations Expert Role Actions check
	//If the player is on a city that has no research station and that player is an operations expert, 
	//the OperationsExpertBuildAction (the first of two actions that an operations expert can do) is added to available actions
	if (player->getRole()->getName().compare("Operations Expert") == 0) {
		canPerformRoleAction = true;
		if (!onARsearchStation) {
			availableActions.push_back(new OperationsExpertBuildAction(&researchStations));
			//to prevent a player from moving again in the same turn (this will be inconsistent as turn is not being controlled from the board)
			canPerformRoleAction = false;
		}
		// Check if player can perform a move action
		else if (onARsearchStation && canPerformRoleAction) {
			//randomly generate an id for the card that a player would want to move to 
			srand(time(NULL));
			int randomNum = rand() % cardManager->getPlayerCardDeck()->size();
			for (auto &card : *cardManager->getPlayerCardDeck()) {
				if (card->getId() == randomNum) {
					availableActions.push_back(new OperationsExpertMoveAction(card->getId(), cardManager->getPlayerCardDiscard(), cardManager->getPlayerCardDeck()));
					break;
				}
			}
		}
	}
	
	//Event Card Actions Check
	bool canPerformEventAction = false;
	int randomCity;
	string ownPawnOrOther, permissionFromOther;
	for (int i = 0; i < player->getPlayerCards().size(); i++) {
		//N.B. A player should not typically have more than one event card but in the case where he does, he will not be allowed to perform more than one event card action per turn
		if (player->getPlayerCards()[i]->getType() == "event") {
			//Resilient Population Event Card Action Check
			canPerformEventAction = true;
			if (player->getPlayerCards()[i]->getCardName() == "Resilient Population" && canPerformEventAction) {
				availableActions.push_back(new ResilientPopulationEventAction(cardManager->getInfectionCardDiscard(), cardManager->getPlayerCardDiscard()));
				canPerformEventAction = false;
				break;
			}
			//Government Grant Event Card Action Check
			else if (player->getPlayerCards()[i]->getCardName() == "Government Grant" && canPerformEventAction) {
				for (int i = 0; i < researchStations.size(); i++) {
					srand(time(NULL));
					randomCity = rand() % boardMap->getMapLocation().size() + 1;
					if (boardMap->getLocationAtId(randomCity).getId() != researchStations[i]) {
						cout << player->getRole()->getName() << " Building a Research Station at" << boardMap->getLocationAtId(randomCity).getCity() << endl;
						availableActions.push_back(new GovernmentGrantEventAction(&researchStations, cardManager->getPlayerCardDiscard(), randomCity));
						canPerformEventAction = false;
						break;
					}
				}
			}
			//Airlift Event Card Action Check
			else if (player->getPlayerCards()[i]->getCardName() == "Airlift" && canPerformEventAction) {
				//Get a random location for a pawn to be moved to
				srand(time(NULL));
				randomCity = rand() % boardMap->getMapLocation().size() + 1;	
				//Ask player if he wants to move his own pawn or another's (this will be prompted before the player can do any of this his actions to inquire about how the event card will be used)
				cout << "Since you have the event card Airlift, would you like to use it to move your own pawn (Y for your own/N for another pawn)? Bear in mind that any other input will not let use the card on this turn." << endl;
				cin >> ownPawnOrOther;
				if (ownPawnOrOther == "Y" || ownPawnOrOther == "y") {
					availableActions.push_back(new AirliftEventAction(randomCity, cardManager->getPlayerCardDiscard()));
					canPerformEventAction = false;
					break;
				}
				else if (ownPawnOrOther == "N" || ownPawnOrOther == "n") {
					//The first player who inputs Y will have their pawn moved.
					for (auto &otherPlayer : players) {
						if (otherPlayer != player) {
							//The idea here is that you get permission to move another player's pawn and if you get a yes, then you can move the pawn on this turn or a future turn
							//the same applies to your own pawn
							cout << "Can I move the pawn of the " << otherPlayer->getRole()->getName() << "?" << endl;
							cin >> permissionFromOther;
							if (permissionFromOther == "Y" || permissionFromOther == "y") {
								availableActions.push_back(new AirliftEventAction(otherPlayer->getPlayerPawn()->getCurrentLocation(), cardManager->getPlayerCardDiscard()));
								canPerformEventAction = false;
								break;
							}
							else if (permissionFromOther == "N" || permissionFromOther == "n") {
								cout << "Cannot move pawn as do not have permission from the " << otherPlayer->getRole()->getName() << "." << endl;
							}
						}
					}
					//If you get here, no other player gave their permission and you can only move your own pawn
					if (permissionFromOther == "N" || permissionFromOther == "n") {
						cout << "You will only be allowed to move your own pawn when you want." << endl;
						availableActions.push_back(new AirliftEventAction(randomCity, cardManager->getPlayerCardDiscard()));
						canPerformEventAction = false;
						break;
					}
				}
			}
			//Forecast Event Card Action Check
			else if (player->getPlayerCards()[i]->getCardName() == "Forecast" && canPerformEventAction) {
				availableActions.push_back(new ForecastEventAction(cardManager->getInfectionCardDeck(), cardManager->getPlayerCardDiscard()));
				canPerformEventAction = false;
				break;
			}
			//One Quiet Night Event Card Action Check
			else if (player->getPlayerCards()[i]->getCardName() == "One Quiet Night" && canPerformEventAction) {
				availableActions.push_back(new OneQuietNightEventAction(cardManager->getPlayerCardDiscard()));
				hasOneQuietNightEventCard = true;
				canPerformEventAction = false;
				break;
			}
		}
	}

	// check for shuttleflight action
	if (onARsearchStation) {
		for (int i = 0; i < researchStations.size(); i++) { // add every other research station player can move to.
			if (player->getPlayerPawn()->getCurrentLocation() != researchStations[i])
				availableActions.push_back(new ShuttleFlightAction(researchStations[i]));
		}
	}

	if (player->getPlayerCards().size() > 0) {
		for (auto &card : player->getPlayerCards()) {
			// check for build RS action and charterflight action
			if (card->getId() < MAX_ID_FOR_CITY_CARD) {
				if (player->getPlayerPawn()->getCurrentLocation() == card->getId()) {
					if (!onARsearchStation) // can't build a research station if there already is one
						availableActions.push_back(new BuildRSAction(&researchStations));
					availableActions.push_back(new CharterFlightAction());
				}
				// check for directflight action
				else
					availableActions.push_back(new DirectFlightAction(card->getId(), cardManager->getPlayerCardDiscard()));
			}
		}
	}
	
	// check for discover cure action
	if (onARsearchStation) { // is the player on a research station
		int blueAreaCardCounter = 0; // keep track of number of player's blue cards
		int blackAreaCardCounter = 0; // keep track of number of player's black cards
		int redAreaCardCounter = 0; // keep track of number of player's red cards
		int yellowAreaCardCounter = 0; // keep track of number of player's yellow cards

		string blueArea = "Blue";
		string blackArea = "Black";
		string redArea = "Red";
		string yellowArea = "Yellow";

		
		if (player->getPlayerCards().size() > 0) { // does the player have any cards
			// need at least 5 cards for Researcher OR 4 cards for Scientist
			if (player->getPlayerCards().size() >= MIN_NUM_CARDS_FOR_CURE || ((player->getRole()->getName().compare("Scientist") == 0) && player->getPlayerCards().size() >= MIN_NUM_CARDS_FOR_SCIENTIST)) {
				for (auto &card : player->getPlayerCards()) { // count the number of cards with the same area as the reasearch station's area
					if (card->getId() <= 48 && card->getId() > 0) {
						string cardArea = boardMap->getMapLocation().at(card->getId()).getArea();

						// count the number of each area card
						if (cardArea == blueArea) blueAreaCardCounter++;
						else if (cardArea == blackArea) blackAreaCardCounter++;
						else if (cardArea == redArea) redAreaCardCounter++;
						else if (cardArea == yellowArea) yellowAreaCardCounter++;
					}
				}

				// if the player has any number of area cards greater than or equal to 5, he can discover a cure for that area
				if ((player->getRole()->getName().compare("Scientist") == 0)) {
					if (blueAreaCardCounter >= MIN_NUM_CARDS_FOR_SCIENTIST)
						availableActions.push_back(new ScientistAction());
					if (blackAreaCardCounter >= MIN_NUM_CARDS_FOR_SCIENTIST)
						availableActions.push_back(new ScientistAction());
					if (redAreaCardCounter >= MIN_NUM_CARDS_FOR_SCIENTIST)
						availableActions.push_back(new ScientistAction());
					if (yellowAreaCardCounter >= MIN_NUM_CARDS_FOR_SCIENTIST)
						availableActions.push_back(new ScientistAction());
					
				}
				else {
						// if the player has any number of area cards greater than or equal to 5, he can discover a cure for that area
					if (blueAreaCardCounter >= MIN_NUM_CARDS_FOR_CURE && !blueCureFound)
						 availableActions.push_back(new DiscoverCureAction(blueArea, &blueCureFound, cardManager->getPlayerCardDiscard(), boardMap->getMapLocation()));
					if (blackAreaCardCounter >= MIN_NUM_CARDS_FOR_CURE && !blackCureFound)
						availableActions.push_back(new DiscoverCureAction(blackArea, &blackCureFound, cardManager->getPlayerCardDiscard(), boardMap->getMapLocation()));
					if (redAreaCardCounter >= MIN_NUM_CARDS_FOR_CURE && !redCureFound)
						availableActions.push_back(new DiscoverCureAction(redArea, &redCureFound, cardManager->getPlayerCardDiscard(), boardMap->getMapLocation()));
					if (yellowAreaCardCounter >= MIN_NUM_CARDS_FOR_CURE && !yellowCureFound)
						availableActions.push_back(new DiscoverCureAction(yellowArea, &yellowCureFound, cardManager->getPlayerCardDiscard(), boardMap->getMapLocation()));
					
				}
			}
		}
	}
	

	// check for drive action
	for (auto connection : boardMap->getLocationAtId(player->getPlayerPawn()->getCurrentLocation()).getConnections()) {
		availableActions.push_back(new DriveAction(connection));
	}

	

	// check for share action
	for (auto &otherPlayer : players) {
		if (otherPlayer != player) {
			if (otherPlayer->getPlayerPawn()->getCurrentLocation() == player->getPlayerPawn()->getCurrentLocation()) {
				for (int i = 0; i < otherPlayer->getPlayerCards().size(); i++) { // if other player has cards, player can take from him
					if (otherPlayer->getPlayerCards()[i]->getId() == otherPlayer->getPlayerPawn()->getCurrentLocation())
						availableActions.push_back(new ShareTakeAction(otherPlayer, i));
				}
					
				for (int i = 0; i < player->getPlayerCards().size(); i++) { // if player has cards, player can take from him
					if (player->getPlayerCards()[i]->getId() == player->getPlayerPawn()->getCurrentLocation())
						availableActions.push_back(new ShareGiveAction(otherPlayer, i));
				}
			}
		}
	}

	// check for treat action
	Location currentLocation = boardMap->getLocationAtId(player->getPlayerPawn()->getCurrentLocation());
	int currentLocationId = currentLocation.getId();

	if (currentLocation.getBlue() > 0)
		availableActions.push_back(new TreatAction(BLUE, boardMap, currentLocationId));
	if (currentLocation.getBlack() > 0)
		availableActions.push_back(new TreatAction(BLACK, boardMap, currentLocationId));
	if (currentLocation.getRed() > 0)
		availableActions.push_back(new TreatAction(RED, boardMap, currentLocationId));
	if (currentLocation.getYellow() > 0)
		availableActions.push_back(new TreatAction(YELLOW, boardMap, currentLocationId));

	return availableActions;
};
