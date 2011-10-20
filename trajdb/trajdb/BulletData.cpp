/*
 * BulletData.cpp
 *
 *  Created on: Oct 19, 2011
 *      Author: wassj
 */

#include "BulletData.h"

traj::BulletData::BulletData()
		: id(0), bc(0), weight(0), caliber(0)
{
}

traj::BulletData::~BulletData()
{
}

int traj::BulletData::getId() const
{
	return id;
}

void traj::BulletData::setId(int id)
{
	this->id = id;
}

const char* traj::BulletData::getName() const
{
	return name.c_str();
}

void traj::BulletData::setName(const char* name)
{
	this->name = name;
}

float traj::BulletData::getBc() const
{
	return bc;
}

void traj::BulletData::setBc(float bc)
{
	this->bc = bc;
}

float traj::BulletData::getCaliber() const
{
	return caliber;
}

void traj::BulletData::setCaliber(float caliber)
{
	this->caliber = caliber;
}

float traj::BulletData::getWeight() const
{
	return weight;
}

void traj::BulletData::setWeight(float weight)
{
	this->weight = weight;
}

int traj::BulletData::getManufacturer() const
{
	return manufacturer;
}

void traj::BulletData::setManufacturer(int manufacturer)
{
	this->manufacturer = manufacturer;
}

const char* traj::BulletData::getImage() const
{
	return image.c_str();
}

void traj::BulletData::setImage(const char* image)
{
	if (0 != image) {
		this->image = image;
	}
	else {
		this->image.clear();
	}
}

const char* traj::BulletData::getModel() const
{
	return model.c_str();
}

void traj::BulletData::setModel(const char* model)
{
	if (0 != model) {
		this->model = model;
	}
	else {
		this->model.clear();
	}
}

