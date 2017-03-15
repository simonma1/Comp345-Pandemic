#include "Player.h"

//The player will move the Pawn 
void Player::movePawn(int destinationId)
{
	playerPawn->setLocation(destinationId);//Returns the current location for now
}


//Constructor for the player. 
Player::Player(Role* role, Pawn* playerPawn) {
	this->role = role;
	this->playerPawn = playerPawn;
	this->referenceCard = new ReferenceCard;
}

Player::Player() {
	this->referenceCard = new ReferenceCard;
}

Player::~Player() {
	delete playerPawn;
	playerPawn = NULL;
	delete role;
	role = NULL;
	delete referenceCard;
	referenceCard = NULL;
}

vector<PlayerCard*> Player::getPlayerCards() {
	return playerCards;
}

void Player::setPlayerCards(vector<PlayerCard*> playerCards) {
	this->playerCards = playerCards;
}

void Player::removePlayerCard(int cardId) {
	int numPlayerCards = playerCards.size();
	if (numPlayerCards > 0) {
		for (int i = 0; i < numPlayerCards; i++) {
			if (playerCards[i]->getId() == cardId) {
				playerCards.erase(playerCards.begin() + i);
			}
		}
	}
}

void Player::setReferenceCard(ReferenceCard * ref)
{
	this->referenceCard = ref;
}

void Player::setRole(Role* role)
{
	this->role = role;
}

string Player::toString(){
	string playerInfo = "Here is the info of the player:\n" "Pawn:"+ playerPawn->getColor() + "\n" 
		+ "Role: " + role->getName() + "\n"
		+ "Location: " + to_string(playerPawn->getCurrentLocation());

	return playerInfo;
}

Pawn* Player::getPlayerPawn() {
	return playerPawn;
}

//The player can call this method at any time to display the content of the reference card
void Player::lookAtReferenceCard() {
	referenceCard -> displayPossibleActions();
}

void Player::addPlayerCard(PlayerCard * card)
{
	playerCards.push_back(card);
}
