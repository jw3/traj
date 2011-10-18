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

using namespace std;

traj::Trajectory::Trajectory()
{
	trajectory = trajectory_create();

	trajectory->velocity = 3400;
	trajectory->weight = 55;
	trajectory->wind.x = 0;
	trajectory->wind.y = 0;
	trajectory->wind.z = 0;
	trajectory->chronodist = 7;
	trajectory->sight_height = INTOFT(1.6);
	trajectory->sight_offset = 0;
	trajectory->speed = 5;  // target speed?
	trajectory->speed_angle = 90;
	trajectory->los_angle = 0;
	trajectory->cant_angle = 0;
	trajectory->range_min = 0;
	trajectory->range_max = 500;
	trajectory->range_inc = 100;
	trajectory->zero.x = 250;
	trajectory->zero.y = 0;
	trajectory->zero.z = 0;
	trajectory->bc->bc = .255;

	bc_setdragfunc(trajectory->bc, g1);
	trajectory->atmos->temperature = ATMOS_TEMPSTD;
	trajectory->atmos->pressure = ATMOS_PRESSSTD;
	trajectory->atmos->humidity =  0;
	trajectory->atmos->altitude =  0;

	// no idea'r
	trajectory->azimuth = 0;//RAD(BRACKETDEF(tmp, MIN_AZ, MAX_AZ, DEF_AZ)/60.0);
	trajectory->elevation = 0;//RAD(BRACKETDEF(tmp, MIN_EL, MAX_EL, DEF_EL)/60.0);

	options_setoption(trajectory->options, TRAJ_OPT_AZIM, true);
	options_setoption(trajectory->options, TRAJ_OPT_ELEV, true);
	options_setoption(trajectory->options, TRAJ_OPT_ALTI, true);
	options_setoption(trajectory->options, TRAJ_OPT_BASIC, true);
	options_setoption(trajectory->options, TRAJ_OPT_IN, 1);
}

traj::Trajectory::~Trajectory()
{
	trajectory_destroy(trajectory);
}

double traj::Trajectory::getVelocity() const
{
	return trajectory->velocity = 3400;
}

void traj::Trajectory::setVelocity(double velocity)
{
	trajectory->velocity = 3400;
}


void traj::Trajectory::calculate(std::vector<TrajRangeData*>* vector)
{
	trajectory_calculate(trajectory);

	if(NULL != vector)
	{
		int steps = (trajectory->range_max - trajectory->range_min)/trajectory->range_inc;
		for (int i = 0; i < steps + 1; ++i)
		{
			TrajRangeData* data = new TrajRangeData(trajectory->ranges[i]);
			vector->push_back(data);
		}
	}
}


std::string traj::Trajectory::print()
{
	std::stringstream ss;
	int colw = 12;
	ss << setw(colw) << "range" << setw(colw) << "V" << setw(colw) << "energy" << setw(colw) << "momentum" << setw(colw) << "drop" << setw(colw) << "wind" << setw(colw) << "lead" << endl;

	int steps = (trajectory->range_max - trajectory->range_min)/trajectory->range_inc;
	for (int i = 0; i < steps + 1; ++i)
	{
		ss << setw(colw) << trajectory->ranges[i].range << setw(colw)
		  << setw(colw) << trajectory->ranges[i].velocity << setw(colw)
		  << setw(colw) << trajectory->ranges[i].energy << setw(colw)
		  << setw(colw) << trajectory->ranges[i].momentum << setw(colw)
		  << setw(colw) << FTTOIN(trajectory->ranges[i].drop) << setw(colw)
		  << setw(colw) << FTTOIN(trajectory->ranges[i].windage) << setw(colw)
		  << setw(colw) << FTTOIN(trajectory->ranges[i].lead) << endl;
	}

	return ss.str();
}
