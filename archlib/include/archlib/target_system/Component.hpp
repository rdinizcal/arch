#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>

#include "ros/ros.h"

#include "archlib/ROSComponent.hpp"

namespace arch {
    namespace target_system {

        class Component : public ROSComponent {

            public:
                Component(const int32_t &argc, char **argv);
                virtual ~Component();

            private:
                Component(const Component &);
                Component &operator=(const Component &);

            public:
                virtual void setUp();
                virtual void tearDown();
                virtual int32_t run();
                virtual void body() = 0;

            private:
                ros::NodeHandle handle;
        };

    }
}

#endif