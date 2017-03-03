#include "Cards.h"



//Default constructor that will automatically put in the 8 actions that a player's double-sided reference card is to indicate.
ReferenceCard::ReferenceCard() {
	//Places 8 elements into the vector that correspond to the action available to the player
	actions.reserve(8);
	actions.push_back("DRIVE/FERRY\n Move to a city connected by a white line.");
	actions.push_back("DIRECT FLIGHT\n Discard a City card to move to the city named on the card.");
	actions.push_back("CHARTER FLIGHT\n Discard the City card that matches the city you are in to move to any city.");
	actions.push_back("SHUTTLE FLIGHT\n Move from a city with a research station o any other city that has a research station.");
	actions.push_back("BUILD A RESEARCH STATION\n Discard the Cit card that matches the city you are in to place a research station there.");
	actions.push_back("TREAT DISEASE\n Remove 1 disease cube from the city you are in. If this color is cured, remove all cubes of that color from the city.");
	actions.push_back("SHARE KNOWLEDGE\n Either give the card that maches the ciy you are in to another player, or take that card from another player. The other player must also be in the city with you.");
	actions.push_back("DISCOVER A CURE\n At any research station, discard 5 city cards of the same disease color to cure that disease.");

	//Print statement to indicate that a reference card was created and handed out to a player. 
	cout << "-------------------------------------------------------------------------------" "\n" << endl;
	cout << "REFERENCE CARD WAS CREATED AND HANDED OUT TO PLAYER.\n" << endl;
	cout << "-------------------------------------------------------------------------------" "\n" << endl;
};

//Displays all the possible actions to the player.
void ReferenceCard::displayPossibleActions() {
	cout << "THE FOLLOWING IS A DESCRIPTION OF ALL THE BASIC ACTIONS THAT YOU CAN DO.\n" << endl;
	//Using the iterator to traverse the vector and display all the actions strings. 
	for (vector<string>::const_iterator i = actions.begin(); i != actions.end(); ++i)
		cout << *i + "\n" << endl;
};


std::string PlayerCard::getCardName() {
	return cardName;
}



Role::Role(std::string name) {
	this->name = name;
}

PlayerCard::PlayerCard(std::string cardName) {
	this->cardName = cardName;
}