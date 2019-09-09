#include "archlib/ROSComponent.hpp"

namespace arch {
	ROSComponent::ROSComponent(int &argc, char **argv, const std::string &name) : rosComponentDescriptor() {
        ros::init(argc, argv, name, ros::init_options::AnonymousName);
        rosComponentDescriptor.setName(ros::this_node::getName());
    }
	ROSComponent::~ROSComponent() {}

	ROSComponent::ROSComponent(const ROSComponent &obj){}
    ROSComponent& ROSComponent::operator=(const ROSComponent &obj) {}
}