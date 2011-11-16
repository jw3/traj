/*
 * TrajBulletModel.h
 *
 *  Created on: Nov 12, 2011
 *      Author: wassj
 */

#ifndef TRAJBULLETMODEL_H_
#define TRAJBULLETMODEL_H_

#include <QAbstractItemModel>

#include <map>
#include <string>


typedef double Caliber;
typedef std::string Bullet;
typedef std::string Profile;

typedef std::multimap<Caliber, Bullet> Calibers;
typedef std::multimap<Bullet, Profile> Profiles;

class TrajBulletModel :
		public QAbstractItemModel
{
	Q_OBJECT

	public:
		TrajBulletModel(QObject* parent = 0);
		virtual ~TrajBulletModel();

		virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
		virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
		virtual QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
		virtual QModelIndex parent(const QModelIndex & index) const;
		virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;

	private:
		ITreeNode& root;

		Calibers calibers;
		Profiles profiles;
};

#endif /* TRAJBULLETMODEL_H_ */
