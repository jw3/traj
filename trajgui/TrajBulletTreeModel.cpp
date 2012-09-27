/*
 * TrajBulletModel.cpp
 *
 *  Created on: Nov 12, 2011
 *      Author: wassj
 */

#include "TrajBulletTreeModel.h"

#include <map>
#include <string>

#include <trajdb/MfgData.h>
#include <trajdb/BulletData.h>
#include <trajdb/CaliberData.h>

#include "ITreeNode.h"

TrajBulletTreeModel::TrajBulletTreeModel(QObject* parent)
		: QAbstractItemModel(parent)
{
}

TrajBulletTreeModel::~TrajBulletTreeModel()
{
}

int TrajBulletTreeModel::columnCount(const QModelIndex& parent) const
{
	return 1;
}

QVariant TrajBulletTreeModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid()) {
		return QVariant();
	}

	if (role != Qt::DisplayRole) {
		return QVariant();
	}

	IVariantNode* node = static_cast<IVariantNode*>(index.internalPointer());
	return node->getVariantData();
}

QModelIndex TrajBulletTreeModel::index(int row, int column, const QModelIndex& parent) const
{

}

QModelIndex TrajBulletTreeModel::parent(const QModelIndex& index) const
{

}

int TrajBulletTreeModel::rowCount(const QModelIndex& parent) const
{
	if (parent.column()) {
		return 0;
	}

	TreeItem *parentItem;
	if (!parent.isValid())
		parentItem = rootItem;
	else
		parentItem = static_cast<TreeItem*>(parent.internalPointer());

	return parentItem->childCount();
}

bool TrajBulletTreeModel::init(traj::TrajDatabase& db)
{
	auto calibers = db.list<traj::CaliberData>();
	root = new RootNode("root");
	for (auto calPair : calibers) {
		auto cal = calPair.second;
		CaliberNode* caliberNode = new CaliberNode(cal->getCaliber());
		root->addChild(caliberNode);

		std::stringstream where;
		where << "caliber=";
		where << cal->getId();
		auto bullets = db.getBullets(where.str().c_str());
		for (auto bulletPair : bullets) {
			auto bullet = bulletPair.second;
			BulletNode* bulletNode = new BulletNode(bullet.getName());
			caliberNode->addChild(bulletNode);
		}
	}

	return true;
}
