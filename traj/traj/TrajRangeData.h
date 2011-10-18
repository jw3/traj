/*
 * TrajRangeData.h
 *
 *  Created on: Oct 17, 2011
 *      Author: wassj
 */

#ifndef TRAJRANGEDATA_H_
#define TRAJRANGEDATA_H_

extern "C"
{
#include "jbm/traj.h"
}

namespace traj
{
class TrajRangeData {
public:
	TrajRangeData();
	TrajRangeData(const Range& range);
	virtual ~TrajRangeData();

    double getDrop() const { return drop; }
    void setDrop(double drop) { this->drop = drop; }

    double getEnergy() const  { return energy; }
    void setEnergy(double energy) { this->energy = energy; }

    double getLead() const { return lead; }
    void setLead(double lead) { this->lead = lead; }

    double getMomentum() const { return momentum; }
    void setMomentum(double momentum) { this->momentum = momentum; }

    double getRange() const { return range; }
    void setRange(double range) { this->range = range; }

    double getVelocity() const { return velocity; }
    void setVelocity(double velocity) { this->velocity = velocity; }

    double getWind() const { return wind; }
    void setWind(double wind) { this->wind = wind; }

private:
    double range;
    double velocity;
    double energy;
    double momentum;
    double drop;
    double wind;
    double lead;
};
}

#endif /* TRAJRANGEDATA_H_ */
