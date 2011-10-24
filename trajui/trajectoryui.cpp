#include "trajectoryui.h"

#include <traj/Trajectory.h>
#include <traj/TrajRangeData.h>
#include <trajdb/TrajDatabase.h>
#include <trajdb/BulletData.h>

#include <iostream>
#include <vector>
#include <map>

#include <QtCore/QString>
#include <QItemSelection>

using namespace std;
using namespace traj;

TrajectoryUI::TrajectoryUI(QWidget *parent)
		: QDialog(parent)
{
	ui.setupUi(this);
}

TrajectoryUI::~TrajectoryUI()
{
}

void TrajectoryUI::on_calculateButton_clicked()
{
	traj::Trajectory trajectory;
	std::vector<traj::TrajRangeData*> data;
	trajectory.calculate(&data);

	///////////////////////////////////////////////
	//
	QString qstr(trajectory.print().c_str());
	std::cout << qstr.toStdString() << std::endl;
	//ui.resultsTextEdit->setText(qstr);
	//
	///////////////////////////////////////////////

	TableModel* tableModel = new TableModel(data, this);
	ui.tableView->setModel(tableModel);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->horizontalHeader()->setStretchLastSection(true);
	ui.tableView->verticalHeader()->setVisible(false);
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);

	ui.tableView->show();
}
