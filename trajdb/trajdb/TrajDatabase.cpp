#include <iostream>
#include <sstream>

#include "sqlite3.h"

#include "TrajDatabase.h"
#include "BulletData.h"
#include "MfgData.h"

using namespace traj;

static int bulletQueryCallback(void*, int, char**, char**);
static int mfgQueryCallback(void*, int, char**, char**);

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
		int ec = sqlite3_open("/home/wassj/code/personal/traj/trajdb/resources/trajdb.sqlite", &db);
		if (SQLITE_OK == ec) {
			std::cout << "[connected trajdb]" << std::endl;
			return true;
		}
		error = sqlite3_errmsg(db);
	}
	else {
		error = "already connected";
		return true;
	}
	return false;
}

void TrajDatabase::disconnect()
{
	if (0 != db) {
		sqlite3_close(db);
		std::cout << "[disconnected trajdb]" << std::endl;
	}
}

std::map<int, BulletData> TrajDatabase::getBullets(const char* where)
{
	std::map<int, BulletData> bullets;
	if (0 != db) {
		char* err = 0;
		std::string base = "SELECT * FROM bullets";
		if (0 != where) {
			base += " WHERE ";
			base += where;
		}
		int ec = sqlite3_exec(db, base.c_str(), bulletQueryCallback, &bullets, &err);
		if (SQLITE_OK != ec) {
			error = err;
			sqlite3_free(err);
		}
	}
	return bullets;
}

std::map<int, MfgData> TrajDatabase::getMfgs(const char* where)
{
	std::map<int, MfgData> mfgs;
	if (0 != db) {
		char* err = 0;
		std::string base = "SELECT * FROM manufacturers";
		if (0 != where) {
			base += " WHERE ";
			base += where;
		}
		int ec = sqlite3_exec(db, base.c_str(), mfgQueryCallback, &mfgs, &err);
		if (SQLITE_OK != ec) {
			error = err;
			sqlite3_free(err);
		}
	}
	return mfgs;
}

// expected order: id, caliber, weight, bc, name, img, mfg, dragfx
static int bulletQueryCallback(void* pMap, int c, char** v, char** col)
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
	{
		int fx = 0;
		ss << v[7];
		ss >> fx;
		bullet.setDragFx(static_cast<DRAGFUNC>(fx));
		ss.clear();
	}

	map->insert(std::make_pair(bullet.getId(), bullet));

	return 0;
}

// expected order: id, name
static int mfgQueryCallback(void* pMap, int c, char** v, char** col)
{
	std::map<int, MfgData>* map = static_cast<std::map<int, MfgData>*>(pMap);
	std::stringstream ss;

	MfgData mfg;
	{
		int id = 0;
		ss << v[0];
		ss >> id;
		mfg.setId(id);
		ss.clear();
	}
	mfg.setName(v[1]);

	map->insert(std::make_pair(mfg.getId(), mfg));

	return 0;
}
