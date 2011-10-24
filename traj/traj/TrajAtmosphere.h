/*
 * TrajAtmosphere.h
 *
 *  Created on: Oct 18, 2011
 *      Author: wassj
 */

#ifndef TRAJATMOSPHERE_H_
#define TRAJATMOSPHERE_H_

extern "C"
{
#include "jbm/atmos.h"
}

namespace traj
{

class TrajAtmosphere
{
	public:
		TrajAtmosphere();
		TrajAtmosphere(const Atmos&);
		~TrajAtmosphere()=default;

		/* temperature in °F */
		double getTemperature() const { return a.temperature; }
		void setTemperature(double t) { a.temperature = t; }

		/* pressure in in Hg    */
		double getPressure() const { return a.pressure; }
		void setPressure(double p) { a.pressure = p; }

		/* relative humdity     */
		double getHumidity() const { return a.humidity; }
		void setHumidity(double h) { a.humidity = h; }

		/* altitude in feet     */
		double getAltitude() const { return a.altitude; }
		void setAltitude(double alt) { a.altitude = alt; }

		/* mach 1.0 in feet/sec */
		double getMach() const { return a.mach; }

		/* atmospheric density  */
		double getDensity() const { return a.density; }

	private:
		Atmos a;
};

} /* namespace traj */
#endif /* TRAJATMOSPHERE_H_ */
