/*
 * TrajBC.h
 *
 *  Created on: Oct 18, 2011
 *      Author: wassj
 */

#ifndef TRAJBC_H_
#define TRAJBC_H_

extern "C"
{
#include "jbm/bc.h"
}

namespace traj
{

class TrajBC
{
	public:
		TrajBC();
		TrajBC(const BC&);
		virtual ~TrajBC();

		double getBC() const  { return bc.bc; }
		void setBC(double bc) { this->bc.bc = bc; }

		DRAGFUNC getDragFx() const { return bc.dragfunc; }
		void setDragFx(DRAGFUNC fx) { bc_setdragfunc(&bc, fx); }

	private:
		BC bc;
};

} /* namespace traj */
#endif /* TRAJBC_H_ */
