/*
 * TrajDatabase.h
 *
 *  Created on: Oct 19, 2011
 *      Author: wassj
 */

#ifndef TRAJDATABASE_H_
#define TRAJDATABASE_H_

#include <map>
#include <string>

#include "BulletData.h"

struct sqlite3;

namespace traj
{

class TrajDatabase
{
	public:
		TrajDatabase();
		virtual ~TrajDatabase();

		bool connect();
		void disconnect();

		std::map<int, BulletData> getBullets();

		const char* getError() const { return !error.empty() ? error.c_str() : 0; }

	private:
		sqlite3 *db;
		std::string error;
};

} /* namespace traj */
#endif /* TRAJDATABASE_H_ */
