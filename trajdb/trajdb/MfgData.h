#ifndef MFGDATA_H_
#define MFGDATA_H_

#include <string>

#include "IConcept.h"

namespace traj
{

class MfgData : public IConcept
{
	public:
		MfgData();
		~MfgData()=default;

		int getId() const;
		void setId(int id);

		const char* getName() const;
		void setName(const char* name);

		virtual int queryCallback(int, char**, char**);

	private:
		int id;
		std::string name;
};

} /* namespace traj */
#endif /* MFGDATA_H_ */
