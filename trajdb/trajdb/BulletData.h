/*
 * BulletData.h
 *
 *  Created on: Oct 19, 2011
 *      Author: wassj
 */

#ifndef BULLETDATA_H_
#define BULLETDATA_H_

#include <string>

namespace traj
{

class BulletData
{
	public:
		BulletData();
		virtual ~BulletData();

	private:
		int id;
		float bc;
		float weight;
		float caliber;
		std::string name;
		std::string model;
		std::string image;
		std::string manufacturer;

		//caliber weight bc name model img mfg
};

} /* namespace traj */
#endif /* BULLETDATA_H_ */
