#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QtGui/QWidget>
#include <QAbstractTableModel>

#include <vector>
#include <traj/TrajRangeData.h>

class TableModel :
		public QAbstractTableModel
{
	Q_OBJECT

	public:
		TableModel(QWidget *parent = 0);
		TableModel(std::vector<traj::TrajRangeData*> rangeData, QWidget* parent);
		~TableModel();

		int rowCount(const QModelIndex &parent) const;
		int columnCount(const QModelIndex &parent) const;

		QVariant data(const QModelIndex &index, int role) const;
		QVariant headerData(int section, Qt::Orientation orientation, int role) const;

		Qt::ItemFlags flags(const QModelIndex& index) const;

	private:
		std::vector<traj::TrajRangeData*> rangeData;
};

#endif // TABLEMODEL_H
