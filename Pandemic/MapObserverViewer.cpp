#include "MapObserverViewer.h"
#include <stdio.h>

void MapObserverViewer::update(Observable * o) {
	cout << "=============================" << endl;
	cout << "THE MAP WAS UPDATED" << endl;
	cout << "=============================" << endl;
	cout << static_cast<Map*>(o)->toString() << endl;
}
