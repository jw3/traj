/*
 * TrajAtmosphere.cpp
 *
 *  Created on: Oct 18, 2011
 *      Author: wassj
 */

#include "TrajAtmosphere.h"


traj::TrajAtmosphere::TrajAtmosphere()
{
	atmos_standardatmos(&a);
}

traj::TrajAtmosphere::TrajAtmosphere(const Atmos& atmos)
{
	a.altitude = atmos.altitude;
	a.density = atmos.density;
	a.humidity = atmos.humidity;
	a.mach = atmos.mach;
	a.pressure = atmos.pressure;
	a.temperature = atmos.temperature;
}
