#ifndef BULLETDATA_H_
#define BULLETDATA_H_

#include <jbm/drag.h>
#include <string>

namespace traj
{

class BulletData
{
	public:
		BulletData();
		~BulletData()=default;

		float getBc() const;
		void setBc(float bc);

		float getCaliber() const;
		void setCaliber(float caliber);

		int getId() const;
		void setId(int id);

		const char* getImage() const;
		void setImage(const char* image);

		int getManufacturer() const;
		void setManufacturer(int manufacturer);

		const char* getModel() const;
		void setModel(const char* model);

		const char* getName() const;
		void setName(const char* name);

		float getWeight() const;
		void setWeight(float weight);

		DRAGFUNC getDragFx() const;
		void setDragFx(DRAGFUNC dragFx);

	private:
		int id;
		float bc;
		float weight;
		float caliber;
		int manufacturer;
		std::string name;
		std::string model;
		std::string image;
		DRAGFUNC dragFx;

		//caliber weight bc name model img mfg
};

} /* namespace traj */
#endif /* BULLETDATA_H_ */
