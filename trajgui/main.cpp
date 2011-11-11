#include <QtGui>
#include <QApplication>

#include <iostream>
#include <map>
#include <trajdb/TrajDatabase.h>
#include "TrajFrame.h"

using namespace std;
using namespace traj;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	app.setApplicationName("Traj");

	TrajDatabase db;
	if (!db.connect()) {
		cout << "Error connecting to db, " << db.getError() << endl;
		return 1;
	}

	//	auto bullets = db.getBullets("caliber=.308");
	//	for (auto bullet : bullets) {
	//		cout << bullet.first << ": " << bullet.second.getName() << endl;
	//	}

	TrajFrame f;
	f.show();

	return app.exec();
}
