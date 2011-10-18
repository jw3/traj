#include "tablemodel.h"

#include <iostream>

TableModel::TableModel(QWidget* parent)
    : QAbstractTableModel(parent)
{
}

TableModel::TableModel(std::vector<traj::TrajRangeData*> rangeData, QWidget* parent)
	: QAbstractTableModel(parent), rangeData(rangeData)
{
}

TableModel::~TableModel()
{
	for(uint i=0; i<rangeData.size(); ++i)
	{
		delete rangeData[i];
	}
}

int TableModel::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return rangeData.size();
}

int TableModel::columnCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return 7;
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole /*&& index.isValid() && rangeData.size() > index.row()*/)
	{
		traj::TrajRangeData* data = rangeData.at(index.row());
		switch(index.column())
		{
			case 0: return data->getRange();
			case 1: return data->getVelocity();
			case 2: return data->getEnergy();
			case 3: return data->getMomentum();
			case 4: return data->getDrop();
			case 5: return data->getWind();
			case 6: return data->getLead();
		}
	}
	return QVariant();
}



QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role == Qt::DisplayRole){
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
				case 0: return QString(tr("range"));
				case 1: return QString(tr("velocity"));
				case 2: return QString(tr("energy"));
				case 3: return QString(tr("momentum"));
				case 4: return QString(tr("drop"));
				case 5: return QString(tr("wind"));
				case 6: return QString(tr("lead"));
			}
		}
	}
	return QVariant();
}


Qt::ItemFlags TableModel::flags (const QModelIndex& index) const
   {
	   if (index.row() < rangeData.size() && index.column() < columnCount(QModelIndex()))
	   {
		 return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
	   }
	   else
	   {
		 return 0;
	   }
   }
