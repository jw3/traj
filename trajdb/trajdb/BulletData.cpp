#include "BulletData.h"

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


