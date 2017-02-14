#include "Player.h";
#include "RoleCard.h"
#include <string>
#include <iostream>

Player::Player() {
	referenceCard = new ReferenceCard();

	cout << "Player created." << endl;
}

Player::~Player() {
	delete referenceCard;
	delete roleCard;
	referenceCard = NULL;
	roleCard = NULL;
}


RoleCard* Player::getRole() {
	return roleCard;
}

void Player::setRole(RoleCard* newRoleCard) {
	roleCard = newRoleCard;
}

Pawn* Player::getPawn() {
	return pawn;
}

void Player::setPawn(Pawn* newPawn) {
	pawn = newPawn;
}

vector<PlayerCard*> Player::getPlayerCards() {
	return playerCards;
}

void Player::addPlayerCard(PlayerCard* playerCard) {
	playerCards.push_back(playerCard);
}