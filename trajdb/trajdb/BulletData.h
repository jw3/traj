#ifndef BULLETDATA_H_
#define BULLETDATA_H_

#include <string>

namespace traj
{

class BulletData
{
	public:
		BulletData();
		virtual ~BulletData();

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

	private:
		int id;
		float bc;
		float weight;
		float caliber;
		int manufacturer;
		std::string name;
		std::string model;
		std::string image;

		//caliber weight bc name model img mfg
};

} /* namespace traj */
#endif /* BULLETDATA_H_ */
