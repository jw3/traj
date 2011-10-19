/*
 * TrajDatabase.cpp
 *
 *  Created on: Oct 19, 2011
 *      Author: wassj
 */

#include <iostream>

#include "TrajDatabase.h"
#include "sqlite3.h"

static int callback(void* returnVector, int count, char **values, char **cols);


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

void traj::TrajDatabase::getBullets()
{
	char* err = 0;
	int ec = sqlite3_exec(db, "SELECT count(*) FROM manufacturers", callback, 0, &err);
	if (SQLITE_OK != ec) {
		error = err;
		sqlite3_free(err);
		//return false;
	}
	//return true;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for (i = 0; i < argc; i++) {
		std::cout << azColName[i] << (argv[i] ? argv[i] : "NULL") << std::endl;
	}
	return 0;
}
