#include "MfgData.h"

using namespace traj;

MfgData::MfgData()
		: id(0)
{
}

MfgData::~MfgData()
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