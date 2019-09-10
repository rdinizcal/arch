#include "archlib/ROSComponent.hpp"

namespace arch {
	ROSComponent::ROSComponent(int &argc, char **argv, const std::string &name) : rosComponentDescriptor() {
        ros::init(argc, argv, name, ros::init_options::AnonymousName); //Configure node name and sets commnd line arguments
        rosComponentDescriptor.setName(ros::this_node::getName());
    }
	ROSComponent::~ROSComponent() {}

    int32_t ROSComponent::run() {
        setUp();

        while(ros::ok()) {
            ros::Rate loop_rate(rosComponentDescriptor.getFreq());
            ros::spinOnce();
            body();
            loop_rate.sleep();
        }

        tearDown();
        
        return 0;
    }
}