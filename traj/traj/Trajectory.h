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
#include <vector>

#include "traj/TrajRangeData.h"
#include "traj/TrajVector.h"
#include "traj/TrajAtmosphere.h"
#include "traj/TrajBC.h"

extern "C"
{
#include <jbm/traj.h>
}

namespace traj
{

class Trajectory
{
	public:
		Trajectory();
		virtual ~Trajectory();

		void calculate(std::vector<TrajRangeData*>*);
		std::string print();

		double getMinimumRange() const	{ return t->range_min; }
		void setMinimumRange(double minRange) { t->range_min = minRange; }

		double getMaximumRange() const { return t->range_max; }
		void setMaximumRange(double maxRange) { t->range_max = maxRange; }

		double getStepSize() const { return t->range_inc; }
		void setStepSize(double stepSize) { t->range_inc = stepSize; }

		double getVelocity() const { return t->velocity; }
		void setVelocity(double velocity) { t->velocity = velocity; }

		double getChronoDistance() const { return t->chronodist; }
		void setChronoDistance(double distance) { t->chronodist = distance; }

		double getBulletWeight() const { return t->weight; }
		void setBulletWeight(double weight) { t->weight = weight; }

		double getSightHeight() const { return t->sight_height; }
		void setSightHeight(double height) { t->sight_height = height; }

		double getTargetMovementSpeed() const { return t->speed; }
		void setTargetMovementSpeed(double speed) { t->speed = speed; }

		double getTargetMovementAngle() const { return t->speed_angle; }
		void setTargetMovementAngle(double angle) { t->speed_angle = angle; }

		double getLineOfSightAngle() const { return t->los_angle; }
		void setLineOfSightAngle(double angle) { t->los_angle = angle; }

		traj::TrajVector getZeroVector() const;
		void setZeroVector(const traj::TrajVector&);

		traj::TrajVector getWindVector() const;
		void setWindVector(const traj::TrajVector&);

		traj::TrajAtmosphere getAtmosphere() const;
		void setAtmosphere(const traj::TrajAtmosphere&);

		traj::TrajBC getBC() const;
		void setBC(const traj::TrajBC&);

		/*
		double azimuth;			// ?
		double elevation;		// ?
		double cant_angle;		// REVISIT
		double sight_offset;	// REVISIT
		Vector gravity;			// Constant

		options_setoption(trajectory->options, TRAJ_OPT_AZIM, true); 	// REVISIT
		options_setoption(trajectory->options, TRAJ_OPT_ELEV, true); 	// REVISIT
		options_setoption(trajectory->options, TRAJ_OPT_ALTI, true); 	// REVISIT
		options_setoption(trajectory->options, TRAJ_OPT_BASIC, true); 	// REVISIT
		options_setoption(trajectory->options, TRAJ_OPT_IN, 1); 		// REVISIT
		 */

	private:
		lpTrajectory t;
};
}

#endif /* TRAJECTORY_H_ */
