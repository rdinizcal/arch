#ifndef ROSCOMPONENT_DESCRIPTOR_H
#define ROSCOMPONENT_DESCRIPTOR_H

#include <string>

namespace arch {
	class ROSComponentDescriptor {

		public:
			ROSComponentDescriptor(std::string &name);
			virtual ~ROSComponentDescriptor();

		private:
			ROSComponentDescriptor(const ROSComponentDescriptor &);
			ROSComponentDescriptor &operator=(const ROSComponentDescriptor &);

		public:
			std::string getName() const;

			void setFreq(const double &freq);
			double getFreq() const;

		private:
			std::string name;
			double freq;
	};
}


#endif