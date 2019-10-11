#ifndef ROSCOMPONENT_HPP
#define ROSCOMPONENT_HPP

#include <string>
#include <stdexcept>

#include "ros/ros.h"

#include "archlib/ROSComponentDescriptor.hpp"

namespace arch {
    class ROSComponent{

        public:
            ROSComponent(int &argc, char **argv, const std::string &name);
		    virtual ~ROSComponent();

        private:
            ROSComponent(const ROSComponent &);
		    ROSComponent &operator=(const ROSComponent &);

        public:
            virtual void setUp() = 0;
            virtual void tearDown() = 0;
            virtual int32_t run();
            virtual void body() = 0;

        protected:
            ROSComponentDescriptor rosComponentDescriptor;    

            static std::string getRosNodeName(const std::string& node_name, const std::string& node_namespace) {
                std::string ros_node_name = node_name;

                // std::cout << ros_node_name << std::endl;
                // ROS_INFO("%s", ros_node_name.c_str());
                size_t pos = ros_node_name.find(node_namespace);
                ros_node_name.replace(pos, node_namespace.length(), "");

                return ros_node_name;
            }
    };
}

#endif
