#include "archlib/Module.hpp"

namespace arch {
		
	Module::Module(const int32_t &argc, char **argv) : moduleDescriptor() {}
	Module::~Module() {}

	Module::Module(const Module &obj) : 
        moduleDescriptor(obj.getModuleDescriptor()) {}

    Module& Module::operator=(const Module &obj) {
        this->moduleDescriptor = obj.getModuleDescriptor();
    }

	void Module::setModuleDescriptor(const ModuleDescriptor &moduleDescriptor) {
		this->moduleDescriptor = moduleDescriptor;
	}
	
    ModuleDescriptor Module::getModuleDescriptor() const {
		return this->moduleDescriptor;
	}

	void Module::run() {
		setUp();

		ros::Rate loop_rate(moduleDescriptor.getFreq());
		while(!ros::isShuttingDown()) {
			ros::spinOnce();
            body();
            loop_rate.sleep();
		}

		tearDown();
	}
}