/*
 * TrajBulletModel.cpp
 *
 *  Created on: Nov 12, 2011
 *      Author: wassj
 */

#include "TrajBulletModel.h"

TrajBulletModel::TrajBulletModel(QObject* parent)
		: QAbstractItemModel(parent)
{

}

TrajBulletModel::~TrajBulletModel()
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

int TrajBulletModel::columnCount(const QModelIndex& parent) const
{

}

QVariant TrajBulletModel::data(const QModelIndex& index, int role) const
{

}

QModelIndex TrajBulletModel::index(int row, int column, const QModelIndex& parent) const
{

}

QModelIndex TrajBulletModel::parent(const QModelIndex& index) const
{

}

int TrajBulletModel::rowCount(const QModelIndex& parent) const
{

}
