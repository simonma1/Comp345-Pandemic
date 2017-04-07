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
	value += "\tThe Infection Level is at: " + to_string(infectionRateMarker) + "\n\n";
	

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
	Map* map = new Map();

	cardManager = new CardManager;
	this->listOfRoles = loadCommon.gameSetup(map, cardManager);
	*boardMap = *map;
	map = NULL;

}

void Board::drawPlayerCards() {
	for (int i = 0; i < 2; i++) {
		players[turn]->addPlayerCard(cardManager->drawPlayerCard());
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

Location Board::drawInfectionCard()
{
	Location locationToInfect = cardManager->drawInfectionCard();
	boardMap->infectCity(locationToInfect);
		
	return locationToInfect;
}

void Board::endOfTurnInfection() {
	/*
	//A player who has the event card one quiet night will automatically not start an infection (which is always desirable in this game) after his current turn
	//Still to implement (consider using getAvailableActions method)
	for (int i = 0; i < getPlayerAvailableActions(players.at(getTurn())).size(); i++) {
		if (getPlayerAvailableActions(players.at(getTurn())).at(i)->toString() == "Skip the next Infect Cities step (Do not flip over any Infection Cards)") {
			hasOneQuietNightEventCard = true;
			break;
		}
	}
	*/
	//Otherwise, proceed as normal
	if (hasOneQuietNightEventCard == false) {
		cout << "\nThe Infection Level is at: " << infectionRateMarker << ". Therefore " << infectionRateMarker << " Infection Cards will be drawn\n" << endl;
		for (int i = 0; i < infectionRateMarker; i++) {
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

bool Board::isGameLost() {
	return cardManager->getPlayerCardDeck().size() < 1 || outbreakMarker == 8;
}

bool Board::isGameWon()
{
	return (yellowCureFound && blackCureFound && redCureFound && blueCureFound);
}

vector<Action*> Board::getPlayerAvailableActions(Player *player) {
	vector<Action*> availableActions;
	
	//Checks if player can perform a specific role action
	bool canPerformRoleAction = false;

	if ( (player->getRole()->getName().compare("Scientist" ) == 0) ) {
		availableActions.push_back(new ScientistAction());
		canPerformRoleAction = true;
	}
	if ((player->getRole()->getName().compare("Medic") == 0) ) {
		availableActions.push_back(new MedicAction());
		canPerformRoleAction = true;
	}
	if ((player->getRole()->getName().compare("Researcher") == 0) ) {
		availableActions.push_back(new ResearcherAction());
		canPerformRoleAction = true;
	}

	if ((player->getRole()->getName().compare("Dispatcher") == 0)) {
		availableActions.push_back(new DispatcherAction());
		canPerformRoleAction = true;
	}

	//Quarantine Specialist Role Check (simulation)
	Location currentLocation2 = boardMap->getLocationAtId(player->getPlayerPawn()->getCurrentLocation());
	int currentLocationId2 = currentLocation2.getId();
	if ((player->getRole()->getName().compare("Quarantine Specialist") == 0) ) {
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
			int randomNum = rand() % cardManager->getPlayerCardDeck().size();
			for (auto &card : cardManager->getPlayerCardDeck()) {
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
				cout << "Since you have the event card Airlift, would you like to use it to move your own pawn? (Y for your own/N for another pawn/Any other input will not let use the card on this turn)" << endl;
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
							cout << "Can I move your pawn?" << endl;
							cin >> permissionFromOther;
							if (permissionFromOther == "Y" || permissionFromOther == "y") {
								availableActions.push_back(new AirliftEventAction(otherPlayer->getPlayerPawn()->getCurrentLocation(), cardManager->getPlayerCardDiscard()));
								canPerformEventAction = false;
								break;
							}
							else if (permissionFromOther == "N" || permissionFromOther == "n") {
								cout << "Cannot move pawn as do not have permission from owner of pawn." << endl;
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
				availableActions.push_back(new ForecastEventAction(cardManager->getInfectionCardDiscard(), cardManager->getPlayerCardDiscard()));
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
			if (player->getPlayerCards().size() >= MIN_NUM_CARDS_FOR_CURE) { // need at least 5 cards
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
