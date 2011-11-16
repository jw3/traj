/*
 * CaliberData.h
 *
 *  Created on: Nov 15, 2011
 *      Author: wassj
 */

#ifndef CALIBERDATA_H_
#define CALIBERDATA_H_

namespace traj
{

class CaliberData
{
	public:
		CaliberData();
		~CaliberData()=default;

		int getId() const;
		void setId(int id);

		float getCaliber() const;
		void setCaliber(float caliber);

	private:
		int id;
		float caliber;
	};
}

#endif /* CALIBERDATA_H_ */
