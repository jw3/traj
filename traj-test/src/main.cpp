#include <iostream>
#include <sstream>
#include <map>

#include "traj/Trajectory.h"

#include "trajdb/TrajDatabase.h"
#include "trajdb/BulletData.h"
#include "trajdb/MfgData.h"

#include "jbm/drag.h"

using namespace std;
using namespace traj;

int main(int argc, char **argv)
{
	TrajDatabase db;
	db.connect();
	map<int, MfgData> mfgs = db.getMfgs("name = 'Sierra'");

	map<int, MfgData>::iterator mfgIter;
	for (mfgIter = mfgs.begin(); mfgIter != mfgs.end(); mfgIter++) {
		const MfgData& mfg = mfgIter->second;
		cout << "Mfg(" << mfg.getId() << ")" << endl << "\tName: " << mfg.getName() << endl;

		stringstream ss;
		ss << "mfg=";
		ss << mfg.getId();

		map<int, BulletData> bullets = db.getBullets(ss.str().c_str());
		map<int, BulletData>::iterator bulletIter;
		for (bulletIter = bullets.begin(); bulletIter != bullets.end(); bulletIter++) {
			const BulletData& bullet = bulletIter->second;

			cout << "Bullet(" << bullet.getId() << ")" << endl;
			cout << "\tName: " << bullet.getName() << endl;
			cout << "\tWeight: " << bullet.getWeight() << endl;
			cout << "\tBC: " << bullet.getBc() << endl;

			const char* dragStr = dragstr[bullet.getDragFx()];
			cout << "\tFx: " << dragStr << endl;
		}
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
