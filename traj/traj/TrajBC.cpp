/*
 * TrajBC.cpp
 *
 *  Created on: Oct 18, 2011
 *      Author: wassj
 */

#include "TrajBC.h"


traj::TrajBC::TrajBC()
{
	bc.bc = .5;
	bc_setdragfunc(&bc, g1);
}

traj::TrajBC::TrajBC(const BC& bc)
{
	this->bc.bc = bc.bc;
	bc_setdragfunc(&this->bc, bc.dragfunc);
}

traj::TrajBC::~TrajBC()
{
}
