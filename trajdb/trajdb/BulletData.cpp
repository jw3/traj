#include "BulletData.h"

#include <sstream>

using namespace traj;

BulletData::BulletData()
		: id(0), bc(0), weight(0), caliber(0), dragFx(g1)
{
}

int BulletData::getId() const
{
	return id;
}

void BulletData::setId(int id)
{
	this->id = id;
}

const char* BulletData::getName() const
{
	return name.c_str();
}

void BulletData::setName(const char* name)
{
	if (0 != name) {
		this->name = name;
	}
	else {
		this->name.clear();
	}
}

float BulletData::getBc() const
{
	return bc;
}

void BulletData::setBc(float bc)
{
	this->bc = bc;
}

int BulletData::getCaliber() const
{
	return caliber;
}

void BulletData::setCaliber(int caliber)
{
	this->caliber = caliber;
}

float BulletData::getWeight() const
{
	return weight;
}

void BulletData::setWeight(float weight)
{
	this->weight = weight;
}

int BulletData::getVelocity() const
{
	return velocity;
}

void BulletData::setVelocity(int velocity)
{
	this->velocity = velocity;
}

int BulletData::getManufacturer() const
{
	return manufacturer;
}

void BulletData::setManufacturer(int manufacturer)
{
	this->manufacturer = manufacturer;
}

const char* BulletData::getImage() const
{
	return image.c_str();
}

void BulletData::setImage(const char* image)
{
	if (0 != image) {
		this->image = image;
	}
	else {
		this->image.clear();
	}
}

const char* BulletData::getModel() const
{
	return model.c_str();
}

void BulletData::setModel(const char* model)
{
	if (0 != model) {
		this->model = model;
	}
	else {
		this->model.clear();
	}
}

DRAGFUNC traj::BulletData::getDragFx() const
{
	return dragFx;
}



void traj::BulletData::setDragFx(DRAGFUNC dragFx)
{
	this->dragFx = dragFx;
}

int traj::BulletData::queryCallback(int c, char** v, char** col)
{
	std::stringstream ss;

	{
		int id = 0;
		ss << v[0];
		ss >> id;
		this->setId(id);
		ss.clear();
	}
	{
		float caliber = 0;
		ss << v[1];
		ss >> caliber;
		this->setCaliber(caliber);
		ss.clear();
	}
	{
		float weight = 0;
		ss << v[2];
		ss >> weight;
		this->setWeight(weight);
		ss.clear();
	}
	{
		float bc = 0;
		ss << v[3];
		ss >> bc;
		this->setBc(bc);
		ss.clear();
	}

	this->setName(v[4]);
	this->setImage(v[5]);

	{
		int mfg = 0;
		ss << v[6];
		ss >> mfg;
		this->setManufacturer(mfg);
		ss.clear();
	}
	{
		int fx = 0;
		ss << v[7];
		ss >> fx;
		this->setDragFx(static_cast<DRAGFUNC>(fx));
		ss.clear();
	}

	return 0;
}
