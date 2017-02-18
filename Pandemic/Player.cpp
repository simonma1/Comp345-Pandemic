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

void Player::setReferenceCard(ReferenceCard * ref)
{
	this->referenceCard = ref;
}

void Player::setRole(string role)
{
	this->role = role;
}

Player::Player()
{
}

//Constructor for the player. 
Player::Player(string role, ReferenceCard* reference) {
	playerPawn = new Pawn();//The pawn should be created in the Board and passed to the player to prevent duplicate
	this->role = role;
	this->referenceCard = reference;
}

string Player::toString(){
	string playerInfo = "Here is the info of the player:\n" "Pawn:"+ playerPawn->getColor() + "\n" 
		+ "Role: " + role + "\n" + "Reference Card: " + referenceCard->getName();

	return playerInfo;
}

Player::~Player() {
	delete playerPawn;
	delete referenceCard;
}

