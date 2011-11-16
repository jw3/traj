/*
 * CaliberData.cpp
 *
 *  Created on: Nov 15, 2011
 *      Author: wassj
 */

#include "CaliberData.h"

namespace traj
{

CaliberData::CaliberData()
		: id(0), caliber(0)
{
}

int CaliberData::getId() const
{
	return id;
}

void CaliberData::setId(int id)
{
	this->id = id;
}

float CaliberData::getCaliber() const
{
	return caliber;
}

void CaliberData::setCaliber(float caliber)
{
	this->caliber = caliber;
}

}
