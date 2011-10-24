#ifndef TRAJECTORYUI_H
#define TRAJECTORYUI_H

#include <QtGui/QDialog>
#include "ui_trajectoryui.h"

#include "tablemodel.h"

namespace traj
{
class TrajDatabase;
}

class TrajectoryUI :
		public QDialog
{
	Q_OBJECT

	public:
		TrajectoryUI(QWidget *parent = 0);
		~TrajectoryUI();

	private slots:
		void on_calculateButton_clicked();

	private:
		Ui::TrajectoryUIClass ui;
		traj::TrajDatabase* db;
};

#endif // TRAJECTORYUI_H
