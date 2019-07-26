#ifndef SCHEDULABLE_COMPONENT_HPP
#define SCHEDULABLE_COMPONENT_HPP

#include <signal.h>

#include "RuntimeBehavior.hpp"
#include "Communication.hpp"
#include "ModuleDescriptor.hpp"

#include "std_msgs/String.h"
#include "ros/ros.h"


namespace arch {

    class SchedulableComponent : RuntimeBehavior, Communication {
        private:
            SchedulableComponent(const SchedulableComponent &);
		    SchedulableComponent &operator=(const SchedulableComponent &);

            void schedulingCallback(const std_msgs::StringConstPtr& msg);

        public:
            virtual void SchedulableComponent(const int32_t &argc, char **argv);
		    virtual void ~SchedulableComponent();
            static void schedulingSigIntHandler(int sig);

            virtual void setup();
            virtual void teardown();
            virtual void run();
            virtual void body() = 0;

        private:
            arch:ModuleDescriptor md;
            std::string received_name;
            ros::Publisher scheduling_pub;
            ros::Subscriber sched;
            ros::ServiceClient client_module;
            std::string topic_name;
            std::string finish_topic_name;
            float check_frequency;
            float period;
    };
}

#endif