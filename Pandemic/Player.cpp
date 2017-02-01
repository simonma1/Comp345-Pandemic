#include "Player.h"


Player Player::generatePlayer()
{
	Player p = Player();
	return p;
}

Role Player::getRole()
{
	return role;
}

//The player will move the Pawn 
Location Player::movePawn()
{
	return playerPawn.getCurrentLocation();//Returns the current location for now
}

//Constructor for the player. 
Player::Player() {


}

