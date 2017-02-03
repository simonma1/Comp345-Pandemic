#include "Player.h";
#include <string>

Player::Player() {}

void Player::setRole(RoleCard role) {
	roleCard.setColor(role.getColor());
	roleCard.setRoleName(role.getRoleName());
}

RoleCard Player::getRole() {
	return roleCard;
}


