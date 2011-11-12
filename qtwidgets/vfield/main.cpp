/*
 * main.cpp
 *
 *  Created on: Nov 11, 2011
 *      Author: wassj
 */

#include <QtGui>
#include <QApplication>
#include "ValidateTextField.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	ValidateTextField v;
	v.show();

	return app.exec();
}
