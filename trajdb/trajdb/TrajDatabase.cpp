/*
 * TrajDatabase.cpp
 *
 *  Created on: Oct 19, 2011
 *      Author: wassj
 */

#include <iostream>

#include "TrajDatabase.h"
#include "sqlite3.h"

static int callback(void*, int, char**, char**);

traj::TrajDatabase::TrajDatabase()
		: db(0)
{
}

traj::TrajDatabase::~TrajDatabase()
{
	disconnect();
}

bool traj::TrajDatabase::connect()
{
	if (0 == db) {
		int ec = sqlite3_open("C:/local/code/personal/traj/trajdb/resources/trajdb.sqlite", &db);
		if (SQLITE_OK == ec) {
			std::cout << "connectedzzz" << std::endl;
			return true;
		}
		error = sqlite3_errmsg(db);
	}
	else {
		error = "already connected";
	}
	return false;
}

void traj::TrajDatabase::disconnect()
{
	if (0 != db) {
		sqlite3_close(db);
		std::cout << "disconnected" << std::endl;
	}
}

std::map<int, traj::BulletData> traj::TrajDatabase::getBullets()
{
	std::map<int, traj::BulletData> data;
	if (0 != db) {
		char* err = 0;
		int ec = sqlite3_exec(db, "SELECT count(*) FROM manufacturers", callback, &data, &err);
		if (SQLITE_OK != ec) {
			error = err;
			sqlite3_free(err);
			//return false;
		}
	}
	return data;
}

static int callback(void* pData, int argc, char** argv, char** azColName)
{
	std::map<int, traj::BulletData>* data = static_cast<std::map<int, traj::BulletData>*>(pData);

	int i;
	for (i = 0; i < argc; i++) {
		std::cout << azColName[i] << (argv[i] ? argv[i] : "NULL") << std::endl;
	}
	return 0;
}
