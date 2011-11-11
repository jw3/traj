#ifndef TRAJTABLEVIEW_H_
#define TRAJTABLEVIEW_H_

#include <QTableView>

#include <vector>
#include <memory>

#include <traj/Trajectory.h>

class TrajTableView : public QTableView
{
	Q_OBJECT

	public:
		TrajTableView(QWidget* parent = 0);
		virtual ~TrajTableView();

	public slots:
		void trajectoryChanged(const traj::TrajectoryData&);
};

#endif /* TRAJTABLEVIEW_H_ */
