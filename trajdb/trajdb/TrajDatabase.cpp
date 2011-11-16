#include <iostream>
#include <sstream>
#include <functional>

#include "sqlite3.h"

#include "TrajDatabase.h"
#include "CaliberData.h"
#include "BulletData.h"
#include "MfgData.h"

using namespace traj;

template<class T>
static std::map<int, T> executeQuery(sqlite3*, sqlite3_callback, const char*, const char*, std::string&);
static int caliberQueryCallback(void*, int, char**, char**);
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

std::map<int, CaliberData> TrajDatabase::getCalibers(const char* where)
{
	return executeQuery<CaliberData>(db, caliberQueryCallback, "calibers", where, error);
}

std::map<int, BulletData> TrajDatabase::getBullets(const char* where)
{
	return executeQuery<BulletData>(db, bulletQueryCallback, "bullets", where, error);
}

std::map<int, MfgData> TrajDatabase::getMfgs(const char* where)
{
	return executeQuery<MfgData>(db, mfgQueryCallback, "manufacturers", where, error);
}

template <class T>
static std::map<int, T> executeQuery(sqlite3* db, sqlite3_callback callback, const char* table, const char* where, std::string& error)
{
	std::map<int, T> data;
	if (0 != db) {
		char* err = 0;
		std::stringstream ss;
		ss << "SELECT * FROM ";
		ss << table;
		if (0 != where) {
			ss << " WHERE ";
			ss << where;
		}
		int ec = sqlite3_exec(db, ss.str().c_str(), callback, &data, &err);
		if (SQLITE_OK != ec) {
			error = err;
			std::cout << "err, " << error << std::endl;
			sqlite3_free(err);
		}
	}
	return data;
}

// expected order: id, caliber
static int caliberQueryCallback(void* pMap, int c, char** v, char** col)
{
	std::map<int, CaliberData>* map = static_cast<std::map<int, CaliberData>*>(pMap);
	std::stringstream ss;

	CaliberData caliber;
	{
		int id = 0;
		ss << v[0];
		ss >> id;
		caliber.setId(id);
		ss.clear();
	}
	{
		// hmm, interesting if this works..
		decltype(caliber.getCaliber()) cal = 0;
		ss << v[1];
		ss >> cal;
		caliber.setCaliber(cal);
		ss.clear();
	}

	map->insert(std::make_pair(caliber.getId(), caliber));

	return SQLITE_OK;
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

	return SQLITE_OK;
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

	return SQLITE_OK;
}
