/*
 * TrajRangeData.cpp
 *
 *  Created on: Oct 17, 2011
 *      Author: wassj
 */

#include "TrajRangeData.h"

traj::TrajRangeData::TrajRangeData(const Range& range)
		: range(range.range), velocity(range.velocity), energy(range.energy), momentum(range.momentum), drop(range.drop), wind(range.windage), lead(range.lead)
{
}

