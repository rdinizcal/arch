#ifndef MODULE_DESCRIPTOR_H
#define MODULE_DESCRIPTOR_H

#include "ros/ros.h"

class ModuleDescriptor {

	public:
		ModuleDescriptor(const std::string &name, const double &freq, const uint32_t &deadline, const uint32_t wce, const bool &connection);
		ModuleDescriptor(const ModuleDescriptor &);
		ModuleDescriptor &operator=(const ModuleDescriptor &);

		ModuleDescriptor();
		~ModuleDescriptor();

	public:
		void setName(const std::string &name);
		std::string getName() const;

        void setFreq(const double &freq);
		double getFreq() const;

        void setDeadline(const uint32_t &deadline);
		uint32_t getDeadline() const;

        void setWorstCaseExecutionTime(const std::uint32_t &wce);
		uint32_t getWorstCaseExecutionTime() const;

        void setConnection(const bool &connection);
		bool getConnection() const;

	private:
        std::string name;
        double freq;
        uint32_t deadline;
        uint32_t wce;
        bool connection;
};

#endif