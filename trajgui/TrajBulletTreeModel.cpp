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

#include <QAccessible>

#include "TreeNodes.h"

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

	IVariantNode* node = dynamic_cast<IVariantNode*>(static_cast<ITreeNode*>(index.internalPointer()));
	if (node) {
		return node->getVariantData();
	}
	return QVariant();
}

QModelIndex TrajBulletTreeModel::index(int row, int column, const QModelIndex& parent) const
{
	if (!hasIndex(row, column, parent)) {
		return QModelIndex();
	}

	ITreeNode *parentItem;
	if (!parent.isValid()) {
		parentItem = root;
	}
	else {
		parentItem = static_cast<ITreeNode*>(parent.internalPointer());
	}

	ITreeNode *child = parentItem->child(row);
	if (child) {
		return createIndex(row, column, child);
	}
	return QModelIndex();
}

QModelIndex TrajBulletTreeModel::parent(const QModelIndex& index) const
{
	if (!index.isValid())
		return QModelIndex();

	ITreeNode *childItem = static_cast<ITreeNode*>(index.internalPointer());
	ITreeNode *parentItem = childItem->getParent();

	if (parentItem == root) {
		return QModelIndex();
	}
	return createIndex(parentItem->row(), 0, parentItem);
}

int TrajBulletTreeModel::rowCount(const QModelIndex& parent) const
{
	ITreeNode *parentItem;
	if (!parent.isValid()) {
		parentItem = static_cast<ITreeNode*>(root);
	}
	else {
		parentItem = static_cast<ITreeNode*>(parent.internalPointer());
	}
	return parentItem->childCount();
}

bool TrajBulletTreeModel::init(traj::TrajDatabase& db)
{
	root = new RootNode("root");

	auto mfgs = db.getMfgs();
	auto calibers = db.getCalibers();

	for (auto calPair : calibers) {
		auto caliber = calPair.second;
		CaliberNode* caliberNode = new CaliberNode(caliber);
		root->addChild(caliberNode);

		for (auto mfgPair : mfgs) {
			auto mfg = mfgPair.second;
			MfgNode* mfgNode = new MfgNode(mfg);

			std::stringstream where;
			where << "caliber=" << caliber.getId();
			where << " and ";
			where << "mfg=" << mfg.getId();

			auto bullets = db.getBullets(where.str().c_str());

			if(!bullets.empty()){
				caliberNode->addChild(mfgNode);
			}
			for (auto bulletPair : bullets) {
				auto bullet = bulletPair.second;

				std::stringstream bulletName;

				auto result = mfgs.find(bullet.getManufacturer());

				//std::cout << bullet.getManufacturer() << ": " << mfgs.count(bullet.getManufacturer()) << std::endl;

				if (result != mfgs.end()) {
					bulletName << result->second.getName() << " ";
				}
				bulletName << bullet.getName();

				BulletNode* bulletNode = new BulletNode(bullet);
				mfgNode->addChild(bulletNode);
			}
		}
	}

	return true;
}
