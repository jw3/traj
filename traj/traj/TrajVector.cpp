/*
 * Vector.cpp
 *
 *  Created on: Oct 18, 2011
 *      Author: wassj
 */

#include "TrajVector.h"


traj::TrajVector::TrajVector()
	: v(vector(0, 0, 0))
{
}

traj::TrajVector::TrajVector(double x, double y, double z)
	: v(vector(x, y, z))
{
}

traj::TrajVector::TrajVector(const Vector& other)
	: v(vector(other.x, other.y, other.z))
{
}

traj::TrajVector::~TrajVector()
{
}

Vector traj::TrajVector::getVector() const
{
	return vector(v.x, v.y, v.z);
}



