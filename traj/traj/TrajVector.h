/*
 * Vector.h
 *
 *  Created on: Oct 18, 2011
 *      Author: wassj
 */

#ifndef TRAJVECTOR_H_
#define TRAJVECTOR_H_

extern "C"
{
#include "jbm/vectors.h"
}

namespace traj
{

class TrajVector
{
	public:
		TrajVector();
		TrajVector(double, double, double);
		TrajVector(const Vector&);

		virtual ~TrajVector();

		double getX() const { return v.x; }
		void setX(double x) { v.x = x; }

		double getY() const { return v.y; }
		void setY(double y) { v.y = y; }

		double getZ() const { return v.z; }
		void setZ(double z) { v.z = z; }

		Vector getVector() const;

	private:
		Vector v;
};

} /* namespace traj */
#endif /* TRAJVECTOR_H_ */
