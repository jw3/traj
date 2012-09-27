#ifndef TRAJDATABASE_H_
#define TRAJDATABASE_H_

#include <map>
#include <string>
#include <memory>
#include <sstream>
#include <typeinfo>
#include <functional>

#include "IConcept.h"

#include "CaliberData.h"
#include "BulletData.h"
#include "MfgData.h"

#include "sqlite3.h"

namespace traj
{
class CaliberData;
class BulletData;
class MfgData;

class TrajDatabase
{
	public:
		TrajDatabase();
		virtual ~TrajDatabase();

		bool connect();
		void disconnect();

		std::map<int, CaliberData> getCalibers(const char* where = 0);
		std::map<int, BulletData> getBullets(const char* where = 0);
		std::map<int, MfgData> getMfgs(const char* where = 0);

		template<class T>
		std::map<int, T*> list(const char* where = 0);

		const char* getError() const;

	private:
		sqlite3* db;
		std::string error;

		std::map<std::string, std::string> tables;
		std::map<std::string, std::map<int, IConcept*>> cache;
};

template<class T>
std::map<int, T*> TrajDatabase::list(const char* where)
{
	std::map<int, T*> data;
	if (0 != db) {
		// REVISIT need to look into the *ninja* static type checking
		//IConcept* concept = dynamic_cast<IConcept*>(&t);
		auto table = tables.find(typeid(T).name());
		if (table != tables.end()) {
			char* err = 0;
			std::stringstream ss;
			ss << "SELECT * FROM ";
			ss << table->second;
			if (0 != where) {
				ss << " WHERE ";
				ss << where;
			}

			/*
			 * REVISIT this code once gcc 4.7 is available
			 * =====================================================
			 * there seems to be some issues with capturing through the lambda.  anytime the data var
			 * is accessed in the lambda as a captured value it segfs.
			 *
			 * there also seems to be a conversion issue between fx*s and std::function. not sure if that
			 * is a bug or a misunderstanding on my part.
			 *
			 * Will hopefully make this code much more elegant later on.
			 */
			int(*callback)(void*x, int f, char**e, char**a) = [&] (void* pMap, int c, char** v, char** col)->int {
				std::map<int, T*>* data2 = static_cast<std::map<int, T*>*>(pMap);
				T* t = new T();
				int ec = t->queryCallback(c, v, col);
				(*data2)[t->getId()]= t;
				return ec;
			};

			int ec = sqlite3_exec(db, ss.str().c_str(), callback, &data, &err);
			if (SQLITE_OK != ec) {
				error = err;
				//std::cout << "err, " << error << std::endl;
				sqlite3_free(err);
			}
		}
	}
	return data;
}

}
#endif /* TRAJDATABASE_H_ */
