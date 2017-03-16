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
	cardManager->moveCardToDeck();
}

Location Board::drawInfectionCard()
{
	Location locationToInfect = cardManager->drawInfectionCard();
	boardMap->infectCity(locationToInfect);

	return locationToInfect;
}

void Board::endOfTurnInfection() {
	cout << "\nThe Infection Level is at: " << infectionRateMarker << ". Therefore " << infectionRateMarker << " Infection Cards will be drawn\n" << endl;

	for (int i = 0; i < infectionRateMarker; i++) {
		drawInfectionCard();
	}
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
	
	// Check if player is on research station
	bool onARsearchStation = false;
	for (int i = 0; i < researchStations.size(); i++) {
		if (player->getPlayerPawn()->getCurrentLocation() == researchStations[i]) { // is the player on a research station
			onARsearchStation = true;
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
			if (player->getPlayerPawn()->getCurrentLocation() == card->getId()) {
				if (!onARsearchStation) // can't build a research station if there already is one
					availableActions.push_back(new BuildRSAction(&researchStations));
				availableActions.push_back(new CharterFlightAction());
			}
			// check for directflight action
			else
				availableActions.push_back(new DirectFlightAction(card->getId()));
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
					availableActions.push_back(new DiscoverCureAction(blueArea, &blueCureFound));
				if (blackAreaCardCounter >= MIN_NUM_CARDS_FOR_CURE && !blackCureFound)
					availableActions.push_back(new DiscoverCureAction(blackArea, &blackCureFound));
				if (redAreaCardCounter >= MIN_NUM_CARDS_FOR_CURE && !redCureFound)
					availableActions.push_back(new DiscoverCureAction(redArea, &redCureFound));
				if (yellowAreaCardCounter >= MIN_NUM_CARDS_FOR_CURE && !yellowCureFound)
					availableActions.push_back(new DiscoverCureAction(yellowArea, &yellowCureFound));
			}
		}
	}
	

	// check for drive action
	for (auto connection : boardMap->getLocationAtId(player->getPlayerPawn()->getCurrentLocation()).getConnections()) {
		availableActions.push_back(new DriveAction(connection));
	}

	// check for role action
	
	// if (player->canPerformRoleAction()) {
	//	   availableActions.push_back(player->getRoleAction());
	// }

	// check for share action
	for (auto &otherPlayer : players) {
		if (otherPlayer != player) {
			if (otherPlayer->getPlayerPawn()->getCurrentLocation() == player->getPlayerPawn()->getCurrentLocation()) {
				if (otherPlayer->getPlayerCards().size() > 0) // if other player has cards, player can take from him
					availableActions.push_back(new ShareTakeAction(otherPlayer));
				if (player->getPlayerCards().size() > 0) // if player has cards, he can give to other player
					availableActions.push_back(new ShareGiveAction(otherPlayer));
			}
		}
	}

	// check for treat action
	Location currentLocation = boardMap->getLocationAtId(player->getPlayerPawn()->getCurrentLocation());
	if (currentLocation.getBlue() > 0)
		availableActions.push_back(new TreatAction(BLUE));
	if (currentLocation.getBlack() > 0)
		availableActions.push_back(new TreatAction(BLACK));
	if (currentLocation.getRed() > 0)
		availableActions.push_back(new TreatAction(RED));
	if (currentLocation.getYellow() > 0)
		availableActions.push_back(new TreatAction(YELLOW));

	return availableActions;
};
