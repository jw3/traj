/*
 * TrajBulletModel.cpp
 *
 *  Created on: Nov 12, 2011
 *      Author: wassj
 */

#include "TrajBulletModel.h"

TrajBulletTreeModel::TrajBulletTreeModel(QObject* parent)
		: QAbstractItemModel(parent)
{

}

TrajBulletTreeModel::~TrajBulletTreeModel()
{
	calibers.insert(std::make_pair(.308, "168 gr HPBT"));
	calibers.insert(std::make_pair(.308, "175 gr HPBT"));
	calibers.insert(std::make_pair(.308, "150 gr HPBT"));
	calibers.insert(std::make_pair(.308, "168 gr SP"));
	calibers.insert(std::make_pair(.308, "180 gr SP"));

	calibers.insert(std::make_pair(.224, "55 gr HPBT"));
	calibers.insert(std::make_pair(.224, "55 gr SP"));
	calibers.insert(std::make_pair(.224, "55 gr VMax"));
}

int TrajBulletTreeModel::columnCount(const QModelIndex& parent) const
{

}

QVariant TrajBulletTreeModel::data(const QModelIndex& index, int role) const
{

}

QModelIndex TrajBulletTreeModel::index(int row, int column, const QModelIndex& parent) const
{

}

QModelIndex TrajBulletTreeModel::parent(const QModelIndex& index) const
{

}

int TrajBulletTreeModel::rowCount(const QModelIndex& parent) const
{

}
