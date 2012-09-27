/*
 * TrajBulletModel.h
 *
 *  Created on: Nov 12, 2011
 *      Author: wassj
 */

#ifndef TRAJBULLETMODEL_H_
#define TRAJBULLETMODEL_H_

#include <QAbstractItemModel>

#include <trajdb/TrajDatabase.h>
#include "TreeNodes.h"

class TrajBulletTreeModel :
		public QAbstractItemModel
{
	Q_OBJECT

	public:
		TrajBulletTreeModel(QObject* parent = 0);
		virtual ~TrajBulletTreeModel();

		virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
		virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
		virtual QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
		virtual QModelIndex parent(const QModelIndex & index) const;
		virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;

		bool init(traj::TrajDatabase&);

	private:
		RootNode* root;
};

#endif /* TRAJBULLETMODEL_H_ */
