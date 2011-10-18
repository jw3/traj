/*
 * TrajRangeData.cpp
 *
 *  Created on: Oct 17, 2011
 *      Author: wassj
 */

#include "TrajRangeData.h"

traj::TrajRangeData::TrajRangeData()
		: range(-9999), velocity(-9999), energy(-9999), momentum(-9999), drop(-9999), wind(-9999), lead(-9999)
{
}

traj::TrajRangeData::TrajRangeData(const Range& range)
		: range(range.range), velocity(range.velocity), energy(range.energy), momentum(range.momentum), drop(range.drop), wind(range.windage), lead(range.lead)
{
}

traj::TrajRangeData::~TrajRangeData()
{
}

