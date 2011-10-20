#include <iostream>
#include <map>

#include "traj/Trajectory.h"

#include "trajdb/TrajDatabase.h"
#include "trajdb/BulletData.h"
#include "trajdb/MfgData.h"

using namespace std;
using namespace traj;

int main(int argc, char **argv)
{
	TrajDatabase db;
	db.connect();
	map<int, MfgData> mfgs = db.getMfgs();
	map<int, BulletData> bullets = db.getBullets("id = 17222");

	map<int, BulletData>::iterator bulletIter;
	for (bulletIter = bullets.begin(); bulletIter != bullets.end(); bulletIter++) {
		const BulletData& bullet = bulletIter->second;
		cout << "Bullet(" << bullet.getId() << ")" << endl
			<< "\tName: " << bullet.getName() << endl
			<< "\tWeight: " << bullet.getWeight()
			<< endl << "\tBC: "
			<< bullet.getBc() << endl;
	}

	map<int, MfgData>::iterator mfgIter;
		for (mfgIter = mfgs.begin(); mfgIter != mfgs.end(); mfgIter++) {
			const MfgData& bullet = mfgIter->second;
			cout << "Mfg(" << bullet.getId() << ")" << endl
				<< "\tName: " << bullet.getName() << endl;
		}

	// some cool c++11 stuff
//	for (auto bullet_entry : bullets) {
//		const BulletData& bullet = bullet_entry.second;
//		cout << "Bullet(" << bullet.getId() << ")" << endl
//				<< "\tName: " << bullet.getName() << endl
//				<< "\tWeight: " << bullet.getWeight()
//				<< endl << "\tBC: "
//				<< bullet.getBc() << endl;
//	}
//
//	auto f = [] () {cout << "in lambda" << endl;};
//	f();

	return 0;
}
