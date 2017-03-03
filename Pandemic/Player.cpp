#include "Player.h"

//The player will move the Pawn 
Location Player::movePawn()
{
	return playerPawn->getCurrentLocation();//Returns the current location for now
}

Pawn Player::setPawn(string color)
{
	this->playerPawn = new Pawn(color);
	return *playerPawn;
}


//Constructor for the player. 
Player::Player(Role* role, Pawn* playerPawn) {
	this->role = role;
	this->playerPawn = playerPawn;
	//this->referenceCard = referenceCard;
}

Player::Player() {

}

Player::~Player() {
	delete playerPawn;
	playerPawn = NULL;
	delete role;
	role = NULL;
	delete referenceCard;
	referenceCard = NULL;
	for (auto card : this->getPlayerCards()) {
		delete card;
	}
	this->getPlayerCards().clear();
}

vector<PlayerCard*> Player::getPlayerCards() {
	return playerCards;
}

void Player::setPlayerCards(vector<PlayerCard*> playerCards) {
	this->playerCards = playerCards;
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
		+ "Role: " + role->getName();

	return playerInfo;
}

Pawn* Player::getPlayerPawn() {
	return playerPawn;
}