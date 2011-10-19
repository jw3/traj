#include <iostream>
#include "traj/Trajectory.h"
#include "trajdb/TrajDatabase.h"

using namespace std;

int main(int argc, char **argv)
{
	traj::TrajDatabase db;
	db.connect();
	db.getBullets();

	return 0;
}
