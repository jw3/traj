#include "trajectoryui.h"

#include <traj/Trajectory.h>
#include <iostream>

#include <QtCore/QString>

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
    trajectory.calculate();

    QString qstr(trajectory.print().c_str());

    std::cout << qstr.toStdString() << std::endl;

    ui.resultsTextEdit->setText(qstr);
}
