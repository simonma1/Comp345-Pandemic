#pragma once
#include <iostream>
#include <string>

using namespace std;

class RoleCard {
public:
	string getRoleName();
	void setRoleName(string newRoleName);
	string getColor();
	void setColor(string color);

private:
	string roleName;
	string color;
};