#include "BuildRSAction.h"

using namespace std;

void BuildRSAction::act(Player *player) {
	cout << player->getRole()->getName() << " Building a Research Station" << endl;
}
