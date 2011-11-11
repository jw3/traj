#include "TrajTableModel.h"

#include <iostream>

TrajTableModel::TrajTableModel(QWidget* parent)
		: QAbstractTableModel(parent)
{
}

TrajTableModel::TrajTableModel(const traj::TrajectoryData& rangeData, QWidget* parent)
		: QAbstractTableModel(parent), rangeData(rangeData)
{
}

TrajTableModel::~TrajTableModel()
{
}

int TrajTableModel::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return rangeData.size();
}

int TrajTableModel::columnCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return 7;
}

QVariant TrajTableModel::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole /*&& index.isValid() && rangeData.size() > index.row()*/) {
		const std::shared_ptr<traj::TrajRangeData> data = rangeData.at(index.row());
		switch (index.column())
		{
			case 0:
				return data->getRange();
			case 1:
				return data->getVelocity();
			case 2:
				return data->getEnergy();
			case 3:
				return data->getMomentum();
			case 4:
				return data->getDrop();
			case 5:
				return data->getWind();
			case 6:
				return data->getLead();
		}
	}
	return QVariant();
}

QVariant TrajTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			switch (section)
			{
				case 0:
					return QString(tr("range"));
				case 1:
					return QString(tr("velocity"));
				case 2:
					return QString(tr("energy"));
				case 3:
					return QString(tr("momentum"));
				case 4:
					return QString(tr("drop"));
				case 5:
					return QString(tr("wind"));
				case 6:
					return QString(tr("lead"));
			}
		}
	}
	return QVariant();
}

Qt::ItemFlags TrajTableModel::flags(const QModelIndex& index) const
{
	if (index.row() < rangeData.size() && index.column() < columnCount(QModelIndex())) {
		return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
	}
	else {
		return 0;
	}
}
