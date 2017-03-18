#include "MapObserverViewer.h"
#include <iostream>

void MapObserverViewer::update(Observable * o) {
	cout << "=============================" << endl;
	cout << "THE MAP WAS UPDATED" << endl;
	cout << "=============================" << endl;
	cout << static_cast<Map*>(o)->toString() << endl;
}
