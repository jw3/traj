#ifndef BULLETDATA_H_
#define BULLETDATA_H_

#include <jbm/drag.h>
#include <string>

#include "IConcept.h"

namespace traj
{

class BulletData : public IConcept
{
	public:
		BulletData();
		~BulletData()=default;

		float getBc() const;
		void setBc(float bc);

		int getCaliber() const;
		void setCaliber(int caliber);

		virtual int getId() const;
		virtual void setId(int id);

		const char* getImage() const;
		void setImage(const char* image);

		int getManufacturer() const;
		void setManufacturer(int manufacturer);

		int getVelocity() const;
		void setVelocity(int velocity);

		const char* getModel() const;
		void setModel(const char* model);

		const char* getName() const;
		void setName(const char* name);

		float getWeight() const;
		void setWeight(float weight);

		DRAGFUNC getDragFx() const;
		void setDragFx(DRAGFUNC dragFx);

		virtual int queryCallback(int, char**, char**);

	private:
		int id;
		float bc;
		float weight;
		float caliber;
		int velocity;
		int manufacturer;
		std::string name;
		std::string model;
		std::string image;
		DRAGFUNC dragFx;

		//caliber weight bc name model img mfg
};

} /* namespace traj */
#endif /* BULLETDATA_H_ */
