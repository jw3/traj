#include <iostream>
#include <map>

#include "traj/Trajectory.h"
#include "trajdb/TrajDatabase.h"

using namespace std;
using namespace traj;

int main(int argc, char **argv)
{
	TrajDatabase db;
	db.connect();
	map<int, BulletData> bullets = db.getBullets();

	map<int, BulletData>::iterator iter;
	for (iter = bullets.begin(); iter != bullets.end(); iter++) {
		const BulletData& bullet = iter->second;

		cout << "Bullet(" << bullet.getId() << ")" << endl
				<< "\tName: " << bullet.getName() << endl
				<< "\tWeight: " << bullet.getWeight() << endl
				<< "\tBC: " << bullet.getBc() << endl;
	}

	return 0;
}
