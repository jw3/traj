/*
 * IConcept.h
 *
 *  Created on: Nov 16, 2011
 *      Author: wassj
 */

#ifndef ICONCEPT_H_
#define ICONCEPT_H_

#include "sqlite3.h"

struct IConcept
{
	virtual ~IConcept(){}

	virtual int getId() const = 0;
	virtual int queryCallback(int, char**, char**) = 0;
};


#endif /* ICONCEPT_H_ */
