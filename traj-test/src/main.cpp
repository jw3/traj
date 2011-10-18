#include <iostream>
#include "traj/Trajectory.h"

using namespace std;

int main(int argc, char** argv)
{
	traj::Trajectory t;

	t.calculate();
	t.print();

	return 0;
}
