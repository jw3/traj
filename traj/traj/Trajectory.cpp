/*
 * Trajectory.cpp
 *
 *  Created on: Oct 13, 2011
 *      Author: wassj
 */

#include "Trajectory.h"

#include <iostream>
#include <iomanip>
#include <sstream>

#include <jbm/utility.h>
#include <traj/TrajRangeData.h>

using namespace std;

traj::Trajectory::Trajectory()
{
	t = trajectory_create();

	t->velocity = 3400;
	t->weight = 55;
	t->wind.x = 0;
	t->wind.y = 0;
	t->wind.z = 0;
	t->chronodist = 7;
	t->sight_height = INTOFT(1.6);
	t->sight_offset = 0;
	t->speed = 5;  // target speed?
	t->speed_angle = 90;
	t->los_angle = 0;
	t->cant_angle = 0;
	t->range_min = 0;
	t->range_max = 500;
	t->range_inc = 100;
	t->zero.x = 250;
	t->zero.y = 0;
	t->zero.z = 0;
	t->bc->bc = .255;

	bc_setdragfunc(t->bc, g1);
	t->atmos->temperature = ATMOS_TEMPSTD;
	t->atmos->pressure = ATMOS_PRESSSTD;
	t->atmos->humidity = 0;
	t->atmos->altitude = 0;

	// no idea'r
	t->azimuth = 0;  //RAD(BRACKETDEF(tmp, MIN_AZ, MAX_AZ, DEF_AZ)/60.0);
	t->elevation = 0;  //RAD(BRACKETDEF(tmp, MIN_EL, MAX_EL, DEF_EL)/60.0);

	options_setoption(t->options, TRAJ_OPT_AZIM, true);
	options_setoption(t->options, TRAJ_OPT_ELEV, true);
	options_setoption(t->options, TRAJ_OPT_ALTI, true);
	options_setoption(t->options, TRAJ_OPT_BASIC, true);
	options_setoption(t->options, TRAJ_OPT_IN, 1);
}

traj::Trajectory::~Trajectory()
{
	trajectory_destroy(t);
}

traj::TrajectoryData traj::Trajectory::calculate()
{
	trajectory_calculate(t);

	TrajectoryData results;

	int steps = (t->range_max - t->range_min) / t->range_inc;
	for (int i = 0; i < steps + 1; ++i) {
		results.push_back(make_shared<TrajRangeData>(t->ranges[i]));
	}

	return results;
}

std::string traj::Trajectory::print()
{
	std::stringstream ss;
	int colw = 12;
	ss << setw(colw) << "range" << setw(colw) << "V" << setw(colw) << "energy" << setw(colw) << "momentum" << setw(colw) << "drop" << setw(colw) << "wind"
			<< setw(colw) << "lead" << endl;

	int steps = (t->range_max - t->range_min) / t->range_inc;
	for (int i = 0; i < steps + 1; ++i) {
		ss << setw(colw) << t->ranges[i].range << setw(colw) << setw(colw) << t->ranges[i].velocity << setw(colw) << setw(colw) << t->ranges[i].energy
				<< setw(colw) << setw(colw) << t->ranges[i].momentum << setw(colw) << setw(colw) << FTTOIN(t->ranges[i].drop) << setw(colw) << setw(colw)
				<< FTTOIN(t->ranges[i].windage) << setw(colw) << setw(colw) << FTTOIN(t->ranges[i].lead) << endl;
	}

	return ss.str();
}

traj::TrajVector traj::Trajectory::getZeroVector() const
{
	return TrajVector(t->zero.x, t->zero.y, t->zero.z);
}

void traj::Trajectory::setZeroVector(const traj::TrajVector& vector)
{
	t->zero.x = vector.getX();
	t->zero.y = vector.getY();
	t->zero.z = vector.getZ();
}

traj::TrajVector traj::Trajectory::getWindVector() const
{
	return TrajVector(t->wind.x, t->wind.y, t->wind.z);
}

void traj::Trajectory::setWindVector(const traj::TrajVector& vector)
{
	t->wind.x = vector.getX();
	t->wind.y = vector.getY();
	t->wind.z = vector.getZ();
}

traj::TrajAtmosphere traj::Trajectory::getAtmosphere() const
{
	return TrajAtmosphere(*t->atmos);
}

void traj::Trajectory::setAtmosphere(const traj::TrajAtmosphere& atmosphere)
{
	t->atmos->temperature = atmosphere.getTemperature();
	t->atmos->pressure = atmosphere.getPressure();
	t->atmos->humidity = atmosphere.getHumidity();
	t->atmos->altitude = atmosphere.getAltitude();
	t->atmos->mach = atmosphere.getMach();
	t->atmos->density = atmosphere.getDensity();
}

traj::TrajBC traj::Trajectory::getBC() const
{
	return TrajBC(*t->bc);
}

void traj::Trajectory::setBC(const traj::TrajBC& bc)
{
	t->bc->bc = bc.getBC();
	bc_setdragfunc(t->bc, bc.getDragFx());
}
