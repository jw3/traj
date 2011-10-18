#include "trajectoryui.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TrajectoryUI w;
	w.show();
	return a.exec();
}
