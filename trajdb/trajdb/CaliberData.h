/*
 * CaliberData.h
 *
 *  Created on: Nov 15, 2011
 *      Author: wassj
 */

#ifndef CALIBERDATA_H_
#define CALIBERDATA_H_

#include "IConcept.h"

namespace traj
{

class CaliberData : public IConcept
{
	public:
		CaliberData();
		~CaliberData()=default;

		virtual int getId() const;
		void setId(int id);

		float getCaliber() const;
		void setCaliber(float caliber);

		virtual int queryCallback(int, char**, char**);

	private:
		int id;
		float caliber;
	};
}

#endif /* CALIBERDATA_H_ */
