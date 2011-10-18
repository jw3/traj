#ifndef TRAJECTORYUI_H
#define TRAJECTORYUI_H

#include <QtGui/QDialog>
#include "ui_trajectoryui.h"

#include "tablemodel.h"

class TrajectoryUI : public QDialog
{
    Q_OBJECT

public:
    TrajectoryUI(QWidget *parent = 0);
    ~TrajectoryUI();

private slots:
    void on_calculateButton_clicked();

private:
    Ui::TrajectoryUIClass ui;
};

#endif // TRAJECTORYUI_H
