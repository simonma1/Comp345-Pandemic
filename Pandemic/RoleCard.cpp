#include "RoleCard.h"


RoleCard::RoleCard() {
	cout << "RoleCard created" << endl;
}

string RoleCard::getRoleName() {
	return roleName;
}

void RoleCard::setRoleName(string newRoleName) {
	roleName = newRoleName;
}

string RoleCard::getColor() {
	return color;
}

void RoleCard::setColor(string newColor) {
	color = newColor;
}