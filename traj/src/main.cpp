/*
 * main.cpp
 *
 *  Created on: Oct 13, 2011
 *      Author: wassj
 */

#include <iostream>
#include "Trajectory.h"

using namespace std;

int main(int argc, char** argv)
{
	traj::Trajectory t;
	t.calculate();
	t.print();

	return 0;
}
