#ifndef PROBE_HPP
#define PROBE_HPP

#include <fstream>
#include <iostream>
#include <chrono>

#include "ros/ros.h"

#include "archlib/ROSComponent.hpp"

namespace arch {
    namespace target_system {

        class Probe : public ROSComponent {

            public:
                Probe(int &argc, char **argv);
                virtual ~Probe();

            private:
                Probe(const Probe &);
                Probe &operator=(const Probe &);

            public:
                virtual void setUp();
                virtual void tearDown();
                virtual int32_t run();
                virtual void body() = 0;

                void collectEvent(const messages::Event::ConstPtr& /*msg*/);
                void collectStatus(const messages::Status::ConstPtr& /*msg*/);

            private:
                ros::NodeHandle handle;
                ros::Subscriber collect_event;
                ros::Subscriber collect_status;
                ros::Publisher log_event;
                ros::Publisher log_status;
        };

    }
}


#endif 