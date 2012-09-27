#include "MfgData.h"

#include <sstream>

using namespace traj;

MfgData::MfgData()
		: id(0)
{
}

int MfgData::getId() const
{
	return id;
}

void MfgData::setId(int id)
{
	this->id = id;
}

const char* MfgData::getName() const
{
	return name.c_str();
}

void MfgData::setName(const char* name)
{
	if (0 != name) {
		this->name = name;
	}
	else {
		this->name.clear();
	}
}

int MfgData::queryCallback(int c, char** v, char** col)
{
	std::stringstream ss;
	{
		int id = 0;
		ss << v[0];
		ss >> id;
		this->setId(id);
		ss.clear();
	}
	this->setName(v[1]);

	return 0;
}
