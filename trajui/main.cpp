#include "trajectoryui.h"

#include <QtGui>
#include <QApplication>

#include <map>
#include <trajdb/TrajDatabase.h>

using namespace std;
using namespace traj;

int main(int argc, char *argv[])
{
	TrajDatabase db;
	map<int, BulletData> bullets = db.getBullets("caliber = .308");
	map<int, BulletData>::iterator bulletIter;
	for (bulletIter = bullets.begin(); bulletIter != bullets.end(); bulletIter++) {

	}

	QApplication a(argc, argv);
	TrajectoryUI w;
	w.show();
	return a.exec();
}
