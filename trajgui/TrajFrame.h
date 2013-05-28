/*
 * TrajFrame.h
 *
 *  Created on: Nov 11, 2011
 *      Author: wassj
 */

#ifndef TRAJFRAME_H_
#define TRAJFRAME_H_

#include <QMainWindow>

#include <memory>
#include <vector>

#include <trajdb/TrajDatabase.h>
#include <traj/Trajectory.h>
#include "TrajBulletTreeModel.h"

namespace Ui
{
class TrajFrame;
}

class TrajFrame :
		public QMainWindow
{
	Q_OBJECT

	public:
		TrajFrame(TrajBulletTreeModel* bulletModel, QWidget* parent = 0);
		virtual ~TrajFrame();

	public slots:
		void calculateTrajectory();
		void setBulletModelIndex(QModelIndex);

	signals:
		void trajectoryUpdated(const traj::TrajectoryData&);

	private:
		std::unique_ptr<Ui::TrajFrame> ui;
		TrajBulletTreeModel* bulletModel;
};

#endif /* TRAJFRAME_H_ */
