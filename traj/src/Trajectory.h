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

extern "C"
{
#include <traj.h>
}

namespace traj
{
class Trajectory {
public:
	Trajectory();
	virtual ~Trajectory();

	void calculate();
	void print();

private:
	lpTrajectory trajectory;
};
}

#endif /* TRAJECTORY_H_ */
