#include <iostream>
#include <sstream>

#include "sqlite3.h"

#include "TrajDatabase.h"
#include "BulletData.h"

using namespace traj;

static int callback(void*, int, char**, char**);

TrajDatabase::TrajDatabase()
		: db(0)
{
}

TrajDatabase::~TrajDatabase()
{
	disconnect();
}

bool TrajDatabase::connect()
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

void TrajDatabase::disconnect()
{
	if (0 != db) {
		sqlite3_close(db);
		std::cout << "disconnected" << std::endl;
	}
}

std::map<int, BulletData> TrajDatabase::getBullets()
{
	std::map<int, BulletData> data;
	if (0 != db) {
		char* err = 0;
		int ec = sqlite3_exec(db, "SELECT * FROM bullets", callback, &data, &err);
		if (SQLITE_OK != ec) {
			error = err;
			sqlite3_free(err);
			//return false;
		}
	}
	return data;
}

// expected order: id, caliber, weight, bc, name, img, mfg
static int callback(void* pMap, int c, char** v, char** col)
{
	std::map<int, BulletData>* map = static_cast<std::map<int, BulletData>*>(pMap);
	std::stringstream ss;

	BulletData bullet;
	{
		int id = 0;
		ss << v[0];
		ss >> id;
		bullet.setId(id);
		ss.clear();
	}
	{
		float caliber = 0;
		ss << v[1];
		ss >> caliber;
		bullet.setCaliber(caliber);
		ss.clear();
	}
	{
		float weight = 0;
		ss << v[2];
		ss >> weight;
		bullet.setWeight(weight);
		ss.clear();
	}
	{
		float bc = 0;
		ss << v[3];
		ss >> bc;
		bullet.setBc(bc);
		ss.clear();
	}

	bullet.setName(v[4]);
	bullet.setImage(v[5]);

	{
		int mfg = 0;
		ss << v[6];
		ss >> mfg;
		bullet.setManufacturer(mfg);
		ss.clear();
	}

	map->insert(std::make_pair(bullet.getId(), bullet));

	return 0;
}
