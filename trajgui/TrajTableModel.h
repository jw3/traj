#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QtGui/QWidget>
#include <QAbstractTableModel>

#include <vector>
#include <traj/Trajectory.h>

class TrajTableModel :
		public QAbstractTableModel
{
	Q_OBJECT

	public:
		TrajTableModel(QWidget* parent = 0);
		TrajTableModel(const traj::TrajectoryData& rangeData, QWidget* parent = 0);
		~TrajTableModel();

		int rowCount(const QModelIndex &parent) const;
		int columnCount(const QModelIndex &parent) const;

		QVariant data(const QModelIndex &index, int role) const;
		QVariant headerData(int section, Qt::Orientation orientation, int role) const;

		Qt::ItemFlags flags(const QModelIndex& index) const;

	private:
		traj::TrajectoryData rangeData;
};

#endif // TABLEMODEL_H
