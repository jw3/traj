/*
 * Trajectory.h
 *
 *  Created on: Oct 13, 2011
 *      Author: wassj
 *
 *  Wrapper for the JBM Trajectory struct and related calculations
 */

#ifndef TRAJECTORY_H_
#define TRAJECTORY_H_

#include <string>

extern "C"
{
#include <jbm/traj.h>
}

namespace traj
{
class Trajectory {
public:
	Trajectory();
	virtual ~Trajectory();

	void calculate();
	std::string print();

	double getVelocity() const;
	void setVelocity(double);

private:
	lpTrajectory trajectory;
};
}

#endif /* TRAJECTORY_H_ */
