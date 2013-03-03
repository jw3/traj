#include <QtGui>
#include <QApplication>

#include <iostream>
#include <string>
#include <map>

#include <trajdb/TrajDatabase.h>

#include <trajdb/MfgData.h>
#include <trajdb/BulletData.h>
#include <trajdb/CaliberData.h>

#include "TrajFrame.h"
#include "TrajBulletTreeModel.h"

using namespace std;
using namespace traj;

int main(int c, char** v)
{
	QApplication app(c, v);

	app.setApplicationName("Traj");

	TrajDatabase db;
	if (!db.connect()) {
		cout << "Error connecting to db, " << db.getError() << endl;
		return 1;
	}

	TrajBulletTreeModel bulletModel;
	bulletModel.init(db);

	TrajFrame f(&bulletModel);
	f.show();

	int exex = app.exec();
	return exex;
}
