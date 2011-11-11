#ifndef TRAJFRAME_H_
#define TRAJFRAME_H_

#include <QMainWindow>
#include <ui_TrajFrame.h>

#include <iostream>
#include <memory>
#include <vector>

#include <trajdb/TrajDatabase.h>
#include <traj/Trajectory.h>

class TrajFrame: public QMainWindow
{
    Q_OBJECT

	public:
		TrajFrame(QWidget* parent = 0);
		virtual ~TrajFrame();

	public slots:
		void calculateTrajectory();

	signals:
		void trajectoryUpdated(const traj::TrajectoryData&);


	private:
		Ui::TrajFrame ui;
		std::shared_ptr<traj::TrajDatabase> db;
};

#endif /* TRAJFRAME_H_ */