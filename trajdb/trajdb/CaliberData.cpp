/*
 * CaliberData.cpp
 *
 *  Created on: Nov 15, 2011
 *      Author: wassj
 */

#include "CaliberData.h"

#include <sstream>

using namespace traj;

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

int CaliberData::queryCallback(int c, char** v, char** col)
{
	std::stringstream ss;
	{
		int id = 0;
		ss << v[0];
		ss >> id;
		this->setId(id);
		ss.clear();
	}
	{
		// hmm, interesting if this works..
		decltype(this->getCaliber()) cal = 0;
		ss << v[1];
		ss >> cal;
		this->setCaliber(cal);
		ss.clear();
	}
	return 0;
}
