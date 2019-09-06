#include "archlib/ROSComponent.hpp"

namespace arch {
	ROSComponent::ROSComponent(const int32_t &argc, char **argv) : rosComponentDescriptor(argv[1]) {
        if(argc < 2) throw std::invalid_argument("Could not start component. Name not specified.");
        ros::init(argc, argv, argv[1]);
    }
	ROSComponent::~ROSComponent() {}

	ROSComponent::ROSComponent(const ROSComponent &obj){}
    ROSComponent& ROSComponent::operator=(const ROSComponent &obj) {}
}