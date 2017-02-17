#include "Player.h"

//Player Player::generatePlayer()
//{
//	Player p = Player();
//	return p;
//}

Role* Player::getRole()
{
	return role;
}

//The player will move the Pawn 
Location Player::movePawn()
{
	return playerPawn->getCurrentLocation();//Returns the current location for now
}

//Constructor for the player. 
Player::Player(Role* role, Pawn* playerPawn) {
	this->role = role;
	this->playerPawn = playerPawn;
}

Player::Player() {

}

vector<PlayerCard*> Player::getPlayerCards() {
	return playerCards;
}

void Player::setPlayerCards(vector<PlayerCard*> playerCards) {
	this->playerCards = playerCards;
}

Pawn* Player::getPlayerPawn() {
	return playerPawn;
}