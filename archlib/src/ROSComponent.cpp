#include "archlib/ROSComponent.hpp"

namespace arch {
	ROSComponent::ROSComponent(int &argc, char **argv, const std::string &name) : rosComponentDescriptor() {
        ros::init(argc, argv, name, ros::init_options::NoSigintHandler); //Configure node name and sets commnd line arguments
        std::string node_name = getRosNodeName(ros::this_node::getName(), ros::this_node::getNamespace());
        rosComponentDescriptor.setName(node_name);
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
